/*
 * function: func_02162774
 * address: 0x02162774
 * packet: pkt_ov010_02162774
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj07296.h"
typedef unsigned short u16;
void func_02162774(char *p, unsigned i, u16 v) { if(i < ((struct Obj07296 *)p)->f14) *(u16 *)(*(char * *)&((struct Obj07296 *)p)->f20+i*0x24+2)=v; }
