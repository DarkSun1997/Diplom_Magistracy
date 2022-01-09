import matplotlib.pyplot as plt
import numpy as np

directory = "C:/Users/SuperUser/Documents/Visual Studio 2010/Projects/Diplom_mag/Diplom_mag/output/"
file_output = open(directory + 'output.txt', 'r')

data_loc = []
for line_loc in file_output:
    data_loc.append([float(x) for x in line_loc.split()])

file_output.close()

print("Good")

time_step_count = len(data_loc)
print(time_step_count)
countstep = 100
time_start = 4990
time_stop = 5000
h = -1
time = []
for t in range(time_step_count):
    if(time_start <= t / countstep + h) and (time_stop >= t / countstep + h):
        time.append(t/countstep + h)

result_equation = []
for t in range(time_step_count):
    if(time_start <= t / countstep + h)and (time_stop >= t / countstep + h):
        result_equation.append(data_loc[t])

result_os = []
for t in range(time_step_count):
    if(time_start <= t / countstep + h)and (time_stop >= t / countstep + h):
        result_os.append(0)
plt.plot(time, result_equation)
#plt.plot(time, result_os)
p1=[]
p1.append(0)
p1.append(0)
p2=[]
p2.append(4990)
p2.append(5000)
plt.plot(p2,p1,color = (0,0,0))
p1=[]
p1.append(-0.00001)
p1.append(0.00001)
p2=[]
p2.append(4990)
p2.append(4990)
plt.plot(p2,p1,color = (0,0,0))
plt.xlabel('t')
plt.ylabel('y', rotation=0)
plt.show()
