/*
 * function: func_021AC9D8
 * address:  0x021AC9D8
 * packet:   pkt_ov021_021AC9D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   d_021D90C0     0x021D90C0  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0216D83C(u32 a);
extern u32 func_0216D86C(u32 a);
extern u32 func_0216D608(u32 a);
extern u32 func_0216D804(u32 a);
extern u32 func_0216D81C(u32 a);
extern u8 d_021D90C0[];

int func_021AC9D8(u8 *p)
{
    u32 a = *(u32 *)(p + 8);
    u32 x = func_0216D83C(a);
    u32 y = func_0216D86C(a);
    u32 f = d_021D90C0[*(u32 *)(p + 0x24)];
    if (*(u32 *)(p + 0xc) == x && *(u32 *)(p + 0x10) == y)
        goto yes;
    if (f == 0 && func_0216D608(a) == 0) {
        x = func_0216D804(a);
        y = func_0216D81C(a);
        if (*(u32 *)(p + 0xc) == x && *(u32 *)(p + 0x10) == y)
            return 1;
    }
    return 0;
yes:
    return 1;
}
