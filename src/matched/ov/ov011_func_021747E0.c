/*
 * function: INTRUDE_COMM_RecvReturnPending
 * address: 0x021747E0
 * packet: pkt_ov011_021747E0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_021743B4.c and filed here.
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_SetReturnSlotIfOffline 0x02162008 thumb ov010
 */

typedef unsigned short u16;
typedef unsigned char  u8;
void EVENT_FIELD_PROCLINK_SetReturnSlotIfOffline(u8 *p, u16 v);
void INTRUDE_COMM_RecvReturnPending(int a, int b, int c, u8 *p);

void INTRUDE_COMM_RecvReturnPending(int a, int b, int c, u8 *p)
{
    EVENT_FIELD_PROCLINK_SetReturnSlotIfOffline(p + 0x35c, (u16)a);
}
