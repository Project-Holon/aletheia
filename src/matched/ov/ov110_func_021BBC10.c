/*
 * function: func_021BBC10
 * address: 0x021BBC10
 * packet: pkt_ov110_021BBC10
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 */
#include "../include/Obj04446.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u8 func_021BF6DC(u8 *);
int func_021BBC10(u8 *p)
{
    u16 state = CLACT_GetActorAnimSeq(((struct Obj04446 *)p)->f54);
    if (state != 31 && state != 30) return 1;
    if (CLACT_IsActorAnimActive(((struct Obj04446 *)p)->f54) == 0) {
        func_0204B3DC(((struct Obj04446 *)p)->f54, ((struct Obj04446 *)p)->f58);
        CLACT_SetActorAnimSeq(((struct Obj04446 *)p)->f54, func_021BF6DC(*(u8 * *)&((struct Obj04446 *)p)->f4) == 0 ? 4 : 6);
        *(int *)&((struct Obj04446 *)p)->f58 = 0;
        return 1;
    }
    return 0;
}
