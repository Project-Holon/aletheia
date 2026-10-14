/*
 * function: POKETRADE_NEGO_CloseCancelMenu
 * address: 0x021DD294
 * packet: pkt_ov119_021DD294
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_CloseTaskMenuWindow 0x021E2A1C thumb ov119
 */
#include "../include/Obj22738.h"
extern void POKETRADE_SAVE_CloseTaskMenuWindow(char *p, int a, int b);
void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b)
{
    if (((struct Obj22738 *)p)->f118C == 3)
        POKETRADE_SAVE_CloseTaskMenuWindow(p, a, b);
}
