/*
 * function: func_02208850
 * address:  0x02208850
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * True when the ov195 scene object's +8 state is 4; unlabelled leaf.
 */
int func_02208850(int *p)
{
    if (p[2] == 4)
        return 1;
    return 0;
}
