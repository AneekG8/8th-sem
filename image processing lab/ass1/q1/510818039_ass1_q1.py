import numpy as np
from PIL import Image

imgArr = np.loadtxt('../../image/b256.dat',dtype=np.uint8)

img = Image.fromarray(imgArr)

img.save('original.png')

imgArrBin128 = np.where(imgArr < 128,np.uint8(0),np.uint8(255))

np.savetxt('bin128.dat',imgArrBin128,fmt='%.0d')

imgBin128 = Image.fromarray(imgArrBin128)

imgBin128.save('bin128.png')

print('grayscale image to binary with threshold value: 128')

th = (np.amax(imgArr) + np.amin(imgArr))/2

imgArrBinMinMax = np.where(imgArr < th,np.uint8(0),np.uint8(255))

np.savetxt('binMinMax.dat',imgArrBinMinMax,fmt='%.0d')

imgBinMinMax = Image.fromarray(imgArrBinMinMax)

imgBinMinMax.save('binMinMax.png')

print('grayscale image to binary with threshold value: ',th)

