/*
 * function: func_021BEACC
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
 *   d_021D9FF0     0x021D9FF0  data
 */

typedef unsigned int u32;

typedef struct {
    u32 v[6][6];
} Table;

extern const Table d_021D9FF0;

u32 func_021BEACC(int a, int b)
{
    Table t = d_021D9FF0;

    return t.v[a][b];
}
