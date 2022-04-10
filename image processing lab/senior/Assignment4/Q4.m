R = load('.\image\l256.dat');

a = min(min(R));
b = max(max(R));
c = input('Enter min value of output image: ');
d = input('Enter max value of output image: ');

R = (((R - a)/(b-a))*(d-c)) + c;

FileName = sprintf('linStretched%d_%d.png',c,d);
imwrite(repmat(uint8(R), [1 1 3]), FileName);



