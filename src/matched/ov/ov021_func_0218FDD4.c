/*
 * function: FIELD_CAMERA_LerpFx32
 * address:  0x0218FDD4
 * packet:   pkt_ov021_0218FDD4
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

int FIELD_CAMERA_LerpFx32(int *p, int *q, int n, int d)
{
    int x0 = *p;
    int x1 = *q;
    int diff;
    if (n == d)
        return x1;
    diff = x1 - x0;
    return x0 + diff * d / n;
}
