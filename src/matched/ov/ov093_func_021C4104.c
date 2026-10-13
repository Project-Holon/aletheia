/*
 * function: BTL_SERVER_FLOW_ProcSubstituteDamage
 * address:  0x021C4104
 * packet:   pkt_ov093_021C4104
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Opens with `push {r0-r3}`: the address of parameters 3-6 is taken; the
 * fifth and sixth parameters are one 8-byte struct passed by value.
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgSetPoke  0x021C5D88  thumb  ov093
 *   func_021C5840  0x021C5840  thumb  ov093
 *   BTL_SERVER_FLOW_PushCriticalHitMessage  0x021C59C4  thumb  ov093
 *   BTL_POKEPARAM_DamageSubstitute  0x021D6D9C  thumb  ov093
 *   BTL_SERVER_FLOW_RemoveSubstitute  0x021C41C0  thumb  ov093
 *   BTL_SERVER_FLOW_ProcDrainHeal  0x021C1DCC  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMoveCategoryEffect  0x021C1880  thumb  ov093
 *   BTL_SERVER_FLOW_ProcDamageEndEvents  0x021C4218  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { int a; u8 b; } S;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_PushMsgSetPoke(u8 *p, u8 *a, int b);
extern void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag);
extern void BTL_SERVER_FLOW_PushCriticalHitMessage(u8 *p, u32 n, u8 **a, u8 *b, int flag);
extern int BTL_POKEPARAM_DamageSubstitute(u8 *c, u16 *d);
extern void BTL_SERVER_FLOW_RemoveSubstitute(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_ProcDrainHeal(u8 *p, u8 *q, u32 a, u8 *b, u32 s);
extern void BTL_SERVER_FLOW_ProcMoveCategoryEffect(u8 *p, u8 *q, u32 a, u32 b, u32 s0, int s1);
extern void BTL_SERVER_FLOW_ProcDamageEndEvents(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);

u16 BTL_SERVER_FLOW_ProcSubstituteDamage(u8 *p, u32 q, u8 *c, u16 d, S s, u16 *e)
{
    u16 ev = *e;
    u8 sa = s.a;
    int m = BTL_POKEPARAM_GetPokeId(c);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x54, m, sa, ev);
    BTL_SERVER_FLOW_PushMsgSetPoke(p, c, 0x317);
    func_021C5840(p, 1, (int *)(&s), &c, 0);
    BTL_SERVER_FLOW_PushCriticalHitMessage(p, 1, &c, &s.b, 0);
    if (BTL_POKEPARAM_DamageSubstitute(c, &d))
        BTL_SERVER_FLOW_RemoveSubstitute(p, c);
    BTL_SERVER_FLOW_ProcDrainHeal(p, (u8 *)e, q, c, d);
    BTL_SERVER_FLOW_ProcMoveCategoryEffect(p, (u8 *)e, q, (u32)c, d, 1);
    BTL_SERVER_FLOW_ProcDamageEndEvents(p, (u8 *)q, c, (u8 *)e, s.a, d, s.b, 1);
    return d;
}
