/*
 * function: BTL_CALC_SlowStartBeginOnce
 * address: 0x021D8964
 * packet: pkt_ov093_021D8964
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_CALC_SlowStartBegin 0x021D8974 thumb ov093
 */
extern void BTL_CALC_SlowStartBegin(void *, int, int, int *);

void BTL_CALC_SlowStartBeginOnce(void *a, int b, int c, int *d)
{
    if (d[0] == 0) BTL_CALC_SlowStartBegin(a,b,c,d);
}
