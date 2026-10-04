/*
 * function: func_02162478
 * address: 0x02162478
 * packet: pkt_ov010_02162478
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02162F0C 0x02162F0C thumb ov010
 */
#include "../include/Obj01639.h"
#include "../include/Obj12337.h"
typedef unsigned short u16;
extern int func_02162F0C(char *, int *);
int func_02162478(char *p, int *v) { char *r=*(char * *)&((struct Obj12337 *)p)->f28; u16 n,i; if(r) { n=((struct Obj12337 *)p)->f18; for(i=0;i<n;i++,r+=22) { if(func_02162F0C(r,v) && ((struct Obj01639 *)r)->f6==6) return 1; } } return 0; }
