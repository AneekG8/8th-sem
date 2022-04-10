R = load('.\image\o256.dat');
p = input('Enter the percentage of pixels which have to be noise corrupted: ');
rows = size(R,1);
cols = size(R,2);
NumofPixels = rows * cols;
NoisyPixels = round((p*NumofPixels)/100);
q = input('Enter the percentage by which pixels have to be noise corrupted: ');
S = R;
for i = 1:1:NoisyPixels
    row = round(randi([0,255],1,1));
    col = round(randi([0,255],1,1));
    if(i < (NoisyPixels/2))
        S(row+1,col+1) = round(R(row+1,col+1) + round((q*R(row+1,col+1))/100));
    elseif(i >= (NoisyPixels/2))
        S(row+1,col+1) = round(R(row+1,col+1) - round((q*R(row+1,col+1))/100));
    end
end
S = uint8(S);
R = S;
ModeFilterFunction = @(x) mode(x(:));
output = nlfilter(S, [3 3], ModeFilterFunction);
figure,imshowpair(R,output,'montage');
FileName = sprintf('mode3x3image.png');
imwrite(repmat(uint8(output), [1 1 3]), FileName);


N = 3;
[row,col] = size(S);
F_Im = zeros(row,col);
for i = 2:row-1
    for j = 2:col-1
        filter = [S(i-1,j-1),S(i-1,j),S(i-1,j+1),S(i,j-1),S(i,j),S(i,j+1),S(i+1,j-1),S(i+1,j),S(i+1,j+1)];
        F_Im(i,j) = median(filter);
    end
end
figure,imshowpair(R,F_Im,'montage');
FileName = sprintf('median%dx%dimage.png',N,N);
imwrite(repmat(uint8(output), [1 1 3]), FileName);

N = 5;
[row,col] = size(S);
F_Im = zeros(row,col);
for i = 3:row-2
    for j = 3:col-2
        filter = [S(i-2,j-2),S(i-2,j-1),S(i-2,j),S(i-2,j+1),S(i-2,j+2),S(i-1,j-2),S(i-1,j-1),S(i-1,j),S(i-1,j+1),S(i-1,j+2),S(i,j-2),S(i,j-1),S(i,j),S(i,j+1),S(i,j+2),S(i+1,j-2),S(i+1,j-1),S(i+1,j),S(i+1,j+1),S(i+1,j+2),S(i+2,j-2),S(i+2,j-1),S(i+2,j),S(i+2,j+1),S(i+2,j+2)];
        F_Im(i,j) = median(filter);
    end
end
figure,imshowpair(R,F_Im,'montage');
FileName = sprintf('median%dx%dimage.png',N,N);
imwrite(repmat(uint8(output), [1 1 3]), FileName);
 

%proving 3X3 filter applied twice is equivalent to 5X5 applied once
N = 3;
output1 = S;
[row,col] = size(S);
F_Im = zeros(row,col);
for i = 2:row-1
    for j = 2:col-1
        filter = [S(i-1,j-1),S(i-1,j),S(i-1,j+1),S(i,j-1),S(i,j),S(i,j+1),S(i+1,j-1),S(i+1,j),S(i+1,j+1)];
        F_Im(i,j) = median(filter);
    end
end
figure, imshowpair(R, F_Im, 'montage');
FileName = sprintf('median%dx%dPass1.png',N,N);
imwrite(repmat(uint8(F_Im), [1 1 3]), FileName);

for i = 2:row-1
    for j = 2:col-1
        filter = [F_Im(i-1,j-1),F_Im(i-1,j),F_Im(i-1,j+1),F_Im(i,j-1),F_Im(i,j),F_Im(i,j+1),F_Im(i+1,j-1),F_Im(i+1,j),F_Im(i+1,j+1)];
        F_Im(i,j) = median(filter);
    end
end
F_Im1 = F_Im;
figure, imshowpair(R, F_Im, 'montage');
FileName = sprintf('median%dx%dPass2.png',N,N);
imwrite(repmat(uint8(F_Im), [1 1 3]), FileName);

F_Im = zeros(row,col);
for i = 3:row-2
    for j = 3:col-2
        filter = [S(i-2,j-2),S(i-2,j-1),S(i-2,j),S(i-2,j+1),S(i-2,j+2),S(i-1,j-2),S(i-1,j-1),S(i-1,j),S(i-1,j+1),S(i-1,j+2),S(i,j-2),S(i,j-1),S(i,j),S(i,j+1),S(i,j+2),S(i+1,j-2),S(i+1,j-1),S(i+1,j),S(i+1,j+1),S(i+1,j+2),S(i+2,j-2),S(i+2,j-1),S(i+2,j),S(i+2,j+1),S(i+2,j+2)];
        F_Im(i,j) = median(filter);
    end
end
f = figure;
imshowpair(F_Im1, F_Im, 'montage');
filename = sprintf('medianCompare3x3twicevs5x5once.png');
saveas(f,filename);