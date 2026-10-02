/*
 * function: func_0218C02C
 * address:  0x0218C02C
 * packet:   pkt_ov021_0218C02C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Entry of the d_021D3D58 dispatch table (pool word 0x0218C02D at +0x0 and
 * +0x18), called by func_0218BFB4 as fn(a, out): clears out[2..5].
 *
 * symbols:
 */

typedef unsigned int u32;

void func_0218C02C(void *a, u32 *out)
{
    int i;

    for (i = 0; i < 4; i++) {
        out[2 + i] = 0;
    }
}
