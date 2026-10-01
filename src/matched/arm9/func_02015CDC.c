/*
 * function: func_02015CDC
 * address:  0x02015CDC
 * packet:   pkt_02015CDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x128. Inverse of func_02015CC4.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015CDC(void *p, u32 *src)
{
    *(u32 *)((char *)p + 0x128) = src[0];
    *(u32 *)((char *)p + 0x12C) = src[1];
    *(u32 *)((char *)p + 0x130) = src[2];
}
