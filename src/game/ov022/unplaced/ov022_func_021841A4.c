/*
 * function: UNION_APP_GetMemberCount
 * address:  0x021841A4
 * packet:   pkt_ov022_021841A4
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02080D24  0x02080D24  arm
 */

extern int func_02080D24(unsigned int x);

int UNION_APP_GetMemberCount(unsigned char *p)
{
    return func_02080D24(p[1]);
}
