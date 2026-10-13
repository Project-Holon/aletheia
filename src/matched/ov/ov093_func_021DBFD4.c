/*
 * function: HAND_TOKUSEI_SheerForce_IsBoostedMove
 * address:  0x021DBFD4
 * packet:   pkt_ov093_021DBFD4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WAZA_TOOL_GetCategory  0x0201C1BC  thumb
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   WAZA_TOOL_GetRankEffectCount  0x0201C020  thumb
 *   WAZA_TOOL_GetRankEffect  0x0201C0BC  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 WAZA_TOOL_GetCategory(u16 id);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern u8 WAZA_TOOL_GetRankEffectCount(u16 id);
extern u8 WAZA_TOOL_GetRankEffect(u16 id, u32 idx, s32 *out);

int HAND_TOKUSEI_SheerForce_IsBoostedMove(u16 id)
{
    u32 t = WAZA_TOOL_GetCategory(id);
    if (WAZA_TOOL_GetParam(id, 10) != 0) {
        return 1;
    }
    switch (t) {
    case 4:
        if (WAZA_TOOL_GetParam(id, 11) == 8) {
            return 0;
        }
    case 6:
        return 1;
    case 7: {
        u32 n;
        u32 i;
        s32 out;
        n = WAZA_TOOL_GetRankEffectCount(id);
        for (i = 0; i < n; i++) {
            WAZA_TOOL_GetRankEffect(id, i, &out);
            if (out < 0) {
                return 0;
            }
        }
        return 1;
    }
    default:
        if (id == 0x122) {
            return 1;
        }
        return 0;
    }
}
