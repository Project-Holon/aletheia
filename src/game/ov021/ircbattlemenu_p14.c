/*
 * file:     ircbattlemenu_p14.c
 * unit:     yes
 * function: func_021988F4, func_02198918
 * address:  0x021988F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021984C0 0x021984C0  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

extern void func_021984C0(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g, u32 h);
int func_021988F4(u8 *a);
int func_02198918(u8 *a);


int func_021988F4(u8 *a)
{
    func_021984C0(a, 1, 0x2000, 24, 3, 0, 0xA0, 0);
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_02198918(u8 *a)
{
    func_021984C0(a, 2, 0x2000, 24, 3, 0, 0xA0, 0);
    return 1;
}
