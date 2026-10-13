/*
 * function: ITEMMENU_CloseYesNoList
 * address: 0x021BB1AC
 * packet: pkt_ov070_021BB1AC
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 */
#include "../include/Obj13159.h"
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
void ITEMMENU_CloseYesNoList(char *p) { APP_TASKMENU_CloseMenu(((struct Obj13159 *)p)->f77C); ((struct Obj13159 *)p)->f77C = 0; }
