def fib(n):
    n = int(n)
    a = 0
    b = 1
    for i in range(n-1):
        if (n<=1): return n
        else:
            c = a + b
            a = b
            b = c
    return c
print(fib(input()))