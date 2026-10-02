/*
 * function: func_021BE20C
 * address:  0x021BE20C
 * packet:   pkt_ov210_021BE20C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BEA54  0x021BEA54  thumb  ov210
 *   func_021BF81C  0x021BF81C  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern void func_021BEA54(u8 *p);
extern void func_021BF81C(u8 *p);

void func_021BE20C(u8 *p)
{
    (*(u8 **)(*(u8 **)p + 8))[3] = 0xff;
    (*(u8 **)(*(u8 **)p + 8))[4] = 0xff;
    func_021BEA54(p);
    func_021BF81C(p);
}
