/*
 * function: HAND_TOKUSEI_SoundproofBlockSoundMove
 * address:  0x021DAB78
 * packet:   pkt_ov093_021DAB78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_TOKUSEI_SoundproofBlockSoundMove(int unused, void *a, int id)
{
    u8 *r;

    if (id == BTL_EVENT_GetVar(4)) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 8) != 0 && BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
            BTL_SERVER_FLOW_PushCmdRecord(a, 2, id);
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 4, id);
            BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0xd2);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
            BTL_SERVER_FLOW_CommitCmdRecord(a, r);
            BTL_SERVER_FLOW_PushCmdRecord(a, 3, id);
        }
    }
}
