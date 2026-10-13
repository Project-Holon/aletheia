/*
 * function: HAND_TOKUSEI_HarvestRestoreBerry
 * address:  0x021DCB38
 * packet:   pkt_ov093_021DCB38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   ITEM_IsBerry  0x020213C0  thumb
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   HAND_TOKUSEI_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07816.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QI;
struct QK;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct QK *p);
extern int ITEM_IsBerry(u32 a);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern int HAND_TOKUSEI_RollChanceOrFlag(int a, u32 b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_HarvestRestoreBerry(int a, void *b, int c)
{
    u8 *m;
    void *mon;
    u32 n;

    if (c == BTL_EVENT_GetVar(2)) {
        mon = BTL_SERVER_FLOW_GetPokeParam(b, c);
        n = BTL_POKEPARAM_GetConsumedItem(mon);
        if (n != 0 && ITEM_IsBerry(n) != 0 && BTL_POKEPARAM_GetItem(mon) == 0
            && (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(b) == 1 || HAND_TOKUSEI_RollChanceOrFlag((int)b, 0x32) != 0)) {
            m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x20, c);
            ((struct Obj07816 *)m)->f0 |= 0x20 << 18;
            ((struct Obj07816 *)m)->f4 = n;
            m[6] = c;
            m[7] = 1;
            BTL_SERVER_FLOW_InitMsgRecord(m + 0xc, 2, 0x1db);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), c);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), n);
            BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        }
    }
}
