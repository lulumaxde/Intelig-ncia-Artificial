def ClassificaIgual(String,NewPalavra,numero):
    for m in range(numero):
        if(String[m] == NewPalavra):
            return 1


    return 0

def RegraLetrafaltando(String,NewPalavra,numero,output):

    dic = len(String)
    tar = len(NewPalavra)
    print("{}{}".format(dic,tar))
    if((dic - tar == 1) or (dic - tar == -1)):
        counter = 0

        for j in range(tar):
            for k in range(dic):
                if(String[k] != NewPalavra[j]):
                    if(dic > tar):
                        j = j-1
                    else:
                        k = k-1
                else:
                    counter = counter+1
        
        print("{}{}{}".format(counter,j,k))
        if((tar < dic and counter == tar) or (tar > dic and counter == dic)):
            output = String
            return output

        return 0
            
def RegraLetraErrada(String,NewPalavra,numero,output):

    Alvo = len(NewPalavra)
    counter = 0
    Str = len(String)
    if(Alvo == Str ):
        for j in range(Alvo):
            if(String[j] == NewPalavra[j]):
                counter = counter+1
    if(counter == Alvo-1):
        out = String
        return out
    return 0

def RegraOrdemErrada(String,NewPalavra,numero,output):
    Alvo = len(NewPalavra)
    counter = 0
    Str = len(String)
    inc = False
    if( Alvo == Str):
        for j in range(Alvo):
            if(String[j] == NewPalavra[j]):
                counter = counter+1
            elif( j > 0 and not inc and String[j-1] == NewPalavra[j] and String[j] == NewPalavra[j-1]):
                inc = True
                counter = counter+2
    #print(counter,tar)
    if(counter == Alvo):   
        out = String
        return out

    return 0
                


def ClassificaStr(String,NewPalavra,numero,output):

    for i in range(numero):
        #if(RegraLetrafaltando(String[i],NewPalavra,numero,output) != 0):
           #out = RegraLetrafaltando(String[i],NewPalavra,numero,output)
           #return out
        if(RegraLetraErrada(String[i],NewPalavra,numero,output) != 0):
           out = RegraLetraErrada(String[i],NewPalavra,numero,output)
           return out
        elif(RegraOrdemErrada(String[i],NewPalavra,numero,output) != 0):
           out = RegraOrdemErrada(String[i],NewPalavra,numero,output)
           return out
        
    return 0
           


def main():
    String = []
    # 1 correto 2 Missing 3 Unknown
    numero = int(input())
    for k in range(numero):
        palavra = input()
        
        String.append(palavra)

    numeroNovo = int(input())
    StringCorrige = []

    define = 0
    output = ''
    for j in range(numeroNovo):
        
        NewPalavra = input()
    
        if(ClassificaIgual(String,NewPalavra,numero) == 1):
            print("{} is correct ".format(NewPalavra))
        elif(ClassificaStr(String,NewPalavra,numero,output) != 0):
            out = ClassificaStr(String,NewPalavra,numero,output)
            print("{} is a misspelling of {} ".format(NewPalavra,out))
        else:
            print("{} is unknown".format(NewPalavra))
            
main()
