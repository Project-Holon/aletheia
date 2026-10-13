/*
 * function: BTL_NET_ExpectReplies
 * address:  0x021D4C58
 * packet:   pkt_021D4C58
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_NET_ResetReplySlots   0x021D4CEC  thumb ov093
 *   BTL_NET_ExpectReplies   0x021D4C58  thumb ov093
 *
 * tail-call thunk to BTL_NET_ResetReplySlots
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void BTL_NET_ResetReplySlots(void);

void BTL_NET_ExpectReplies(u32 a)
{
    BTL_NET_ResetReplySlots();
}
