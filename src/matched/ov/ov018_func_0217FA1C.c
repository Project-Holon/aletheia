/*
 * function: EVENT_COMM_COMMON_FreeMissionInfoWork
 * address:  0x0217FA1C
 * packet:   pkt_ov018_0217FA1C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb  ov018
 */

void EVENT_COMM_COMMON_ExitMsgBox(void *p);

void EVENT_COMM_COMMON_FreeMissionInfoWork(void *p)
{
    EVENT_COMM_COMMON_ExitMsgBox(p);
}
