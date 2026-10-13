/*
 * unit:     yes
 * function: HAND_WAZA_DigOnChargeTurn, HAND_WAZA_DigNoOp, HAND_WAZA_AddSolarBeam
 * address:  0x021E63BC
 * packet:   pkt_ov093_021E63BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gSolarBeamHandlers     0x021F2AF8  data   ov093  a4
 */
#include "../include/Obj13535.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern int gSolarBeamHandlers[];

void HAND_WAZA_DigOnChargeTurn(int u, void *a, u32 b)
{
    u8 *e;

    if (b == BTL_EVENT_GetVar(3)) {
        e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x17, b);
        e[8] = b;
        ((struct Obj13535 *)e)->f4 = 5;
        BTL_SERVER_FLOW_CommitCmdRecord(a, e);
        e = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, b);
        BTL_SERVER_FLOW_InitMsgRecord(e + 4, 2, 0x21a);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 4), b);
        BTL_SERVER_FLOW_CommitCmdRecord(a, e);
    }
}

void HAND_WAZA_DigNoOp(void)
{
}

int *HAND_WAZA_AddSolarBeam(int *p)
{
    *p = 3;
    return gSolarBeamHandlers;
}
