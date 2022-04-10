import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

imgArr = np.loadtxt('../../image/l256.dat',dtype=np.uint8)

img = Image.fromarray(imgArr)

imgHist = img.histogram()

plt.plot(imgHist)
plt.savefig('histogram.png')
plt.close()


a = np.amin(imgArr)

b = np.amax(imgArr)

ranges = [(0,50),(200,255),(50,150)]

i = 0

for range in ranges:
    c,d = range

    imgArrStretched = np.uint8((imgArr-a)/(b-a) * (d-c) + c)
        
    imgStretched = Image.fromarray(imgArrStretched)

    imgHistStretched = imgStretched.histogram()

    plt.plot(imgHistStretched)
    plt.savefig('histogramStretched' + str(i+1) + '.png')
    plt.close()

    i=i+1
