/*
 * function: func_021BE0C4
 * address:  0x021BE0C4
 * packet:   pkt_ov210_021BE0C4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BFF18  0x021BFF18  thumb  ov210
 *   func_021BCE0C  0x021BCE0C  thumb  ov210
 *   func_021BC82C  0x021BC82C  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern void func_021BFF18(int p);
extern void func_021BCE0C(char *p, int delta);
extern void func_021BC82C(char *p, u8 b, u8 c);

u32 func_021BE0C4(u8 *p)
{
    func_021BFF18((int)p);
    func_021BCE0C((char *)p, 8);
    func_021BC82C((char *)p, 0, 16);
    return 1;
}
