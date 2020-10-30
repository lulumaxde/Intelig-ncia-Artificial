#include <stdio.h>
#include <stdlib.h>

void imprime(float *X1,float *V1,int tam){
    int i,j;
    printf("Posicao \n");
    for(i = 0 ; i < tam ; i++){
        printf("%.3f ", X1[i]);
    }
    printf("\n");
    printf("Velocidade \n");
    for(j = 0 ; j < tam ; j++){
        printf("%.4f ", V1[j]);
    }
}

void imprimeFunction(float *X2,int tam){
    int i,j;
    for(i = 0 ; i < tam ; i++){
        printf("%.4f ", X2[i]);
    }
}

void SegundaInteracao(int tam, int GBEST, float BestFitness,float *X2,float *V2){

        float w = 0.70, c1 = 0.20, c2 = 0.60, r1 = 0.4657, r2 = 0.5319;
        int n = 5, iteracao = 3;
        float NEWV[tam], NEWPOSI[tam];
        for(int i = 0 ; i < tam ; i++){
            NEWV[i] = w*V2[i] + c1*r1*(BestFitness - X2[i]) + c2*r2*(X2[GBEST]-X2[i]);
        }

        for(int j = 0 ; j < tam ; j++){
            NEWPOSI[j] = X2[j] + NEWV[j];
        }

       printf(" Segunda Interacao : \n");
       imprime(NEWPOSI,NEWV,tam);
       printf("\n");
       calculafuncao2(NEWPOSI,NEWV,tam);



}

void calculafuncao2(float *NEWPOSI,float *NEWV,int tam){

    int i;
    float Funcao2[tam];
    for(int i = 0 ; i < tam ; i++){
        Funcao2[i] = 1+(NEWPOSI[i]*2-(NEWPOSI[i]*NEWPOSI[i]));
    }
    printf("F(2): \n");
    imprimeFunction(Funcao2,tam);
    printf("\n");
    definePbestGbest2(NEWV,Funcao2,NEWPOSI,tam);

}
void definePbestGbest2(float *NEWV, float *Funcao2,float *NEWPOSI,int tam){

    float BestFitness2 = 0;
    int GBEST2;

    for(int i = 0; i < tam ; i++){
        if(Funcao2[i]>BestFitness2){
            BestFitness2 = Funcao2[i];
        }
    }
    int j;

    for(j = 0; j < 5 ; j++){
        if(Funcao2[j] == BestFitness2){
            GBEST2 = j;
        }
    }
   // imprimeFunction(Funcao2,tam);
    printf("\n");
    printf("fitness: %.4f GBEST: %.3f",BestFitness2, NEWPOSI[GBEST2]);


}

void definePbestGbest(float *V1, float *Funcao,float *X1,int tam){

    float BestFitness = 0;
    int GBEST;

    for(int i = 0; i < tam ; i++){
        if(Funcao[i]>BestFitness){
            BestFitness = Funcao[i];
        }
    }
    int j;

    for(j = 0; j < 5 ; j++){
        if(Funcao[j] == BestFitness){
            GBEST = j;
        }
    }
    //imprimeFunction(X1,tam);
    //printf("%.4f %.3f",BestFitness, X1[GBEST]);
    SegundaInteracao(tam,GBEST,BestFitness, X1, V1);

}

void calculafuncao(float *X1,float *V1,int tam){

    int i;
    float Funcao[tam];
    for(int i = 0 ; i < tam ; i++){
        Funcao[i] = 1+(X1[i]*2-(X1[i]*X1[i]));
    }
    //imprimeFunction(X2,tam);
    definePbestGbest(V1,Funcao,X1,tam);

}

void inicializaPosiVelo(float *X,float *V,int tam){

    int i,j;
    float X1[tam], V1[tam];
    for(int i = 0 ; i < tam ; i++){
        X1[i] = X[i]-0.5;
        V1[i] = V[i]-0.5;
    }

    for(int j = 0 ; j < tam ; j++){
        X1[j] = X1[j]*10;
    }
    calculafuncao(X1,V1,5);
   //imprime(X1,V1,5);
}


int main()
{

    float X[5] = {0.4657, 0.8956, 0.3877, 0.4902, 0.5039};
    float V[5] = {0.5319, 0.8185, 0.8331, 0.7677, 0.1708};
    int tam = 5;
    inicializaPosiVelo(X,V,tam);

}
