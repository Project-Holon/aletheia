/*
 * function: func_021B9AB8
 * address: 0x021B9AB8
 * packet: pkt_ov172_021B9AB8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Draws a line from (x0, y0) to (x1, y1) into a 4bpp tile buffer with func_021B9B88, in
 *   n = max(|dx|, |dy|) + 1 fixed-point steps (step = round(d << 12) / n).
 * lever (2026-10-05, wD9r lane157): value is a narrow parameter (u8 colour index) passed straight
 *   to a u8 callee parameter. With int value the stack-argument copy came first at entry; the narrow
 *   type puts the x0 spill store first (str r3; ldr value; str r2; str value), as in ov127 021C5C8C.
 *   Earlier levers kept: u8 x0 (reloaded at each use), Abs as a static inline ternary, y1/y0 copied
 *   into locals after the dx abs, the y0 read `*(u8 *)&y0` before the loop in an explicit
 *   `if (n > 0)` do/while, stepy declared before stepx.
 * symbols:
 *   func_021B9B88 0x021B9B88 thumb ov172
 *   func_0209BDBC 0x0209BDBC arm
 *   func_0209C95C 0x0209C95C arm
 *   func_0209CB8C 0x0209CB8C arm
 *   func_0209C494 0x0209C494 arm
 *   func_0209C0A4 0x0209C0A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int func_0209C0A4(int a, int b);
extern void func_021B9B88(u8 *p, u8 x, u8 y, u8 value);

static inline int Abs(int a)
{
    return a < 0 ? -a : a;
}

void func_021B9AB8(int a0, int a1, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, u8 value)
{
    int stepx, stepy;
    int dx = Abs(x0 - x1);
    int dy;
    int n, i;
    int accx, accy;
    int d, r;
    int ay; int by; int yb;
    by = y1; ay = y0; dy = Abs(ay - by);
    if (dx <= dy)
        dx = dy;
    n = dx + 1;
    d = x1 - x0;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepx = func_0209C0A4(func_0209C494(r), n);
    d = by - ay;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepy = func_0209C0A4(func_0209C494(r), n);
    accx = 0;
    accy = 0;
    i = 0;
    if (n > 0) {
        yb = *(u8 *)&y0;
        do {
            func_021B9B88(p, x0 + (accx >> 12), yb + (accy >> 12), value);
            accx += stepx;
            accy += stepy;
            i++;
        } while (i < n);
    }
}
