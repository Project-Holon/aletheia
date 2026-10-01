/*
 * function: func_021C0598
 * address:  0x021C0598
 * packet:   pkt_ov021_021C0598
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Point-in-rectangle test against an active rect (EXACT*: trailing pad).
 */

typedef struct { int x, y, w, h, f10, active; } Rect;

int func_021C0598(int x, int y, const Rect *r)
{
    int l, t, rr, b;

    if (r->active == 0)
        return 0;
    l = r->x;
    t = r->y;
    rr = l + r->w - 1;
    b = t + r->h - 1;
    if (l <= x && x <= rr && t <= y && y <= b)
        return 1;
    return 0;
}
