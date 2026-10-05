/*
 * function: func_021BE430
 * address:  0x021BE430
 * packet:   pkt_021BE430
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02035C60(void);
extern u32 func_020362DC(void);

u32 func_021BE430(void)
{
    if (func_02035C60() != 0 || func_020362DC() != 0) {
        return 1;
    }
    return 0;
}

