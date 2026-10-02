/*
 * function: func_0218B310
 * address:  0x0218B310
 * packet:   pkt_ov021_0218B310
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219E418  0x0219E418  thumb  ov021
 */

void *func_021A3074(unsigned char *p);
int func_0219E418(int a, unsigned short b);

int func_0218B310(int a, unsigned char *s)
{
    if ((func_0219E418(func_021A3074((void *)a), *(unsigned short *)(s + 0x24)) & 3) == 0)
        return 1;
    return 0;
}
