/*
 * function: MB_UTIL_MSG_GetTaskMenuResult
 * address: 0x021F19C8
 * packet: pkt_ov107_021F19C8
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 */
#include "../include/Obj13766.h"
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern unsigned char APP_TASKMENU_GetCursorPos(const unsigned char *);
int MB_UTIL_MSG_GetTaskMenuResult(unsigned char *a) { if(APP_TASKMENU_IsFinish(((struct Obj13766 *)a)->f3C)==1) return APP_TASKMENU_GetCursorPos(((struct Obj13766 *)a)->f3C)+1; return 0; }
