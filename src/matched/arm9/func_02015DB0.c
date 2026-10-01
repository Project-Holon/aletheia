/*
 * function: func_02015DB0
 * address:  0x02015DB0
 * packet:   pkt_02015DB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

void func_02015DB0(void *p)
{
    *(unsigned int *)((char *)p + 0x140) |= 0x100u;
}
