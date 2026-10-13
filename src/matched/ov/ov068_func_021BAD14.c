/*
 * function: OPTION_MENU_StepSelectedSetting
 * address:  0x021BAD14
 * packet:   pkt_ov068_021BAD14
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OPTION_MENU_StepSetting  0x021BB000  thumb
 *   OPTION_MENU_ApplySoundMode  0x021BACF4  thumb
 */
#include "../include/Obj09870.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned int  u32;

extern void OPTION_MENU_StepSetting(u8 *p, int i, int delta);
extern void OPTION_MENU_ApplySoundMode(u8 *p, u32 a, u32 b);

void OPTION_MENU_StepSelectedSetting(u8 *p, u32 v)
{
    if (((struct Obj09870 *)p)->f4 < 5) {
        OPTION_MENU_StepSetting(p + 0x44, ((struct Obj09870 *)p)->f4, v);
        OPTION_MENU_ApplySoundMode(p, *(s8 *)(p + 0x44 + ((struct Obj09870 *)p)->f4), 0);
    }
}
