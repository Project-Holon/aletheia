/*
 * function: func_021B9AB8
 * address: 0x021B9AB8
 * packet: pkt_ov172_021B9AB8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-04): draft is logic-correct (186 byte diff, 206 vs 208 bytes). Residue: original keeps x0 and p
 *   purely on the stack (str r3,[sp,#4] first; x0 reloaded each use) and holds y1,y0 in r4,r5 across the
 *   float-round calls, re-reading y0 from the stack arg in the loop pre-header; mine copies x0 to r1 and
 *   spills y0 to [sp,#8] early. Tried: u8 vs one-field struct stack params, struct x0, ternary max,
 *   declaration order of accumulators, u8 callee params. None changed the allocation.
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
extern void func_021B9B88(u8 *p, u8 x, u8 y, int value);

void func_021B9AB8(int a0, int a1, u8 *p, int x0, u8 y0, u8 x1, u8 y1, int value)
{
    int dx = x0 - x1;
    int dy;
    int n, i;
    int stepx, stepy;
    int accx, accy;
    int d, r;
    if (dx < 0)
        dx = -dx;
    dy = y0 - y1;
    if (dy < 0)
        dy = -dy;
    if (dx <= dy)
        dx = dy;
    n = dx + 1;
    d = x1 - x0;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepx = func_0209C0A4(func_0209C494(r), n);
    d = y1 - y0;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepy = func_0209C0A4(func_0209C494(r), n);
    accx = 0;
    accy = 0;
    for (i = 0; i < n; i++) {
        func_021B9B88(p, x0 + (accx >> 12), y0 + (accy >> 12), value);
        accx += stepx;
        accy += stepy;
    }
}
