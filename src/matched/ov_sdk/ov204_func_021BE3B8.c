/*
 * function: func_021BE3B8
 * address:  0x021BE3B8
 * packet:   pkt_021BE3B8
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
extern int func_02005F38(void);

u32 func_021BE3B8(void)
{
    if (func_02005F38() != 0) {
        return 1;
    }
    return 0;
}

