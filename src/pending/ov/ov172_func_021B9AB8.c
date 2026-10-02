/*
 * function: func_021B9AB8
 * address:  0x021B9AB8
 * packet:   pkt_ov172_021B9AB8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Steps along the line from (a3, s0) to (s1, s2) in fixed point, calling func_021B9B88 per pixel.
 *
 * 2026-10-02 (C1-03): logic and callees are right (13 relocation sites resolve, same call
 * sequence and 208-byte extent). Remaining diff is register/spill shape only: the
 * original spills a3 to [sp,#4] first and reloads it for the first |a3-s1| (a3 never
 * lives in r3), then keeps s2/s0 in r4/r5 and re-reads s0 from the arg home in the
 * loop; ours keeps a3 in r3 and spills s0 to [sp,#8]. Tried: x0 local copy, ternary
 * abs, int params with (u8) casts (worse). Not tried: volatile or struct params.
 *
 * symbols:
 *   func_0209BDBC  0x0209BDBC  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_0209C494  0x0209C494  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_021B9B88  0x021B9B88  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern int func_0209BDBC(int a);
extern int func_0209C0A4(int a, int b);
extern int func_0209C494(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern void func_021B9B88(int a, u8 x, u8 y, int c);

void func_021B9AB8(int a0, int a1, int a2, int a3, u8 s0, u8 s1, u8 s2, int s3)
{
    int dx = a3 - s1;
    int dy, n, t, i, sx, sy, cx, cy;

    dx = (dx < 0) ? -dx : dx;
    dy = s0 - s2;
    dy = (dy < 0) ? -dy : dy;
    if (dx <= dy)
        dx = dy;
    n = dx + 1;
    t = s1 - a3;
    if (t > 0)
        t = func_0209C95C(0x3F000000, func_0209BDBC(t << 12));
    else
        t = func_0209CB8C(func_0209BDBC(t << 12), 0x3F000000);
    sx = func_0209C0A4(func_0209C494(t), n);
    t = s2 - s0;
    if (t > 0)
        t = func_0209C95C(0x3F000000, func_0209BDBC(t << 12));
    else
        t = func_0209CB8C(func_0209BDBC(t << 12), 0x3F000000);
    sy = func_0209C0A4(func_0209C494(t), n);
    cx = 0;
    cy = 0;
    for (i = 0; i < n; i++) {
        func_021B9B88(a2, (u8)(a3 + (cx >> 12)), (u8)(s0 + (cy >> 12)), s3);
        cx += sx;
        cy += sy;
    }
}
