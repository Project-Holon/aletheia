/*
 * function: EVENT_COMM_COMMON_StartMsgEvent110Alt
 * address: 0x021829F8
 * packet: pkt_ov018_021829F8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02183A14 0x02183A14 data a2
 *   EVENT_COMM_COMMON_StartMsgEvent 0x021828B8 thumb ov018
 */

extern unsigned short d_02183A14[];
extern void EVENT_COMM_COMMON_StartMsgEvent(void *, void *, unsigned short *);
void EVENT_COMM_COMMON_StartMsgEvent110Alt(void *a, void *b) { EVENT_COMM_COMMON_StartMsgEvent(a,b,d_02183A14); }
