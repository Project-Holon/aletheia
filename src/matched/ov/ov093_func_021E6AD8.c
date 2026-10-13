/*
 * function: HAND_WAZA_MetronomeSetFailMessage
 * address:  0x021E6AD8
 * packet:   pkt_ov093_021E6AD8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_MetronomeSetFailMessage(int x, int a, int c)
{
    void *p;
    u16 id;

    if (c == BTL_EVENT_GetVar(2)) {
        p = (void *)BTL_EVENT_GetVar(0x3f);
        id = BTL_EVENT_GetVar(0x12);
        BTL_SERVER_FLOW_InitMsgRecord(p, 1, 0x78);
        BTL_SERVER_FLOW_AppendMsgRecordArg(p, id);
        BTL_EVENT_OverwriteVar(0x51, 1);
    }
}
