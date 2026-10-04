/*
 * function: func_021F6D1C
 * address: 0x021F6D1C
 * packet: pkt_ov215_021F6D1C
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02015FAC 0x02015FAC thumb
 *   func_02015FBC 0x02015FBC thumb
 */
#include "../include/Obj05551.h"
typedef unsigned char u8;
struct Data;
extern u8 func_02015FAC(struct Data *);
extern void func_02015FBC(char *,int);
void func_021F6D1C(char *p){u8 n;if(((struct Obj05551 *)p)->f3C){n=func_02015FAC(*(struct Data * *)&((struct Obj05551 *)p)->f34);if(n>((struct Obj05551 *)p)->f40)n--;else n++;func_02015FBC(*(char * *)&((struct Obj05551 *)p)->f34,n);if(n==((struct Obj05551 *)p)->f40)((struct Obj05551 *)p)->f3C=0;}}
