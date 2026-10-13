/*
 * function: BTLV_CORE_EventRedirectMove
 * address:  0x021E8744
 * packet:   pkt_ov093_021E8744
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_PushMoveQueueWithPos  0x021C8434  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_SERVER_FLOW_PushMoveQueueWithPos(u8 *p, int a, int b);

void BTLV_CORE_EventRedirectMove(int u, void *a, int b, int d)
{
    u8 k;
    u16 m;

    k = BTL_EVENT_GetVar(2);
    if (BTL_MAIN_IsPokeSamePair(k, b) == 0) {
        m = BTL_EVENT_GetVar(0x12);
        if (WAZA_TOOL_GetCategory(m) == 0xb) {
            if (WAZA_TOOL_GetFlag(m, 4) != 0) {
                if (BTL_EVENT_OverwriteVar(0x22, 0x19) != 0)
                    BTL_SERVER_FLOW_PushMoveQueueWithPos(a, b, k);
            }
        }
    }
}
