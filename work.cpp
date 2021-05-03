#include "work.h"

Work::Work()
{

}

unsigned long long cash[100000] = {0};

unsigned long long Work::recursiveAlg(int  n){
   unsigned long long sum = 0;
   if(cash[n] != 0){
       sum = cash[n];
   }else{
       if(n < 2){
           sum = n;
       }
       for(int i = 2; i <= n; i++){
           sum+=recursiveAlg(n/i);
       }
       cash[n] = sum;
   }
   return sum;
}

void Work::clear(){
   for(int i = 0; i<100000;i++){
       cash[i] = 0;
   }
}

unsigned long long Work::iterAlg(int  n){

    int i = 0;
        while (i <= (n / 2) || i == n) {
            if (i < 2) {
                cash[i] = i;
            } else {
                unsigned long long sum = 0;
                for (int j = 2; j <= i; ++j) {
                    sum += cash[i / j];
                }
                cash[i] = sum;
                if (i == n / 2) {
                    i = n - 1;
                }
            }
            i++;
        }
        return cash[n];
}
