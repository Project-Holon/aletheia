/*
 * function: HAND_TOKUSEI_IllusionBreak
 * address:  0x021DCE48
 * packet:   pkt_ov093_021DCE48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct R4;
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_IllusionBreak(int a, u8 *b, int c)
{
    u8 *p;
    if (BTL_POKEPARAM_IsIllusionActive(BTL_SERVER_FLOW_GetPokeParam((int *)b, c))) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x34, c);
        p[4] = c;
        BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 478);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
