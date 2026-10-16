/*
 * function: BTL_CLIENT_GetEscapeBlockerForSide
 * address:  0x021CF918
 * packet:   pkt_ov093_021CF918
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_CLIENT_IsHeldItemEffective  0x021CF89C  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_CLIENT_FindTrapper  0x021CF9B4  thumb  ov093
 */
#include "../include/Obj07774.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern int BTL_CLIENT_IsHeldItemEffective(u8 *p, void *q);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u32 BTL_CLIENT_FindTrapper(u8 *g, void *m, u8 *a, u16 *b);

u32 BTL_CLIENT_GetEscapeBlockerForSide(u8 *g, u8 *a, u16 *b)
{
    u32 i;
    u8 *m;
    u32 r;

    for (i = 0; i < g[0x11c]; i++) {
        m = BTL_SLOT_GetPokeParam(((struct Obj07774 *)g)->f118, (u8)i);
        if (BTL_POKEPARAM_IsFainted(m) == 0) {
            if (BTL_CLIENT_IsHeldItemEffective(g, m) != 0 && BTL_POKEPARAM_GetItem((struct QI *)m) == 0xe4)
                return 4;
            if (BTL_POKEPARAM_GetValue(m, 0x11) == 0x32)
                return 4;
        }
    }
    for (i = 0; i < g[0x11c]; i++) {
        r = BTL_CLIENT_FindTrapper(g, BTL_SLOT_GetPokeParam(((struct Obj07774 *)g)->f118, (u8)i), a, b);
        if (r != 4)
            return r;
    }
    return 4;
}
