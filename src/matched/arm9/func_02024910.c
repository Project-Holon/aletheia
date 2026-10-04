/*
 * function: func_02024910
 * address:  0x02024910
 * packet:   pkt_02024910
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: address of the 8-byte entry idx of the table at p + 8.
 *
 * symbols:
 *   (none - no relocations)
 */

void *func_02024910(char *p, int idx)
{
    return p + 8 + idx * 8;
}
