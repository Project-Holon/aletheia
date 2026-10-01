/*
 * function: func_021C7048
 * address: 0x021C7048
 * packet: pkt_ov136_021C7048
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
int func_021C7048(u8 *p)
{
    if (p[0x20] != 6) {
        *(int *)(p + 0x28) = 0x15;
        return 0;
    }
    *(int *)(p + 0x14) = 2;
    return 6;
}
