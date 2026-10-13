/*
 * function: PLIST_DEMO_FriendshipItemApplies
 * address:  0x021BE9BC
 * packet:   pkt_ov091_021BE9BC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_02021014  0x02021014  thumb
 */

typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
struct Rec;
extern u32 func_02021014(struct Rec *p, u32 sel);

int PLIST_DEMO_FriendshipItemApplies(void *a, void *b)
{
    int r = 0;
    int v = POKE_TOOL_GetPartyValue(a, 9, 0);
    if (v >= 0xFF)
        return r;
    if (v < 100) {
        if ((int)func_02021014(b, 0x31) != 0 && (int)func_02021014(b, 0x3C) > 0)
            return 1;
        return 0;
    }
    if (v >= 100 && v < 200) {
        if ((int)func_02021014(b, 0x32) != 0 && (int)func_02021014(b, 0x3D) > 0)
            return 1;
        return 0;
    }
    if (v >= 200 && v < 0xFF) {
        if ((int)func_02021014(b, 0x33) != 0 && (int)func_02021014(b, 0x3E) > 0)
            return 1;
        return 0;
    }
    return 0;
}
