/*
 * function: SODATEYA_MonKnowsMove
 * address:  0x021C3670
 * packet:   pkt_ov021_021C3670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   sSodateyaHasMoveSlotIds     0x021DA8D8  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef struct { u32 v[4]; } T4;

extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern const T4 sSodateyaHasMoveSlotIds;

int SODATEYA_MonKnowsMove(void *a, u32 b)
{
    T4 t = sSodateyaHasMoveSlotIds;
    int i;

    for (i = 0; i < 4; i++) {
        if (b == POKE_TOOL_GetPartyValue(a, t.v[i], 0))
            return 1;
    }
    return 0;
}
