/*
 * function: BTL_SERVER_FLOW_NextFieldPokeIter
 * address:  0x021BD34C
 * packet:   pkt_ov093_021BD34C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_GetClientChecked  0x021BB85C  thumb  ov093
 *   BTL_SERVER_GetClientIfUsed  0x021BB878  thumb  ov093
 *   BTL_SLOT_GetPoke  0x021B9BF0  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 */
#include "../include/Obj13306.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *BTL_SERVER_GetClientChecked(u8 *p, unsigned int i);
extern u8 *BTL_SERVER_GetClientIfUsed(u8 *p, u32 i);
struct S2;
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *p);

int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *p, u8 **q, u8 **out)
{
    u8 *m;
    u8 *x;
    u8 n;
    int f;
    if (p[2] != 0) return 0;
    *out = (u8 *)BTL_SLOT_GetPoke((struct S2 *)(*(u8 **)(BTL_SERVER_GetClientChecked(*q, p[0]) + 4)), p[1]);
    p[1]++;
    while (p[0] < 4) {
        m = BTL_SERVER_GetClientIfUsed(*q, p[0]);
        if (m) {
            n = p[3] == 0 ? m[9] : 3;
            for (; p[1] < n; p[1]++) {
                x = (u8 *)BTL_SLOT_GetPoke((struct S2 *)(*(u8 * *)&((struct Obj13306 *)m)->f4), p[1]);
                if (x) f = BTL_POKEPARAM_IsFainted(x) == 0;
                else f = 0;
                if (f) return 1;
            }
        }
        p[0]++;
        p[1] = 0;
    }
    p[2] = 1;
    return 1;
}
