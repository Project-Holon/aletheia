/*
 * function: func_021AA69C
 * address:  0x021AA69C
 * packet:   pkt_ov021_021AA69C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02188C6C  0x02188C6C  thumb
 *   func_021A1BF4  0x021A1BF4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02188C6C(void *p);
extern u16 func_021A1BF4(u8 *p);

u8 func_021AA69C(void *p)
{
    switch (func_021A1BF4(func_02188C6C(p))) {
    case 2:
    case 6:
    case 7:
        return 2;
    case 3:
    case 12:
        return 4;
    case 4:
    case 5:
        return 3;
    }
    return 0;
}
