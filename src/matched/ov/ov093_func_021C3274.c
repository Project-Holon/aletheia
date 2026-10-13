/*
 * function: BTL_SERVER_FLOW_ProcMoveRecoverHpAllTargets
 * address:  0x021C3274
 * packet:   pkt_ov093_021C3274
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C331C  0x021C331C  thumb  ov093
 *   func_021C332C  0x021C332C  thumb  ov093
 *   func_021C333C  0x021C333C  thumb  ov093
 *   BTL_SERVER_FLOW_TryRecoverHp  0x021C334C  thumb  ov093
 *   BTL_SERVER_FLOW_IsHpRecoverUnneeded  0x021C3370  thumb  ov093
 *   func_021C79E0  0x021C79E0  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj09969.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 pad[5]; u8 f : 1; } BF;

extern void func_021C331C(u32 c);
extern u32 func_021C332C(u32 c);
extern u32 func_021C333C(u32 c);
extern int BTL_SERVER_FLOW_TryRecoverHp(u8 *p, u8 *q, int a, int b);
extern int BTL_SERVER_FLOW_IsHpRecoverUnneeded(u8 *p, void *q);
extern u32 func_021C79E0(u8 *p, u32 x, u8 *a);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

void BTL_SERVER_FLOW_ProcMoveRecoverHpAllTargets(u8 *p, u32 q, u32 b, u32 c)
{
    u32 t;
    func_021C331C(c);
    for (t = func_021C332C(c); t != 0; t = func_021C333C(c)) {
        u8 m = BTL_POKEPARAM_GetPokeId((u8 *)t);
        if (BTL_SERVER_FLOW_IsHpRecoverUnneeded(p, (void *)t) == 0) {
            if (BTL_SERVER_FLOW_TryRecoverHp(p, (u8 *)t, (u16)func_021C79E0(p, q, (u8 *)t), 1) != 0) {
                BF *f = *(BF * *)&((struct Obj09969 *)p)->f4A8;
                if (!f->f)
                    f->f = 1;
                BTL_SERVER_CMD_PushVariable(((struct Obj09969 *)p)->fC, 0x5b, 387, m, 0xffff0000);
            }
        } else if (BTL_POKEPARAM_IsHpFull((u8 *)t) != 0) {
            BTL_SERVER_CMD_PushVariable(((struct Obj09969 *)p)->fC, 0x5b, 893, m, 0xffff0000);
        }
    }
}
