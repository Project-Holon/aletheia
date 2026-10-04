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
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 */
#include "../include/Obj10393.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u16 func_0204B898(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
int func_021D6AC0(u8 *p){if(!((struct Obj10393 *)p)->f134)return 0;if((u32)func_0204B898(((struct Obj10393 *)p)->f134)>=29){if(func_0204B98C(((struct Obj10393 *)p)->f134)==0)return 1;return 0;}return 0;}
