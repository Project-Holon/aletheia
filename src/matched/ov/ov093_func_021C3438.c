/*
 * function: BTL_SERVER_FLOW_ProcMoveOhko
 * address: 0x021C3438
 * packet: pkt_ov093_021C3438
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: declare the unsigned iterator after the event flags, keep its
 * postincrement in the call operand, and spell the filter as nested arms.
 * ABI: C3660 is the labelled Thumb veneer to ov095 0689CC70(S*,u32),
 * returning an unchanged full-word id or zero. i uses unsigned full-word
 * increment (346C), with no assumed bound. The id is used as an address.
 * C3670 forwards to 0689D5C8; C3680/C3690 forward all four inputs to
 * 0689CBB8, including the full-word id and the halfword amount.
 * CC8D8 returns the entire pre-mutation 32-bit Lock; 34FA saves all r0,
 * 363A forwards it in r1 to CC95C, whose own body stores the whole word.
 * Both original line arguments, 0x216b and 0x219c, are preserved.
 * C6948 receives the live fourth halfword loaded at3494 despite its own
 * three-input body; BFA00's pointer slot receives that same 32-bit payload.
 * C6948/C572C keep their matched caller's u32 parameter; the ldrh at each
 * site supplies a zero-extended halfword without any asserted value range.
 * C36E8 reads sixth input by ldrh at36EE and forwards full fifth input
 * to C16F8 at3712. C1828 r1 is the unchanged C3670 result (351E/35D8):
 * its own u8 parameter is widened under the observed-full-width rule.
 * half is initialized unconditionally by352A before C1678, which may
 * return0 without writing. Both event flags are initialized3536/3538.
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C3660 0x021C3660 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_FLOW_CheckNoGuardHit 0x021BF324 thumb ov093
 *   BTL_SERVER_FLOW_QuerySemiInvulnerableHit 0x021C6948 thumb ov093
 *   BTL_SERVER_FLOW_CheckAllyMoveAutoHit 0x021BFA00 thumb ov093
 *   BTL_SERVER_FLOW_PushMoveBlockedMessage 0x021C572C thumb ov093
 *   BTL_SERVER_FLOW_GetSlotTableEntry 0x021CC8B8 thumb ov093
 *   BTL_SERVER_FLOW_PushActionFailedMessage 0x021C5774 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_CheckOneHitKoHit 0x021C6A9C thumb ov093
 *   SODATEYA_MonKnowsMove 0x021C3670 thumb ov093
 *   BTL_CALC_SummarizeTypeAffinity 0x021D7AD4 thumb ov093
 *   BTL_POKEPARAM_HasSubstitute 0x021D6D7C thumb ov093
 *   BTL_SERVER_FLOW_ProcOhkoSubstituteBroken 0x021C3720 thumb ov093
 *   func_021C3680 0x021C3680 thumb ov093
 *   BTL_SERVER_FLOW_CheckEndureEvent 0x021C1678 thumb ov093
 *   BTL_SERVER_FLOW_ProcOhkoFaint 0x021C36A0 thumb ov093
 *   BTL_SERVER_FLOW_ProcOhkoEndured 0x021C36E8 thumb ov093
 *   func_021C3690 0x021C3690 thumb ov093
 *   BTL_SERVER_FLOW_RecordDamageHit 0x021C1828 thumb ov093
 *   BTL_SERVER_FLOW_ProcDamageEndEvents 0x021C4218 thumb ov093
 *   BTL_SERVER_FLOW_RunMoveDamageEndEvent 0x021C1C88 thumb ov093
 *   BTL_SERVER_FLOW_ProcFaintedPoke 0x021C4F64 thumb ov093
 *   BTL_SERVER_FLOW_GetLockState 0x021C88E4 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 */
