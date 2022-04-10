from pickletools import uint8
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt

imgArr = np.loadtxt('../../image/l256.dat',dtype=np.uint8)

img = Image.fromarray(imgArr)

imgHist = img.histogram()

plt.plot(imgHist)
plt.savefig('histogram.png')
plt.close()

imgArrLow = np.bitwise_and(imgArr,np.uint8(140))

imgLow = Image.fromarray(imgArrLow)

imgHistLow = imgLow.histogram()

plt.plot(imgHistLow)
plt.savefig('histogramLow.png')
plt.close()

imgArrHigh = np.bitwise_and(imgArr,np.uint8(15))

imgHigh = Image.fromarray(imgArrHigh)

imgHistHigh = imgHigh.histogram()

plt.plot(imgHistHigh)
plt.savefig('histogramHigh.png')
plt.close()