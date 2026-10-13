/*
 * function: EVENT_COMM_COMMON_StartMsgEvent95
 * address:  0x02182988
 * packet:   pkt_ov018_02182988
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save): tail call to EVENT_COMM_COMMON_StartMsgEvent with the
 * u16 table at 0x02183A20.
 *
 * symbols:
 *   EVENT_COMM_COMMON_StartMsgEvent  0x021828B8  thumb  ov018
 *   d_02183A20     0x02183A20  data   a2
 */

typedef unsigned short u16;

extern u16 d_02183A20[];

void EVENT_COMM_COMMON_StartMsgEvent(void *a, void *p, u16 *t);

void EVENT_COMM_COMMON_StartMsgEvent95(void *a, void *p)
{
    EVENT_COMM_COMMON_StartMsgEvent(a, p, d_02183A20);
}
