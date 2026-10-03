/*
 * function: func_021A3644
 * address:  0x021A3644
 * packet:   pkt_ov021_021A3644
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02188CFC  0x02188CFC  thumb
 *   func_021A54A0  0x021A54A0  thumb
 *   func_021A54B4  0x021A54B4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_02188CFC(u8 *p);
extern int func_021A54A0(void *p);
extern void func_021A54B4(u8 *p);

void func_021A3644(void **p)
{
    if (func_02188CFC(p[0]) == 0 && func_021A54A0(p[2]) == 1)
        func_021A54B4(p[2]);
}
