/*
 * function: SYMBOL_MAP_GetNeighborCellId
 * address:  0x021663F4
 * packet:   pkt_ov010_021663F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Finds the position of a value in a byte list (SYMBOL_MAP_FindGridIndex) and returns
 * the entry a step away from it: 0 = three back, 1 = three on, 2 = one
 * back, 3 = one on; any other direction returns the default.
 *
 * symbols:
 *   SYMBOL_MAP_FindGridIndex  0x0216630C  thumb  ov010
 */

typedef unsigned char u8;

extern int SYMBOL_MAP_FindGridIndex(int a0, int a1, int a2, int a3);

int SYMBOL_MAP_GetNeighborCellId(u8 *list, int def, unsigned dir, int a3)
{
    int i = SYMBOL_MAP_FindGridIndex((int)list, def, dir, a3);

    switch (dir) {
    case 0:
        return list[i - 3];
    case 1:
        return list[i + 3];
    case 2:
        return list[i - 1];
    case 3:
        return list[i + 1];
    }
    return def;
}
