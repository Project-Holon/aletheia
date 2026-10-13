/*
 * unit:     yes
 * function: HAND_WAZA_RazorWindOnChargeTurn, HAND_WAZA_AddSkyAttack
 * address:  0x021E64B8
 * packet:   pkt_ov093_021E64B8
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
 *   gSkyAttackHandlers     0x021F25DC  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern int gSkyAttackHandlers[];

void HAND_WAZA_RazorWindOnChargeTurn(int u, void *a, u32 b)
{
    u8 *e;

    if (b == BTL_EVENT_GetVar(3)) {
        e = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, b);
        BTL_SERVER_FLOW_InitMsgRecord(e + 4, 2, 0x223);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 4), b);
        BTL_SERVER_FLOW_CommitCmdRecord(a, e);
    }
}

int *HAND_WAZA_AddSkyAttack(int *p)
{
    *p = 1;
    return gSkyAttackHandlers;
}
