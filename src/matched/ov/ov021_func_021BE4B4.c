/*
 * function: func_021BE4B4
 * address:  0x021BE4B4
 * packet:   pkt_ov021_021BE4B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, sibling of func_021BE4A4: store v at +4 of slot j
 * (stride 0x44) of the array whose pointer sits at +0xC of element i
 * (stride 0x10).  Leaf of ov062 func_021F36C0.
 *
 * symbols:
 *   func_021BE4B4  0x021BE4B4  thumb
 */

void func_021BE4B4(char *p, int i, int j, int v)
{
    char *e = p + i * 0x10;

    *(int *)(*(char **)(e + 0xC) + j * 0x44 + 4) = v;
}
