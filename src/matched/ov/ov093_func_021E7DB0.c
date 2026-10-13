/*
 * function: func_021E7DB0
 * address:  0x021E7DB0
 * packet:   pkt_ov093_021E7DB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnRecord  0x021C812C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb  ov093
 *   func_021E7DF0  0x021E7DF0  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern u8 *BTL_SERVER_FLOW_GetTurnRecord(u8 *p);
struct Q7;
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 BTL_SERVER_FLOW_GetTurnCount(struct Q7 *p);
extern u32 func_021E7DF0(int a, int b, int c);
extern void BTLV_CORE_EventScaleDamage(int n);

void func_021E7DB0(void *a, void *b, int c)
{
    int x;
    u16 y;
    if (c == BTL_EVENT_GetVar(3)) {
        x = (int)BTL_SERVER_FLOW_GetTurnRecord((u8 *)((int)b));
        y = BTL_EVENT_GetFactorKey(a);
        if (func_021E7DF0(x, y, BTL_SERVER_FLOW_GetTurnCount(b)) > 1)
            BTLV_CORE_EventScaleDamage(2);
    }
}
