/*
 * function: MOVE_POKEMON_MoveEntry
 * address:  0x0215E358
 * packet:   pkt_0215E358
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   MOVE_POKEMON_MoveToNeighbor  0x0215E740  thumb
 */

void MOVE_POKEMON_MoveToNeighbor(int a, int b, int c, int d);

void MOVE_POKEMON_MoveEntry(int a, int b, int c)
{
    MOVE_POKEMON_MoveToNeighbor(a, b, c, 0xff);
}
