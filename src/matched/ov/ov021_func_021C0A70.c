/*
 * function: func_021C0A70
 * address:  0x021C0A70
 * packet:   pkt_ov021_021C0A70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns 1 when every one of the p[0x15] handles reports done.
 *
 * symbols:
 *   func_0218C8FC  0x0218C8FC  thumb  ov021
 */

typedef unsigned char u8;

extern int func_0218C8FC(unsigned char *p, int i);

int func_021C0A70(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++) {
        if (func_0218C8FC((unsigned char *)(((int *)(p + 0x1C))[i]), 0) != 1)
            return 0;
    }
    return 1;
}
