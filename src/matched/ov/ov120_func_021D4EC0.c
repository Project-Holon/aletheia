/*
 * function: GTSNEGO_DISP_CreateConfirmUi
 * address: 0x021D4EC0
 * packet: pkt_ov120_021D4EC0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 *   GTSNEGO_MSG_ClearRows 0x021D7D3C thumb ov120
 *   GTSNEGO_DISP_RedrawActors 0x021D6814 thumb ov120
 *   GTSNEGO_DISP_OnRowCursorMoved 0x021D444C thumb ov120
 *   GTSNEGO_MSG_CreateListUi 0x021D7DC8 thumb ov120
 *   GTSNEGO_DISP_OnMenuCallback 0x021D4C98 thumb ov120
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   GTSNEGO_MSG_CreateTooltip 0x021D7ECC thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_HandleConfirmKeys 0x021D4D28 thumb ov120
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb  arm9
 */
#include "../include/Obj01253.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 GTSNEGO_DISP_GetTouchbar(u8 *p);
extern void TOUCHBAR_SetAllButtonsVisible(u8 *, u32);
typedef unsigned short u16;
struct Obj;
extern void GTSNEGO_MSG_ClearRows(char *p);
extern void GTSNEGO_DISP_RedrawActors(u8 *p);
extern int GTSNEGO_DISP_OnRowCursorMoved(int n, char *p);
extern void GTSNEGO_DISP_OnMenuCallback(void *p, int n, u8 *s);
extern void GTSNEGO_MSG_CreateListUi(char *p, int a, int b, int c, int d, int e);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern void *GTSNEGO_MSG_CreateTooltip(char *p, u16 n);
extern u8 func_020355C4(void);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void func_02041B6C(u32 bit);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_HandleConfirmKeys(u8 *p);
void GTSNEGO_DISP_CreateConfirmUi(u8 *p)
{
    ((struct Obj01253 *)p)->f138 = 0;
    TOUCHBAR_SetAllButtonsVisible((u8 *)GTSNEGO_DISP_GetTouchbar(((struct Obj01253 *)p)->f3C), 1);
    GTSNEGO_MSG_ClearRows(((struct Obj01253 *)p)->f40);
    GTSNEGO_DISP_RedrawActors(((struct Obj01253 *)p)->f3C);
    *(void (**)(int))(p + 4) = (void (*)(int))GTSNEGO_DISP_OnRowCursorMoved;
    GTSNEGO_MSG_CreateListUi(((struct Obj01253 *)p)->f40, (int)GTSNEGO_DISP_OnMenuCallback, (int)p, ((struct Obj01253 *)p)->f144, ((struct Obj01253 *)p)->f13C, ((struct Obj01253 *)p)->f140);
    GTSNEGO_MSG_PrintWindow(((struct Obj01253 *)p)->f40, 20);
    ((struct Obj01253 *)p)->f34 = GTSNEGO_MSG_CreateTooltip(((struct Obj01253 *)p)->f40, 18);
    if (func_020355C4() == 0) {
        GTSNEGO_DISP_SetCursorState(((struct Obj01253 *)p)->f3C, 0, ((struct Obj01253 *)p)->f160);
        if (((struct Obj01253 *)p)->f160 == 5)
            APP_TASKMENU_WIN_SetActive(((struct Obj01253 *)p)->f34, 1);
    } else {
        GTSNEGO_DISP_SetCursorState(((struct Obj01253 *)p)->f3C, 0, 9);
    }
    func_02041B6C(6);
    GTSNEGO_DISP_SetStateCallback((int *)p, (int)((void (*)(int))GTSNEGO_DISP_HandleConfirmKeys), 0x537);
}
