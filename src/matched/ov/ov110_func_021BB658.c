/*
 * function: PMSIV_CATEGORY_SetCursorVisible
 * address: 0x021BB658
 * packet: pkt_ov110_021BB658
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 */
#include "../include/Obj04444.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
void PMSIV_CATEGORY_SetCursorVisible(u8 *p, int enable)
{
    if (enable) {
        if (**(int * *)&((struct Obj04444 *)p)->f5C == 0) {
            CLACT_SetActorDrawEnable(((struct Obj04444 *)p)->f54, 1);
            if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj04444 *)p)->f4) == 0) {
                CLACT_SetActorAnimSeq(((struct Obj04444 *)p)->f54, 4);
            } else {
                CLACT_SetActorAnimSeq(((struct Obj04444 *)p)->f54, 6);
            }
        } else {
            CLACT_SetActorDrawEnable(((struct Obj04444 *)p)->f54, 0);
        }
    } else {
        CLACT_SetActorDrawEnable(((struct Obj04444 *)p)->f54, 0);
    }
}
