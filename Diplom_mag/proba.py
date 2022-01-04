
from pylab import *
from ddeint import ddeint

model = lambda Y, t: 3*Y(t)*(1-Y(t - 1))  # Model
tt = linspace(0, 100, 100000)  # Time start, time end, nb of points/steps
g = lambda t:0.5 # Expression of Y(t) before the integration interval
yy = ddeint(model, g, tt)  # Solving

# PLOTTING
plot(tt, yy, c='r', label="$y(t)$")

plt.show()