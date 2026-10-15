/*
 * function: GTSNEGO_DISP_OnRowCursorMoved
 * address: 0x021D444C
 * packet: pkt_ov120_021D444C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   GTSNEGO_DISP_MoveRowCursor 0x021D43BC thumb ov120
 */
#include "../include/Obj10385.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void APP_TASKMENU_WIN_SetActive(struct Obj *,u32);
extern int GTSNEGO_DISP_MoveRowCursor(int,char *);
int GTSNEGO_DISP_OnRowCursorMoved(int n,char *p) { int result; if(*(struct Obj * *)&((struct Obj10385 *)p)->f34) APP_TASKMENU_WIN_SetActive(*(struct Obj * *)&((struct Obj10385 *)p)->f34,0); result=GTSNEGO_DISP_MoveRowCursor(n,p); if(result) ((struct Obj10385 *)p)->f160=result; return 1; }
