/*
 * function: HAND_WAZA_TeleportEscape
 * address:  0x021E5C64
 * packet:   pkt_ov093_021E5C64
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_KeepFactorRunning  0x021D70C8  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_KeepFactorRunning(void *a);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);

void HAND_WAZA_TeleportEscape(void *a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        BTL_EVENT_KeepFactorRunning(a);
        BTL_SERVER_FLOW_PushCmdRecord(b, 0x28, c);
    }
}
