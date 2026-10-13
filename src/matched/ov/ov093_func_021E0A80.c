/*
 * unit: yes
 * function: HAND_WAZA_SketchLearnTargetMove, HAND_WAZA_GetFollowMeHandlers
 * address: 0x021E0A80
 * packet: pkt_ov093_021E0A80
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E0B5C store-return stub included; consecutive guards spelled separately.
 * symbols:
 *   gFollowMeHandlers 0x021F2D78 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_IsTransformed 0x021D6D54 thumb ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId 0x021D67A8 thumb ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_HasMove 0x021D5750 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 */
#include "../include/Obj06268.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
struct QL;
struct QQ;
struct R5;
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsTransformed(struct R5 *p);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *p);
extern int BTL_POKEPARAM_HasMove(void *, int);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
void HAND_WAZA_SketchLearnTargetMove(void *a, void *q, int id)
{
    void *m;
    void *t;
    int move;
    int other;
    int slot;
    int text;
    u8 *r;
    if (id == BTL_EVENT_GetVar(3)) {
        m = BTL_SERVER_FLOW_GetPokeParam(q, id);
        t = BTL_SERVER_FLOW_GetPokeParam(q, (u8)BTL_EVENT_GetVar(6));
        move = BTL_POKEPARAM_GetLastUsedMoveId(t);
        other = BTL_POKEPARAM_GetLastSelectedMoveId(t);
        if (other != move) move = other;
        if (move == 0) return;
        if (move == 166) return;
        if (move == 165) return;
        text = 448;
        if (move == text || BTL_POKEPARAM_HasMove(m, move) != 0 || BTL_POKEPARAM_IsTransformed(m) != 0) return;
        slot = BTL_POKEPARAM_FindMoveSlot(m, BTL_EVENT_GetFactorKey(a));
        if (slot == 4) return;
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 37, id);
        r[4] = id;
        r[5] = slot;
        ((struct Obj06268 *)r)->f8 = move;
        r[6] = 0;
        r[7] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 4, id);
        text += 240;
        BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, text);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), move);
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
    }
}
extern u32 gFollowMeHandlers[];
u32 *HAND_WAZA_GetFollowMeHandlers(u32 *p)
{
    *p = 4;
    return gFollowMeHandlers;
}
