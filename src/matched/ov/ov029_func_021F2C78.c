/*
 * function: C_GEAR_StepFadeIcon
 * address:  0x021F2C78
 * packet:   pkt_ov029_021F2C78
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_StartFadeFx  0x021F2E68  thumb  ov029
 *   C_GEAR_StepFadeFx  0x021F2E8C  thumb  ov029
 */
#include "../include/Obj09788.h"

extern void C_GEAR_StartFadeFx(char *a, int b);
extern int C_GEAR_StepFadeFx(char *a);

int C_GEAR_StepFadeIcon(char *p)
{
    switch (((struct Obj09788 *)p)->f455) {
    case 0:
        switch (((struct Obj09788 *)p)->f416) {
        case 3:
            C_GEAR_StartFadeFx(p + 0x21c, 0x1c0);
            break;
        case 4:
            C_GEAR_StartFadeFx(p + 0x21c, 0x200);
            break;
        }
        ((struct Obj09788 *)p)->f455 += 1;
        break;
    case 1:
        if (C_GEAR_StepFadeFx(p + 0x21c) != 0)
            return 1;
        break;
    }
    return 0;
}
