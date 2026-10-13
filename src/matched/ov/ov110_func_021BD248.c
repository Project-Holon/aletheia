/*
 * function: func_021BD248
 * address: 0x021BD248
 * packet: pkt_ov110_021BD248
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj10279.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void func_021BD248(u8 *p)
{
    CLACT_SetActorDrawEnable(((struct Obj10279 *)p)->f28,1);
    CLACT_SetActorAnimSeq(((struct Obj10279 *)p)->f28,1);
    ((struct Obj10279 *)p)->f2C=0;
}
