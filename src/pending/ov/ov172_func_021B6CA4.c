/*
 * function: func_021B6CA4
 * address: 0x021B6CA4
 * packet: pkt_ov172_021B6CA4
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-02 (relaunch) 65 bytes left, logic and loop shape now match. Keys found: the glyph
 *   table is const (g->w/g->h loads are not killed by the calls, which gives the hoisted bound and
 *   the guard that reuses w); w/h are u32 (lsrs); lx/ly compare against the previous px/py;
 *   c is u16; real func_021B6E5C prototype with (u16) casts on x/y. Residue: (1) y0/y1 colours
 *   swapped (orig y0=r4, y1=r6); (2) the hoisted (u16)(py + row) temp gets slot sp+0x10 instead of
 *   sp+0x4c, which shifts n/ox/oy/... by 4; (3) the ox/oy spill stores land before the n>0 guard,
 *   the original puts them after it (loop preheader). Inert: x0/x1 as u16, dx/dy statement order,
 *   lx/ly order, ox/oy copies before the loop vs in the for init (the for init is closest),
 *   CSE form px = x0 - (w >> 1) + (cx >> 12), yy as a declared u16 local.
 * symbols:
 *   func_0209BDBC 0x0209BDBC arm
 *   func_0209C0A4 0x0209C0A4 arm
 *   func_0209C494 0x0209C494 arm
 *   func_0209C95C 0x0209C95C arm
 *   func_0209CB8C 0x0209CB8C arm
 *   func_021B6E5C 0x021B6E5C thumb ov172
 *   d_021C4E84 0x021C4E84 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u8 w;
    u8 h;
    u8 px[32][32];
} Glyph;

extern int func_0209BDBC(int a);
extern int func_0209C0A4(int a, int b);
extern int func_0209C494(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern void func_021B6E5C(u16 *p, char *base, unsigned x, unsigned y, u16 v);
extern const Glyph d_021C4E84[];

void func_021B6CA4(u16 *o, char *t, int x0, int x1, u16 y0, u16 y1, int idx, u16 c)
{
    const Glyph *g = &d_021C4E84[idx];
    int sx, sy, cx, cy, i;
    u8 fx, fy, row;
    int px, py, ox, oy, n;
    u32 w, h;
    int lx, ly, dx, dy, d;
    u8 m, col;

    dx = x0 - x1;
    dx = (dx < 0) ? -dx : dx;
    dy = y0 - y1;
    dy = (dy < 0) ? -dy : dy;
    if (dx <= dy)
        dx = dy;
    n = dx + 1;
    d = x1 - x0;
    if (d > 0)
        d = func_0209C95C(0x3F000000, func_0209BDBC(d << 12));
    else
        d = func_0209CB8C(func_0209BDBC(d << 12), 0x3F000000);
    sx = func_0209C0A4(func_0209C494(d), n);
    d = y1 - y0;
    if (d > 0)
        d = func_0209C95C(0x3F000000, func_0209BDBC(d << 12));
    else
        d = func_0209CB8C(func_0209BDBC(d << 12), 0x3F000000);
    sy = func_0209C0A4(func_0209C494(d), n);
    cx = 0;
    cy = 0;
    w = g->w;
    h = g->h;
    lx = x0 - (w >> 1);
    ly = y0 - (h >> 1);
    fx = (sx >= 0) ? 2 : 8;
    fy = (sy >= 0) ? 4 : 1;
    for (ox = lx, oy = ly, i = 0; i < n; i++) {
        px = ox + (cx >> 12);
        py = oy + (cy >> 12);
        if (i > 0) {
            m = 0;
            if (px != lx)
                m += fx;
            if (py != ly)
                m += fy;
        } else {
            m = 0x1F;
        }
        for (row = 0; row < g->h; row++) {
            for (col = 0; col < g->w; col++) {
                if (g->px[row][col] & m)
                    func_021B6E5C(o, t, (u16)(px + col), (u16)(py + row), c);
            }
        }
        cx += sx;
        cy += sy;
        lx = px;
        ly = py;
    }
}
