/*
 * function: func_021F19B8
 * address: 0x021F19B8
 * packet: pkt_ov107_021F19B8
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 */
#include "../include/Obj13765.h"
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *);
void func_021F19B8(unsigned char *a) { APP_TASKMENU_CloseMenu(*(struct TaskMenu * *)&((struct Obj13765 *)a)->f3C); ((struct Obj13765 *)a)->f3C=0; }
