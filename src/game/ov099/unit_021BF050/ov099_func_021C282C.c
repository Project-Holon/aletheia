/*
 * function: func_021C282C
 * address:  0x021C282C
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */
typedef unsigned char u8;

extern int func_02082D44(const void *a, const void *b, int n);

int func_021C282C(u8 *p)
{
    u8 z[6] = {0, 0, 0, 0, 0, 0};

    return func_02082D44(z, p + 8, 6);
}
