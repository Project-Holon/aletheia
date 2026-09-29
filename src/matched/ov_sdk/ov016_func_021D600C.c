/*
 * function: func_021D600C
 * address:  0x021D600C
 * packet:   pkt_ov016_021D600C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Coord2Rect (libdwcutil.TWL.HYB.a foundation.o)
 *
 * notes:    const inputs let all four halfwords load before the first store.
 *
 * symbols:

 */

typedef struct tagCOORD { unsigned short x, y; } COORD;
typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

void func_021D600C(const COORD *coord, const COORD *size, RECT *rect)
{
    rect->l = coord->x;
    rect->t = coord->y;
    rect->r = coord->x + size->x;
    rect->b = coord->y + size->y;
}
