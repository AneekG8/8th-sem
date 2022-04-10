A = load('D:\Downloads\image\l256.dat');
FileName = sprintf('LennaImg.png');
imwrite(repmat(uint8(A), [1 1 3]), FileName);
k=[1 2 4];
figure
for i = 1:3
    R = A(1:2:end,1:2:end);
    FileName = sprintf('down%dx.png', k(i)*2);
    imwrite(repmat(uint8(R), [1 1 3]), FileName);
    imshowpair(A,R,'montage'),xlabel(FileName);
    pause(1);
    A = R;
end

for i = 3:5
    R = repelem(A,2,2);
    FileName = sprintf('up%dx.png', k(i-2)*2);
    imwrite(repmat(uint8(R), [1 1 3]), FileName);
    imshowpair(A,R,'montage'),xlabel(FileName);
    pause(1);
    A = R;
end