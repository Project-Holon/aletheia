/*
 * function: BTL_CLIENT_AnyMemberHasMoveVsTarget
 * address:  0x021D055C
 * packet:   pkt_ov093_021D055C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_CALC_GetScanStartIndex  0x021D7F2C  thumb  ov093
 *   BTL_CLIENT_HasSlotInOrder  0x021CFBBC  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_CLIENT_HasMoveWithAffinityVsTarget  0x021D0644  thumb  ov093
 */
#include "../include/Obj00340.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Q1;
struct S2;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u32 BTL_MAIN_GetRule(void **p);
extern u8 BTL_CALC_GetScanStartIndex(u32 a, u8 b);
typedef signed char    s8;
extern int BTL_CLIENT_HasSlotInOrder(s8 *p, int v);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_CLIENT_HasMoveWithAffinityVsTarget(void *g, void *m, void *a, int b);

int BTL_CLIENT_AnyMemberHasMoveVsTarget(u8 *g, void *a, int b)
{
    u32 n;
    u32 i;

    n = BTL_SLOT_GetCount(((struct Obj00340 *)g)->f118);
    i = BTL_CALC_GetScanStartIndex(BTL_MAIN_GetRule(((struct Obj00340 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (BTL_CLIENT_HasSlotInOrder((s8 *)g, (u8)i) == 0) {
            if (BTL_CLIENT_HasMoveWithAffinityVsTarget(g, BTL_SLOT_GetPokeParam(((struct Obj00340 *)g)->f118, (u8)i), a, b))
                return 1;
        }
    }
    return 0;
}
