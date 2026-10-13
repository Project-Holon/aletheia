/*
 * function: HAND_WAZA_SnoreOnActionCheck
 * address:  0x021E1BD4
 * packet:   pkt_ov093_021E1BD4
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
 */

extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_SnoreOnActionCheck(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(34) == 2)
        BTL_EVENT_OverwriteVar(65, 1);
}
