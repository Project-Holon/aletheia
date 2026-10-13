/*
 * function: PMSIV_CATEGORY_IsSelectAnimDone
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
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 */
#include "../include/Obj04446.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
int PMSIV_CATEGORY_IsSelectAnimDone(u8 *p)
{
    u16 state = CLACT_GetActorAnimSeq(((struct Obj04446 *)p)->f54);
    if (state != 31 && state != 30) return 1;
    if (CLACT_IsActorAnimActive(((struct Obj04446 *)p)->f54) == 0) {
        CLACT_SetActorDrawEnable(((struct Obj04446 *)p)->f54, ((struct Obj04446 *)p)->f58);
        CLACT_SetActorAnimSeq(((struct Obj04446 *)p)->f54, PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj04446 *)p)->f4) == 0 ? 4 : 6);
        *(int *)&((struct Obj04446 *)p)->f58 = 0;
        return 1;
    }
    return 0;
}
