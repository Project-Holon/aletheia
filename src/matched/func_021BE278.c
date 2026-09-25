/*
 * function: func_021BE278
 * address:  0x021BE278
 * packet:   pkt_021BE278
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BEB8C  0x021BEB8C  thumb  ov210
 *   func_021BF81C  0x021BF81C  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BEB8C(u8 *);
extern void func_021BF81C(u8 *);

void func_021BE278(u8 *p)
{
    u32 t = *(u32 *)p;
    *(u8 *)(*(u32 *)(t + 8) + 5) = 0xff;
    func_021BEB8C(p);
    func_021BF81C(p);
}

