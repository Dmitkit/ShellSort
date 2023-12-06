import matplotlib.pyplot as plt

def makePlot(file, x, y):
    f = open(file, 'r')
    n = 1
    while n < 10001:
        # считываем строку
        line = f.readline()
        # прерываем цикл, если строка пустая
        if not line:
            break
        words = line.split()
        x.append(int(words[0]))
        y.append(int(words[1]))
        n += 1
    f.close

# x = []
# y = []
# makePlot('2tox.txt', x, y)

# x1 = []
# y1 = []
# makePlot('2-3smooth.txt', x1, y1)

x2 = []
y2 = []
makePlot('stdsort.txt', x2, y2)

# x3 = []
# y3 = []
# makePlot('sedg.txt', x3, y3)

# x4 = []
# y4 = []
# makePlot('univ.txt', x4, y4)

x5 = []
y5 = []
makePlot('fib.txt', x5, y5)

#plt.plot(x, y, alpha = 0.7)
#plt.plot(x1, y1, alpha = 0.7)
plt.plot(x2, y2, alpha = 0.7)
# plt.plot(x3, y3, alpha = 0.7)
# plt.plot(x4, y4, alpha = 0.7)
plt.plot(x5, y5, alpha = 0.7)
plt.legend(['std','k = 1/3, a = 3, h2 = 3']) 
plt.show()