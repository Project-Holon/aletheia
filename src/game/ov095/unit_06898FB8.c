/*
 * file:     unit_06898FB8.c
 * function: func_06898FB8
 * address:  0x06898FB8
 * packet:   pkt_ov095_06898FB8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int a);
extern u8 *BTL_SERVER_FLOW_AllocCmdRecord(int p, int n, u8 v);
extern void BTL_SERVER_FLOW_InitMsgRecord(u8 *p, int n, int c);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(u8 *p, u8 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(int p, u8 *q);

void func_06898FB8(int a0, int p, int a2, int *s)
{
    u8 v;
    u8 *t;

    if (*s != 0) {
        v = BTL_EVENT_GetVar(4);
        t = BTL_SERVER_FLOW_AllocCmdRecord(p, 4, v);
        BTL_SERVER_FLOW_InitMsgRecord(t + 4, 2, 0x347);
        BTL_SERVER_FLOW_AppendMsgRecordArg(t + 4, v);
        BTL_SERVER_FLOW_CommitCmdRecord(p, t);
        *s = 0;
    }
}
