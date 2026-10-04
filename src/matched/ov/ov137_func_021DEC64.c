/*
 * function: func_021DEC64
 * address: 0x021DEC64
 * packet: pkt_ov137_021DEC64
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E170C 0x021E170C thumb ov137
 *   func_021E16C4 0x021E16C4 thumb ov137
 */
#include "../include/Obj01753.h"
typedef unsigned short u16;
extern int func_021E170C(char *);
extern int func_021E16C4(char *,int);
int func_021DEC64(char *p) {if(func_021E16C4(p,8)==1){((struct Obj01753 *)p)->f30=func_021E170C(p)+1;((struct Obj01753 *)p)->f0=10;}return 0;}
