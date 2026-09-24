/*
 * function: func_021B6620
 * address:  0x021B6620
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Delegate to func_021B65D8 unless the argument is 7.
 *
 * symbols:
 *   func_021B65D8  0x021B65D8  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021B65D8(void);

void func_021B6620(int x)
{
    if (x != 7) {
        func_021B65D8();
    }
}
