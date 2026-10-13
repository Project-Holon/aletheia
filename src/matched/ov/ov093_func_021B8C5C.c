/*
 * function: BTL_MAIN_GetFacingPos
 * address:  0x021B8C5C
 * packet:   pkt_ov093_021B8C5C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetEnemyLanePos  0x021B8C20  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 BTL_MAIN_GetEnemyLanePos(int kind, u32 flags, u32 v);

u8 BTL_MAIN_GetFacingPos(int kind, u32 flags)
{
    u8 x;
    switch (kind) {
    default:
    case 0:
        return BTL_MAIN_GetEnemyLanePos(kind, flags, 0);
    case 1:
        x = flags >> 1;
        return BTL_MAIN_GetEnemyLanePos(kind, flags, (u8)(1 ^ x));
    case 2:
        x = flags >> 1;
        if (x == 0) {
            x = 2;
        } else if (x == 2) {
            x = 0;
        }
        return BTL_MAIN_GetEnemyLanePos(kind, flags, x);
    case 3:
        return BTL_MAIN_GetEnemyLanePos(kind, flags, 0);
    }
}
