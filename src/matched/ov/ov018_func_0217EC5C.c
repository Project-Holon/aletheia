/*
 * function: INTRUDE_SUBDISP_IsInTouchRect
 * address: 0x0217EC5C
 * packet: pkt_ov018_0217EC5C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef struct { int l, t, r, b; } Rect;
int INTRUDE_SUBDISP_IsInTouchRect(int x, int y, const Rect *r)
{
    if (r->l < x && r->r > x && r->t < y && r->b > y) return 1;
    return 0;
}
