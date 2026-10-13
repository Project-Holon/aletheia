/*
 * function: HAND_TOKUSEI_MummySpreadAbility
 * address:  0x021DC9C8
 * packet:   pkt_ov093_021DC9C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07815.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(u8 *p);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_MummySpreadAbility(int a, void *b, int c)
{
    u8 *m;
    u8 k;

    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0 && BTL_SERVER_FLOW_CheckShowdownThunk(b) == 0
        && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 0) != 0) {
        k = BTL_EVENT_GetVar(3);
        if (func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(b, k), 0x10) != 0x98) {
            m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1f, c);
            ((struct Obj07815 *)m)->f4 = 0x98;
            m[6] = k;
            BTL_SERVER_FLOW_InitMsgRecord(m + 0xc, 2, 0x1cf);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), m[6]);
            if (BTL_MAIN_IsPokeSamePair(c, k) == 0)
                ((struct Obj07815 *)m)->f0 |= 2 << 22;
            BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        }
    }
}
