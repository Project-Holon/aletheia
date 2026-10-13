/*
 * function: C_GEAR_POWER_ONOFF_GetMenuResult
 * address:  0x021F0364
 * packet:   pkt_ov035_021F0364
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf of C_GEAR_POWER_ONOFF_StepTurnOff (reads the menu handle at +0x44).
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_GetMenuResult 0x021F0364 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 */
#include "../include/Obj20482.h"

typedef unsigned char u8;

extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);

u8 C_GEAR_POWER_ONOFF_GetMenuResult(char *p)
{
    return APP_TASKMENU_GetCursorPos(((struct Obj20482 *)p)->f44);
}
