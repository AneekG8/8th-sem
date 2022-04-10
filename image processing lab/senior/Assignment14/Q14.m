R = load('.\image\l256.dat');
S = uint8(R);

[row,col] = size(S);
F_Im = zeros(row,col);

for i = 2:row-1
    for j = 2:col-1 
        delX = abs(S(i+1,j-1)+S(i+1,j)+S(i+1,j+1) - (S(i-1,j-1)+S(i-1,j)+S(i-1,j+1)));
        delY = abs(S(i-1,j+1)+S(i,j+1)+S(i+1,j+1) - (S(i-1,j-1)+S(i,j-1)+S(i+1,j-1)));
        F_Im(i,j) = delX + delY;
    end
end
F_Im = uint8(F_Im);
output = S-F_Im;
f = figure;
subplot(1,3,1),imshow(S), title('Original Image');
subplot(1,3,2),imshow(F_Im),title('Prewitt Filtered Image');
subplot(1,3,3),imshow(output),title('Sharpened Image');
saveas(f,'Sharpening using Prewitt Filter.png');
