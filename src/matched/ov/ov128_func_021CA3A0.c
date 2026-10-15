/*
 * function: WF2DMAP_TOUCH_PlayActorAnimA
 * address: 0x021CA3A0
 * packet: pkt_ov128_021CA3A0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj03813.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Obj;
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
void WF2DMAP_TOUCH_PlayActorAnimA(char *p) {CLACT_SetActorAnimFrame(((struct Obj03813 *)p)->f164,0);CLACT_SetActorAnimSeq(((struct Obj03813 *)p)->f164,9);CLACT_SetActorAutoAnim(((struct Obj03813 *)p)->f164,1);}
