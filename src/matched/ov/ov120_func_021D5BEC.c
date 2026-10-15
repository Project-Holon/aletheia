/*
 * function: GTSNEGO_DISP_ResetScreen
 * address: 0x021D5BEC
 * packet: pkt_ov120_021D5BEC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GTSNEGO_MSG_DeleteDraw 0x021D846C thumb ov120
 *   GTSNEGO_DISP_SetTradePalette 0x021D63F4 thumb ov120
 *   func_02040588 0x02040588 arm
 *   GTSNEGO_MSG_Teardown 0x021D761C thumb ov120
 *   GTSNEGO_MSG_DeleteWindow 0x021D7B38 thumb ov120
 *   GTSNEGO_MSG_DeleteAll 0x021D883C thumb ov120
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_ShowPartySelect 0x021D588C thumb ov120
 */
#include "../include/Obj01056.h"
#include "../include/Obj22834.h"
#include "../include/Obj22835.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GTSNEGO_MSG_DeleteDraw(u8 *);
extern void GTSNEGO_DISP_SetTradePalette(u8 *p, int flag, int mode);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GTSNEGO_MSG_Teardown(u8 *p);
extern void GTSNEGO_MSG_DeleteWindow(char *p);
extern void GTSNEGO_MSG_DeleteAll(char *);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_ShowPartySelect(u8 *p);
void GTSNEGO_DISP_ResetScreen(u8 *p)
{
    if (((struct Obj22834 *)(*(u8 * *)&((struct Obj01056 *)p)->f48))->f1B0 != 1) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        GFL_NET_SetLoginOption(0);
        GTSNEGO_MSG_DeleteDraw(*(u8 * *)&((struct Obj01056 *)p)->f40);
        GTSNEGO_DISP_SetTradePalette(((struct Obj01056 *)p)->f3C, 0, 0);
        func_02040588(4, 0);
        GTSNEGO_MSG_Teardown(((struct Obj01056 *)p)->f3C);
        GTSNEGO_MSG_DeleteWindow((char *)(*(int *)&((struct Obj01056 *)p)->f40));
        GTSNEGO_MSG_DeleteAll(*(char * *)&((struct Obj01056 *)p)->f40);
        GTSNEGO_DISP_SetCursorState(((struct Obj01056 *)p)->f3C, 0, 9);
        ((struct Obj01056 *)p)->f1B0 = 1;
        ((struct Obj01056 *)p)->f1B4 = zero;
        ((struct Obj22835 *)(*(u8 * *)&((struct Obj01056 *)p)->f48))->f1B0 = 1;
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_ShowPartySelect, 0x937);
    }
}
