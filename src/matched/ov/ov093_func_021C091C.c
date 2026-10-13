/*
 * function: BTL_SERVER_FLOW_ProcMoveHitTargets
 * address: 0x021C091C
 * packet: pkt_ov093_021C091C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_RunMoveUsedEventLocked 0x021C19D8 thumb ov093
 *   func_021C0A1C 0x021C0A1C thumb ov093
 *   BTL_SERVER_FLOW_CalcMultiHitCount 0x021C71E0 thumb ov093
 *   BTL_SERVER_FLOW_RemoveSelfProtectedTargets 0x021C14E0 thumb ov093
 *   func_021C0A2C 0x021C0A2C thumb ov093
 *   BTL_SERVER_FLOW_GetHitFlagsMultiHit 0x021C1194 thumb ov093
 *   func_021C0A3C 0x021C0A3C thumb ov093
 *   BTL_SERVER_FLOW_ProcMultiHitDamage 0x021C0F24 thumb ov093
 *   BTL_SERVER_FLOW_ProcDamageTargets 0x021C0D90 thumb ov093
 *   BTL_SERVER_FLOW_ProcDamageAbsorbRecovery 0x021C2048 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveAfterDamageEvents 0x021C1A54 thumb ov093
 *   BTL_SERVER_FLOW_PushPendingHpRecovery 0x021BFBD0 thumb ov093
 */
#include "../include/Obj00003.h"
#include "../include/Obj04358.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { u8 pad[5]; u8 a:1; u8 b:1; };
extern void BTL_SERVER_FLOW_RunMoveUsedEventLocked(u8 *, u8 *, u8 *);
extern void func_021C0A1C(u8 *);
extern int BTL_SERVER_FLOW_CalcMultiHitCount(u8 *, u8 *, u32, u8 *);
extern void BTL_SERVER_FLOW_RemoveSelfProtectedTargets(u8 *, u8 *, int, u8 *);
extern int func_021C0A2C(u8 *);
extern u8 BTL_SERVER_FLOW_GetHitFlagsMultiHit(u8 *p);
extern int func_021C0A3C(u8 *);
extern u32 BTL_SERVER_FLOW_ProcMultiHitDamage(u8 *, u8 *, u8 *, u8 *, u32);
extern u32 BTL_SERVER_FLOW_ProcDamageTargets(u8 *, u8 *, u8 *, u8 *, u32, u32 *, u32);
extern void BTL_SERVER_FLOW_ProcDamageAbsorbRecovery(u8 *, u8 *, u32, u32);
extern void BTL_SERVER_FLOW_ProcMoveAfterDamageEvents(u8 *, u8 *, u8 *, u8 *, u32, u32);
extern void BTL_SERVER_FLOW_PushPendingHpRecovery(u8 *, u32, u8 *, u32);
void BTL_SERVER_FLOW_ProcMoveHitTargets(u8 *p, u8 *q, u8 *a, u8 *b, u32 c, u32 d)
{
    u32 result = 0;
    int flag = 0;
    u32 out;
    p[0x1fe9] = 0;
    BTL_SERVER_FLOW_RunMoveUsedEventLocked(p, a, q);
    func_021C0A1C(*(u8 * *)&((struct Obj00003 *)p)->f860);
    BTL_SERVER_FLOW_CalcMultiHitCount(p, a, ((struct Obj04358 *)q)->f0, *(u8 * *)&((struct Obj00003 *)p)->f4B4);
    BTL_SERVER_FLOW_RemoveSelfProtectedTargets(p, a, (int)q, b);
    if (func_021C0A2C(b) != 0) {
        if (BTL_SERVER_FLOW_GetHitFlagsMultiHit(*(u8 * *)&((struct Obj00003 *)p)->f4B4) != 0 && func_021C0A3C(b) == 1) {
            result = BTL_SERVER_FLOW_ProcMultiHitDamage(p, q, a, b, c);
        } else {
            result = BTL_SERVER_FLOW_ProcDamageTargets(p, q, a, b, c, &out, d);
            flag = 1;
        }
        BTL_SERVER_FLOW_ProcDamageAbsorbRecovery(p, a, ((struct Obj04358 *)q)->f0, result);
    }
    BTL_SERVER_FLOW_ProcMoveAfterDamageEvents(p, q, a, *(u8 * *)&((struct Obj00003 *)p)->f860, result, d);
    if (flag != 0) {
        struct State *s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a == 0) {
            s->a = 1;
            s->b = 1;
        }
        BTL_SERVER_FLOW_PushPendingHpRecovery(p, ((struct Obj04358 *)q)->f0, *(u8 * *)&((struct Obj00003 *)p)->f4A8, out);
    }
}
