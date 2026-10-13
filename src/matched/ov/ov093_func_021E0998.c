/*
 * function: HAND_WAZA_MimicCopyTargetMove
 * address: 0x021E0998
 * packet: pkt_ov093_021E0998
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: move stays int; the caller passes the full value to BTL_POKEPARAM_FindMoveSlot without narrowing.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_IsTransformed 0x021D6D54 thumb ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId 0x021D67A8 thumb ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   func_021E0A64 0x021E0A64 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 */
#include "../include/Obj06267.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
struct QL;
struct QQ;
struct R5;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsTransformed(struct R5 *p);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *p);
extern int func_021E0A64(int);
extern u8 BTL_POKEPARAM_FindMoveSlot(void *, int);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
void HAND_WAZA_MimicCopyTargetMove(void *a, void *q, int id)
{
    void *m;
    void *t;
    int move;
    int other;
    int slot;
    u8 *r;
    if (id == BTL_EVENT_GetVar(3)) {
        m = BTL_SERVER_FLOW_GetPokeParam(q, id);
        if (BTL_POKEPARAM_IsTransformed(m) != 0) return;
        t = BTL_SERVER_FLOW_GetPokeParam(q, (u8)BTL_EVENT_GetVar(6));
        move = BTL_POKEPARAM_GetLastUsedMoveId(t);
        other = BTL_POKEPARAM_GetLastSelectedMoveId(t);
        if (other != move) move = other;
        if (move == 0 || func_021E0A64(move) != 0 || BTL_POKEPARAM_FindMoveSlot(m, move) != 4) return;
        slot = BTL_POKEPARAM_FindMoveSlot(m, BTL_EVENT_GetFactorKey(a));
        if (slot == 4) return;
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 37, id);
        r[4] = id;
        r[5] = slot;
        ((struct Obj06267 *)r)->f8 = move;
        r[6] = 0;
        r[7] = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 4, id);
        BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0x2b0);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), move);
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
    }
}
