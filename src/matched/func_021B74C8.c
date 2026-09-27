/*
 * function: func_021B74C8
 * address:  0x021B74C8
 * packet:   pkt_ov180_021B74C8
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021B90CC     0x021B90CC  data  ov180  a4
 *   d_021B90E4     0x021B90E4  data  ov180  a4
 */

extern int d_021B90CC[6];
extern int d_021B90E4[7];

void func_021B74C8(int *base)
{
    unsigned i;

    for (i = 0; i < 6; i++) {
        ((int *)base)[i + 0x2433] = -1;
    }
    for (i = 0; i < 7; i++) {
        ((int *)base)[i + 0x2439] = -1;
    }
    for (i = 0; i < 6; i++) {
        ((int *)base)[i + 0x2440] = -1;
    }
}

