# image SDR-to-HDR
\
图像SDR to HDR，目标：暗光区域 光照增强，过曝光区域 光照减弱\
\
其中暗光照增强的MATLAB实现主要参考北大学者的论文与开源工程\
北大学者github：https://github.com/baidut \
参考论文：\
A Bio-Inspired Multi-Exposure Fusion Framework for Low-light Image Enhancement\
A New Image Contrast Enhancement Algorithm using Exposure Fusion Framework\
A New Low-Light Image Enhancement Algorithm using Camera Response Model\
\
创新点：只对缺失光照的地方进行补光增强，而其他光照良好的地方不会增强，从而使得整张图更清晰\
有待优化之处（个人拙见）：原方法处理了低光照区域和光照良好区域，但过曝光的区域仍然不清晰，还可以对过曝光区域进行降光处理\
\
需要环境:MATLAB\
使用方法：在demoTSQlight.m中修改输入图像路径即可，增强图会展示出来，并且在输入图像的路径下会生成 文件名_out.jpg文件\
demoTSQtest.m 用于评价效果好坏
\
![image](https://github.com/taoshiqian/image_SDR_to_HDR/blob/master/person/input.jpg)
![image](https://github.com/taoshiqian/image_SDR_to_HDR/blob/master/person/input_out.jpg)
\
\
\
我的修改：\
1.代码修改部分细节，并新增中文注解\
_2.代码新增：“低光区域增强”+“过曝光区域降光”,并引入其他颜色空间\

代码见demoTSQdark_light.m\

代码V2 = TooDark(J,0.5,0.38);中的第三个参数0.38曝光率可以控制光照，越低则降光越多。

_3.代码新增：“低光区域增强”+“过曝光区域降光”,并引入其他颜色空间\
测试所有颜色空间下，“暗光区域增亮”+“过曝光区域降光”双重功能下的结果，保存在allColor文件夹下。\
allColor文件夹中，P（或Q属于输入图片的名字）。其他图的名字含义是:图片名_颜色空间_操作.后缀。\
其中操作包括Dark(过曝光区域降光)  Light(暗光区域增亮)    Light_Dark(“暗光区域增亮”+“过曝光区域降光”)\
详见demoTSQall.m\
4.需要包colorspace\
\
\
效果展示\
原图\
![image](https://github.com/taoshiqian/image_SDR_to_HDR/blob/master/allColor/Q.jpg)\

RGB空间下，景色部分（树、海岸……）得到“暗光区域增亮”的加强，人脸、锁骨、衣服白色字体等部分得到了“过曝光区域降光”的美化\

![image](https://github.com/taoshiqian/image_SDR_to_HDR/blob/master/allColor/Q_RGB_Light_Dark.jpg)\

HSV空间下，景色部分（树、海岸……）得到“暗光区域增亮”的加强，人脸、锁骨、衣服白色字体等部分得到了“过曝光区域降光”的美化\
![image](https://github.com/taoshiqian/image_SDR_to_HDR/blob/master/allColor/Q_HSV_Light_Dark.jpg)\
更多颜色空间下的效果请看allColor文件夹

