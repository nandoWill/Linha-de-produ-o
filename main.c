#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int f[2][100];
    int t[2][100];
    int a[2][100];
    int s[2][100];
    int fim;
    int x1=(rand()%10),x2=(rand()%10);
    int e1=(rand()%10),e2=(rand()%10);
    int i;
    //preenchendo aleatoriamente
    for(i=0;i<100;i++){
        t[0][i]=(rand()%10);
        t[1][i]=(rand()%10);
        a[0][i]=(rand()%10);
        a[1][i]=(rand()%10);
       // printf("%d %d %d %d",f[0][i],f[1][i],s[0][i],s[1][0]);
    }
    //soma o caso base que é a primeira estação
    f[0][0]=e1+a[0][0];
    f[1][0]=e2+a[1][0];
    int k;

    //calcula o custo e adiciona na matriz S qual o caminho foi escolhido.
    for(k=1;k<100;k++){
        if(f[0][k-1]<f[1][k-1]+t[1][k-1]){
            f[0][k]=f[0][k-1]+a[0][k];
            s[0][k]=1;
        }else{
            f[0][k]=f[1][k-1]+t[1][k-1]+a[0][k];
            s[0][k]=2;
        }
        if(f[1][k-1]<f[0][k-1]+t[0][k-1]){
            f[1][k]=f[1][k-1]+a[1][k];
            s[1][k]=2;
        }else{
            f[1][k]=f[0][k-1]+t[0][k-1]+a[1][k];
            s[1][k]=1;
        }
    }
    if(f[0][99]+x1<f[1][99]+x2){
        fim = f[0][99]+x1;
    }else{
        fim = f[1][99]+x2;
    }


}
