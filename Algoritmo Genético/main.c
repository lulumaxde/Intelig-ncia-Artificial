#include <stdio.h>
#include <stdlib.h>


float mutation(int NovoIndividuoA[],int NovoIndividuoB[],int IndividuoC[],int bits,float mutacao){
    int NovoIndividuoAMutado[bits], NovoIndividuoBMutado[bits];
    int i,j;
    for(i = 0 ; i < bits ; i++){
        if(NovoIndividuoA[i] == IndividuoC[i]){
            NovoIndividuoAMutado[i] = 0;
        }else NovoIndividuoAMutado[i] = 1;

    }

    for(j = 0 ; j < bits ; j++){
        if(NovoIndividuoB[j] == IndividuoC[j]){
            NovoIndividuoBMutado[j] = 0;
        }else NovoIndividuoBMutado[j] = 1;

    }
   // imprime(NovoIndividuoAMutado, NovoIndividuoBMutado, bits);

    float pmtotal, pm1[bits] , pm2[bits],total1,total2;
    int k, calcula;

    for(k = 0 ; k < bits ; k++){
      if (NovoIndividuoAMutado[k] == 0 ){
        pm1[k] = (1-mutacao);
      } else pm1[k] = mutacao;
    } k = 0;

    total1 = pm1[0];
    for( calcula = 1 ; calcula<bits ; calcula++){
        total1 = total1*pm1[calcula];
    } calcula = 1;

    for( k = 0 ; k < bits ; k++){
      if (NovoIndividuoBMutado[k] == 0 ){
        pm2[k] = (1-mutacao);
      } else pm2[k] = mutacao;
    }
     total2 = pm2[0];
     for( calcula = 1 ; calcula<bits ; calcula++){
        total2 = total2*pm2[calcula];
    }

    float totalfinal;
    totalfinal = total1+total2-(total1*total2);
    return totalfinal;

}


float nextgeneration(int IndividuoA[],int IndividuoB[],int IndividuoC, int bits,int corte,float mutacao){
    int NovoIndividuoA[bits], NovoIndividuoB[bits];
    int restante = bits-corte;
    int i;
    for (i = 0; i < corte ; i++){
        NovoIndividuoA[i] = IndividuoA[i];
        NovoIndividuoB[i] = IndividuoB[i];
    } i = 0;

    for (i = 0; i < restante ; i++){
        NovoIndividuoA[i+corte] = IndividuoB[i+corte];
        NovoIndividuoB[i+corte] = IndividuoA[i+corte];
    }

    float probabilidade;
    probabilidade = mutation(NovoIndividuoA,NovoIndividuoB,IndividuoC,bits,mutacao);

    //  float probabilidade;
    // probabilidade = calculaprobabilidade(NovoIndividuoA[], NovoIndividuoB[],IndividuoC[], bits);

   return probabilidade;
}


int main()
{
    int bits, posi, teste, corte, c = 0;
    float mutacao;
    int i,j;

  // printf("Digite a quantidade de testes \n");
    scanf("%d", &teste);
    float guardaresultado[teste];
    while(c < teste){

          //  printf("Digite o numero de Bits: \n");
            scanf("%d ", &bits);

            int IndividuoA[bits];
            int IndividuoB[bits];
            int IndividuoC[bits];
            char s[bits];
            scanf("%d %f", &corte, &mutacao);
            //s = realloc(s, bits*sizeof(char));
            scanf("%s", s);
            for (i = 0 ; i < bits ; i++){
                //scanf("%d", &posi);
                IndividuoA[i] = s[i];
            }
            scanf("%s", s);
            for (i = 0 ; i < bits ; i++){
                //scanf("%d", &posi);
                IndividuoB[i] = s[i];
            }
            scanf("%s", s);
            for (i = 0 ; i < bits ; i++){
                //scanf("%d", &posi);
                IndividuoC[i] = s[i];
            }
           guardaresultado[c] = nextgeneration(IndividuoA,IndividuoB,IndividuoC,bits,corte,mutacao);
    c++;
    }
    for(j = 0 ; j < teste ; j++)
    printf("%.7f\n", guardaresultado[j]);
}
