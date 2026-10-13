/*
 * function: HAND_TOKUSEI_ImposterTransform
 * address:  0x021DCD20
 * packet:   pkt_ov093_021DCD20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_MAIN_GetFacingPos  0x021B8C5C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeIdAtFieldIndex  0x021C8020  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10065.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern int BTL_SERVER_FLOW_GetRule(int *p);
extern u8 BTL_MAIN_GetFacingPos(int kind, u32 flags);
extern u8 BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(u8 *p, u8 v);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_ImposterTransform(int a, void *b, int c)
{
    u8 *m;
    void *p;
    int k;
    int n;

    if (c == BTL_EVENT_GetVar(2)) {
        n = BTL_SERVER_FLOW_GetPokeViewPos(b, c);
        k = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(b, BTL_MAIN_GetFacingPos(BTL_SERVER_FLOW_GetRule(b), n));
        p = BTL_SERVER_FLOW_GetPokeParam(b, k);
        if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(b, c)) == 0 && BTL_POKEPARAM_IsFainted(p) == 0) {
            m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x33, c);
            ((struct Obj10065 *)m)->f0 |= 2 << 22;
            m[4] = k;
            BTL_SERVER_FLOW_InitMsgRecord(m + 8, 2, 0x284);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 8), c);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 8), m[4]);
            BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        }
    }
}
