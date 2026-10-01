/*
 * function: func_02015C60
 * address:  0x02015C60
 * packet:   pkt_02015C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x11C. Twin of func_02015C78.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015C60(void *p, u32 *out)
{
    out[0] = *(u32 *)((char *)p + 0x11C);
    out[1] = *(u32 *)((char *)p + 0x120);
    out[2] = *(u32 *)((char *)p + 0x124);
}
