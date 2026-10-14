/*
 * function: POKETRADE_2D_GetGridCellMon
 * address: 0x021E49DC
 * packet: pkt_ov119_021E49DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb ov119
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb ov119
 *   POKETRADE_PROC_GetSlotMonPtr 0x021D8E24 thumb ov119
 */
#include "../include/Obj22805.h"
extern int POKETRADE_PROC_GetBoxIndexForSlot(int, char *);
extern int POKETRADE_PROC_GetSlotIndexInBox(int, int);
extern char *POKETRADE_PROC_GetSlotMonPtr(int, int, char *);
char *POKETRADE_2D_GetGridCellMon(int a, int b, char *p)
{
    int n;
    if (a >= 2) {
        n = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
        return POKETRADE_PROC_GetSlotMonPtr(n, POKETRADE_PROC_GetSlotIndexInBox(a, b), p);
    }
    if (b < 3)
        return POKETRADE_PROC_GetSlotMonPtr(((struct Obj22805 *)p)->f630, a + b * 2, p);
    return 0;
}
