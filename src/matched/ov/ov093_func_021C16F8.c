/*
 * function: BTL_SERVER_FLOW_ProcDamageAftereffect
 * address:  0x021C16F8
 * packet:   pkt_ov093_021C16F8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The empty `case 3: break;` is what keeps the `cmp r4, #3` and the
 * unconditional branch; a plain `if (k == 3) {}` compiles differently.
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_RunDamageAftereffectEvent  0x021C1758  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);
extern u32 func_021CC8D8(void *lock, int line);
extern void BTL_SERVER_FLOW_RunDamageAftereffectEvent(u8 *p, u8 *a, int k);
extern void func_021CC95C(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_ProcDamageAftereffect(u8 *p, u8 *a, int k)
{
    u32 s;
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    switch (k) {
    case 1:
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x202, n, 0xffff0000);
        return;
    case 3:
        break;
    }
    s = func_021CC8D8(p + 0x1d74, 0x1a04);
    BTL_SERVER_FLOW_RunDamageAftereffectEvent(p, a, k);
    func_021CC95C((u32 *)(p + 0x1d74), s, 0x1a07);
}
