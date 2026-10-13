/*
 * function: BTL_MAIN_GetFrontEnemyPos
 * address: 0x021B9A00
 * packet: pkt_ov093_021B9A00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_IsBackRowPos 0x021B99F0 thumb ov093
 *   BTL_MAIN_GetEnemyLanePos 0x021B8C20 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 BTL_MAIN_IsBackRowPos(u32);
extern u8 BTL_MAIN_GetEnemyLanePos(int, u32, u32);
int BTL_MAIN_GetFrontEnemyPos(u32 x, u8 *out)
{
    if (BTL_MAIN_IsBackRowPos(x) == 0) {
        *out = BTL_MAIN_GetEnemyLanePos(2, x, (u8)(x >> 1));
        return 1;
    }
    return 0;
}
