/*
 * function: ITEMMENU_FreeActionMenuResources
 * address: 0x021B9ED8
 * packet: pkt_ov070_021B9ED8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DrawSystem 0x0204A600 arm
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 */
#include "../include/Obj13157.h"
extern void CLACT_DrawSystem(void);
extern void APP_TASKMENU_UpdateMenu(void *);
void ITEMMENU_FreeActionMenuResources(char *p) { CLACT_DrawSystem(); if (((struct Obj13157 *)p)->f77C) APP_TASKMENU_UpdateMenu(((struct Obj13157 *)p)->f77C); }
