function [fused,W] = TooLight(I, mu, k, a, b) % camera a, b
%%
% @inproceedings{ying2017new,
%   title={A New Image Contrast Enhancement Algorithm Using Exposure Fusion Framework},
%   author={Ying, Zhenqiang and Li, Ge and Ren, Yurui and Wang, Ronggang and Wang, Wenmin},
%   booktitle={International Conference on Computer Analysis of Images and Patterns},
%   pages={36--46},
%   year={2017},
%   organization={Springer}
% }
%
% Please feel free to contact me (yingzhenqiang-at-gmail-dot-com) if you
% have any questions or concerns.


% 如果该参数没有赋值，将其赋固定值
if  ~exist( 'mu', 'var' )  %照度图T的指数，数值越大，增强程度越大
    mu = 0.5;
end

if ~exist( 'a', 'var' )  %BTF函数的参数
    a = -0.3293;
end

if ~exist( 'b', 'var' )  %BTF函数的参数
    b = 1.1258;
end

if ~isfloat(I)
    %size(I)
    %I
    I = im2double( I );  %图像数据类型转换为double类型
    %I
end

% 
lambda = 0.5;
sigma = 5;

%% t: scene illumination map
t_b = max( I, [], 3 );  %取RGB中的最大值作为该像素的灰度值 ， 亮度矩阵L（灰度图）
%size(t_b)
%t_b(1,1) 看看矩阵结果
%t_b(101,101)
%t_b(151,151)
%t_b(201,201)
t_our =  imresize( tsmooth( imresize( t_b, 0.5 ), lambda, sigma ), size( t_b ) ); %求解照度图T（灰度图）
%t_our =  imresize( tsmooth( imresize( t_b, [256,256] ), lambda, sigma ), size( t_b ) ); %求解照度图T（灰度图）
%t_b2=imresize( t_b, 0.5 );
%t_our = tsmooth( t_b, lambda, sigma ); 
%t_our = imresize( t_our, size( t_b ) );
%t_our =  tsmooth(  t_b, lambda, sigma ); %求解照度图T（灰度图）
%imshow( t_our);

%% k: exposure ratio
if  ~exist( 'k', 'var' ) || isempty(k) %k为曝光率，没有k则：先计算k，再计算曝光图J   
    isBad = t_our < 0.5;  %是低光照的像素点
    J = maxEntropyEnhance(I, isBad,1,10);  %求k和曝光图
else                                               %有k则：直接根据k计算曝光图
    J = applyK(I, k, a, b); %k
    J = min(J, 1); % fix overflow
    J = max(J, 0); % fix overflow
end

%% W: Weight Matrix 
t = repmat(t_our, [1 1 size(I,3)]); % 照度图L（灰度图） ->  照度图L（RGB图）：灰度值重复3次赋给RGB
                           % size为(I,3) ， 防止与原图尺寸有偏差
%imshow(t);                          
%size(I,3)                         
W = t.^mu; %原图的权重。三维矩阵

%imshow(W);

I2 = I.*W; %原图*权重
J2 = J.*(1-W); %曝光图*权重

%imshow(I2);
%imshow(J2);

fused = I2 + J2; %增强图
[fused,W];
%imshow(W);
%fused = fused.*W;

%fused = toDark(fused,t_our,W);
%fused = t_our; %看看而已

    function fused = toDark(I,t_our,W)
        W = (1-W);
        I3 = I.*W;
        iBad = t_our>0.7;
        J3 = maxEntropyEnhance(I,iBad,0.1,0.6);
        J3 = J3.*(1-W);
        fused = I3+J3;
    end

    function J = maxEntropyEnhance(I, isBad,mink,maxk)
        %I
        Y = rgb2gm(real(max(imresize(I, [50 50]), 0)));  %read求复数的实部  ；   rgb2gm在下面，转成几何平均的灰度图
        %Y = rgb2gm( imresize(I, [50 50]) );
        if exist('isBad', 'var')
            isBad = (imresize(isBad, [50 50])); 
            Y = Y(isBad); %取出isBad为真的Y的值，形成一个列向量
            %Y = sort(Y);
        end
        if isempty(Y)
           J = I; % no enhancement k = 1
           return;
        end
               %最小化时k的值   %熵  %使用k曝光后的亮度图  %k的范围[1,7]
        opt_k = fminbnd(@(k) ( -entropy(applyK(Y, k)) ),mink, maxk);
        %-entropy(applyK(Y, 1))
        %-entropy(applyK(Y, 6))
        %-entropy(applyK(Y, 6.2))
        %-entropy(applyK(Y, 6.3))
        %-entropy(applyK(Y, 6.9))
        %-entropy(applyK(Y, 7))
        %-entropy(applyK(Y, 8))
        %-entropy(applyK(Y, 10))
        %'lighting......'
        %opt_k
        fprintf('light......The opt_k = %f\n', opt_k);
        J = applyK(I, opt_k, a, b) - 0.01;
    end
