% 只做“过曝降光”
% 单张图测试，把file修改成输入图像的路径，并修改文件名后缀，运行，即可得到增强后的输出（和输入图片同一路径）
tic;
addpath ours;
file = 'person\Q';%修改输入图片的路径
I = imread( [file,'.jpg'] );%修改输入图片的后缀
%J = BIMEF(I); 
%{
A = Ying_2017_CAIP(I,0.5);
imwrite(A, [file,'_out_A.jpg'] );
B = 1-I;
imwrite(B, [file,'_out_B.jpg'] );
C = Ying_2017_CAIP(B,0.5);
imwrite(C, [file,'_out_C.jpg'] );
D = 1-C;
%J = test_diff(I);
imwrite(D, [file,'_out_D.jpg'] );
%}
J = TooDark(I,0.5,0.38); % 原图，照度变化，曝光率（曝光率人为控制亮度，越低越暗）
imwrite(J, [file,'_dark.jpg'] );

toc;

subplot 121; imshow(I); title('原始图');
subplot 122; imshow(J); title('处理后'); 