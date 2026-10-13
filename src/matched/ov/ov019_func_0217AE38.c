/*
 * function: UNION_CHARA_SetNextAction
 * address:  0x0217AE38
 * packet:   pkt_0217AE38
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

int UNION_CHARA_SetNextAction(char *p, char v)
{
    p[9] = v;
    return 1;
}
