/*
 * function: UNION_APP_SetQuitAccepted
 * address:  0x02183F7C
 * packet:   pkt_ov022_02183F7C
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * leaf:     Sole game blocker of assigned ov012 caller; root claim granted.
 */

typedef unsigned char u8;
typedef unsigned int u32;

void UNION_APP_SetQuitAccepted(u8 *p)
{
    p[0x12] = 1;
}
