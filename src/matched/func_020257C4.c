/*
 * function: func_020257C4
 * address:  0x020257C4
 * packet:   pkt_020257C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module: a bare tail call forwarding the
 * word at +4.
 *
 * symbols:
 *   func_0204B3F4  0x0204B3F4  arm
 *
 * Addresses are Black-image addresses.
 */

extern int func_0204B3F4(int);

int func_020257C4(const int *p)
{
    return func_0204B3F4(p[1]);
}
