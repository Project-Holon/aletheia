/*
 * function: BTL_NET_FreePlayerInfoPacket
 * address:  0x021D4A64
 * packet:   pkt_021D4A64
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0   0x020307B0  arm arm9
 *   BTL_NET_FreePlayerInfoPacket   0x021D4A64  thumb ov093
 *
 * tail-call thunk to func_020307B0
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u32 func_020307B0(void *p);

void BTL_NET_FreePlayerInfoPacket(void *p)
{
    func_020307B0(p);
}
