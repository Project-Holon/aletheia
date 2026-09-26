/*
 * function: func_02051A2C
 * address:  0x02051A2C
 * packet:   pkt_02051A2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x94/4] = v`. The +0x94 twin of func_02051A24.
 *
 * Addresses are Black-image addresses.
 */

void func_02051A2C(void *p, int v)
{
    *(int *)((char *)p + 0x94) = v;
}
