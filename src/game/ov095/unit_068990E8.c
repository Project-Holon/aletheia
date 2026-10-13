/*
 * file:     unit_068990E8.c
 * function: func_068990E8
 * address:  0x068990E8
 * packet:   pkt_ov095_068990E8
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
extern u8 *BTL_SERVER_FLOW_AllocCmdRecord(int p, int n, int v);
extern void BTL_SERVER_FLOW_InitMsgRecord(u8 *p, int n, int c);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(u8 *p, int v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(int p, u8 *q);

void func_068990E8(int a0, int p, int a2, int *s)
{
    int k;
    u8 v;
    u8 *t;

    if (s[0] != 0) {
        k = BTL_EVENT_GetVar(0x19);
        if (k == 0 || s[1] != k) {
            v = BTL_EVENT_GetVar(2);
            t = BTL_SERVER_FLOW_AllocCmdRecord(p, 4, v);
            BTL_SERVER_FLOW_InitMsgRecord(t + 4, 2, 0x34a);
            BTL_SERVER_FLOW_AppendMsgRecordArg(t + 4, v);
            BTL_SERVER_FLOW_CommitCmdRecord(p, t);
            s[1] = k;
        }
        s[0] = 0;
    }
}
