/*
 * function: func_021B9AF8
 * address: 0x021B9AF8
 * packet: pkt_ov181_021B9AF8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9AD4 0x021B9AD4 thumb ov181
 *   func_020056A0 0x020056A0 thumb
 */
#include "../include/Obj03327.h"
extern void func_021B9AD4(void *,char *);
extern void *func_020056A0(void *,void *,int);
void func_021B9AF8(char *p){((struct Obj03327 *)p)->f4=func_020056A0(func_021B9AD4,p,0);}
