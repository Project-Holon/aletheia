/*
 * function: func_021BD000
 * address: 0x021BD000
 * packet: pkt_ov110_021BD000
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BD026.
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj08004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
int func_021BD000(char *p) { if (CLACT_GetActorDrawEnable(((struct Obj08004 *)p)->f28) && ((struct Obj08004 *)p)->f2C==0) { CLACT_SetActorAnimSeq(((struct Obj08004 *)p)->f28,9); ((struct Obj08004 *)p)->f2C=1; return 1; } return 0; }
