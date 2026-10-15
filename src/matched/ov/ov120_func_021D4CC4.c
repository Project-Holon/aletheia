/*
 * function: GTSNEGO_DISP_OnConfirmDone
 * address: 0x021D4CC4
 * packet: pkt_ov120_021D4CC4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   func_02041B6C 0x02041B6C arm
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   GTSNEGO_MSG_CreateIdleUi 0x021D7550 thumb ov120
 *   GTSNEGO_MSG_PrintStatus 0x021D8520 thumb ov120
 *   GTSNEGO_DISP_SetTradePalette 0x021D63F4 thumb ov120
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_StartMatchmaking 0x021D4B48 thumb ov120
 */
#include "../include/Obj03258.h"
#include "../include/Obj22829.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_02041B6C(u32 bit);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern void GTSNEGO_MSG_CreateIdleUi(u8 *p);
extern void GTSNEGO_MSG_PrintStatus(char *p, u16 n);
extern void GTSNEGO_DISP_SetTradePalette(u8 *p, int flag, int mode);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_StartMatchmaking(u8 *p);
void GTSNEGO_DISP_OnConfirmDone(u8 *p)
{
    if (APP_TASKMENU_WIN_IsFinish(((struct Obj03258 *)p)->f34)) {
        APP_TASKMENU_WIN_Delete(((struct Obj03258 *)p)->f34);
        *(int *)&((struct Obj03258 *)p)->f34 = 0;
        func_02041B6C(5);
        GTSNEGO_MSG_PrintWindow(((struct Obj03258 *)p)->f40, 14);
        GTSNEGO_MSG_CreateIdleUi(((struct Obj03258 *)p)->f3C);
        GTSNEGO_MSG_PrintStatus(((struct Obj03258 *)p)->f40, 13);
        GTSNEGO_DISP_SetTradePalette(((struct Obj03258 *)p)->f3C, 1, 2);
        ((struct Obj22829 *)(*(u8 * *)&((struct Obj03258 *)p)->f48))->f1B0 = 2;
        GTSNEGO_DISP_SetCursorState(((struct Obj03258 *)p)->f3C, 0, 9);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)((void (*)(int))GTSNEGO_DISP_StartMatchmaking), 0x460);
    }
}
