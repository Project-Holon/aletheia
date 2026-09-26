/*
 * function: func_02015EA0
 * address:  0x02015EA0
 * packet:   pkt_02015EA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 11 (0x800) of the
 * 32-bit register at +0x140. Pairs with func_02015EB0, which clears it.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015EA0(void *p)
{
    *(volatile u32 *)((char *)p + 0x140) |= 0x800u;
}
