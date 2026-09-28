/*
 * function: func_021C4230
 * address:  0x021C4230
 * packet:   pkt_021C4230
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_0204B3DC(void *, int);

void func_021C4230(char *p, int a)
{
    func_0204B3DC(*(void **)(p + 4), a);
    if (*(void **)(p + 8) != 0)
        func_0204B3DC(*(void **)(p + 8), a);
}
