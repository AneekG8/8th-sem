clc
close all
R = load('D:\Downloads\image\o256.dat');
numofpixels = size(R,1) * size(R,2);
HIm = uint8(zeros(size(R,1),size(R,2)));
freq = zeros(256,1);
pdf = zeros(256,1);
cdf = zeros(256,1);
cum = zeros(256,1);
output = zeros(256,1);

for i = 1:size(R,1)
    for j = 1:size(R,2)
        value = R(i,j);
        freq(value+1) = freq(value+1) + 1;
        pdf(value+1) = freq(value+1)/numofpixels;
    end
end

sum = 0;
maxval = max(max(R));

for i = 1:size(pdf)
    sum = sum + freq(i);
    cum(i) = sum;
    cdf(i) = cum(i)/numofpixels;
    output(i) = round(cdf(i)*maxval);
end

for i = 1:size(R,1)
    for j = 1:size(R,2)
        HIm(i,j) = output(R(i,j)+1);
    end
end
imshowpair(R,HIm,'montage');
pause(2);
subplot(1,2,1),histogram(R,0:255),title('Original Histogram');
subplot(1,2,2),histogram(HIm,0:255),title('Post Equalization');

%2nd pass
numofpixels = size(HIm,1) * size(HIm,2);
HIm2 = uint8(zeros(size(HIm,1),size(HIm,2)));
freq = zeros(256,1);
pdf = zeros(256,1);
cdf = zeros(256,1);
cum = zeros(256,1);
output = zeros(256,1);

for i = 1:size(HIm,1)
    for j = 1:size(HIm,2)
        value = HIm(i,j);
        freq(value+1) = freq(value+1) + 1;
        pdf(value+1) = freq(value+1)/numofpixels;
    end
end

sum = 0;
maxval = max(max(HIm));

for i = 1:size(pdf)
    sum = sum + freq(i);
    cum(i) = sum;
    cdf(i) = cum(i)/numofpixels;
    output(i) = round(cdf(i)*maxval);
end

for i = 1:size(HIm,1)
    for j = 1:size(HIm,2)
        HIm2(i,j) = output(HIm(i,j)+1);
    end
end
figure
imshowpair(HIm,HIm2,'montage');
pause(2);
subplot(1,2,1),histogram(HIm,0:255),title('Post Equalization1');
subplot(1,2,2),histogram(HIm2,0:255),title('Post Equalization2');
