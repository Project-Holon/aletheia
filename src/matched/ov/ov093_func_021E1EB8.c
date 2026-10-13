/*
 * function: HAND_WAZA_ChargeStoreOnUse
 * address:  0x021E1EB8
 * packet:   pkt_ov093_021E1EB8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_ChargeStoreOnUse(void *u, int a, int b, int *p)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_EVENT_GetVar(0x12) == BTL_EVENT_GetFactorKey(u)) {
            s = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 4, b);
            BTL_SERVER_FLOW_InitMsgRecord(s + 4, 2, 0x298);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(s + 4), b);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)a, s);
            BTL_EVENT_OverwriteVar(0x3e, 1);
            p[6] = 1;
            p[0] = 1;
        }
    }
}
