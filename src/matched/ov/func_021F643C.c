/*
 * function: WORLDTRADE_BOX_StateDepositConfirmInput
 * address:  0x021F643C
 * packet:   pkt_021F643C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_UpdateTaskMenuYesNo  0x021F4D14  thumb  ov135
 *   WORLDTRADE_CloseTaskMenu  0x021F4CE4  thumb  ov135
 *   WORLDTRADE_BOX_TryConfirmDeposit  0x021F6474  thumb  ov135
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9

 * Two-way mode dispatch: mode 1 clears and runs the sub-step, mode 2 clears, releases the +0xdd0 word and latches state 1.
 */
#include "../include/Obj00045.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);
extern void WORLDTRADE_CloseTaskMenu(char *p);
extern void WORLDTRADE_BOX_TryConfirmDeposit(u8 *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

int WORLDTRADE_BOX_StateDepositConfirmInput(u8 *p)
{
    u32 k = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);

    if (k == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        WORLDTRADE_BOX_TryConfirmDeposit(p);
    } else if (k == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        BMP_MENUWORK_DrawWindowBorder((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 0);
        ((struct Obj00045 *)p)->f28 = 1;
    }
    return 2;
}
