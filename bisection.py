def dx(x):
    return (x**3 - x - 11)

def fx():
    l = []
    for i in range(0, 5):
        if dx(i) >= 0:
            l.append(i-1)
            l.append(i)
            return l
            break

a = fx()

def bisection(l):
    for i in range(11):
        b = (l[0] + l[1]) / 2
        a = dx(b)
        if a < 0:
            l[0] = b
        else:
            l[1] = b

        print(b)
    return b 
print(bisection(a))
