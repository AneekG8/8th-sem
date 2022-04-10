from pickletools import uint8
from PIL import Image
import numpy as np

imgArr = np.loadtxt('../../image/l256.dat',dtype=np.uint8)

img = Image.fromarray(imgArr)

img.save('original.png')

row , col = imgArr.shape

imgArrFilter = np.array(imgArr)

for i in range(1,row-2):
    for j in range(1,col-2):
        delX = abs(int(imgArr[i+1][j-1]) + 2*int(imgArr[i+1][j]) + int(imgArr[i+1][j+1]) - int(imgArr[i-1][j-1]) - 2 * int(imgArr[i-1][j]) - int(imgArr[i-1][j+1]))
        delY = abs(int(imgArr[i-1][j+1]) + 2*int(imgArr[i][j+1]) + int(imgArr[i+1][j+1]) - int(imgArr[i-1][j-1]) - 2 * int(imgArr[i][j-1]) - int(imgArr[i+1][j-1]))
        imgArrFilter[i][j] = np.uint8(delX + delY)

imgFilter = Image.fromarray(imgArrFilter)

imgFilter.save('sobelFilteredImage.png')

imgArrSharp = imgArr - imgArrFilter

imgSharp = Image.fromarray(imgArrSharp)

imgSharp.save('sobelSharpenedImage.png')