/*
 * function: func_021E82AC
 * address:  0x021E82AC
 * packet:   pkt_ov093_021E82AC
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
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void func_021E82AC(void *a, void *b, int c)
{
    u8 *p;
    int v;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetFactorKey(a) == 0x229)
            v = 0x35f;
        else
            v = 0x362;
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, (u16)v);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
