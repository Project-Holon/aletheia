/*
 * function: MOVE_POKEMON_StartSkillOnTarget
 * address:  0x0215EC54
 * packet:   pkt_0215EC54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_SEARCH_SetCountValue  0x02165534  thumb  ov010
 *   FLD_WIPE_3DOBJ_CreateMapChangeEvent  0x021C8268  thumb
 */
#include "../include/Obj12043.h"
#include "../include/Obj17699.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int GAME_BEACON_SEARCH_SetCountValue();
extern int FLD_WIPE_3DOBJ_CreateMapChangeEvent();

int MOVE_POKEMON_StartSkillOnTarget(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
a0 = 0x13;
    a0 = GAME_BEACON_SEARCH_SetCountValue(a0);
loc_0215EC60:
a0 = ((struct Obj12043 *)t4)->f8;
a1 = ((struct Obj12043 *)t4)->f10;
a2 = ((struct Obj17699 *)t5)->f4;
    a0 = FLD_WIPE_3DOBJ_CreateMapChangeEvent(a0, a1, a2);
loc_0215EC6A:
    return a0;}
