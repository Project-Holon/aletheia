/*
 * function: BTL_SERVER_FLOW_ProcPokeChangeActions
 * address:  0x021BC220
 * packet:   pkt_ov093_021BC220
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_GetClientChecked  0x021BB85C  thumb  ov093
 *   BTL_SERVER_GetActionTableValue  0x021BB8A8  thumb  ov093
 *   BTL_SERVER_GetActionTableEntry  0x021BB8B0  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMemberIn  0x021BD9D4  thumb  ov093
 *   BTL_SERVER_FLOW_ProcAfterMemberIn  0x021BDA00  thumb  ov093
 *   BTL_SERVER_FLOW_ProcFaintRewards  0x021C5200  thumb  ov093
 *
 * BTL_SERVER_GetActionTableEntry returns a 4-byte bitfield struct: declaring it that way
 * (a u32 return with shifts and masks gives a different frame) is what
 * matches.
 */
#include "../include/Obj00003.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 a : 4;
    u32 b : 3;
    u32 c : 3;
    u32 d : 1;
} Bf;

extern u8 *BTL_SERVER_GetClientChecked(u8 *p, unsigned int i);
extern u8 BTL_SERVER_GetActionTableValue(u8 *p, u8 i);
extern Bf BTL_SERVER_GetActionTableEntry(u8 *p, u8 i, u8 j);
extern void BTL_SERVER_FLOW_ProcMemberIn(u8 *p, u8 i, u8 a, u8 b, int c);
extern int BTL_SERVER_FLOW_ProcAfterMemberIn(u8 *p);
extern int BTL_SERVER_FLOW_ProcFaintRewards(u8 *p);

int BTL_SERVER_FLOW_ProcPokeChangeActions(u8 *p, u8 *o)
{
    u32 i;
    u32 j;
    u32 n;
    Bf v;

    for (i = 0; i < 4; i++) {
        if (BTL_SERVER_GetClientChecked((u8 *)(*(int *)&((struct Obj00003 *)p)->f0), (u8)i) != 0) {
            n = BTL_SERVER_GetActionTableValue(o, i);
            for (j = 0; j < n; j++) {
                v = BTL_SERVER_GetActionTableEntry(o, i, j);
                if (v.a == 3 && v.d == 0)
                    BTL_SERVER_FLOW_ProcMemberIn(p, i, v.b, v.c, 1);
            }
        }
    }
    BTL_SERVER_FLOW_ProcAfterMemberIn(p);
    return BTL_SERVER_FLOW_ProcFaintRewards(p);
}
