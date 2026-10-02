/*
 * function: func_0217EC44
 * address: 0x0217EC44
 * packet: pkt_ov018_0217EC44
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef struct { int l, t, r, b; } Rect;
void func_0217EC44(int x, int y, int w, int h, Rect *r)
{
    r->t = y - h;
    r->b = y + h;
    r->l = x - w;
    r->r = x + w;
}
