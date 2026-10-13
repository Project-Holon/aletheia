/*
 * unit:     yes
 * function: func_021E74E4, func_021E7548
 * address:  0x021E74E4
 * packet:   pkt_ov093_021E74E4
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
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   d_021F279C     0x021F279C  data   ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int d_021F279C[];

void func_021E74E4(int a, int b, int c)
{
    u8 k;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetVar(0x46) == 0) {
            k = BTL_EVENT_GetVar(4);
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x10, c);
            p[4] = 1;
            p[5] = k;
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
            BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0xc3);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), k);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        }
    }
}

int *func_021E7548(int *p)
{
    *p = 1;
    return d_021F279C;
}
