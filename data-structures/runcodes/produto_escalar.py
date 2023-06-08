vetor1 = [int(i) for i in input().split()]
vetor2 = [int(i) for i in input().split()]
total = 0
for i in range(len(vetor1)):
    total += vetor1[i]*vetor2[i]
print(total)