/*
 * function: DRAW_SYSTEM_DrawLine
 * address: 0x021B6CA4
 * packet: pkt_ov172_021B6CA4
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 wD4 lane05: EXACT. Rewritten from the listing: const Shape table {u8 w, h; u8 m[32][32]}
 *   (const lets the t->w / t->h loop bounds hoist), u32 w/h locals, callee seen with u16 x/y, m1/m2 as
 *   `sx >= 0 ? 2 : 8`, px/py computed with ox/oy as copies inside an `if (n > 0)` around a do-while,
 *   and the abs values in the ternary macro form `(v < 0) ? -(v) : (v)` (fixes the y0/y1 colours).
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   gDrawBrushes 0x021C4E84 data a4
 *   DRAW_SYSTEM_PutPixel 0x021B6E5C thumb ov172
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct Shape {
    u8 w;
    u8 h;
    u8 m[32][32];
} Shape;
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern const Shape gDrawBrushes[];
extern void DRAW_SYSTEM_PutPixel(u16 *p, char *base, u16 x, u16 y, u16 v);

void DRAW_SYSTEM_DrawLine(u16 *a, char *b, int x0, int x1, u16 y0, u16 y1, int idx, u16 arg)
{
    const Shape *t = &gDrawBrushes[idx];
    int sx, sy, ax, ay, k;
    u8 m1, m2, j;
    int bx, by, ox, oy, n;
    int adx, ady, d, px, py;
    u8 fl, i;
    u32 w, h;
    adx = ((x0 - x1) < 0) ? -(x0 - x1) : (x0 - x1);
    ady = ((y0 - y1) < 0) ? -(y0 - y1) : (y0 - y1);
    n = (adx > ady ? adx : ady) + 1;
    d = x1 - x0;
    sx = _ffix(d > 0 ? _fadd(0.5f, _fflt(d << 12)) : _fsub(_fflt(d << 12), 0.5f)) / n;
    d = y1 - y0;
    sy = _ffix(d > 0 ? _fadd(0.5f, _fflt(d << 12)) : _fsub(_fflt(d << 12), 0.5f)) / n;
    ax = 0;
    ay = 0;
    w = t->w;
    h = t->h;
    px = x0 - (w >> 1);
    py = y0 - (h >> 1);
    m1 = (sx >= 0) ? 2 : 8;
    m2 = (sy >= 0) ? 4 : 1;
    k = 0;
    if (n > 0) {
    ox = px;
    oy = py;
    do {
        bx = ox + (ax >> 12);
        by = oy + (ay >> 12);
        if (k > 0) {
            fl = 0;
            if (bx != px) fl += m1;
            if (by != py) fl += m2;
        } else {
            fl = 0x1F;
        }
        for (j = 0; j < t->h; j++) {
            for (i = 0; i < t->w; i++) {
                if (t->m[j][i] & fl)
                    DRAW_SYSTEM_PutPixel(a, b, bx + i, by + j, arg);
            }
        }
        ax += sx;
        ay += sy;
        px = bx;
        py = by;
    } while (++k < n);
    }
}
