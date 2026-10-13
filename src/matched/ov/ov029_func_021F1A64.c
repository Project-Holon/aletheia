/*
 * function: C_GEAR_SetAllActorsVisible
 * address:  0x021F1A64
 * packet:   pkt_ov029_021F1A64
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   C_GEAR_UpdateClock  0x021F1F80  thumb  ov029
 */
#include "../include/Obj00106.h"

typedef unsigned char u8;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void C_GEAR_UpdateClock(char *p);

void C_GEAR_SetAllActorsVisible(char *p, int flag)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (*(int *)(p + i * 12 + 0x3c) != 0) {
            CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 12 + 0x3c), flag);
        }
    }
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 4 + 0x158) != 0 && ((struct Obj00106 *)p)->f45A != 0) {
            CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x158), flag);
        }
    }
    for (i = 0; i < 11; i++) {
        if (*(int *)(p + i * 4 + 0x12c) != 0) {
            if ((unsigned)(i - 8) <= 1) {
                if (((struct Obj00106 *)p)->f45A != 0) {
                    CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x12c), flag);
                }
            } else {
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x12c), flag);
            }
        }
    }
    if (((struct Obj00106 *)p)->f164 != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00106 *)p)->f164, flag);
    }
    if (((struct Obj00106 *)p)->f168 != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00106 *)p)->f168, flag);
    }
    if (((struct Obj00106 *)p)->f16C != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00106 *)p)->f16C, flag);
    }
    if (flag == 1) {
        C_GEAR_UpdateClock(p);
    }
}
