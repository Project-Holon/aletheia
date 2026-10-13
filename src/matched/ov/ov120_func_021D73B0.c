/*
 * function: func_021D73B0
 * address: 0x021D73B0
 * packet: pkt_ov120_021D73B0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj13936.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void func_021D73B0(char *p) { u16 next; next=CLACT_GetActorAnimSeq(((struct Obj13936 *)p)->f130)+1; if(next>26) next=11; CLACT_SetActorAnimSeq(((struct Obj13936 *)p)->f130,next); }
