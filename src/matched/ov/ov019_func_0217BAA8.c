/*
 * function: UNION_ONESELF_CheckEntryParties
 * address:  0x0217BAA8
 * packet:   pkt_ov019_0217BAA8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_IsBattleStatus  0x0217B9BC  thumb  ov019
 *   UNION_ONESELF_LoadRegulation  0x0217BA10  thumb  ov019
 *   UNION_ONESELF_CheckMyParty  0x0217BA48  thumb  ov019
 *   UNION_ONESELF_CheckBattleTeamParty  0x0217BA6C  thumb  ov019
 */

extern int UNION_ONESELF_IsBattleStatus(unsigned int x);
extern void UNION_ONESELF_LoadRegulation(char *p, int x);
extern int UNION_ONESELF_CheckMyParty(char *p, unsigned int *mask);
extern int UNION_ONESELF_CheckBattleTeamParty(char *p, unsigned int *mask);

int UNION_ONESELF_CheckEntryParties(int a, int b, int *p, int *q)
{
    int r, t;
    *p = 0;
    *q = 0;
    if (UNION_ONESELF_IsBattleStatus(b) == 0)
        return 1;
    UNION_ONESELF_LoadRegulation((char *)a, b);
    r = UNION_ONESELF_CheckMyParty((char *)a, (unsigned int *)p);
    t = UNION_ONESELF_CheckBattleTeamParty((char *)a, (unsigned int *)q);
    if (r == 0 || t == 0)
        return 1;
    return 0;
}
