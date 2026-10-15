/*
 * function: GTSNEGO_DISP_OpenExitMenu
 * address: 0x021D5188
 * packet: pkt_ov120_021D5188
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   GTSNEGO_MSG_OpenMenuB 0x021D8358 thumb ov120
 *   GTSNEGO_DISP_SetTradePalette 0x021D63F4 thumb ov120
 *   GTSNEGO_MSG_RestartIconAnim 0x021D6FD8 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_OnExitMenuDone 0x021D50C4 thumb ov120
 */
#include "../include/Obj05344.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
extern u32 GTSNEGO_DISP_GetTouchbar(u8 *p);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void *GTSNEGO_MSG_OpenMenuB(char *p, int n);
extern void GTSNEGO_DISP_SetTradePalette(u8 *p, int flag, int mode);
extern void GTSNEGO_MSG_RestartIconAnim(u8 *p, u32 flag);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_OnExitMenuDone(u8 *p);
void GTSNEGO_DISP_OpenExitMenu(u8 *p)
{
    if (GTSNEGO_MSG_UpdatePrintStream(((struct Obj05344 *)p)->f40)) {
        TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(((struct Obj05344 *)p)->f3C), 1, 0);
        ((struct Obj05344 *)p)->f38 = GTSNEGO_MSG_OpenMenuB(((struct Obj05344 *)p)->f40, 1);
        GTSNEGO_DISP_SetTradePalette(((struct Obj05344 *)p)->f3C, 1, 1);
        GTSNEGO_MSG_RestartIconAnim(((struct Obj05344 *)p)->f3C, 0);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_OnExitMenuDone, 0x634);
    }
}
