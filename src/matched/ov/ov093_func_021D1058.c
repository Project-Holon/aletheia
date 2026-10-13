/*
 * function: BTL_CLIENT_TrySetRotateAction
 * address:  0x021D1058
 * packet:   pkt_ov093_021D1058
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SLOT_GetRotateSrcIndex  0x021B9AB0  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_ACTION_SetRotate  0x021D83FC  thumb  ov093
 */
#include "../include/Obj13369.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_SLOT_GetRotateSrcIndex(int k);
struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void BTL_ACTION_SetRotate(u32 *p, u32 sub);

int BTL_CLIENT_TrySetRotateAction(u8 *s, void *q)
{
    int k;

    k = 2;
    if (BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(((struct Obj13369 *)s)->f118, (u8)BTL_SLOT_GetRotateSrcIndex(2))) == 0) {
        BTL_ACTION_SetRotate(q, k);
        return 4;
    }
    k = 3;
    if (BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(((struct Obj13369 *)s)->f118, (u8)BTL_SLOT_GetRotateSrcIndex(3))) == 0) {
        BTL_ACTION_SetRotate(q, k);
        return 4;
    }
    return 0;
}
