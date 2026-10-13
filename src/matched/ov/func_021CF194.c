/*
 * function: COMM_ENTRY_RecvJoinRequest
 * address:  0x021CF194
 * packet:   pkt_021CF194
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   COMM_ENTRY_MENU_AddMember  0x021CD624  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 COMM_ENTRY_MENU_AddMember(u32, u32, u32, u32, u32);

int COMM_ENTRY_RecvJoinRequest(u32 a, u32 b, u32 c, u32 d)
{
return COMM_ENTRY_MENU_AddMember(d, a, c, *(u8 *)((u8 *)((c + 38))), (c + 32));
}

