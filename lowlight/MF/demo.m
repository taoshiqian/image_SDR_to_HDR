clc;
clear all;


input = imread('D:\MATLAB\HDR\BIMEF\dataset\zhangfan1.jpg'); 

output = multi_fusion(input);

%figure,imshow(input),title('original image');
%figure,imshow(output),title('enhanced image');


subplot 121; imshow(input); title('原始图');
subplot 122; imshow(output); title('处理后'); 