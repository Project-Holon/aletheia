/*
 * function: func_021BC298
 * address: 0x021BC298
 * packet: pkt_ov209_021BC298
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056A0 0x020056A0 thumb
 *   func_021BC2BC 0x021BC2BC thumb ov209
 */
#include "../include/Obj00123.h"
extern void *func_020056A0(unsigned,unsigned,unsigned);extern void func_021BC2BC(void *,char *);
void func_021BC298(char *p){((struct Obj00123 *)p)->f4=func_020056A0((unsigned)func_021BC2BC,(unsigned)p,0);}
