/*
 * function: TR_AI_CompareDamage
 * address:  0x02189170
 * packet:   pkt_ov096_02189170
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_Compare  0x0218A0F4  thumb  ov096
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_CalcPredictedMoveDamage  0x021C7E14  thumb  ov093
 */
#include "../include/Obj06343.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int TR_AI_Compare(u8 *a, int op, int x, int y, int z);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021D59B4(u8 *p, int k);
extern u16 BTL_SERVER_FLOW_CalcPredictedMoveDamage(u8 *p, int a, int b, u32 c, int e0, int e1);

int TR_AI_CompareDamage(struct Cursor *a, int b, int c)
{
    int t;
    int w;
    int y;
    int z;
    int r;

    VM_GetU32(a);
    t = VM_GetU32(a);
    w = func_021D59B4(*(u8 * *)&((struct Obj06343 *)b)->fC0, 0xd);
    y = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj06343 *)b)->fBC);
    z = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj06343 *)b)->fC0);
    r = BTL_SERVER_FLOW_CalcPredictedMoveDamage((u8 *)(((struct Obj06343 *)b)->fB4), y, z, ((struct Obj06343 *)b)->f2, 1, 0);
    return TR_AI_Compare((u8 *)a, c, w, r, t);
}
