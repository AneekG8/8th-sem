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
for width = [3,7,9]
   kernel = ones(width)/(width^2);
   output = conv2(S, kernel);
   output(:,1) = [];
   output(:,257) = [];
   output(1,:) = [];
   output(257,:) = [];
   figure,imshowpair(R,output,'montage');
   FileName = sprintf('mean%dx%dimage.png',width,width);
   imwrite(repmat(uint8(output), [1 1 3]), FileName);
end    

%proving 3X3 filter applied twice is equivalent to 5X5 applied once
width = 3;
output1 = S;
for k = 1:2
    kernel = ones(width)/(width^2);
    output1 = uint8(conv2(output1, kernel));
    output1(:,1) = [];
    output1(:,257) = [];
    output1(1,:) = [];
    output1(257,:) = [];
    figure, imshowpair(R, output1, 'montage');
    FileName = sprintf('mean%dx%dPass%d.png',width,width,k);
    imwrite(repmat(uint8(output1), [1 1 3]), FileName);
end

width = 5;
output2 = S;
%kernel = ones(width)/(width^2);
kernel = [1,2,3,2,1;2,4,6,4,2;3,6,9,6,3;2,4,6,4,2;1,2,3,2,1];
kernel = kernel/81;
output2 = uint8(conv2(output2, kernel));
output2(:,1) = [];
output2(:,257) = [];
output2(1,:) = [];
output2(257,:) = [];
f = figure;
imshowpair(output1, output2, 'montage');
filename = sprintf('meanCompare3x3twicevs5x5once.png');
saveas(f,filename);