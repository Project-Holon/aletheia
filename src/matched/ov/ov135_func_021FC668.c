/*
 * function: WORLDTRADE_DETAIL_StateConfirmYesNoInput
 * address: 0x021FC668
 * packet: pkt_ov135_021FC668
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * spelling: if/else keeps the first arm before the second compare; switch moved both compares ahead.
 * symbols:
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_DETAIL_DrawRequestWindow 0x021FCBF0 thumb ov135
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 */
#include "../include/Obj08186.h"
extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);
extern void WORLDTRADE_CloseTaskMenu(char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_DETAIL_DrawRequestWindow(char *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *p, unsigned kind);
int WORLDTRADE_DETAIL_StateConfirmYesNoInput(char *p)
{
    unsigned r;
    r = WORLDTRADE_UpdateTaskMenuYesNo(p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenu(p);
        ((struct Obj08186 *)p)->f28 = 2;
        ((struct Obj08186 *)p)->fEB4 = 1;
        WORLDTRADE_SetStateAndReturn((u8 *)p, 7, 8);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    } else if (r == 2) {
        WORLDTRADE_CloseTaskMenu(p);
        ((struct Obj08186 *)p)->f28 = 0;
        BMP_MENUWORK_DrawWindowBorder(((struct Obj08186 *)p)->fD40, 0);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    }
    return 2;
}
