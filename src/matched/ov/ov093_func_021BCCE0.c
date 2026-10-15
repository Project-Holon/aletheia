/*
 * function: BTL_SERVER_FLOW_ProcAction
 * address: 0x021BCCE0
 * packet: pkt_ov093_021BCCE0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: CC8D8's own matched source returns one-word struct Lock;
 *   this caller treats all r0 bits as a raw u32, copies r0 to r6 at 021BCEA4,
 *   and forwards r6 unchanged in r1 at 021BCEB6 to CC95C (str r1,[r0]).
 *   CC8D8 returns the entire pre-mutation 32-bit word. No bit is interpreted,
 *   narrowed or changed; both line arguments and all arities are preserved.
 *   Matched BD708 uses this same scalar interface. Struct diagnostic run03
 *   adds 8 frame bytes; byte score is not the payload/effect equivalence proof.
 * lever: Union views preserve bits7..22 for the full move field and bits7..9
 *   for case3; arg is bits23..30. Wrapping arithmetic is never signed.
 * semantics: Packed word widths derive from listing shift pairs; all fields
 *   unsigned, no signed arithmetic or asserted external selector bounds.
 * symbols:
 *   BTL_SERVER_FLOW_PushFrame 0x021C859C thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   ZKNSEARCH_MAIN_GetListIndexA 0x021BCEEC thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_MAIN_GetCompetitorKind 0x021B86E4 thumb ov093
 *   BTL_POKEPARAM_GetCounter 0x021D69AC thumb ov093
 *   BTL_SERVER_FLOW_SetPokeCounter 0x021C0780 thumb ov093
 *   BTL_SERVER_FLOW_NotifyActionStart 0x021BCEFC thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_SERVER_FLOW_ProcRotation 0x021BC418 thumb ov093
 *   BTL_SERVER_FLOW_ProcPreTurnMoveCheck 0x021BC568 thumb ov093
 *   BTL_SERVER_FLOW_CheckDisobedience 0x021BCFAC thumb ov093
 *   BTL_SERVER_FLOW_ProcFight 0x021BDE98 thumb ov093
 *   BTL_SERVER_FLOW_ProcBagItemUse 0x021CB730 thumb ov093
 *   BTL_SERVER_FLOW_CommitEscape 0x021BD708 thumb ov093
 *   BTL_SERVER_FLOW_ProcMemberChange 0x021BDC98 thumb ov093
 *   BTL_SERVER_FLOW_ProcAfterMemberIn 0x021BDA00 thumb ov093
 *   BTL_SERVER_FLOW_ProcEscape 0x021BD584 thumb ov093
 *   BTL_SERVER_FLOW_ProcShift 0x021BD3E8 thumb ov093
 *   BTL_SERVER_FLOW_PushActionBlockedMessage 0x021C54BC thumb ov093
 *   BTL_SERVER_FLOW_SetContFlag 0x021C60EC thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_DispatchActionEndEvent 0x021BCF70 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_PopFrame 0x021C85B8 thumb ov093
 */
#include "../include/Obj00309.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    struct { u32 type:4, select:3, move:3, rest:22; } small;
} Action;
typedef struct { u8 *a; Action b; u32 c; u8 d, processed; u16 pad; } E;
extern void BTL_SERVER_FLOW_PushFrame(u8 *);
extern int BTL_POKEPARAM_IsFainted(void *);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int ZKNSEARCH_MAIN_GetListIndexA(void *, u8);
struct Unk021D62A8;
struct UtilWork;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_MAIN_GetCompetitorKind(unsigned int **p);
extern u8 BTL_POKEPARAM_GetCounter(u8 *, int);
extern void BTL_SERVER_FLOW_SetPokeCounter(u8 *, u8 *, int, u8);
extern void BTL_SERVER_FLOW_NotifyActionStart(u8 *, u8 *, u32);
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *p, u32 n);
extern u32 BTL_MAIN_GetRule(void **p);
extern void BTL_SERVER_FLOW_ProcRotation(u8 *, int, int);
extern void BTL_SERVER_FLOW_ProcPreTurnMoveCheck(u8 *);
extern int BTL_SERVER_FLOW_CheckDisobedience(u8 *, u8 *);
extern void BTL_SERVER_FLOW_ProcFight(u8 *, u8 *, Action *, u32);
extern int BTL_SERVER_FLOW_ProcBagItemUse(u8 *, u8 *, u16, u8, u8);
extern int BTL_SERVER_FLOW_CommitEscape(u8 *, u8 *, int, int);
extern void BTL_SERVER_FLOW_ProcMemberChange(u8 *p, u8 *a, u8 v);
extern int BTL_SERVER_FLOW_ProcAfterMemberIn(u8 *);
extern int BTL_SERVER_FLOW_ProcEscape(u8 *, u8 *);
extern void BTL_SERVER_FLOW_ProcShift(u8 *, u8 *);
extern void BTL_SERVER_FLOW_PushActionBlockedMessage(u8 *, u8 *);
extern void BTL_SERVER_FLOW_SetContFlag(u8 *p, u8 *a, u32 n);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_DispatchActionEndEvent(u8 *, u8 *, u32);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern void BTL_SERVER_FLOW_PopFrame(u8 *);

