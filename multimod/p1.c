#include "multimod.h"
#include <stdio.h>
int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  // TODO: implement
  int sign = 0;
  if(a==0 || b==0) return 0;
  if(a<0){
    sign++;
	a=-a;
  }
  if(b<0){
    sign++;
	b=-b;
  }
  int64_t sum = 0;
  int ad = 0;
  int64_t tmp = 1;
  int64_t rs1 = b%m;
  printf("rs1 : %ld",rs1);
  for(int i=0; i<64; i++){
    ad = 1&a ;
	printf("ad : %ld\n",a);
	a = a >> 1;
	tmp = tmp << i;
	tmp *= ad;
	tmp = tmp%m;
	printf("tmp : %ld",tmp);
	sum += rs1 * tmp;
	tmp = 1;
  }
  if(sign==1) sum = m-sum%m; 
  else sum = sum%m;
  return sum;
}
