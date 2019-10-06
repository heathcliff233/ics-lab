#include "multimod.h"
#include <stdlib.h>
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
  int sum = 0;
  int ad = 0;
  int tmp = 1;
  int rs1 = b%m;
  printf("rs1 : %d",rs1);
  for(int i=0; i<64; i++){
    ad = 1&a ;
	printf("ad : %ld\n",a);
	a = a >> 1;
	tmp = tmp << i;
	tmp *= ad;
	tmp = tmp%m;
	printf("tmp : %d",tmp);
	sum += rs1 * tmp;
	tmp = 1;
  }
  if(sign==1) sum = m-sum%m; 
  else sum = sum%m;
  return sum;
}
