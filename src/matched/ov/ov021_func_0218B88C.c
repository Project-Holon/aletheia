/*
 * function: func_0218B88C
 * address:  0x0218B88C
 * packet:   pkt_ov021_0218B88C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C934  0x0218C934  thumb  ov021
 */

void func_0218C934(void *p);

void func_0218B88C(unsigned char *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (((void **)(p + 0x1DC))[i] != 0)
            func_0218C934(((void **)(p + 0x1DC))[i]);
    }
}