u32 BTL_SERVER_FLOW_ProcAction(u8 *p, E *e)
{
    u8 *a;
    Action b;
    u32 lock;
    if (e->processed == 0) {
        a = e->a;
        b = e->b;
        BTL_SERVER_FLOW_PushFrame(p);
        e->processed = 1;
        if (((struct Obj00309 *)p)->f14 == 5 && b.full.type != 4) goto end;
        if (BTL_POKEPARAM_IsFainted(a) != 0) goto end;
        if (b.full.type != 6 && ZKNSEARCH_MAIN_GetListIndexA(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(a)) == 0) goto end;
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x21) != 0) {
            if (b.full.type != 4 || BTL_MAIN_GetCompetitorKind((unsigned int **)(*(u8 * *)&((struct Obj00309 *)p)->f4)) != 2) {
                if (BTL_POKEPARAM_GetCounter(a, 3) != 0) BTL_SERVER_FLOW_SetPokeCounter(p, a, 3, 0);
                goto end;
            }
        }
        BTL_SERVER_FLOW_NotifyActionStart(p, a, e->b.full.type);
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 0);
        switch (b.full.type) {
        case 6:
            if (BTL_MAIN_GetRule(((struct Obj00309 *)p)->f4) == 3) BTL_SERVER_FLOW_ProcRotation(p, e->d, (u8)b.full.select);
            break;
        case 1:
            if (p[0x1fe8] == 0) {
                BTL_SERVER_FLOW_ProcPreTurnMoveCheck(p);
                p[0x1fe8] = 1;
            }
            ((struct Obj00309 *)p)->f1F78 = BTL_SERVER_FLOW_CheckDisobedience(p, a);
            BTL_SERVER_FLOW_ProcFight(p, a, &b, e->c & 0x3fffff);
            break;
        case 2:
            if (BTL_SERVER_FLOW_ProcBagItemUse(p, a, (u16)b.full.move, (u8)b.full.arg, (u8)b.full.select) == 1) {
                if (BTL_SERVER_FLOW_CommitEscape(p, a, 1, 1)) ((struct Obj00309 *)p)->f14 = 5;
            }
            break;
        case 3:
            BTL_SERVER_FLOW_ProcMemberChange(p, a, (u8)b.small.move);
            BTL_SERVER_FLOW_ProcAfterMemberIn(p);
            break;
        case 4:
            if (BTL_SERVER_FLOW_ProcEscape(p, a)) ((struct Obj00309 *)p)->f14 = 5;
            break;
        case 8:
            ((struct Obj00309 *)p)->f14 = 4;
            break;
        case 5:
            BTL_SERVER_FLOW_ProcShift(p, a);
            break;
        case 7:
            BTL_SERVER_FLOW_PushActionBlockedMessage(p, a);
            break;
        case 0:
        default:
            break;
        }
        if (b.full.type == 1 || b.full.type == 2) {
            BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 1);
            BTL_SERVER_FLOW_SetContFlag(p, a, 0);
        }
        lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 0x83b);
        BTL_SERVER_FLOW_DispatchActionEndEvent(p, a, b.full.type);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 0x83d);
    end:
        BTL_SERVER_FLOW_PopFrame(p);
        return b.full.type;
    }
    return 0;
}
