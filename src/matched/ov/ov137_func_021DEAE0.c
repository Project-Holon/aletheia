/*
 * function: func_021DEAE0
 * address: 0x021DEAE0
 * packet: pkt_ov137_021DEAE0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
#include "../include/Obj14220.h"
typedef unsigned short u16;
extern int func_021DCBC4(void *,int,void *,int);
int func_021DEAE0(char *p) {u16 v=1;if(func_021DCBC4(((struct Obj14220 *)p)->fDC,0x2805,&v,2)==1){((struct Obj14220 *)p)->f0=4;return 1;}return 0;}
