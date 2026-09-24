/*
 * function: func_021B8B5C
 * address:  0x021B8B5C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two arm9 calls in sequence.
 *
 * symbols:
 *   sub_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void sub_020399A8(void);
extern void func_0203D1A4(void);

void func_021B8B5C(void)
{
    sub_020399A8();
    func_0203D1A4();
}
