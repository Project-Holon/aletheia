/*
 * function: func_021DEB40
 * address: 0x021DEB40
 * packet: pkt_ov137_021DEB40
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_021E170C 0x021E170C thumb ov137
 */
#include "../include/Obj01753.h"
typedef unsigned short u16;
extern int func_021DCBC4(void *,int,void *,int);
extern int func_021E170C(char *);
int func_021DEB40(char *p) {((struct Obj01753 *)p)->f30=func_021E170C(p)+1;if(func_021DCBC4(((struct Obj01753 *)p)->fDC,0x280A,p+48,4)==1){((struct Obj01753 *)p)->f14=0;((struct Obj01753 *)p)->f0=6;}return 0;}
