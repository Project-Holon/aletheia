/*
 * function: func_02015EB0
 * address:  0x02015EB0
 * packet:   pkt_02015EB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word; the live bytes decode as Thumb). Clears bit 11
 * (0x800) of the 32-bit field at +0x140. This is one of the pair
 * func_02015EA0/func_02015EB0 that set and clear the same bit; it is called
 * from the ov118 event state machine at 0x021D7130 and from
 * func_021D6E04, and is an image-wide-only reference target (no func_ label),
 * so matching it supplies the `matched` witness those callers lack.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_02015EB0(void *p)
{
    *(volatile u32 *)((char *)p + 0x140) &= 0xFFFFF7FFu;
}