#include "../include/Obj21086.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Flags { u8 pad[5]; u8 a:1; u8 rest:7; };
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021C3660(void *, u32);
extern int BTL_POKEPARAM_IsFainted(void *);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_SERVER_FLOW_CheckNoGuardHit(u8 *, u8 *, u8 *);
extern int BTL_SERVER_FLOW_QuerySemiInvulnerableHit(u8 *, u8 *, u8 *, u32);
extern int BTL_SERVER_FLOW_CheckAllyMoveAutoHit(u8 *, u8 *, u8 *, void *);
extern void BTL_SERVER_FLOW_PushMoveBlockedMessage(u8 *, u8 *, u32);
extern u32 BTL_SERVER_FLOW_GetSlotTableEntry(u32 *, u32);
extern void BTL_SERVER_FLOW_PushActionFailedMessage(u8 *, u8 *);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern int BTL_SERVER_FLOW_CheckOneHitKoHit(u8 *, u8 *, u8 *, u16);
extern u8 SODATEYA_MonKnowsMove(u8 *, u8);
extern int BTL_CALC_SummarizeTypeAffinity(int);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *);
extern u16 BTL_SERVER_FLOW_ProcOhkoSubstituteBroken(u8 *, u8 *, u16 *, int);
extern void func_021C3680(void *, u32, u16, int);
extern int BTL_SERVER_FLOW_CheckEndureEvent(u8 *, u8 *, u8 *, u32, u16 *);
extern void BTL_SERVER_FLOW_ProcOhkoFaint(u8 *, u8 *, u16 *, int);
extern void BTL_SERVER_FLOW_ProcOhkoEndured(u8 *, u8 *, u16 *, int, int, u16);
extern void func_021C3690(void *, u32, u16, int);
extern void BTL_SERVER_FLOW_RecordDamageHit(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
extern void BTL_SERVER_FLOW_ProcDamageEndEvents(u8 *, u8 *, u8 *, u8 *, u32, u32, u32, u32);
extern void BTL_SERVER_FLOW_RunMoveDamageEndEvent(u8 *, u8 *, u32, u8 *, u32);
extern int BTL_SERVER_FLOW_ProcFaintedPoke(u8 *, u8 *);
extern int BTL_SERVER_FLOW_GetLockState(u8 *);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_ProcMoveOhko(u8 *p, u16 *q, u8 *a, u8 *out)
{
    u8 speed;
    u8 *b;
    u8 id;
    u32 item;
    u32 lock;
    u8 tag;
    int category;
    int event1, event2;
    u32 i;
    u16 half;
    struct Flags *flags;
    i = 0;
    speed = (u8)func_021D59B4(a, 15);
    for (;;) {
        int kind;
        b = (u8 *)func_021C3660(out, i++);
        if (b == 0) break;
        if (BTL_POKEPARAM_IsFainted(b)) continue;
        id = BTL_POKEPARAM_GetPokeId(b);
        if (!BTL_SERVER_FLOW_CheckNoGuardHit(p, a, b)) {
            if (BTL_SERVER_FLOW_QuerySemiInvulnerableHit(p, a, b, *q)) {
                BTL_SERVER_FLOW_PushMoveBlockedMessage(p, b, *q);
                continue;
            }
        }
        if (BTL_SERVER_FLOW_CheckAllyMoveAutoHit(p, a, b, (void *)(u32)*q)) {
            BTL_SERVER_FLOW_PushMoveBlockedMessage(p, b, *q);
            continue;
        }
        if (speed < (u8)func_021D59B4(b, 15)) {
            BTL_SERVER_FLOW_PushActionFailedMessage(p, b);
            continue;
        }
        item = BTL_SERVER_FLOW_GetSlotTableEntry((u32 *)(p + 0x1f88), id);
        if (item == 0) {
            BTL_SERVER_FLOW_PushActionFailedMessage(p, b);
            continue;
        }
        lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 0x216b);
        if (BTL_SERVER_FLOW_CheckOneHitKoHit(p, a, b, *q)) {
            tag = SODATEYA_MonKnowsMove(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(a));
            half = func_021D59B4(b, 13);
            category = BTL_CALC_SummarizeTypeAffinity(item);
            event1 = 0;
            event2 = 0;
            flags = *(struct Flags * *)&((struct Obj21086 *)p)->f4A8;
            if (!flags->a) flags->a = 1;
            if (BTL_POKEPARAM_HasSubstitute(b)) {
                half = BTL_SERVER_FLOW_ProcOhkoSubstituteBroken(p, b, q, category);
                func_021C3680(out, (u32)b, half, 1);
                event1 = 1;
            } else {
                kind = BTL_SERVER_FLOW_CheckEndureEvent(p, a, b, 1, &half);
                if (kind == 0) {
                    BTL_SERVER_FLOW_ProcOhkoFaint(p, b, q, category);
                } else {
                    BTL_SERVER_FLOW_ProcOhkoEndured(p, b, q, category, kind, half);
                    func_021C3690(out, (u32)b, half, 0);
                    event2 = 1;
                }
            }
            if (!event1) BTL_SERVER_FLOW_RecordDamageHit(p, tag, a, b, (u8 *)q, half);
            BTL_SERVER_FLOW_ProcDamageEndEvents(p, a, b, (u8 *)q, item, half, 0, event1);
            if (event2 || event1) BTL_SERVER_FLOW_RunMoveDamageEndEvent(p, a, (u32)out, (u8 *)q, 0);
            BTL_SERVER_FLOW_ProcFaintedPoke(p, b);
        } else if (!BTL_SERVER_FLOW_GetLockState(p)) {
            BTL_SERVER_FLOW_PushMoveBlockedMessage(p, b, *q);
        }
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 0x219c);
    }
}
