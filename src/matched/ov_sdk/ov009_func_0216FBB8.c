/*
 * function: func_0216FBB8
 * address:  0x0216FBB8
 * packet:   pkt_ov009_0216FBB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IsPrivateAddr (dwc_match.o)
 *
 * symbols:

 */

int func_0216FBB8(unsigned long addr_in_netorder)
{
    unsigned long addr_in_hostorder;
    unsigned char a, b;

    addr_in_hostorder = ((addr_in_netorder >> 24) & 0xff) | ((addr_in_netorder >> 8) & 0xff00) | ((addr_in_netorder << 8) & 0xff0000) | ((addr_in_netorder << 24) & 0xff000000);
    a = (addr_in_hostorder & 0xff000000) >> 24;
    b = (addr_in_hostorder & 0xff0000) >> 16;
    if (a == 10)
        return 1;
    if (a == 172 && b >= 16 && b <= 31)
        return 1;
    if (a == 192 && b == 168)
        return 1;
    return 0;
}
