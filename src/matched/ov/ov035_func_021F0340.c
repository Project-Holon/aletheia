/*
 * function: C_GEAR_POWER_ONOFF_CloseMenu
 * address: 0x021F0340
 * packet: pkt_ov035_021F0340
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 */
#include "../include/Obj09809.h"
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
void C_GEAR_POWER_ONOFF_CloseMenu(char *p)
{
    if (((struct Obj09809 *)p)->f44 != 0) {
        APP_TASKMENU_CloseMenu(((struct Obj09809 *)p)->f44);
        ((struct Obj09809 *)p)->f44 = 0;
    }
}
