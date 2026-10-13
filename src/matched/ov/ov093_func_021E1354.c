/*
 * function: HAND_WAZA_TrapOnAddSickMessage
 * address:  0x021E1354
 * packet:   pkt_ov093_021E1354
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
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
struct S;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);

void HAND_WAZA_TrapOnAddSickMessage(void *a, void *unused, int id)
{
    void *p;
    u8 k;
    int v;

    if (id != BTL_EVENT_GetVar(3))
        return;
    if (BTL_EVENT_GetVar(0x1d) != 8)
        return;
    p = (void *)BTL_EVENT_GetVar(0x3f);
    k = BTL_EVENT_GetVar(4);
    switch (BTL_EVENT_GetFactorKey(a)) {
    case 0x23:
        v = 0x32a;
        break;
    case 0x14:
        v = 0x323;
        break;
    case 0x53:
        v = 0x33b;
        break;
    case 0x80:
        v = 0x331;
        break;
    case 0x148:
        v = 0x341;
        break;
    case 0x1cf:
        v = 0x33e;
        break;
    case 0xfa:
        v = 0x338;
        break;
    default:
        return;
    }
    BTL_SERVER_FLOW_InitMsgRecord(p, 2, v);
    BTL_SERVER_FLOW_AppendMsgRecordArg(p, k);
    BTL_SERVER_FLOW_AppendMsgRecordArg(p, id);
}
