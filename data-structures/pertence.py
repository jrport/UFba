vetor1 = [int(i) for i in input().split()]
vetor2 = [int(i) for i in input().split()]
total = 0
if len(vetor1)>=len(vetor2):
    menor = vetor2
    maior = vetor1
else: 
    menor = vetor1
    maior = vetor2
checados = []
for i in menor:
    if (i in maior)&(i not in checados): 
        total += i
        checados.append(i)
print(total)