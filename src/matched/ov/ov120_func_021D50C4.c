/*
 * function: GTSNEGO_DISP_OnExitMenuDone
 * address: 0x021D50C4
 * packet: pkt_ov120_021D50C4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   GTSNEGO_MSG_CloseMenu 0x021D8418 thumb ov120
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   GTSNEGO_MSG_CreateIdleUi 0x021D7550 thumb ov120
 *   GTSNEGO_MSG_PrintStatus 0x021D8520 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_StartMatchmaking 0x021D4B48 thumb ov120
 *   GTSNEGO_DISP_SetTradePalette 0x021D63F4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   GTSNEGO_MSG_RestartIconAnim 0x021D6FD8 thumb ov120
 *   GTSNEGO_DISP_CreateExitTooltip 0x021D50A0 thumb ov120
 */
#include "../include/Obj01151.h"
#include "../include/Obj22830.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void GTSNEGO_MSG_CloseMenu(int);
extern u32 GTSNEGO_DISP_GetTouchbar(u8 *p);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern void GTSNEGO_MSG_CreateIdleUi(u8 *p);
extern void GTSNEGO_MSG_PrintStatus(char *p, u16 n);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_StartMatchmaking(u8 *p);
extern void GTSNEGO_DISP_SetTradePalette(u8 *p, int flag, int mode);
extern u8 func_020355C4(void);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void GTSNEGO_MSG_RestartIconAnim(u8 *p, u32 flag);
extern void GTSNEGO_DISP_CreateExitTooltip(u8 *p);
void GTSNEGO_DISP_OnExitMenuDone(u8 *p)
{
    int state;
    if (APP_TASKMENU_IsFinish(((struct Obj01151 *)p)->f38)) {
        int zero;
        state = APP_TASKMENU_GetCursorPos(((struct Obj01151 *)p)->f38);
        GTSNEGO_MSG_CloseMenu(*(int *)&((struct Obj01151 *)p)->f38);
        zero = 0;
        *(int *)&((struct Obj01151 *)p)->f38 = zero;
        TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(((struct Obj01151 *)p)->f3C), 1, 1);
        switch (state) {
        case 0:
            GTSNEGO_MSG_PrintWindow(((struct Obj01151 *)p)->f40, 0xe);
            GTSNEGO_MSG_CreateIdleUi(((struct Obj01151 *)p)->f3C);
            GTSNEGO_MSG_PrintStatus(((struct Obj01151 *)p)->f40, 0xd);
            ((struct Obj01151 *)p)->f144 = zero;
            ((struct Obj01151 *)p)->f13C = zero;
            ((struct Obj01151 *)p)->f140 = zero;
            ((struct Obj22830 *)(*(u8 * *)&((struct Obj01151 *)p)->f48))->f1B0 = 3;
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_StartMatchmaking, 0x614);
            return;
        case 1:
            GTSNEGO_DISP_SetTradePalette(((struct Obj01151 *)p)->f3C, zero, zero);
            GTSNEGO_MSG_PrintWindow(((struct Obj01151 *)p)->f40, 0x13);
            if (func_020355C4() == 0)
                GTSNEGO_DISP_SetCursorState(((struct Obj01151 *)p)->f3C, 0, ((struct Obj01151 *)p)->f164);
            else
                GTSNEGO_DISP_SetCursorState(((struct Obj01151 *)p)->f3C, 0, 9);
            GTSNEGO_MSG_RestartIconAnim(((struct Obj01151 *)p)->f3C, 1);
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_CreateExitTooltip, 0x620);
            break;
        }
    }
}
