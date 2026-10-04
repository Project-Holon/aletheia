/*
 * function: func_021F0C0C
 * address: 0x021F0C0C
 * packet: pkt_ov033_021F0C0C
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06144.h"
typedef unsigned int   u32;
struct PalAnmSlot;
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern void func_02021540(void *);
extern void func_02030DA4(void *);
extern void func_020307B0(void *);
void func_021F0C0C(char *p) { func_020215A0(((struct Obj06144 *)p)->fBC,1); func_020215A0(((struct Obj06144 *)p)->fBC,3); func_02021540(((struct Obj06144 *)p)->fBC); func_02030DA4(((struct Obj06144 *)p)->fB4); func_020307B0(((struct Obj06144 *)p)->fB8); }
