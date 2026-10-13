/*
 * function: DWCi_TPlCheckATrigger
 * address:  0x021D6B04
 * packet:   pkt_ov016_021D6B04
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_TPlCheckATrigger (libdwcutil.TWL.HYB.a input.o)
 *
 * notes:    const input lets all four halfwords load before the first store.
 *           The fold test reads the shared word at 0x02FFFFA8 through a
 *           volatile u16 cast (a fixed address, no variable, so the vendor
 *           DWARF has nothing to say about it either way).
 *
 * symbols:
 *   DWCi_TPlCheckTrigger  0x021D696C  arm  ov016
 */

typedef struct tagAREA { unsigned short x, y, w, h; } AREA;
typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

typedef unsigned short u16;
extern int DWCi_TPlCheckTrigger(u16 *a);

int DWCi_TPlCheckATrigger(const AREA *a)
{
    RECT r;

    if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
        return 0;
    r.l = a->x;
    r.t = a->y;
    r.r = a->x + a->w;
    r.b = a->y + a->h;
    return DWCi_TPlCheckTrigger((u16 *)(&r));
}
