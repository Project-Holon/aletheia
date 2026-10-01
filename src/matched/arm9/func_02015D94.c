/*
 * function: func_02015D94
 * address:  0x02015D94
 * packet:   pkt_02015D94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x17C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

void func_02015D94(char *p, int *src)
{
    *(int *)(p + 0x17c) = src[0];
    *(int *)(p + 0x180) = src[1];
    *(int *)(p + 0x184) = src[2];
}
