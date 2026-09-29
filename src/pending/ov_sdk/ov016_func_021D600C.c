/*
 * function: func_021D600C
 * address:  0x021D600C
 * packet:   pkt_ov016_021D600C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      DWCi_Coord2Rect (libdwcutil.TWL.HYB.a foundation.o)
 *
 * symbols:

 */

typedef struct tagCOORD { unsigned short x, y; } COORD;
typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

void func_021D600C(COORD *coord, COORD *size, RECT *rect)
{
    unsigned short x = coord->x;
    unsigned short y = coord->y;
    unsigned short w = size->x;
    unsigned short h = size->y;
    rect->l = x;
    rect->t = y;
    rect->r = x + w;
    rect->b = y + h;
}
