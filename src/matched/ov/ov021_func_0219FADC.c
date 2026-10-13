/*
 * function: FLDMMDL_DRAW_CheckStepFrame
 * address:  0x0219FADC
 * packet:   pkt_ov021_0219FADC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

int FLDMMDL_DRAW_CheckStepFrame(u8 *p, int a, u8 *q)
{
    int m = p[3] % 20;
    u8 k = q[3];
    p[3] = m;
    if (k == 11) {
        if (a == 1) {
            if (m < 5 || m >= 15)
                return 1;
        } else {
            if (m < 10)
                return 1;
        }
    } else {
        if ((m >= 5 && m < 10) || m >= 15)
            return 1;
    }
    return 0;
}
