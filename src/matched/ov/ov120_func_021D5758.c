/*
 * function: GTSNEGO_DISP_WaitSelectStart
 * address: 0x021D5758
 * packet: pkt_ov120_021D5758
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_HandlePartyInput 0x021D5AD4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 */
#include "../include/Obj05345.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern u32 GTSNEGO_DISP_GetTouchbar(u8 *p);
extern void TOUCHBAR_SetAllButtonsVisible(u8 *p, u32 v);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_HandlePartyInput(u8 *p);
extern u8 func_020355C4(void);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
void GTSNEGO_DISP_WaitSelectStart(u8 *p)
{
    if (GTSNEGO_MSG_UpdatePrintStream(((struct Obj05345 *)p)->f40)) {
        if (--((struct Obj05345 *)p)->f14 <= 0) {
            GTSNEGO_MSG_PrintWindow(((struct Obj05345 *)p)->f40, 0x20);
            TOUCHBAR_SetAllButtonsVisible((u8 *)GTSNEGO_DISP_GetTouchbar(((struct Obj05345 *)p)->f3C), 1);
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_HandlePartyInput, 0x7c7);
            if (func_020355C4() == 0)
                GTSNEGO_DISP_SetCursorState(((struct Obj05345 *)p)->f3C, 0, ((struct Obj05345 *)p)->f15C);
        }
    }
}
