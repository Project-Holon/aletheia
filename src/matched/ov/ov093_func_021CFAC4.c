/*
 * function: func_021CFAC4
 * address: 0x021CFAC4
 * packet: pkt_ov093_021CFAC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
extern int func_021D59B4(void *, int);
int func_021CFAC4(void *p, void *q)
{
    if (func_021D59B4(q, 17) != 23) return 1;
    return 0;
}
