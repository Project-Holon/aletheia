/*
 * function: func_021F37D8
 * address:  0x021F37D8
 * packet:   pkt_021F37D8
 * region:   ov060
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Call with a zero second argument then read byte 1 of the result.
 *
 * symbols:
 *   func_021897BC  0x021897BC  thumb
 *
 * Unblocked by matching the leaf at 0x021897BC in ov021: its only coherent
 * code home (ov009 is ARM gpiRecvToBuffer there).
 */

int func_021F37D8(void *p)
{
    void *func_021897BC(void *, int);
    return *(unsigned char *)((char *)func_021897BC(p, 0) + 1);
}
