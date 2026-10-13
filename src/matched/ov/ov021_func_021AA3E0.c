/*
 * function: FIELD_ENCOUNT_GetEncountRate
 * address:  0x021AA3E0
 * packet:   pkt_ov021_021AA3E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Tab { u8 pad00[0xC]; u8 *f0C; };

int FIELD_ENCOUNT_GetEncountRate(struct Tab *t, int i, int add)
{
    int v;

    if (i >= 7)
        return 0;
    v = t->f0C[i];
    if (v > 0)
        v += add;
    if (v < 0)
        v = 0;
    return v;
}
