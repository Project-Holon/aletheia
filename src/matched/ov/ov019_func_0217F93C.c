/*
 * function: UNION_EFF_AddAnimEffect
 * address:  0x0217F93C
 * packet:   pkt_ov019_0217F93C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_EFF_AddAnimObj  0x0217F9DC  thumb ov019
 */

typedef unsigned int   u32;
void UNION_EFF_AddAnimObj(char *p, u32 a);

void UNION_EFF_AddAnimEffect(int x, int y)
{
    if (x != 0)
        UNION_EFF_AddAnimObj((char *)x, y);
}
