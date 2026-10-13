/*
 * function: C_GEAR_TileToScreen
 * address:  0x021F0D14
 * packet:   pkt_ov029_021F0D14
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F3344     0x021F3344  data  a4
 */

typedef struct { int a, b; } Pair;

extern const Pair d_021F3344;

void C_GEAR_TileToScreen(int a, int b, int *c, int *d)
{
    Pair t = d_021F3344;
    *c = a * 4 - 2;
    *d = ((int *)&t)[a % 2] + b * 4;
}
