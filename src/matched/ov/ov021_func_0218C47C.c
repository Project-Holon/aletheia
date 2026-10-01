/*
 * function: func_0218C47C
 * address:  0x0218C47C
 * packet:   pkt_ov021_0218C47C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047828  0x02047828  arm
 */

int func_02047828(int h, unsigned short id, int *out);

int func_0218C47C(int *p, int id)
{
    int out;
    func_02047828(*p, id, &out);
    return out;
}
