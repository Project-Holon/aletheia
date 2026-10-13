/*
 * file:     unit_0689ABA0.c
 * function: func_0689ABA0
 * address:  0x0689ABA0
 * packet:   pkt_ov095_0689ABA0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The byte and word out-parameters are one struct local: struct-member
 * loads are re-read after stores/calls (the reload of w for the (u8)
 * argument), and the compound `t.w &= ~0x8000` re-reads the member, which
 * is the second `ldr r1,[sp,#4]`.
 *
 * symbols:
 *   BTL_SLOT_GetRotateSrcIndex  0x021B9AB0  thumb
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb
 *   BTL_ACTION_SetFight  0x021D82D0  thumb
 *   BTL_ACTION_SetFightSlotFlag  0x021D8318  thumb
 *   BTL_ACTION_SetRotate  0x021D83FC  thumb
 *   BTL_CALC_ActionSetNone  0x021D8434  thumb
 *   func_022030F0  0x022030F0  thumb
 */
#include "../../matched/include/Obj04407.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_022030F0(u32 h, u8 *b, u32 *w);
extern int BTL_SLOT_GetRotateSrcIndex(u32 b);
extern u32 BTL_POKEPARAM_GetMoveId(u32 a, u32 b);
extern void BTL_ACTION_SetRotate(u8 *p, u32 b);
extern void BTL_ACTION_SetFight();
extern void BTL_ACTION_SetFightSlotFlag(u32 p);
extern void BTL_CALC_ActionSetNone(u32 p);

typedef struct { u8 b; u32 w; } T;

int func_0689ABA0(int unused, u8 *s)
{
    T t;
    u32 flag;
    u32 w;
    u32 v;

    if (func_022030F0(((struct Obj04407 *)s)->fB0, &t.b, &t.w)) {
        flag = (t.w & 0x8000) != 0;
        t.w &= ~0x8000;
        w = t.w;
        if (w != 4) {
            if (t.b == 0)
                t.b = 1;
            if (w != 7)
                v = BTL_POKEPARAM_GetMoveId(*(u32 *)(*(u32 *)&((struct Obj04407 *)s)->f7C + BTL_SLOT_GetRotateSrcIndex(t.b) * 8), (u8)t.w);
            else
                v = 0xa5;
            BTL_ACTION_SetRotate(*(u8 * *)&((struct Obj04407 *)s)->f7C + 0x18, t.b);
            BTL_ACTION_SetFight(*(u8 * *)&((struct Obj04407 *)s)->f7C + 0x1c, v, 6);
            BTL_ACTION_SetFight(((struct Obj04407 *)s)->f70, v, 6);
            if (flag)
                BTL_ACTION_SetFightSlotFlag(((struct Obj04407 *)s)->f70);
        } else if (w == 4) {
            BTL_CALC_ActionSetNone(((struct Obj04407 *)s)->f70);
        }
        return 1;
    }
    return 0;
}
