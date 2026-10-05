/*
 * function: func_021C93D0
 * address: 0x021C93D0
 * packet: pkt_ov114_021C93D0
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D4084 0x021D4084 data a4
 */
extern unsigned d_021D4084[];
int func_021C93D0(void)
{
    switch (d_021D4084[0]) {
    case 1:
        return 1;
    case 12:
        d_021D4084[0] = 1;
        return 1;
    }
    return 0;
}
