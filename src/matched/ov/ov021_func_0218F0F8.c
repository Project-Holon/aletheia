/*
 * function: func_0218F0F8
 * address:  0x0218F0F8
 * packet:   pkt_ov021_0218F0F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

int func_0218F0F8(u8 *a)
{
    if (*(u32 *)(a + 0x1c) == 0)
        return 0;
    if (*(u32 *)(a + 0xec) != 0)
        return 1;
    return 0;
}
