/*
 * function: EVENT_FIELDMAP_CONTROL_LookupEntranceEffect
 * address:  0x021BEACC
 * packet:   pkt_ov021_021BEACC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gEntranceEffectTable     0x021D9FF0  data
 */

typedef unsigned int u32;

typedef struct {
    u32 v[6][6];
} Table;

extern const Table gEntranceEffectTable;

u32 EVENT_FIELDMAP_CONTROL_LookupEntranceEffect(int a, int b)
{
    Table t = gEntranceEffectTable;

    return t.v[a][b];
}
