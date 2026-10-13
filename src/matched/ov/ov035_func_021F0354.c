/*
 * function: C_GEAR_POWER_ONOFF_UpdateMenu
 * address: 0x021F0354
 * packet: pkt_ov035_021F0354
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: followers 021F0364 and 021F0370 already filed separately.
 * symbols:
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 */
#include "../include/Obj13079.h"
extern void APP_TASKMENU_UpdateMenu(void *p);
void C_GEAR_POWER_ONOFF_UpdateMenu(char *p)
{
    if (((struct Obj13079 *)p)->f44 != 0)
        APP_TASKMENU_UpdateMenu(((struct Obj13079 *)p)->f44);
}
