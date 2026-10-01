/*
 * function: func_0218C934
 * address:  0x0218C934
 * packet:   pkt_ov021_0218C934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047A60  0x02047A60  arm
 */

void func_02047A60(int a, unsigned char *b);

void func_0218C934(unsigned char *p)
{
    if (p != 0)
        func_02047A60(*(int *)(p + 0xC), p + 0x24);
}
