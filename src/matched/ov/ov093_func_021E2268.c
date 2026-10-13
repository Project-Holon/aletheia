/*
 * function: HAND_WAZA_ThrashAdvanceTurn
 * address:  0x021E2268
 * packet:   pkt_ov093_021E2268
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerOfPoke  0x021E03D8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 */
#include "../include/Obj05221.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_CALC_MakeSickContFromKind(int a, void *b, void *c);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void HAND_WAZA_RemoveMoveHandlerOfPoke(u8 *a, int b);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void HAND_WAZA_ThrashAdvanceTurn(void *u, int a, int b, int *p)
{
    void *q;
    u8 *r;
    int f;

    if (b == BTL_EVENT_GetVar(2)) {
        q = BTL_SERVER_FLOW_GetPokeParam((int *)a, b);
        if (p[6] != 0) {
            f = 0;
            if (p[0] != 0)
                p[0] = p[0] - 1;
            if (BTL_EVENT_GetVar(0x51) == 0) {
                r = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0xb, b);
                ((struct Obj05221 *)r)->f4 = 0x19;
                f = 1;
                r[0x14] = 1;
                r[8] = b;
                BTL_SERVER_FLOW_CommitCmdRecord((void *)a, r);
            }
            if (p[0] == 0) {
                r = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0xc, b);
                ((struct Obj05221 *)r)->f4 = 6;
                BTL_CALC_MakeSickContFromKind(6, q, r + 8);
                f = 1;
                r[0xd] = 1;
                r[0xf] = b;
                BTL_SERVER_FLOW_InitMsgRecord(r + 0x14, 2, 0x168);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 0x14), b);
                BTL_SERVER_FLOW_CommitCmdRecord((void *)a, r);
            }
            if (f != 0)
                HAND_WAZA_RemoveMoveHandlerOfPoke(q, BTL_EVENT_GetFactorKey(u));
        }
    }
}
