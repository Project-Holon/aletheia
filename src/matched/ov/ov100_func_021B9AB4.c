/*
 * function: func_021B9AB4
 * address: 0x021B9AB4
 * packet: pkt_ov100_021B9AB4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   POKEPARTY_GetBattleReadyCount 0x0201AA50 thumb
 */
#include "../include/Obj13708.h"
typedef unsigned int   u32;
extern u32 POKEPARTY_GetBattleReadyCount(void *p);
int func_021B9AB4(unsigned a)
{
 int x; int y;
 x=POKEPARTY_GetBattleReadyCount((void *)(*(int *)(((struct Obj13708 *)a)->f244+8)));
 y=POKEPARTY_GetBattleReadyCount((void *)(*(int *)(((struct Obj13708 *)a)->f244+12)));
 if(x>y) return y;
 return x;
}
