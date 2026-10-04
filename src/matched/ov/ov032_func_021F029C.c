/*
 * function: func_021F029C
 * address: 0x021F029C
 * packet: pkt_ov032_021F029C
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C4DC 0x0201C4DC thumb
 */
#include "../include/Obj00007.h"
typedef unsigned int   u32;
struct PrintSys;
extern void func_0201C4DC(struct PrintSys *p, u32 lo, u32 hi);
void func_021F029C(char *p,int flag) { if(flag) func_0201C4DC((struct PrintSys *)(((struct Obj00007 *)p)->fB4),2000,0); else func_0201C4DC((struct PrintSys *)(((struct Obj00007 *)p)->fB4),500,0); }
