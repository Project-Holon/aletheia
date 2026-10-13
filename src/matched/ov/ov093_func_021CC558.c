/*
 * function: BTL_SERVER_FLOW_ItemEffectPushHeldItemMessage
 * address:  0x021CC558
 * packet:   pkt_ov093_021CC558
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTLV_CORE_CheckPartySlotPair  0x021E869C  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */
#include "../include/Obj13347.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTLV_CORE_CheckPartySlotPair(void *p, int id);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

int BTL_SERVER_FLOW_ItemEffectPushHeldItemMessage(char *p, void *m)
{
    u32 s;
    int id;
    u32 t;
    char *q;

    if (BTLV_CORE_CheckPartySlotPair(p, BTL_POKEPARAM_GetPokeId(m)) == 0) {
        t = (u16)(u32)BTL_POKEPARAM_GetItem(m);
        if (t != 0) {
            s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 1944);
            id = BTL_POKEPARAM_GetPokeId(m);
            q = (char *)BTL_SERVER_FLOW_AllocCmdRecord(p, 32, id);
            q[6] = id;
            ((struct Obj13347 *)q)->f4 = 0;
            BTL_SERVER_FLOW_InitMsgRecord(q + 12, 2, 225);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(q + 12), id);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(q + 12), t);
            BTL_SERVER_FLOW_CommitCmdRecord(p, q);
            BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, 1957);
            return 1;
        }
    }
    return 0;
}
