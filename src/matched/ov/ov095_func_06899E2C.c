/*
 * function: func_06899E2C
 * address: 0x06899E2C
 * packet: pkt_ov095_06899E2C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj07909.h"
#include "../include/Obj21887.h"
typedef unsigned int u32;
void func_06899E2C(unsigned char *p) {
 int i;
 u32 zero;
 unsigned char *q;
 zero=0;
 for(i=0;i<4;i++) {
  q=p+i*16;
  ((struct Obj07909 *)q)->f20=zero;
  ((struct Obj07909 *)q)->f24=zero;
  ((struct Obj07909 *)q)->f28=zero;
  ((struct Obj07909 *)q)->f2C=zero;
 }
 ((struct Obj21887 *)p)->f60=zero;
}
