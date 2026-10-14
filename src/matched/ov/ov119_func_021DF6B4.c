/*
 * function: POKETRADE_NEGO_IsMonPeerSelected
 * address: 0x021DF6B4
 * packet: pkt_ov119_021DF6B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb ov119
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb ov119
 */
#include "../include/Obj13904.h"
extern int POKETRADE_PROC_GetBoxIndexForSlot(int a, char *p);
extern int POKETRADE_PROC_GetSlotIndexInBox(int, int);
int POKETRADE_NEGO_IsMonPeerSelected(char *p, int a, int b)
{
    int x = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
    int y = POKETRADE_PROC_GetSlotIndexInBox(a, b);
    if (((struct Obj13904 *)p)->fF94 == y && ((struct Obj13904 *)p)->fF98 == x) {
        return 1;
    }
    return 0;
}
