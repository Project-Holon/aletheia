/*
 * function: func_02185BBC
 * address:  0x02185BBC
 * packet:   pkt_ov023_02185BBC
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020436FC  0x020436FC  arm
 *   func_02045770  0x02045770  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 *
 * Clearing dx/dy before the w/h subtraction is what moves a1 into r0 at
 * entry (t in r1, the bound in r2); clearing it last keeps a1 in r1.
 */

extern int  func_020436FC(int a, int b, int c, int d, int e);
extern int  func_02045770(int a);
extern void func_020439A0(int, int, int, int, int, int, int, int, int);
extern void func_020437AC(int);

void func_02185BBC(int a0, int a1, int x, int y, int w, int h, int dx, int dy,
                   int mx, int my)
{
    int s;
    int t;

    if (dx < 0) {
        t = -dx;
        if (t > mx)
            t = mx;
        x += t;
        dx = 0;
        w -= t;
    }
    if (dy < 0) {
        t = -dy;
        if (t > my)
            t = my;
        y += t;
        dy = 0;
        h -= t;
    }
    s = func_020436FC(a1, 8, 8, 0x20, 0x28);
    func_020439A0(s, func_02045770(a0), x, y, dx, dy, w, h, 0);
    func_020437AC(s);
}
