/*
 * function: func_02015D30
 * address:  0x02015D30
 * packet:   pkt_02015D30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x104.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015D30(void *p, u32 *src)
{
    *(u32 *)((char *)p + 0x104) = src[0];
    *(u32 *)((char *)p + 0x108) = src[1];
    *(u32 *)((char *)p + 0x10C) = src[2];
}
