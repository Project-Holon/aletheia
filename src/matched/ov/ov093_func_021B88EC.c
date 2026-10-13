/*
 * function: BTL_MAIN_ExpandPosTriple
 * address:  0x021B88EC
 * packet:   pkt_ov093_021B88EC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_IsBackRowPos  0x021B99F0  thumb  ov093
 *   BTL_MAIN_GetEnemyLanePosFromWork  0x021B8C50  thumb  ov093
 *   BTL_MAIN_GetEnemyLanePos  0x021B8C20  thumb  ov093
 *   BTL_MAIN_GetOwnLanePos  0x021B8C38  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_MAIN_IsBackRowPos(u32 x);
extern u8 BTL_MAIN_GetEnemyLanePosFromWork(char **p, u32 v, int k);
extern u8 BTL_MAIN_GetEnemyLanePos(int kind, u32 flags, u32 v);
extern u8 BTL_MAIN_GetOwnLanePos(u32 flags, u32 v);

u8 BTL_MAIN_ExpandPosTriple(void *p, u32 k, u32 v, u8 *out)
{
    u8 b = BTL_MAIN_IsBackRowPos(v);
    u8 x;

    switch (k) {
    case 0:
    case 1:
    default:
        if (b) {
            out[0] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 0);
            out[1] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 1);
            out[2] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 2);
            return 3;
        }
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 1);
        x = (u8)(v >> 1);
        if (x == 0) x = 2;
        else if (x == 2) x = 0;
        out[1] = BTL_MAIN_GetEnemyLanePos(2, v, x);
        return 2;
    case 6:
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 0);
        out[1] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 1);
        out[2] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 2);
        return 3;
    case 7:
        out[0] = BTL_MAIN_GetOwnLanePos(v, 0);
        out[1] = BTL_MAIN_GetOwnLanePos(v, 1);
        out[2] = BTL_MAIN_GetOwnLanePos(v, 2);
        return 3;
    case 8:
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 0);
        out[1] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 1);
        out[2] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 2);
        out[3] = BTL_MAIN_GetOwnLanePos(v, 0);
        out[4] = BTL_MAIN_GetOwnLanePos(v, 1);
        out[5] = BTL_MAIN_GetOwnLanePos(v, 2);
        return 6;
    case 2:
        if (b) {
            out[0] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 0);
            out[1] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 1);
            out[2] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 2);
            out[3] = BTL_MAIN_GetOwnLanePos(v, 0);
            out[4] = BTL_MAIN_GetOwnLanePos(v, 2);
            return 5;
        }
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 1);
        x = (u8)(v >> 1);
        if (x == 0) x = 2;
        else if (x == 2) x = 0;
        out[1] = BTL_MAIN_GetEnemyLanePos(2, v, x);
        out[2] = BTL_MAIN_GetOwnLanePos(v, 1);
        return 3;
    case 3:
        if (b) {
            out[0] = v;
            out[1] = BTL_MAIN_GetOwnLanePos(v, 0);
            out[2] = BTL_MAIN_GetOwnLanePos(v, 2);
            return 3;
        }
        out[0] = v;
        out[1] = BTL_MAIN_GetOwnLanePos(v, 1);
        return 2;
    case 9:
        if (b) {
            out[0] = BTL_MAIN_GetOwnLanePos(v, 0);
            out[1] = BTL_MAIN_GetOwnLanePos(v, 2);
            return 2;
        }
        out[0] = BTL_MAIN_GetOwnLanePos(v, 1);
        return 1;
    case 4:
        if (b) {
            out[0] = BTL_MAIN_GetOwnLanePos(v, 0);
            out[1] = BTL_MAIN_GetOwnLanePos(v, 2);
            return 2;
        }
        out[0] = BTL_MAIN_GetOwnLanePos(v, 1);
        return 1;
    case 5:
        if (b) {
            out[0] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 0);
            out[1] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 1);
            out[2] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 2);
            out[3] = BTL_MAIN_GetOwnLanePos(v, 0);
            out[4] = BTL_MAIN_GetOwnLanePos(v, 2);
            out[5] = v;
            return 6;
        }
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 1);
        x = (u8)(v >> 1);
        if (x == 0) x = 2;
        else if (x == 2) x = 0;
        out[1] = BTL_MAIN_GetEnemyLanePos(2, v, x);
        out[2] = BTL_MAIN_GetOwnLanePos(v, 1);
        out[3] = v;
        return 4;
    }
}
