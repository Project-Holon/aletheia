/*
 * function: func_021FFC6C
 * address: 0x021FFC6C
 * packet: pkt_ov186_021FFC6C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 */
#include "../include/Obj06638.h"
struct PrintSys;extern void func_020307B0(void *);extern void func_0201C4C0(struct PrintSys *);
void func_021FFC6C(char *p) {if(((struct Obj06638 *)p)->f88){func_020307B0(((struct Obj06638 *)p)->f88);((struct Obj06638 *)p)->f88=0;}func_020307B0(((struct Obj06638 *)p)->f80);func_0201C4C0(*(struct PrintSys * *)&((struct Obj06638 *)p)->f3C);func_020307B0(p);}
