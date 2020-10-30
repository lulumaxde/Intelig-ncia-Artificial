#include <bits/stdc++.h>

using namespace std;

int RegraInicial( string Nome[], string NovoNome, int n );
int RegraLetraMais(string Nome, string NovoNome, int n, string& out );
int RegraLetraErrada( string Nome, string NovoNome, int n, string& out );
int RegraOrdemErrada( string Nome, string NovoNome, int n, string& out );
int RegraACM( string Nome[], string NovoNome, int n, string& out );

int main()
{
    int Qtd,i,j,define = 3, Qtdnew;

     cin >> Qtd;
     for(i = 0 ; i < Qtd ; i++)
    {
        string Nome[Qtd];

        for( int i = 0; i < Qtd; i++ ) {
            cin >> Nome[i];
        }

        cin >> Qtdnew;
        while( Qtdnew-- )
        {
            string NovoNome, out = " ";
            cin >> NovoNome;
            if( RegraInicial(Nome, NovoNome, Qtd ) == 1) {
                define = 1;
            }
            else if( RegraACM(Nome, NovoNome, Qtd, out ) == 1) {
                define = 2;
            }
            switch(define){
                case 1: cout << NovoNome << " is correct\n"; break;
                case 2: cout << NovoNome << " is a misspelling of " << out << "\n"; break;
                case 3: cout << NovoNome << " is unknown\n"; break;

        }
    }
 }
    return 0;
}


int RegraInicial( string Nome[], string NovoNome, int n )
{   int i = 0;
    while( i < n ) {
        if( Nome[i] == NovoNome ) {
            return 1;
        }
    i++;
    }
    return 0;
}

int RegraLetraMais(string Nome, string NovoNome, int n, string& out )
{
    size_t Str = Nome.size();
    size_t tar = NovoNome.size();

    if( abs( ( int ) Str - ( int ) tar ) == 1 ) {
        unsigned contador = 0;
        size_t j,k;
        for(j = 0, k = 0; j < tar && k < Str; j++, k++ ) {
            if( Nome[k] != NovoNome[j] ) {
                if( Str > tar ) --j;
                else            --k;
            }
            else {
                contador++;
            }
        }

        if( ( tar < Str && contador == tar ) || ( tar > Str && contador == Str ) ) {
            out = Nome;
            return 1;
        }
    }
    return 0;
}

int RegraLetraErrada( string Nome, string NovoNome, int n, string& out )
{
    size_t tar = NovoNome.size();
    size_t Str = Nome.size();
    unsigned contador = 0;
    size_t j = 0;
    if( tar == Str ) {
        while( j < tar ) {
            if( Nome[j] == NovoNome[j] ) {
                contador++;
            }
          j++;
        }
    }
    if( contador == tar - 1 ) {
        out = Nome;
        return 1;
    }
    return 0;
}

int RegraOrdemErrada( string Nome, string NovoNome, int n, string& out )
{
    size_t tar = NovoNome.size();
    size_t Str = Nome.size();
    //printf("%d",tar);
    unsigned contador = 0;
    int j;
    bool indice = false;
    if( tar == Str ) {
        for( j = 0; j < tar; j++ ) {
            if( Nome[j] == NovoNome[j] ) {
                contador++;
            }
            else if( j > 0 && !indice && Nome[j-1] == NovoNome[j] && Nome[j] == NovoNome[j-1] ) {
                indice = true;
                contador += 2;
            }
        }
    }
    if( contador == tar ) {
        out = Nome;
        return 1;
    }
    return 0;
}

int RegraACM( string Nome[], string NovoNome, int n, string& out )
{
    for( int i = 0; i < n; i++ ) {
        if( RegraLetraMais( Nome[i], NovoNome, n, out ) == 1) {
            return 1;
        }
        else if( RegraLetraErrada( Nome[i], NovoNome, n, out ) == 1) {
            return 1;
        }
        else if( RegraOrdemErrada( Nome[i], NovoNome, n, out ) == 1) {
            return 1;
        }
    }

    return 0;
}
