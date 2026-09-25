/*
 * function: func_021B79E4
 * address:  0x021B79E4
 * packet:   pkt_021B79E4
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads two halfword fields and returns void; the trailing `cmp r0, #0`
 * in the image is the folded condition of the second guard, whose take
 * branch is the fall-through `bx lr`.
 */

void func_021B79E4(unsigned short *p)
{
    if (p[1] == 0)
        return;
    if (p[2])
        return;
}
