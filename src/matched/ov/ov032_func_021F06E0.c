/*
 * function: BEACON_VIEW_UpdateAchievements
 * address:  0x021F06E0
 * packet:   pkt_ov032_021F06E0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_CountDifferingRecords  0x021F0684  thumb  ov032
 *   GAME_BEACON_ACCESSOR_GetLanguage  0x02165C50  thumb  ov010
 *   BEACON_VIEW_AddHistoryId  0x021F079C  thumb  ov032
 *   _u32_div_f     0x0209C2B0  arm
 *   BEACON_VIEW_HasRepeatedDigits  0x021F0820  thumb  ov032
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void BEACON_VIEW_CountDifferingRecords(u8 *p, u8 *a, u8 *b);
extern u32 GAME_BEACON_ACCESSOR_GetLanguage(u32 x);
extern void BEACON_VIEW_AddHistoryId(u8 *p, int k);
extern int BEACON_VIEW_HasRepeatedDigits(u32 x);

void BEACON_VIEW_UpdateAchievements(u8 *p, u32 x, int y)
{
    u8 v[2];

    v[1] = 0;
    v[0] = 0;
    BEACON_VIEW_CountDifferingRecords(p, &v[0], &v[1]);
    if (GAME_BEACON_ACCESSOR_GetLanguage(x) != 2)
        BEACON_VIEW_AddHistoryId(p, 1);
    if (p[0x59] != v[1] && v[1] == 0x14)
        BEACON_VIEW_AddHistoryId(p, 2);
    if (((struct Obj00007 *)p)->f2D4 % 100 == 0)
        BEACON_VIEW_AddHistoryId(p, 3);
    if (y == 0x1d && p[0x7b] == 0x1e)
        BEACON_VIEW_AddHistoryId(p, 4);
    if (p[0x58] != v[0] && v[0] == 0x14)
        BEACON_VIEW_AddHistoryId(p, 5);
    if (BEACON_VIEW_HasRepeatedDigits(((struct Obj00007 *)p)->f2D4) != 0)
        BEACON_VIEW_AddHistoryId(p, 6);
    p[0x58] = v[0];
    p[0x59] = v[1];
}
