/*
 * function: func_021F0E7C
 * address: 0x021F0E7C
 * packet: pkt_ov032_021F0E7C
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj00007.h"
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void func_021F0E7C(char *p) { if(((struct Obj00007 *)p)->f7B==0) CLACT_SetActorAnimSeq(((struct Obj00007 *)p)->f2C4,9); else CLACT_SetActorAnimSeq(((struct Obj00007 *)p)->f2C4,7); }
