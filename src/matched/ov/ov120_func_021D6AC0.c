/*
 * function: func_021D6AC0
 * address: 0x021D6AC0
 * packet: pkt_ov120_021D6AC0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */
#include "../include/Obj10393.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
int func_021D6AC0(u8 *p){if(!((struct Obj10393 *)p)->f134)return 0;if((u32)CLACT_GetActorAnimSeq(((struct Obj10393 *)p)->f134)>=29){if(CLACT_IsActorAnimActive(((struct Obj10393 *)p)->f134)==0)return 1;return 0;}return 0;}
