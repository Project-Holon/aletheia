/*
 * function: IRC_COMPATIBLE_MENU_ExitDisplay
 * address: 0x021B78D0
 * packet: pkt_ov102_021B78D0
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   IRC_COMPATIBLE_MENU_ExitSprites 0x021B7BC0 thumb ov102
 */
#include "../include/Obj22141.h"
struct Node; extern void func_02030EAC(struct Node *); extern void IRC_COMPATIBLE_MENU_ExitSprites(void *);
void IRC_COMPATIBLE_MENU_ExitDisplay(void *p) { func_02030EAC(*(struct Node * *)&((struct Obj22141 *)p)->f90); IRC_COMPATIBLE_MENU_ExitSprites(p); }
