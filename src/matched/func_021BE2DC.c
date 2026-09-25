/*
 * function: func_021BE2DC
 * address:  0x021BE2DC
 * packet:   pkt_021BE2DC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF618  0x021BF618  thumb  ov210
 *   func_021BF81C  0x021BF81C  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BF618(u8 *);
extern void func_021BF81C(u8 *);

void func_021BE2DC(u8 *p)
{
    u32 t = *(u32 *)p;
    *(u8 *)(*(u32 *)(t + 8) + 6) = 0xff;
    func_021BF618(p);
    func_021BF81C(p);
}

