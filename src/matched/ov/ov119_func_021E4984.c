/*
 * function: POKETRADE_2D_ResolveGridCell
 * address: 0x021E4984
 * packet: pkt_ov119_021E4984
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb ov119
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb ov119
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 */
#include "../include/Obj00001.h"
extern int POKETRADE_PROC_GetBoxIndexForSlot(int, char *);
extern int POKETRADE_PROC_GetSlotIndexInBox(int, int);
extern void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);
int POKETRADE_2D_ResolveGridCell(int v, int a, int b, char *p, int *out)
{
    int n, m;
    if (a >= 2) {
        n = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
        m = POKETRADE_PROC_GetSlotIndexInBox(a, b);
        *out = 0;
        return (int)POKETRADE_PROC_LoadSlotMonAlt((void *)v, n, m, p);
    }
    if (b < 3) {
        *out = 1;
        return (int)POKETRADE_PROC_LoadSlotMonAlt((void *)v, ((struct Obj00001 *)p)->f630, a + b * 2, p);
    }
    return 0;
}
