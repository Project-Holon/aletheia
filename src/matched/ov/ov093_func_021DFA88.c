/*
 * function: HAND_ITEM_EvioliteDefenseRatio
 * address:  0x021DFA88
 * packet:   pkt_ov093_021DFA88
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_SERVER_FLOW_IsPokeEvolvable  0x021C818C  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int BTL_SERVER_FLOW_IsPokeEvolvable(unsigned char *p, int v);

void HAND_ITEM_EvioliteDefenseRatio(int a, unsigned char *b, int c)
{
    if (c == BTL_EVENT_GetVar(4) && BTL_SERVER_FLOW_IsPokeEvolvable(b, c))
        BTL_EVENT_MultiplyVar(53, 6 << 10);
}
