def cria_matriz(N,M):
    matriz = []
    for i in range(N):
        #cria a linha i
        linha = [] #lista vazia
        for j in range(M):
            valor = input()
            linha.append(valor)
            #coloca linha na matriz
        matriz.append(linha)
    return matriz

class Labiritnto( object ):
    def__init__(self):
        self.mapa = None
        self.entrada = None
        self.Saida = None




def main():
    N = int(input())
    M = int(input())    
    A = cria_matriz(N,M)
    print(A)

main()


