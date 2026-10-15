/*
 * function: CTVT_COMM_PopStroke
 * address:  0x021B8BB8
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wraps the +0x1ac cursor; on a mismatch returns the +0x1ae slot base.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int CTVT_COMM_PopStroke(int a, unsigned char *p, int *out);

int CTVT_COMM_PopStroke(int a, unsigned char *p, int *out)
{
    unsigned char v = (unsigned char)(p[0x1ac] + 1);

    (void)a;
    if (v >= 0x40) {
        v -= 0x40;
    }
    if (v == p[0x1ad]) {
        *out = 1;
        return 0;
    }
    *out = 0;
    return (int)(p + 0x1ae + p[0x1ac] * 8);
}
