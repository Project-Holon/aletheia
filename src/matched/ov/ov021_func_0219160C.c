/*
 * function: FIELD_MSGBG_OpenPlainWin
 * address:  0x0219160C
 * packet:   pkt_ov021_0219160C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TALKMSGWIN_ClearWindowFrame  0x02194A34  thumb  ov021
 */

typedef unsigned int   u32;
extern int TALKMSGWIN_ClearWindowFrame(u32 a, u32 b);

void FIELD_MSGBG_OpenPlainWin(int *p)
{
    TALKMSGWIN_ClearWindowFrame(p[4], p[6]);
}
