/*
 * function: SCRIPT_WORK_SetWorkValue
 * address:  0x02159030
 * packet:   pkt_02159030
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRIPT_WORK_GetWorkPtr  0x02158FE0  thumb  ov010
 */
#include "../include/Obj00020.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u16 *SCRIPT_WORK_GetWorkPtr(void *a, void *b, unsigned int id);

int SCRIPT_WORK_SetWorkValue(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;
    void *p;
    u16 *q;

t5 = a0 + 0;
a0 = *(int *)&((struct Obj00020 *)t5)->f10;
t6 = a1 + 0;
t4 = a2 + 0;
    p = GAMESYSTEM_GetGameData((const struct Ctx *)a0);
loc_0215903E:
    q = SCRIPT_WORK_GetWorkPtr((void *)t5, p, t6);
loc_02159048:
    if (q != 0) goto loc_02159050;
loc_0215904C:
a0 = 0;
    return a0;
loc_02159050:
*q = t4;
a0 = 1;
    return a0;}
