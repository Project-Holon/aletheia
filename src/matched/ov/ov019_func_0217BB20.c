/*
 * function: UNION_ONESELF_CheckNetErrorExit
 * address: 0x0217BB20
 * packet: pkt_ov019_0217BB20
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_ONESELF_CheckNetError 0x0217BB04 thumb ov019
 *   UNION_ONESELF_SetNextPlayCategory 0x0217B8E4 thumb ov019
 */
extern int UNION_ONESELF_CheckNetError(char *);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
int UNION_ONESELF_CheckNetErrorExit(char *p)
{
    if (UNION_ONESELF_CheckNetError(p) == 1) {
        UNION_ONESELF_SetNextPlayCategory(p, 50);
        return 1;
    }
    return 0;
}
