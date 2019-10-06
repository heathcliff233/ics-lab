#include "multimod.h"

int64_t multimod_p1(int64_t a, int64_t b, int64_t m) {
  // TODO: implement
  int sign = 0;
  if(a==0 || b==0) return 0;
  if(a<0) a=-a;
  if(b<0) b=-b;
  int sum = 0;
  int ad = 0;
  int tmp = 1;
  int rs1 = b%m;
  for(int i=0; i<64; i++){
    ad = 1&a ;
	a >> 1;
	tmp << i;
	tmp *= ad;
	tmp = tmp%m;
	sum += rs1 * tmp;
	tmp = 1;
  } 
  sum = sum%m;
  return sum;
}
