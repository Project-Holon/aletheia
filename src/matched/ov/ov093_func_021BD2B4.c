/*
 * function: BTL_SERVER_FLOW_InitFieldPokeIter
 * address:  0x021BD2B4
 * packet:   pkt_ov093_021BD2B4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_GetClientIfUsed  0x021BB878  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 */
#include "../include/Obj13305.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *BTL_SERVER_GetClientIfUsed(u8 *p, u32 i);
struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *p);

void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *p, u8 **q)
{
    u8 i = 0;
    u8 *m;
    u8 j;
    u8 *x;
    int f;
    p[0] = i;
    p[1] = i;
    p[2] = 1;
    p[3] = i;
    for (; i < 4; i++) {
        m = BTL_SERVER_GetClientIfUsed(*q, i);
        if (m == 0) continue;
        for (j = 0; j < m[9]; j++) {
            x = BTL_SLOT_GetPokeParam((struct S2 *)(*(u8 * *)&((struct Obj13305 *)m)->f4), j);
            if (x) f = BTL_POKEPARAM_IsFainted(x) == 0;
            else f = 0;
            if (f) {
                p[0] = i;
                p[2] = 0;
                p[1] = j;
                return;
            }
        }
    }
}
