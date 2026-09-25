/*
 * function: func_021F459C
 * address:  0x021F459C
 * packet:   pkt_ov055_021F459C
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the two halfwords at 0x6 and 0x0.
 */

void func_021F459C(void *p)
{
    *(unsigned short *)((char *)p + 6) = 0;
    *(unsigned short *)p = 0;
}
