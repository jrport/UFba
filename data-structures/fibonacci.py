def fib(n):
    n = int(n)
    a = 0
    b = 1
    if (n<=1): c = n
    else:
        for i in range(n-1):
            c = a + b
            a = b
            b = c
            print(c)
    return c
print(fib(input()))
