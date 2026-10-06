/*
 * function: func_0218C1A4
 * address:  0x0218C1A4
 * packet:   pkt_ov021_0218C1A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047910  0x02047910  arm
 */

int func_02047910(void *a, int idx, int amount);

void func_0218C1A4(int unused, int *s)
{
    int i;
    for (i = 0; i < 4; i++)
        func_02047910((void *)(*s), (unsigned short)i, 0x1000);
}
