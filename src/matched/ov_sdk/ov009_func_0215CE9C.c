/*
 * function: SOCLi_GetCtrlPipe
 * address:  0x0215CE9C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0xa0 of the block, falling back to +0xa4 when it is zero.
 */

int SOCLi_GetCtrlPipe(const int *p, int b)
{
    int v = p[0x28];

    if (v == 0)
        v = p[0x29];
    return v;
}
