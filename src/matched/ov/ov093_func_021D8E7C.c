/*
 * function: HAND_TOKUSEI_ChangeCherrimForm
 * address:  0x021D8E7C
 * packet:   pkt_ov093_021D8E7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

struct Hd { u32 lo : 23; u32 flag : 1; u32 hi : 8; };

void HAND_TOKUSEI_ChangeCherrimForm(int u, void *a, u32 b, u32 c, u8 d)
{
    u8 *r;

    if (c != func_021D59B4(BTL_SERVER_FLOW_GetPokeParam((int *)((int)a), b), 0x13)) {
        r = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x39, b);
        r[4] = b;
        r[5] = c;
        ((struct Hd *)r)->flag = d;
        BTL_SERVER_FLOW_InitMsgRecord(r + 8, 2, 0xde);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), b);
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    }
}
