/*
 * function: BTL_MAIN_GetOwnLanePos
 * address:  0x021B8C38
 * packet:   pkt_ov093_021B8C38
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

u8 BTL_MAIN_GetOwnLanePos(u32 flags, u32 v)
{
    if ((flags & 1) == 0) return v * 2;
    return v * 2 + 1;
}
