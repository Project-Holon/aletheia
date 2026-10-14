/*
 * function: POKETRADE_2D_GetBoxScreenEntry
 * address: 0x021E41A0
 * packet: pkt_ov119_021E41A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj13917.h"
unsigned short POKETRADE_2D_GetBoxScreenEntry(int i, int row, char *p, int mode)
{
    if (i >= ((struct Obj13917 *)p)->f638)
        i -= ((struct Obj13917 *)p)->f638;
    if (i < 12) {
        if (mode)
            return (*(unsigned short **)(p + 0x1180))[i + (row * 32 + 18)];
        else
            return (*(unsigned short **)(p + 0x1178))[i + (row * 32 + 18)];
    } else {
        i = (i - 12) % 20;
        if (mode)
            return (*(unsigned short **)(p + 0x117C))[i + (row * 32 + 18)];
        else
            return (*(unsigned short **)(p + 0x1174))[i + (row * 32 + 18)];
    }
}
