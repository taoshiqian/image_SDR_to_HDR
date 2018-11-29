%评价指标
addpath quality
raw = imread('person\input.jpg'); %输入图像
enhanceResult = imread('person\input_out.jpg'); %增强结果图
loe100x100(raw,enhanceResult)
vif(enhanceResult,enhanceResult)