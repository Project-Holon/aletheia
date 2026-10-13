/*
 * function: UNION_ONESELF_SetNextPlayCategory
 * address:  0x0217B8E4
 * packet:   pkt_0217B8E4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int UNION_ONESELF_SetNextPlayCategory(char *p, int v)
{
    p[0x28a1] = v;
    return 1;
}
