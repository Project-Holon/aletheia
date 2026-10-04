/*
 * function: func_021F38D4
 * address: 0x021F38D4
 * packet: pkt_ov056_021F38D4
 * region: ov056
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0218C860 0x0218C860 thumb ov021
 *   func_0218C69C 0x0218C69C thumb ov021
 */
#include "../include/Obj03166.h"
extern void func_0218C860(void *);
extern void func_0218C69C(unsigned char *,int,int,int);
void func_021F38D4(unsigned char *p) { if (((struct Obj03166 *)p)->f0) { func_0218C860(((struct Obj03166 *)p)->f0); func_0218C69C(*(unsigned char * *)&((struct Obj03166 *)p)->f8,((struct Obj03166 *)p)->f4,0,1); func_0218C69C(*(unsigned char * *)&((struct Obj03166 *)p)->f8,((struct Obj03166 *)p)->f4,0,3); *(int *)&((struct Obj03166 *)p)->f0=0; ((struct Obj03166 *)p)->f4=0; *(int *)&((struct Obj03166 *)p)->f8=0; } }
