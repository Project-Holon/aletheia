/*
 * function: STARTMENU_ShowRowActors
 * address:  0x021BB9DC
 * packet:   pkt_ov088_021BB9DC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   BEACON_GetSlotState  0x0200C308  thumb
 */
#include "../include/Obj03675.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct Blk34;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u8 BEACON_GetSlotState(struct Blk34 *p, u32 i);

void STARTMENU_ShowRowActors(char *p, int flag)
{
    unsigned i;
    if (flag == 0) {
        for (i = 0; i <= 5; i++)
            CLACT_SetActorDrawEnable(*(void **)(p + 0x1c + i * 4), flag);
        return;
    }
    CLACT_SetActorDrawEnable(((struct Obj03675 *)p)->f1C, 1);
    for (i = 0; i < 8; i++) {
        u8 c = *(u8 *)(p + 0x120 + i);
        if (c == 8)
            return;
        if (c == 3) {
            if (BEACON_GetSlotState(((struct Obj03675 *)p)->f8, 1) == 1)
                CLACT_SetActorDrawEnable(((struct Obj03675 *)p)->f24, 1);
        } else if (c == 4) {
            if (BEACON_GetSlotState(((struct Obj03675 *)p)->f8, 2) == 1)
                CLACT_SetActorDrawEnable(((struct Obj03675 *)p)->f28, 1);
        } else if (c == 7) {
            if (BEACON_GetSlotState(((struct Obj03675 *)p)->f8, 3) == 1)
                CLACT_SetActorDrawEnable(((struct Obj03675 *)p)->f2C, 1);
        } else if (c == 5) {
            CLACT_SetActorDrawEnable(((struct Obj03675 *)p)->f30, 1);
        }
    }
}
