def fatorial(n):
    i = 1
    c = 0
    while c != n:
        i = i*(i+1) 
        c += 1
    return i
print(fatorial(3))
