/*
 * function: HAND_WAZA_MagicCoatOnWazaNotice
 * address:  0x021E354C
 * packet:   pkt_ov093_021E354C
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
 *   BTLV_CORE_EventQueueMoveNotice  0x021E8804  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTLV_CORE_EventQueueMoveNotice(int a, void *b, int c, int d);

void HAND_WAZA_MagicCoatOnWazaNotice(int u, void *a, int b, int c)
{
    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_EVENT_OverwriteVar(0x51, 1) != 0)
            BTLV_CORE_EventQueueMoveNotice(u, a, b, c);
    }
}
