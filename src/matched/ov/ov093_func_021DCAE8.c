/*
 * function: BTL_HANDLER_TOKUSEI_MagicBounceReflectMove
 * address:  0x021DCAE8
 * packet:   pkt_ov093_021DCAE8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   BTLV_CORE_EventQueueMoveNotice  0x021E8804  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void func_021C88B4(void *a, int k, int b);
extern void BTLV_CORE_EventQueueMoveNotice(int a, void *b, int c, int d);

void BTL_HANDLER_TOKUSEI_MagicBounceReflectMove(int a, void *b, int c, int d)
{
    if (c == BTL_EVENT_GetVar(2) && BTL_EVENT_OverwriteVar(0x51, 1) != 0) {
        func_021C88B4(b, 2, c);
        BTLV_CORE_EventQueueMoveNotice(a, b, c, d);
        func_021C88B4(b, 3, c);
    }
}
