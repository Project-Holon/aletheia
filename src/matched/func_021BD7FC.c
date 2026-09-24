/*
 * function: func_021BD7FC
 * address:  0x021BD7FC
 * packet:   pkt_021BD7FC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Loads the word at [p] and tail-calls the function at 0x0204B3DC with it.
 */

extern void func_0204B3DC(int);

void func_021BD7FC(int *p)
{
    func_0204B3DC(*p);
}
