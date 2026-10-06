/*
 * function: func_021C8850
 * address: 0x021C8850
 * packet: pkt_ov128_021C8850
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B8F4 0x0204B8F4 arm
 */
#include "../include/Obj00179.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;struct Obj;
extern u32 func_0204B98C(struct Actor *);
extern u32 func_0204B8F4(struct Obj *);
int func_021C8850(u8 *p, u8 *a1) {u32 n;if(func_0204B98C(*(struct Actor * *)&((struct Obj00179 *)p)->f1A0)==0)return 1;n=func_0204B8F4(*(struct Obj * *)&((struct Obj00179 *)p)->f1A0);if(n-((struct Obj00179 *)p)->f1A8>=2) ((struct Obj00179 *)p)->f1A8=n;return 0;}
