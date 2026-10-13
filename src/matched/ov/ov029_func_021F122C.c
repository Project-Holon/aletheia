/*
 * function: C_GEAR_ResetAllTiles
 * address:  0x021F122C
 * packet:   pkt_ov029_021F122C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_ResetTileFlash  0x021F0AE0  thumb  ov029
 *   d_021F3334     0x021F3334  data  a4
 */

typedef struct { int a, b; } Pair;

extern const Pair d_021F3334;
extern void C_GEAR_ResetTileFlash(void *q, void *p, int k);

void C_GEAR_ResetAllTiles(char *p)
{
    Pair t = d_021F3334;
    char *base;
    int i, j, n;

    i = 0;
    base = p + 0x2D0;
    for (; i < 9; i++) {
        n = ((int *)&t)[i % 2];
        for (j = 0; j < n; j++)
            C_GEAR_ResetTileFlash(base + i * 0x20 + j * 8, p, 4);
    }
}
