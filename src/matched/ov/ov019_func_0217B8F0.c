/*
 * function: UNION_ONESELF_SetNextPlayCategoryInMainPhase
 * address: 0x0217B8F0
 * packet: pkt_ov019_0217B8F0
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_ONESELF_SetNextPlayCategory 0x0217B8E4 thumb ov019
 */
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
int UNION_ONESELF_SetNextPlayCategoryInMainPhase(char *p, char v)
{
    if ((unsigned char)p[0x28a2] == 1) return UNION_ONESELF_SetNextPlayCategory(p, v);
    return 0;
}
