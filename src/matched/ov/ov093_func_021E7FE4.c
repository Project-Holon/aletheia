/*
 * function: HAND_WAZA_SkyDropStartCharge
 * address:  0x021E7FE4
 * packet:   pkt_ov093_021E7FE4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById  0x021C846C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById(u8 *p, int a, int b, int *out);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_SkyDropStartCharge(int a, u8 *b, int c)
{
    u8 k;
    int x;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        x = 0;
        if (k == 0x1f || BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById(b, c, k, &x) == 0) {
            BTL_EVENT_OverwriteVar(0x41, 1);
            if (x != 0)
                BTL_EVENT_OverwriteVar(0x4f, 1);
        } else if (BTL_EVENT_OverwriteVar(0x51, 1) != 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
            BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 1118);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), k);
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        }
    }
}
