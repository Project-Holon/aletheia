/*
 * function: func_0217FDF8
 * address:  0x0217FDF8
 * packet:   pkt_ov019_0217FDF8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203D1B4  0x0203D1B4  arm
 */

typedef unsigned char u8;

extern int func_0203D1B4(void);

int func_0217FDF8(u8 *p)
{
    int i;
    int n = 0;

    for (i = 0; i < 4; i++) {
        if (p[0x144 + i] == 1)
            n++;
    }
    if (n >= func_0203D1B4())
        return 1;
    return 0;
}
