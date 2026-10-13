/*
 * function: HAND_WAZA_SnatchOnWazaExecute
 * address:  0x021E35A0
 * packet:   pkt_ov093_021E35A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   HAND_COMMON_IsLastToAct  0x021E8624  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int HAND_COMMON_IsLastToAct(int a, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_SnatchOnWazaExecute(int u, void *p, int key, int *o)
{
    u8 *q;
    if (key == BTL_EVENT_GetVar(3) && HAND_COMMON_IsLastToAct((int)p, key) == 0) {
        q = BTL_SERVER_FLOW_AllocCmdRecord(p, 4, key);
        BTL_SERVER_FLOW_InitMsgRecord(q + 4, 2, 751);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(q + 4), key);
        BTL_SERVER_FLOW_CommitCmdRecord(p, q);
        o[6] = 1;
    }
}
