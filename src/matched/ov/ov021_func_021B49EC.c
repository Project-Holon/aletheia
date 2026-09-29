/*
 * function: func_021B49EC
 * address:  0x021B49EC
 * packet:   pkt_ov021_021B49EC
 * region:   ov021
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

int func_021B49EC(s16 *p, int max, int key)
{
    int s = *p;
    switch (key) {
    case -1:
        *p = s - 1;
        if (*p <= 0) *p = max;
        if (*p == s) return 0;
        return 2;
    case -10:
        *p = s - 10;
        if (*p <= 0) *p = 1;
        if (*p == s) return 0;
        return 2;
    case 1:
        *p = s + 1;
        if (*p > max) *p = 1;
        if (*p == s) return 0;
        return 1;
    case 10:
        *p = s + 10;
        if (*p > max) *p = max;
        if (*p == s) return 0;
        return 1;
    }
    return 0;
}
