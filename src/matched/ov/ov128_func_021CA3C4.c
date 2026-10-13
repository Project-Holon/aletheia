/*
 * function: func_021CA3C4
 * address: 0x021CA3C4
 * packet: pkt_ov128_021CA3C4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../include/Obj03813.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Obj;
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021CA3C4(char *p) {CLACT_SetActorAnimFrame(((struct Obj03813 *)p)->f168,0);CLACT_SetActorAnimSeq(((struct Obj03813 *)p)->f168,8);func_0204B92C(((struct Obj03813 *)p)->f168,1);}
