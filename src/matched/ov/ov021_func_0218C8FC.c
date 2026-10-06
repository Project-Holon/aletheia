/*
 * function: func_0218C8FC
 * address:  0x0218C8FC
 * packet:   pkt_ov021_0218C8FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218C43C  0x0218C43C  thumb  ov021
 */

typedef unsigned int   u32;
int func_0218C43C(u32 *st, int i);

int func_0218C8FC(unsigned char *p, int i)
{
    if (p == 0)
        return 0;
    return func_0218C43C((u32 *)(p + 0xC), i);
}
