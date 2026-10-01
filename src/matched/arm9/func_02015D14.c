/*
 * function: func_02015D14
 * address:  0x02015D14
 * packet:   pkt_02015D14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0xF8. Inverse of func_02015CF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015D14(void *p, u32 *src)
{
    *(u32 *)((char *)p + 0xF8) = src[0];
    *(u32 *)((char *)p + 0xFC) = src[1];
    *(u32 *)((char *)p + 0x100) = src[2];
}
