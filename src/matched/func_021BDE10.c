/*
 * function: func_021BDE10
 * address:  0x021BDE10
 * packet:   pkt_021BDE10
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02043658(void);
extern void func_02041EE4(u32, u32, u32);

void func_021BDE10(void)
{
    if (func_02043658() & 4) {
        func_02041EE4(2, 1, 1);
    }
}

