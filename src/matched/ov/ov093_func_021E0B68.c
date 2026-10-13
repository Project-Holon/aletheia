/*
 * function: HAND_WAZA_FollowMeFailOutsideMultiBattle
 * address:  0x021E0B68
 * packet:   pkt_ov093_021E0B68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

extern int BTL_SERVER_FLOW_GetRule(int *p);
extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_FollowMeFailOutsideMultiBattle(int a, void *b, int c)
{
    int n = 34;

    if (BTL_SERVER_FLOW_GetRule(b) == 0 || BTL_SERVER_FLOW_GetRule(b) == 3) {
        if (c == BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(n) == 0)
            BTL_EVENT_OverwriteVar(n, 26);
    }
}
