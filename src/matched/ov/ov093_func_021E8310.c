/*
 * function: HAND_WAZA_FusionDoublePower
 * address:  0x021E8310
 * packet:   pkt_ov093_021E8310
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnRecord  0x021C812C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb  ov093
 *   func_021E8374  0x021E8374  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern u8 *BTL_SERVER_FLOW_GetTurnRecord(u8 *p);
struct Q7;
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 BTL_SERVER_FLOW_GetTurnCount(struct Q7 *p);
extern int func_021E8374(int a, int b);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(char *p, int x);

void HAND_WAZA_FusionDoublePower(void *a, void *b, int c)
{
    int m;
    int t;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (int)BTL_SERVER_FLOW_GetTurnRecord(b);
        switch (BTL_EVENT_GetFactorKey(a)) {
        case 0x22e:
            t = 0x22f;
            break;
        case 0x22f:
            t = 0x22e;
            break;
        default:
            t = 0;
            break;
        }
        if (t != 0 && t == func_021E8374(m, BTL_SERVER_FLOW_GetTurnCount(b))) {
            BTL_EVENT_MultiplyVar(0x31, 0x2000);
            BTL_SERVER_FLOW_SetCurTurnStateFlag(b, 1);
        }
    }
}
