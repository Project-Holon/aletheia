/*
 * function: func_02015CF8
 * address:  0x02015CF8
 * packet:   pkt_02015CF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0xF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015CF8(void *p, u32 *out)
{
    out[0] = *(u32 *)((char *)p + 0xF8);
    out[1] = *(u32 *)((char *)p + 0xFC);
    out[2] = *(u32 *)((char *)p + 0x100);
}
