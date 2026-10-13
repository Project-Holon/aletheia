/*
 * function: BTL_NET_GetClientReply
 * address:  0x021D4BD4
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_NET_GetClientReply   0x021D4BD4  thumb ov093
 *   BTL_NET_FindNetIdByClient   0x021D4394  thumb ov093
 *   FIELD_GIMMICK_D06_AttachStone   0x021F3B88  data
 *
 * Index a 0xBBC-stride table hanging off the pointer global at 0x021F3B88
 * plus 0xBF4, return the element's +0xBB8 halfword through *q.  The image
 * reaches 0xBBC and 0xBB8 by subtracting 0x38 and 0x3c from the 0xBF4 it
 * already has in r2 (mwcc's constant reuse), which the same expression here
 * reproduces.
 */
#include "../include/Obj18402.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *FIELD_GIMMICK_D06_AttachStone;

u8 BTL_NET_FindNetIdByClient(u32 a);

u16 BTL_NET_GetClientReply(int a, u8 **q)
{
    u8 *p = FIELD_GIMMICK_D06_AttachStone + 0xbf4 + BTL_NET_FindNetIdByClient(a) * 0xbbc;
    *q = p;
    return ((struct Obj18402 *)p)->fBB8;
}
