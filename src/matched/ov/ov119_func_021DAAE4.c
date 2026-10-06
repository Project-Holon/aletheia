/*
 * function: func_021DAAE4
 * address: 0x021DAAE4
 * packet: pkt_ov119_021DAAE4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC62C 0x021DC62C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAA7C 0x021DAA7C thumb ov119
 */
#include "../include/Obj13891.h"
extern void func_021DC62C(char *,int);
extern void func_021D8E84(void *p, int v);
extern void func_021DAA7C(char *);
void func_021DAAE4(char *p) {
 func_021DC62C(p,((struct Obj13891 *)p)->fF2C-1);
 if(((struct Obj13891 *)p)->fF2C>=24) func_021D8E84(p,(int)func_021DAA7C);
}
