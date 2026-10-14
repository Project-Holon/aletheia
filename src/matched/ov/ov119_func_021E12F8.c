/*
 * function: POKETRADE_SAVE_CloseTaskMenu
 * address: 0x021E12F8
 * packet: pkt_ov119_021E12F8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 */
#include "../include/Obj00001.h"
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
void POKETRADE_SAVE_CloseTaskMenu(char *p)
{
    if (((struct Obj00001 *)p)->f64C) {
        *(volatile unsigned short *)0x04000050 = 0;
        APP_TASKMENU_CloseMenu(((struct Obj00001 *)p)->f64C);
        ((struct Obj00001 *)p)->f64C = 0;
    }
}
