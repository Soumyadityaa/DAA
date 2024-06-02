#include <stdio.h>
int n = 5;
int p[10] = {3, 3, 2, 5, 1};
int w[10] = {10, 15, 10, 12, 8};
int W = 10;
int main(){
   int cur_w;
   float tot_v;
   int i, maxi;
   int used[10];
   
   for (i = 0; i < n; ++i)
      used[i] = 0;
   
   cur_w = W;
   
   while (cur_w > 0) {
      maxi = -1;
      
      for (i = 0; i < n; ++i)
         if ((used[i] == 0) &&
               ((maxi == -1) || ((float)w[i]/p[i] > (float)w[maxi]/p[maxi])))
            maxi = i;
      
      
      used[maxi] = 1;
      cur_w =cur_w- p[maxi];
      tot_v =tot_v+ w[maxi];
      
      if (cur_w >= 0){
      }
     
      else {
         tot_v =tot_v- w[maxi];
         tot_v =tot_v+ (1 + (float)cur_w/p[maxi]) * w[maxi];
      }
   }
  
   printf("Filled the bag with objects worth %.2f.\n", tot_v);
   return 0;
}