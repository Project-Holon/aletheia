/*
 * function: EVENT_COMM_COMMON_ChangeTalkedMsgEvent
 * address:  0x02180978
 * packet:   pkt_ov018_02180978
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   EVENT_COMM_COMMON_ChangeTalkMsgEvent  0x021808C4  thumb ov018
 */

void EVENT_COMM_COMMON_ChangeTalkMsgEvent(void *task, const void *src);

void EVENT_COMM_COMMON_ChangeTalkedMsgEvent(int id, void *dst)
{
    EVENT_COMM_COMMON_ChangeTalkMsgEvent((void *)id, dst);
}
