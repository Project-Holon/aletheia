/*
 * function: func_02051A34
 * address:  0x02051A34
 * packet:   pkt_02051A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte load helper,
 * `return p[0x94/4]`. The getter half of func_02051A2C.
 *
 * Addresses are Black-image addresses.
 */

int func_02051A34(void *p)
{
    return *(int *)((char *)p + 0x94);
}
