/*
 * function: BTL_MAIN_GetEnemyLanePos
 * address:  0x021B8C20
 * packet:   pkt_ov093_021B8C20
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

u8 BTL_MAIN_GetEnemyLanePos(int kind, u32 flags, u32 v)
{
    if ((flags & 1) == 0) return v * 2 + 1;
    return v * 2;
}
