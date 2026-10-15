/*
 * function: GTSNEGO_DISP_OnDisconnect
 * address: 0x021D4FF4
 * packet: pkt_ov120_021D4FF4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_IsConfirmFinished 0x021D8664 thumb ov120
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GTSNEGO_MSG_DeleteButtonsKeep 0x021D7EC4 thumb ov120
 *   GTSNEGO_DISP_ResetActors 0x021D68C4 thumb ov120
 *   GTSNEGO_DISP_SetTradePalette 0x021D63F4 thumb ov120
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   GTSNEGO_MSG_TeardownTileRows 0x021D6D94 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_Teardown 0x021D4FD0 thumb ov120
 */
#include "../include/Obj04485.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int GTSNEGO_MSG_IsConfirmFinished(u8 *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void GTSNEGO_MSG_DeleteButtonsKeep(u8 *p);
extern void GTSNEGO_DISP_ResetActors(u8 *p);
extern void GTSNEGO_DISP_SetTradePalette(u8 *p, int flag, int mode);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void func_02041B6C(u32 bit);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GTSNEGO_MSG_TeardownTileRows(u8 *p);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_Teardown(u8 *p);
void GTSNEGO_DISP_OnDisconnect(u8 *p)
{
    if (GTSNEGO_MSG_IsConfirmFinished(((struct Obj04485 *)p)->f40)) {
        BG_SYS_SetSubVisiblePlanes(8);
        GTSNEGO_MSG_DeleteButtonsKeep(((struct Obj04485 *)p)->f40);
        GTSNEGO_DISP_ResetActors(((struct Obj04485 *)p)->f3C);
        GTSNEGO_DISP_SetTradePalette(((struct Obj04485 *)p)->f3C, 0, 0);
        GTSNEGO_DISP_SetCursorState(((struct Obj04485 *)p)->f3C, 0, 9);
        func_02041B6C(5);
        if (((struct Obj04485 *)p)->f138 == 1) {
            func_02040588(4, 0);
            GTSNEGO_MSG_TeardownTileRows(((struct Obj04485 *)p)->f3C);
        }
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)((void (*)(int))GTSNEGO_DISP_Teardown), 0x5dd);
    }
}
