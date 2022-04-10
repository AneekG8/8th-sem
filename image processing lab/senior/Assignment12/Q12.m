R = load('.\image\l256.dat');
S = uint8(R);

[row,col] = size(S);
F_Im = zeros(row,col);

for i = 2:row-1
    for j = 2:col-1        
        F_Im(i,j) = abs(S(i+1,j)-S(i,j)) + abs(S(i,j+1)-S(i,j));
    end
end
F_Im = uint8(F_Im);
output = S-F_Im;
f = figure;
subplot(1,3,1),imshow(S), title('Original Image');
subplot(1,3,2),imshow(F_Im),title('Gradient Filtered Image');
subplot(1,3,3),imshow(output),title('Sharpened Image');
saveas(f,'Sharpening using Gradient Filter.png');
