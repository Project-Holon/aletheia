/*
 * unit:     yes
 * function: OPTION_MENU_GetTextSpeedWait, OPTION_MENU_TakeChangedSetting
 * address:  0x021BB0D0
 * packet:   pkt_ov068_021BB0D0
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ARM9 tail call then a byte read-modify-write.
 *
 * symbols:
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 */
#include "../include/Obj13144.h"

void OPTION_MENU_GetTextSpeedWait(void)
{
    signed char MSG_SPEED_GetWait(void);
    MSG_SPEED_GetWait();
}

int OPTION_MENU_TakeChangedSetting(void *p)
{
    unsigned char old = ((struct Obj13144 *)p)->f5;
    ((struct Obj13144 *)p)->f5 = 0xb;
    return old;
}
