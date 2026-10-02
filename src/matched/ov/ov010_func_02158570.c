/*
 * function: func_02158570
 * address: 0x02158570
 * packet: pkt_ov010_02158570
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: The ternary loop condition preserves the branch to the bottom test.
 * symbols:
 *   d_021700AC 0x021700AC data a2
 */
typedef unsigned short u16;
extern const u16 d_021700AC[61];
int func_02158570(u16 value)
{
    unsigned int i;
    for (i = 0; (i < 61) ? 1 : 0; i++) {
        if (value == d_021700AC[i])
            return 1;
    }
    return 0;
}
