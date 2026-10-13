/*
 * function: TOUCHBAR_OnPressPlain
 * address: 0x021B6A28
 * packet: pkt_ov067_021B6A28
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding at 0x021B6A42.
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj05146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
void TOUCHBAR_OnPressPlain(u8 *p)
{
    ((struct Obj05146 *)p)->f8 = ((struct Obj05146 *)p)->f2A;
    CLACT_SetActorAnimSeq(((struct Obj05146 *)p)->f0, ((struct Obj05146 *)p)->f8);
    if (((struct Obj05146 *)p)->f34) func_020061E4((u32)(((struct Obj05146 *)p)->f34));
}
