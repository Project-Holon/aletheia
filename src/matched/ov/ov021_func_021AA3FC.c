/*
 * function: func_021AA3FC
 * address:  0x021AA3FC
 * packet:   pkt_ov021_021AA3FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_021AA6E0  0x021AA6E0  thumb
 *   func_021AA778  0x021AA778  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021AA778(void *p);
extern u32 func_021AA6E0(void);

int func_021AA3FC(void *a0, void *p, u32 rate)
{
    u32 r;

    if (rate > 100)
        rate = 100;
    r = func_021AA778(p);
    if (r == 0)
        return 0;
    if (r == 1)
        rate = 1;
    if (func_021AA6E0() <= rate)
        return 1;
    return 0;
}
