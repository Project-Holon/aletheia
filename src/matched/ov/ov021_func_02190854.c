/*
 * function: FIELD_MSGBG_ClearInfoMsgWin
 * address:  0x02190854
 * packet:   pkt_ov021_02190854
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 12-byte leaf: passes the second word of its argument to FIELD_MSGBG_ClearMsgPrint.
 *
 * symbols:
 *   FIELD_MSGBG_ClearMsgPrint  0x02190620  thumb  ov021
 */
typedef unsigned int u32;
extern int FIELD_MSGBG_ClearMsgPrint(u32 a);
void FIELD_MSGBG_ClearInfoMsgWin(u32 *p)
{
    FIELD_MSGBG_ClearMsgPrint(p[1]);
}
