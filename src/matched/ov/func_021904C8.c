/*
 * function: FIELD_MSGBG_DeleteMsgData
 * address:  0x021904C8
 * packet:   pkt_02190490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to MSGDATA_Delete with no argument change.
 *
 * symbols:
 *   MSGDATA_Delete  0x02045C04  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);

u32 FIELD_MSGBG_DeleteMsgData(struct Rec *a0)
{
    return MSGDATA_Delete(a0);
}
