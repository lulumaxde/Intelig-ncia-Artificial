matriz = [[-1,1,1,0,1],[1,0,0,1,0],[1,1,1,0,0],[-1,1,0,1,1],[1,1,0,0,1],[-1,0,0,1,1]]



def preenche():

   matriz = [[-1,1,1,0,1],[1,0,0,1,0],[1,1,1,0,0],[-1,1,0,1,1],[1,1,0,0,1],[-1,0,0,1,1]]
   #(-1, 1, 1, -1, 1, -1)
   
   return matriz

def predict_novo(w0,w1,w2,w3,w4):
   mat_novos = [[0,0,0,0,1],[0,1,1,1,1]]
   saida = []
   for k in range(2):
      g = w0*1 + w1*(matriz[k][1]) + w2*(matriz[k][2]) + w3*(matriz[k][3]) + w4*(matriz[k][4])
      if g > 0:
         u = 1
         saida.append(u)
      else:
         saida.append(-1)
      

   print("-1 representa doente +1 representa saudavel")
   print("Luiz %s"%saida[0])
   print("Laura %s"%saida[1])

def predict(w0,w1,w2,w3,w4):
   
   global matriz
   saida = []
   for k in range(6):
      g = w0*1 + w1*(matriz[k][1]) + w2*(matriz[k][2]) + w3*(matriz[k][3]) + w4*(matriz[k][4])
      if g > 0:
         u = -1
         saida.append(u)
      else:
         saida.append(1)
      

   print(saida)
   
def calcula():
    matriz = preenche()
    #z = preenche()
    w0 = 0
    w1 = 0
    w2 = 0
    w3 = 0
    w4 = 0
    n = 0.5
    x0 = -1
    erro = 1
    reajuste = 0
    saida = []

    while erro == 1:
        erro = 0
        for k in range(6):
            g = w0*1 + w1*(matriz[k][1]) + w2*(matriz[k][2]) + w3*(matriz[k][3]) + w4*(matriz[k][4])
            if g > 0:
                u = 1
                #b = u*(-1)
                saida.append(u)
            else:
                u = -1
                #b = u*(-1)
                saida.append(u)
                
            if u != matriz[k][0]:
                w0 = w0 - n * ((matriz[k][0]) - u) * 1
                #print(w1 )
                w1 = w1 - n * ((matriz[k][0]) - u) * -(matriz[k][1])
                #print(w2 )
                w2 = w2 - n * ((matriz[k][0]) - u) * -(matriz[k][2])
                #print(w3 )
                w3 = w3 - n * ((matriz[k][0]) - u) * -(matriz[k][3])
                #print(w4 )
                w4 = w4 - n * ((matriz[k][0]) - u) * -(matriz[k][4])
                #print(w5 )
                #print()
                reajuste += 1

    #print(reajuste)
    #A funcao predict é utilizado para treinar o algoritmo
    predict(w0,w1,w2,w3,w4)
    #A funcao predict_novos é utilizado para prever novas entradas
    predict_novo(w0,w1,w2,w3,w4)

def main():
    calcula()
    
main()




                
            

        
        
                
            
        
