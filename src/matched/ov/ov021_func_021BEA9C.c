/*
 * function: EVENT_FIELDMAP_CONTROL_LookupExitEffect
 * address:  0x021BEA9C
 * packet:   pkt_ov021_021BEA9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gExitEffectTable  0x021D9F60  data
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct {
    u32 v[6][6];
} Table;

extern const Table gExitEffectTable;

u32 EVENT_FIELDMAP_CONTROL_LookupExitEffect(int row, int col)
{
    Table t = gExitEffectTable;

    return t.v[row][col];
}
