/*
 * function: func_02015D88
 * address:  0x02015D88
 * packet:   pkt_02015D88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Stores a halfword at +0x17A.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

void func_02015D88(char *p, u16 value)
{
    *(u16 *)(p + 0x17a) = value;
}
