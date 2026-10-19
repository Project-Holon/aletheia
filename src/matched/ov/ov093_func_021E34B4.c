/*
 * function: HAND_WAZA_MagicCoatOnExecuteCheck
 * address:  0x021E34B4
 * packet:   pkt_ov093_021E34B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   HAND_COMMON_IsLastToAct  0x021E8624  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   HAND_COMMON_EventRedirectMove  0x021E8744  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int HAND_COMMON_IsLastToAct(int a, int b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
extern void HAND_COMMON_EventRedirectMove(int a, void *b, int c, int d);

void HAND_WAZA_MagicCoatOnExecuteCheck(int u, void *p, int key, int o)
{
    u8 v = BTL_EVENT_GetVar(2);
    if (v == key) {
        if (HAND_COMMON_IsLastToAct((int)p, key) != 0) {
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
            return;
        }
    } else if (BTL_MAIN_IsPokeSamePair(key, v) == 0) {
        HAND_COMMON_EventRedirectMove(u, p, key, o);
    }
}