end

function I = rgb2gm(I)
if size(I,3) == 3
    I = im2double(max(0,I)); % negative double --> complex double
    I = ( I(:,:,1).*I(:,:,2).*I(:,:,3) ).^(1/3);  % 几何平均
end
end

function J = applyK(I, k, a, b)

if ~exist( 'a', 'var' )
    a = -0.3293;
end

if ~exist( 'b', 'var' )
    b = 1.1258;
end

f = @(x)exp((1-x.^a)*b);  % 表示f(x)函数
beta = f(k);
gamma = k.^a;
J = I.^gamma.*beta;
end

function S = tsmooth( I, lambda, sigma, sharpness)
if ( ~exist( 'lambda', 'var' ) )
    lambda = 0.01;
end
if ( ~exist( 'sigma', 'var' ) )
    sigma = 3.0;
end
if ( ~exist( 'sharpness', 'var' ) )
    sharpness = 0.001;
end

I = im2double( I );
x = I;

[ wx, wy ] = computeTextureWeights( x, sigma, sharpness);
S = solveLinearEquation( I, wx, wy, lambda );
end

function [ W_h, W_v ] = computeTextureWeights( fin, sigma, sharpness)
%fin
dt0_v = [diff(fin,1,1);fin(1,:)-fin(end,:)];
%imshow(dt0_v);
dt0_h = [diff(fin,1,2)';fin(:,1)'-fin(:,end)']';
gauker_h = filter2(ones(1,sigma),dt0_h); %横着加起来5个
gauker_v = filter2(ones(sigma,1),dt0_v);

%dt0_h
%gauker_h

W_h = 1./(abs(gauker_h).*abs(dt0_h)+sharpness);
W_v = 1./(abs(gauker_v).*abs(dt0_v)+sharpness);
end

function OUT = solveLinearEquation( IN, wx, wy, lambda )
[ r, c, ch ] = size( IN );
k = r * c;
dx =  -lambda * wx( : );
dy =  -lambda * wy( : );
tempx = [wx(:,end),wx(:,1:end-1)];
tempy = [wy(end,:);wy(1:end-1,:)];
dxa = -lambda *tempx(:);
dya = -lambda *tempy(:);
tempx = [wx(:,end),zeros(r,c-1)];
tempy = [wy(end,:);zeros(r-1,c)];
dxd1 = -lambda * tempx(:);
dyd1 = -lambda * tempy(:);
wx(:,end) = 0;
wy(end,:) = 0;
dxd2 = -lambda * wx(:);
dyd2 = -lambda * wy(:);
%dxd12 = [dxd1,dxd2];
%krr = [-k+r,-r];
Ax = spdiags( [dxd1,dxd2], [-k+r,-r], k, k );
%Ax
Ay = spdiags( [dyd1,dyd2], [-r+1,-1], k, k );
%Ay

D = 1 - ( dx + dy + dxa + dya);
A = (Ax+Ay) + (Ax+Ay)' + spdiags( D, [0], k, k );
%(Ax+Ay)
%(Ax+Ay)'
%spdiags( D, [0], k, k )
%A

%{
if exist( 'ichol', 'builtin' )
    L = ichol( A, struct( 'michol', 'on' ) );
    OUT = IN;
    for ii = 1:ch
        tin = IN( :, :, ii );
        [ tout, ~ ] = pcg( A, tin( : ), 0.1, 50, L, L' );
        OUT( :, :, ii ) = reshape( tout, r, c );
    end
else
    OUT = IN;
    for ii = 1:ch
        tin = IN( :, :, ii );
        tout = A\tin( : );
        OUT( :, :, ii ) = reshape( tout, r, c );
    end
end
end
%}
OUT = IN;
for ii = 1:ch
    tin = IN( :, :, ii );
    tout = A\tin( : );
    OUT( :, :, ii ) = reshape( tout, r, c );
    %OUT
end
end