linhas, coluna = [int(i) for i in input().split()]
matriz = []
for n in range(linhas):
    linha = (input().split())
    matriz.append(linha)
matriz_transposta =[ ]
for i in range(coluna):
    linha_transposta = []
    for n in range(linhas):
        linha_transposta.append(matriz[n][i])
    matriz_transposta.append(linha_transposta)
soma=0
for i in range(coluna):
    soma += int(matriz_transposta[i][0])
print(soma)
print(matriz)



