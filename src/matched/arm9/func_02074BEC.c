/*
 * function: func_02074BEC
 * address:  0x02074BEC
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02074324  0x02074324  arm
 *   func_02074CD0  0x02074CD0  arm
 *   func_02074F3C  0x02074F3C  arm
 *   func_0207466C  0x0207466C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02074324(int index);
extern u32 func_02074CD0(u32 a, u32 flags, u32 c, u32 d, u32 *out);
extern u32  func_02074F3C(u32 a, u32 b, u32 c);
extern u32  func_0207466C(u32 a);

u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    u8 *p = func_02074324(a);
    u32 r;

    if (p == 0) return 2;
    r = func_02074CD0(*(u16 *)(p + 4), b, c, d, 0);
    if (r != 0) return r;
    if (b & 1) {
        r = func_02074F3C(*(u32 *)p, c, d);
        if (r == 0) return 6;
    } else {
        r = func_0207466C(*(u32 *)p);
    }
    if (out != 0) *out = r;
    return 0;
}
