/*
 * function: BTL_MAIN_GetEnemyLanePosFromWork
 * address:  0x021B8C50
 * packet:   pkt_021B8C50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetEnemyLanePos  0x021B8C20  thumb  ov093
 */
#include "../include/Obj20968.h"

typedef unsigned char u8;
typedef unsigned int u32;

u8 BTL_MAIN_GetEnemyLanePos(int kind, u32 flags, u32 v);

u8 BTL_MAIN_GetEnemyLanePosFromWork(char **p, u32 v, int k)
{
    return BTL_MAIN_GetEnemyLanePos(((struct Obj20968 *)(*p))->f4, v, k);
}
