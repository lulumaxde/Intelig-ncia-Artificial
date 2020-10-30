#include <stdio.h>
#include <stdlib.h>

float mutation(int NovoIndividuoA[],int NovoIndividuoB[],int IndividuoC[],int bits,float mutacao){
    int NovoIndividuoAMutado[bits], NovoIndividuoBMutado[bits];
    int i;
    for(i = 0 ; i < bits ; i++){
        if(NovoIndividuoA[i] == IndividuoC[i]){
            NovoIndividuoAMutado[i] = 0;
        }else NovoIndividuoAMutado[i] = 1;

    }
    int j;
    for( j = 0 ; j < bits ; j++){
        if(NovoIndividuoB[j] == IndividuoC[j]){
            NovoIndividuoBMutado[j] = 0;
        }else NovoIndividuoBMutado[j] = 1;

    }
   // imprime(NovoIndividuoAMutado, NovoIndividuoBMutado, bits);

    float pmtotal, pm1[bits] , pm2[bits],total1,total2;
    int k;
    for(k = 0 ; k < bits ; k++){
      if (NovoIndividuoAMutado[k] == 0 ){
        pm1[k] = (1-mutacao);
      } else pm1[k] = mutacao;
    }

    total1 = pm1[0];
    int calcula;
    for(calcula = 1 ; calcula<bits ; calcula++){
        total1 = total1*pm1[calcula];
    }

    for(k = 0 ; k < bits ; k++){
      if (NovoIndividuoBMutado[k] == 0 ){
        pm2[k] = (1-mutacao);
      } else pm2[k] = mutacao;
    }
     total2 = pm2[0];
     for(calcula = 1 ; calcula<bits ; calcula++){
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
    }

    for (i = 0; i < restante ; i++){
        NovoIndividuoA[i+corte] = IndividuoB[i+corte];
        NovoIndividuoB[i+corte] = IndividuoA[i+corte];
    }

    float probabilidade;
    probabilidade = mutation(NovoIndividuoA,NovoIndividuoB,IndividuoC,bits,mutacao);
   return probabilidade;
}


int main()
{
    int bits, posi, teste, corte, c = 0 , i;
    float mutacao;
   // printf("Digite a quantidade de testes \n");
    scanf("%d", &teste);
    float guardaresultado[teste];
    while(c < teste){
           // printf("Digite o numero de Bits: \n");
            scanf("%d ", &bits);
            int IndividuoA[bits];
            int IndividuoB[bits];
            int IndividuoC[bits];

            scanf("%d %f", &corte, &mutacao);

            for (int i = 0 ; i < bits ; i++){
                scanf("%d", &posi);
                IndividuoA[i] = posi;
            }
            for (int i = 0 ; i < bits ; i++){
                scanf("%d", &posi);
                IndividuoB[i] = posi;
            }
            for (int i = 0 ; i < bits ; i++){
                scanf("%d", &posi);
                IndividuoC[i] = posi;
            }
           guardaresultado[c] = nextgeneration(IndividuoA,IndividuoB,IndividuoC,bits,corte,mutacao);
    c++;
    }
    int j;
    for( j = 0 ; j < teste ; j++)
    printf("%.7f\n", guardaresultado[j]);
}
