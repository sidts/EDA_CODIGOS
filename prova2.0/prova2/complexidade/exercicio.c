#include <stdio.h>

void questao5(float *v, int m, int j, int k){
    int pmenor, pdir, pesq;
    pesq = j - 1;
    pdir = j + 1;
    while(k>0){
        if((pesq >= 0 ) & (pdir<m)){
            if(fabs(v[pesq] - v[j]) < fabs(v[pdir] - v[j])){
                pmenor = pesq;
                pesq--;
            }
            else{
                pmenor = pdir;
                pdir++;
            }
        }
        else if(pesq >= 0){
            pmenor = pesq;
            pesq--;
        }
        else if(pdir<m){
            pmenor = pdir;
            pdir++;
        }
        else{
            break;
        }

        printf("%f", v[pmenor]);
        k--;
    }

    return;
}