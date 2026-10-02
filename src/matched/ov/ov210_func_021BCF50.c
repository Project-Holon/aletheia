/*
 * function: func_021BCF50
 * address:  0x021BCF50
 * packet:   pkt_ov210_021BCF50
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C0894  0x021C0894  data  a4
 *   func_021BED68  0x021BED68  thumb  ov210
 *   func_021BE3D4  0x021BE3D4  thumb  ov210
 *   func_021C93E4  0x021C93E4  thumb  ov212
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
typedef u32 (*StateFn)(u8 *);
extern StateFn d_021C0894[];
extern void func_021BED68(u8 *p);
extern void func_021BE3D4(u8 *p);
extern void func_021C93E4(u32 a, u32 b, u8 *c);

u32 func_021BCF50(u8 *p)
{
    u32 s = *(u32 *)(p + 0x10);

    s = d_021C0894[s](p);
    *(u32 *)(p + 0x10) = s;
    if (s == 0x1b) {
        return 0;
    }
    func_021BED68(p);
    func_021BE3D4(p);
    func_021C93E4(2, 6, p + 0x2c4);
    return 1;
}
