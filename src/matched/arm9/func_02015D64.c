/*
 * function: func_02015D64
 * address:  0x02015D64
 * packet:   pkt_02015D64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x110. Inverse of func_02015D4C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015D64(void *p, u32 *src)
{
    *(u32 *)((char *)p + 0x110) = src[0];
    *(u32 *)((char *)p + 0x114) = src[1];
    *(u32 *)((char *)p + 0x118) = src[2];
}
