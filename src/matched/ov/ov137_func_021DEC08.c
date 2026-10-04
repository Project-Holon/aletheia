/*
 * function: func_021DEC08
 * address: 0x021DEC08
 * packet: pkt_ov137_021DEC08
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
#include "../include/Obj14221.h"
typedef unsigned short u16;
extern int func_021DCBC4(void *,int,void *,int);
int func_021DEC08(char *p) {u16 v=8;if(func_021DCBC4(((struct Obj14221 *)p)->fDC,0x2805,&v,2)==1)((struct Obj14221 *)p)->f0=10;return 0;}
