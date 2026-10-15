/*
 * function: fwide
 * address:  0x02096508
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note:     the trailing star is the two unlabelled leaves that follow in the
 *           word run -- wcslen (0x02096578) and wcscpy
 *           (0x02096594), both matched in this window -- so the listing extent
 *           runs to 0x020965B4.  Wants seeds for both addresses in
 *           layout/function_starts.txt.
 */
#include "../include/Obj00749.h"

typedef unsigned char u8;
typedef unsigned int u32;

int fwide(u8 *p, int v)
{
    u32 f;

    if (p == 0 || ((((struct Obj00749 *)p)->f4 << 22) >> 29) == 0)
        return 0;

    f = ((struct Obj00749 *)p)->f4;
    switch ((f << 20) >> 30) {
    case 0:
        if (v > 0)
            ((struct Obj00749 *)p)->f4 = (f & ~0xc00u) | 0x800u;
        else if (v < 0)
            ((struct Obj00749 *)p)->f4 = (f & ~0xc00u) | 0x400u;
        break;
    case 1:
        v = -1;
        break;
    case 2:
        v = 1;
        break;
    }
    return v;
}
