import numpy as np
import matplotlib.ticker as ticker
import matplotlib.pyplot as plt


datos=np.genfromtxt('map_data.txt',delimiter=' ')

yMax,xMax=datos.shape[0],datos.shape[1]

f= np.genfromtxt('radios.dat')
xs, ys, r =f[:,0],f[:,1],f[:,2]
theta = np.linspace(0, 2*np.pi, 100)
pos = r.argmax()
r_ = r[pos].mean()
X0 = xs[pos]
Y0 = ys[pos]

fig, ax1 = plt.subplots(1,1,figsize=(16, 12), dpi=100, subplot_kw={'aspect': 'equal'})

ax1.plot([0,xMax],[yMax/2,yMax/2],color='g',label='Ecuador')
ax1.plot([xMax/2,xMax/2],[0,yMax],color='y',label='Greenwich')
plt.legend()

ax1.imshow(datos)

nticksx=744/6
nticksy=500/6

ax1.set_yticks([float(j) for j in range(0,yMax,nticksy)])
ax1.yaxis.set_major_formatter(ticker.FixedFormatter([float(j*2*90/yMax-90) for j in range(0,yMax+1,nticksy+1)]))
ax1.set_xticks([float(j) for j in range(0,xMax+1,nticksx)])
ax1.xaxis.set_major_formatter(ticker.FixedFormatter([float(j*2*180/xMax-180) for j in range(0,xMax+1,nticksx)]))

x = r_*np.cos(theta) + X0
y = r_*np.sin(theta) + Y0

ax1.plot(y, x)
ax1.plot([Y0], [X0], "o")
ax1.set_xlabel('$x$')
ax1.set_ylabel('$y$')
ax1.set_title('Punto Nemo')

plt.savefig("PuntoNemo.pdf")


