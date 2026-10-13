/*
 * function: INTRUDE_COMM_TakeNoticeState
 * address: 0x02175C40
 * packet: pkt_ov011_02175C40
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_SetNoticeState 0x02175C58 thumb ov011
 */
typedef unsigned char u8;
typedef struct { u8 pad[0x1a5]; u8 low:5; u8 value:2; u8 high:1; } Bits;
extern void INTRUDE_COMM_SetNoticeState(void *, int);
int INTRUDE_COMM_TakeNoticeState(void *p)
{
    int v;
    v = ((Bits *)p)->value;
    INTRUDE_COMM_SetNoticeState(p, 0);
    return v;
}
