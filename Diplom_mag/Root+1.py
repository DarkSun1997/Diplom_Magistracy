import math
import matplotlib.pyplot as plt


def lambda_1(loc_k):
    rezult = math.sqrt(loc_k)
    return rezult


def lambda_2(loc_k):
    rezult = -loc_k/4
    return rezult


def lambda_n0(loc_n):
    rezult = complex(0, math.pi * (2 * loc_n))
    return rezult


def lambda_n1(loc_n, loc_k):
    rezult = -(lambda_n0(loc_n) * lambda_n0(loc_n) + loc_k) / lambda_n0(loc_n)
    return rezult


def lambda_n2(loc_n, loc_k, loc_beta1):
    rezult = -(2 * lambda_n0(loc_n) * lambda_n1(loc_n, loc_k) + lambda_n1(loc_n, loc_k) * lambda_n1(loc_n, loc_k)) /\
             lambda_n0(loc_n) + lambda_n1(loc_n, loc_k) * lambda_n1(loc_n, loc_k) / 2 + loc_beta1
    return rezult


# все что связано с епсилон
eps_start = 0.2
stop_eps = 0.001
step_eps = 0.001

# параметры необходимые для уравнений
k = 2
beta_1 = 1
# количество пар которое будет нарисовано
count_pair = 3
i = -count_pair

list_graf_Im_os = []
list_graf_Re_os = []

while i <= count_pair:
    list_graf_Im_os.append((2 * i) * math.pi)
    list_graf_Re_os.append(0)
    i = i+1

plt.plot(list_graf_Re_os, list_graf_Im_os, color=(0, 0, 0))

i = -count_pair
# основной цикл действия
while i <= count_pair:
    if i != 0:
        list_graf_Re = []
        list_graf_Im = []
        #
        count_step = 0
        list_graf_Re_prom = []
        list_graf_Im_prom = []
        eps = eps_start
        while eps >= stop_eps:
            x = lambda_n0(i) + eps * lambda_n1(i, k) + eps * eps * lambda_n2(i, k, beta_1)
            if(eps-step_eps < stop_eps) or (count_step % 20 == 0):
                list_graf_Re_prom.append(x.real)
                list_graf_Im_prom.append(x.imag)
            count_step = count_step+1
            list_graf_Re.append(x.real)
            list_graf_Im.append(x.imag)
            eps = eps - step_eps
        plt.plot(list_graf_Re, list_graf_Im, color=(0, 0, 1),linewidth = 1)

        for j in range(len(list_graf_Re_prom)):
            plt.scatter(list_graf_Re_prom[j], list_graf_Im_prom[j], color=(1, 0, 0), s=20)
    i = i+1

# случай нулевого без пары
list_graf_Re = []
list_graf_Im = []
list_graf_Re_prom = []
list_graf_Im_prom = []
count_step = 0
eps = eps_start

while eps >= stop_eps:
    g = complex(eps * lambda_2(k), math.sqrt(eps) * lambda_1(k))
    if(eps - step_eps < stop_eps) or (count_step % 20 == 0):
        list_graf_Re_prom.append(g.real)
        list_graf_Im_prom.append(g.imag)
    count_step = count_step+1
    list_graf_Re.append(g.real)
    list_graf_Im.append(g.imag)
    eps = eps-step_eps
plt.plot(list_graf_Re, list_graf_Im, color=(0, 0, 1),linewidth = 1)

for j in range(len(list_graf_Re_prom)):
    plt.scatter(list_graf_Re_prom[j], list_graf_Im_prom[j], color=(1, 0, 0), s=20)

# случай нулевого без пары
list_graf_Re = []
list_graf_Im = []
list_graf_Re_prom = []
list_graf_Im_prom = []
count_step = 0
eps = eps_start

while eps >= stop_eps:
    g = complex(eps * lambda_2(k), -math.sqrt(eps) * lambda_1(k))
    if(eps-step_eps < stop_eps) or (count_step % 20 == 0):
        list_graf_Re_prom.append(g.real)
        list_graf_Im_prom.append(g.imag)
    count_step = count_step + 1
    list_graf_Re.append(g.real)
    list_graf_Im.append(g.imag)
    eps = eps - step_eps
plt.plot(list_graf_Re, list_graf_Im, color=(0, 0, 1),linewidth = 1)

for j in range(len(list_graf_Re_prom)):
    plt.scatter(list_graf_Re_prom[j], list_graf_Im_prom[j], color=(1, 0, 0), s=20)
plt.xlabel('Reλ')
plt.ylabel('Imλ', rotation=0)
plt.show()
