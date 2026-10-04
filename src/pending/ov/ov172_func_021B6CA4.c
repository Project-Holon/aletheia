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
 * note 2026-10-04 wD2 lane01: not improved (266 bytes, 432 vs 440); breadth pass only, no new hypothesis beyond the wD1 note.
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   d_021C4E84 0x021C4E84 data a4
 *   func_021B6E5C 0x021B6E5C thumb ov172
 *
 *
 * note 2026-10-04 (wD1 lane03): DIFF, 266 bytes differ, compiled 432 vs 440. Semantics
 * believed right (line walk with 12-bit fixed steps, 0x402-byte mask table at d_021C4E84,
 * per-cell flags 0x1F first step, then +m1 on x change, +m2 on y change). Parameters:
 * (a, b, x0, x1, u16 y0, u16 y1, idx, u16 arg); y0/y1 are two stack u16 args (a by-value
 * struct was worse). Residue: original frame 0x50 with push {r3..}; it keeps the table
 * pointer t in a stack slot and reloads t[0]/t[1] for the loop bounds, holds x0=r5, y0=r4,
 * y1=r6, spills n to sp+0x10 and ox/oy only just before the loop. Ours spills ox/oy and h
 * early. Tried: single ffix over a ternary float (kept), u8 vs u32 w/h, no w/h locals (worse),
 * local declaration order (no change).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern char d_021C4E84[];
extern void func_021B6E5C(u16 *p, char *base, u32 x, u32 y, u16 v);

void func_021B6CA4(u16 *a, char *b, int x0, int x1, u16 y0, u16 y1, int idx, u16 arg)
{
    char *t = d_021C4E84 + idx * 0x402;
    int adx = x0 - x1;
    int ady, n, d, sx, sy, ax, ay, ox, oy, px, py, k;
    u8 m1, m2, fl, j, i;
    u32 w, h;
    if (adx < 0) adx = -adx;
    ady = y0 - y1;
    if (ady < 0) ady = -ady;
    n = (adx > ady ? adx : ady) + 1;
    d = x1 - x0;
    sx = _ffix(d > 0 ? _fadd(0.5f, _fflt(d << 12)) : _fsub(_fflt(d << 12), 0.5f)) / n;
    d = y1 - y0;
    sy = _ffix(d > 0 ? _fadd(0.5f, _fflt(d << 12)) : _fsub(_fflt(d << 12), 0.5f)) / n;
    ax = 0;
    ay = 0;
    w = *(u8 *)t;
    h = *(u8 *)(t + 1);
    ox = x0 - (w >> 1);
    oy = y0 - (h >> 1);
    m1 = (sx < 0) ? 8 : 2;
    m2 = (sy < 0) ? 1 : 4;
    px = ox;
    py = oy;
    for (k = 0; k < n; k++) {
        int bx = ox + (ax >> 12);
        int by = oy + (ay >> 12);
        if (k > 0) {
            fl = 0;
            if (bx != px) fl += m1;
            if (by != py) fl += m2;
        } else {
            fl = 0x1F;
        }
        for (j = 0; j < h; j++) {
            for (i = 0; i < w; i++) {
                if (*(u8 *)(t + j * 32 + i + 2) & fl)
                    func_021B6E5C(a, b, (u16)(bx + i), (u16)(by + j), arg);
            }
        }
        ax += sx;
        ay += sy;
        px = bx;
        py = by;
    }
}
