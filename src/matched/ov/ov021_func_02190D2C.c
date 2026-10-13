/*
 * function: FIELD_MSGBG_CreateMsgStream
 * address:  0x02190D2C
 * packet:   pkt_ov021_02190D2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_CreateMsgStreamColor  0x02190C94  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern u32 *FIELD_MSGBG_CreateMsgStreamColor(u32 *a, u32 b, u32 c, u32 d, u16 e0, u32 f, u16 g);

u32 *FIELD_MSGBG_CreateMsgStream(u32 *a, u32 b, u32 c, u32 d, u16 e, u32 f)
{
    return FIELD_MSGBG_CreateMsgStreamColor(a, b, c, d, e, f, 0xF);
}
