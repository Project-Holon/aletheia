/*
 * function: BTL_SERVER_FLOW_RemoveOutOfRangeTargets
 * address:  0x021BF04C
 * packet:   pkt_ov093_021BF04C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_RunSeasonFadeIn  0x021BF0A4  thumb  ov093
 *   func_021BF0B4  0x021BF0B4  thumb  ov093
 *   func_021BF0C4  0x021BF0C4  thumb  ov093
 *   func_021BF0D4  0x021BF0D4  thumb  ov093
 *   BTL_SERVER_FLOW_CheckAllyMoveAutoHit  0x021BFA00  thumb  ov093
 *   BTL_SERVER_FLOW_PushMoveBlockedMessage  0x021C572C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void EVENT_FIELDMAP_CONTROL_RunSeasonFadeIn(int c);
extern int func_021BF0B4(int c);
extern void func_021BF0C4(int c, int x);
extern int func_021BF0D4(int c);
extern int BTL_SERVER_FLOW_CheckAllyMoveAutoHit(u8 *p, u8 *a, u8 *b, void *item);
extern void BTL_SERVER_FLOW_PushMoveBlockedMessage(u8 *p, u8 *a, u32 v);

void BTL_SERVER_FLOW_RemoveOutOfRangeTargets(u8 *p, u16 *b, int s, int c)
{
    int x;
    EVENT_FIELDMAP_CONTROL_RunSeasonFadeIn(c);
    x = func_021BF0B4(c);
    while (x != 0) {
        if (BTL_SERVER_FLOW_CheckAllyMoveAutoHit(p, (u8 *)s, (u8 *)x, (void *)(*b)) != 0) {
            func_021BF0C4(c, x);
            BTL_SERVER_FLOW_PushMoveBlockedMessage(p, (u8 *)x, *b);
            p[0x78a] |= 0x10;
        }
        x = func_021BF0D4(c);
    }
}
