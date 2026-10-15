/*
 * function: POKETRADE_PROC_IsSlotVisible
 * address: 0x021DB4EC
 * packet: pkt_ov119_021DB4EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_GetSlotPosition 0x021DB4B4 thumb ov119
 */
#include "../include/Obj13893.h"
extern int POKETRADE_PROC_GetSlotPosition(int);
int POKETRADE_PROC_IsSlotVisible(char *p, int index)
{
    int position = POKETRADE_PROC_GetSlotPosition(index);
    int start = ((struct Obj13893 *)p)->f107C;
    if (start < position && start + 0xe0 > position)
        return 1;
    position += ((struct Obj13893 *)p)->f63C;
    if (start < position && start + 0xe0 > position)
        return 1;
    return 0;
}
