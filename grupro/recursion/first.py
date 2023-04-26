sequencia = []
def series(n):
	n=int(n)
	if n==2: 
		sequencia.append(1)
		sequencia.append(2)
		sequencia.append(1)
	elif n>2:
		series(n-1)
		sequencia.append(n)
		series(n-1)
series(input())
print(sequencia)