/*
 * function: BTL_HANDLER_ITEM_GripClaw_ExtendBind
 * address:  0x021DED28
 * packet:   pkt_ov093_021DED28
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
 *   BTLV_CORE_SetSlotIndex  0x021E8C9C  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
union U;
extern void BTLV_CORE_SetSlotIndex(union U *p, int v);

void BTL_HANDLER_ITEM_GripClaw_ExtendBind(int a, int b, int c)
{
    int t;

    if (c == BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(0x1d) == 8) {
        t = BTL_EVENT_GetVar(0x1e);
        BTLV_CORE_SetSlotIndex((union U *)(&t), 8);
        BTL_EVENT_OverwriteVar(0x1e, t);
    }
}
