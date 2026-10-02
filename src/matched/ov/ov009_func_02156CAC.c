/*
 * function: func_02156CAC
 * address: 0x02156CAC
 * packet: pkt_ov009_02156CAC
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Sole-blocker leaf for ov009_func_021552AC, root claim granted.
 * symbols:
 *   d_021A8264 0x021A8264 data ov009 a4
 */
typedef unsigned char u8;
extern u8 *d_021A8264;
int func_02156CAC(void)
{
    if (d_021A8264) {
        if (*(int *)(d_021A8264 + 0x754) == 6) return 1;
        return 0;
    }
    return 0;
}
