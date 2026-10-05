/*
 * function: func_021BB508
 * address:  0x021BB508
 * packet:   pkt_ov068_021BB508
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * 2026-10-05 P23L3: point-in-box test with unsigned range checks
 * (p - lo <= hi - lo) on each axis, results combined with a bitwise and.
 */

typedef unsigned int u32;

typedef struct {
    u32 x0;
    u32 y0;
    u32 x1;
    u32 y1;
} Box;

typedef struct {
    u32 x;
    u32 y;
} Pt;

u32 func_021BB508(const Box *b, const Pt *p)
{
    u32 inx = (p->x - b->x0) <= (b->x1 - b->x0);
    u32 iny = (p->y - b->y0) <= (b->y1 - b->y0);
    return inx & iny;
}
