/*
 * function: UNION_ONESELF_IsBattleStatus
 * address: 0x0217B9BC
 * packet: pkt_ov019_0217B9BC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
int UNION_ONESELF_IsBattleStatus(unsigned int x)
{
    if (x < 4 || x > 23) return 0;
    return 1;
}
