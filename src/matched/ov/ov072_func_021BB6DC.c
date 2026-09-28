/*
 * function: func_021BB6DC
 * address:  0x021BB6DC
 * packet:   pkt_021BB6DC
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (12) runs past the compiled function (6) into an
 *           unlabelled Thumb leaf (a `bx lr` at 0x021BB6E4), no byte
 *           difference.
 */

void func_021BB6DC(int *p)
{
    p[8] = 1;
}
