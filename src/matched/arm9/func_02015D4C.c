/*
 * function: func_02015D4C
 * address:  0x02015D4C
 * packet:   pkt_02015D4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x110.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015D4C(void *p, u32 *out)
{
    out[0] = *(u32 *)((char *)p + 0x110);
    out[1] = *(u32 *)((char *)p + 0x114);
    out[2] = *(u32 *)((char *)p + 0x118);
}
