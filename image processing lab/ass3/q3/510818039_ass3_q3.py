from cgitb import lookup
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

imgArr = np.loadtxt('../../image/l256.dat',dtype=np.uint8)

img = Image.fromarray(imgArr)

img.save('original.png')

imgHist = np.bincount(imgArr.flatten(),minlength=256)

plt.plot(imgHist)
plt.savefig('histogram.png')
plt.close()

def histogram_equalization(imgArr,imgHist):
    tot_pixels = np.sum(imgHist)    #256*256
    cum_imgHist = np.cumsum(imgHist) / tot_pixels
    lookup_table = np.round(255*cum_imgHist).astype(np.uint8)
    imgList = list(imgArr.flatten())
    eq_imgList = [lookup_table[p] for p in imgList]
    eq_imgArr = np.reshape(np.array(eq_imgList),imgArr.shape)
    return eq_imgArr

imgArrEq1 = histogram_equalization(imgArr= imgArr, imgHist= imgHist)

imgEq1 = Image.fromarray(imgArrEq1)

imgEq1.save('imageEq1.png')

imgHistEq1 = np.bincount(imgArrEq1.flatten(),minlength=256)

plt.plot(imgHistEq1)
plt.savefig('histogramEq1.png')
plt.close()

imgArrEq2 = histogram_equalization(imgArr= imgArrEq1, imgHist= imgHistEq1)

imgEq2 = Image.fromarray(imgArrEq2)

imgEq2.save('imageEq2.png')


imgHistEq2 = np.bincount(imgArrEq2.flatten(),minlength=256)

plt.plot(imgHistEq2)
plt.savefig('histogramEq2.png')
plt.close()