/*
 * function: func_021B6AE4
 * address:  0x021B6AE4
 * packet:   pkt_ov067_021B6AE4
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     b and c are u16 as the matched caller ov067_func_021B6B2C passes
 *           them; the difference is written back into the parameter
 *           (`b = b - f()`): a separate u16 local y swapped p and b between
 *           r4/r5, and `b -= f()` truncates the call result first (worse).
 *
 * symbols:
 *   func_021B6C4C  0x021B6C4C  thumb  ov067
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern u32 func_021B6C4C(u32 a, u32 b, u32 c);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(u32 print, u32 bmp, s16 x, s16 y, u32 str, u32 font, u16 color);

void func_021B6AE4(u8 *p, u32 a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3)
{
    b = b - func_021B6C4C(s0, s1, s3);
    func_0201C724(a, (u32)func_02045770((struct Descriptor *)*(u32 *)p), b, c, s0, s1, s2);
    p[4] = 1;
}
