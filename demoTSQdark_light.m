% 即做“过曝降光”又做“低光增强”
% 单张图测试，把file修改成输入图像的路径，并修改文件名后缀，运行，即可得到增强后的输出（和输入图片同一路径）
tic;
addpath ours;
file = 'person\Q';%修改输入图片的路径
I = imread( [file,'.jpg'] );%修改输入图片的后缀
%RGB空间
name = 'RGB';
J = im2double(I);
fprintf('\n   0 name = RGB\n');
V2 = TooDark(J,0.5,0.38);%原图，照度变化，曝光率（曝光率人为控制亮度，越低越暗）
J = V2;
imwrite(J, [file,'_',name,'_Dark.jpg'] );
%根据RGB中的RGB变亮
[K,W] = TooLight(I,0.5);
imwrite(K, [file,'_',name,'_Light.jpg'] );
J = J.*W+K.*(1-W);
imwrite(J, [file,'_',name,'_Light_Dark.jpg'] );
fprintf('\n');
subplot 121; imshow(I); title('原始图');
subplot 122; imshow(J); title('处理后'); 