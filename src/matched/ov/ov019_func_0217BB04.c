/*
 * function: UNION_ONESELF_HandleNetError
 * address: 0x0217BB04
 * packet: pkt_ov019_0217BB04
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   UNION_ONESELF_SetNextPlayCategory 0x0217B8E4 thumb ov019
 */
extern unsigned int func_0200FB24(void);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
int UNION_ONESELF_HandleNetError(char *p)
{
    if (func_0200FB24() != 0) {
        UNION_ONESELF_SetNextPlayCategory(p, 1);
        return 1;
    }
    return 0;
}
