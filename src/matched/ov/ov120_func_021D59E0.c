/*
 * function: GTSNEGO_DISP_OnPartyMenuDone
 * address: 0x021D59E0
 * packet: pkt_ov120_021D59E0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   GTSNEGO_MSG_CloseMenu 0x021D8418 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_StartWipe 0x021D44AC thumb ov120
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   GTSNEGO_DISP_SetTradePalette 0x021D63F4 thumb ov120
 *   GTSNEGO_DISP_HandlePartyInput 0x021D5AD4 thumb ov120
 */
#include "../include/Obj01928.h"
#include "../include/Obj22833.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void GTSNEGO_MSG_CloseMenu(int);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_StartWipe(int *p);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern u8 func_020355C4(void);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern u32 GTSNEGO_DISP_GetTouchbar(u8 *p);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void GTSNEGO_DISP_SetTradePalette(u8 *p, int flag, int mode);
extern void GTSNEGO_DISP_HandlePartyInput(u8 *p);
void GTSNEGO_DISP_OnPartyMenuDone(u8 *p)
{
    int state;
    if (APP_TASKMENU_IsFinish(((struct Obj01928 *)p)->f38)) {
        state = APP_TASKMENU_GetCursorPos(((struct Obj01928 *)p)->f38);
        GTSNEGO_MSG_CloseMenu(*(int *)&((struct Obj01928 *)p)->f38);
        *(int *)&((struct Obj01928 *)p)->f38 = 0;
        switch (state) {
        case 0:
            ((struct Obj22833 *)(*(u8 * *)&((struct Obj01928 *)p)->f48))->f1B0 = 1;
            ((struct Obj01928 *)p)->f14 = 0;
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_StartWipe, 0x8b5);
            return;
        case 1:
            if (((struct Obj01928 *)p)->f184 == 0)
                GTSNEGO_MSG_PrintWindow(((struct Obj01928 *)p)->f40, 0x20);
            else
                GTSNEGO_MSG_PrintWindow(((struct Obj01928 *)p)->f40, 0x2b);
            if (func_020355C4() == 0)
                GTSNEGO_DISP_SetCursorState(((struct Obj01928 *)p)->f3C, 0, ((struct Obj01928 *)p)->f15C);
            TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(((struct Obj01928 *)p)->f3C), 1, 1);
            GTSNEGO_DISP_SetTradePalette(((struct Obj01928 *)p)->f3C, 0, 0);
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_HandlePartyInput, 0x8c3);
            break;
        }
    }
}
