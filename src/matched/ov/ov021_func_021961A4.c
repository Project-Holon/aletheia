/*
 * function: func_021961A4
 * address:  0x021961A4
 * packet:   pkt_ov021_021961A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   func_02021730  0x02021730  thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02021518(u32 a);
extern void func_0202155C(u32 h, u32 a, u32 b, u32 c);
extern void func_020216D4(u32 h, u32 a, u32 b, u32 c);
extern void func_02021FD8(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02021730(u32 h, u32 a);
extern void func_020215A0(u32 h, u32 a);
extern void func_02021540(u32 h);
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207E5D0(void *p, u32 a, u32 size);
extern void func_0207E468(void *p, u32 a, u32 size);

void func_021961A4(u8 *p, u32 a, u32 b)
{
    u32 h;
    u32 n;
    void *d;

    h = func_02021518(*(u16 *)(p + 0x10));
    func_0202155C(h, a, 0x200, *(u16 *)(p + 0x10));
    n = b << 5;
    func_020216D4(h, a, 0, n);
    func_02021FD8(h, a, 0, (b << 20) >> 16, 6, 0);
    d = (void *)func_02021730(h, a);
    DC_FlushRange(d, n);
    if (a != 1) {
        if (a == 3)
            func_0207E5D0(d, 0, n);
    } else {
        func_0207E468(d, 0, n);
    }
    func_020215A0(h, a);
    func_02021540(h);
}
