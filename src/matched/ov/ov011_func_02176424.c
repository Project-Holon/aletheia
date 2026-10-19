/*
 * function: INTRUDE_COMM_TallyOutcomesAndResetIfComplete
 * address: 0x02176424
 * packet: pkt_ov011_02176424
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_ResetOutcomes 0x021763BC thumb ov011
 */
typedef unsigned char u8;
extern void INTRUDE_COMM_ResetOutcomes(u8 *p);
int INTRUDE_COMM_TallyOutcomesAndResetIfComplete(u8 *p, u8 *a, u8 *b)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (p[i + 6] == 0) return 0;
        if (p[i + 6] == 1) (*a)++;
        else (*b)++;
    }
    INTRUDE_COMM_ResetOutcomes(p);
    return 1;
}
