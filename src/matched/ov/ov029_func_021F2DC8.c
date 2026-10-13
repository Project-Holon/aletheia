/*
 * function: C_GEAR_TickTabFrame
 * address:  0x021F2DC8
 * packet:   pkt_ov029_021F2DC8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_IsAnyIndicatorShown  0x021F2DA8  thumb  ov029
 *   C_GEAR_IsCallTabActive  0x021F05B4  thumb  ov029
 *   C_GEAR_FadeAccentColors  0x021F0F28  thumb  ov029
 */
#include "../include/Obj00042.h"

typedef unsigned char  u8;
extern int C_GEAR_IsAnyIndicatorShown(u8 *p);
extern int C_GEAR_IsCallTabActive(unsigned char *p);
extern void C_GEAR_FadeAccentColors(char *p, int a);

void C_GEAR_TickTabFrame(char *p)
{
    if (C_GEAR_IsAnyIndicatorShown((u8 *)p) == 0 && ((struct Obj00042 *)p)->f465 != 0) {
        ((struct Obj00042 *)p)->f466 += 1;
        if (((struct Obj00042 *)p)->f466 >= 8) {
            if (C_GEAR_IsCallTabActive((unsigned char *)p) != 0)
                C_GEAR_FadeAccentColors(p, 1);
            else
                C_GEAR_FadeAccentColors(p, 0);
            ((struct Obj00042 *)p)->f465 = 0;
        }
    }
}
