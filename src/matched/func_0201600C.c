/*
 * function: func_0201600C
 * address:  0x0201600C
 * packet:   pkt_02015F50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Tests bit 12 of the
 * flag word at +0x140 (the bit func_02015F50 sets). A one-bit bitfield
 * keeps the original's lsls/lsrs pair; a mask would fold to `ands`.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct Flags0201600C {
    u32   : 12;
    u32 f : 1;
};

int func_0201600C(void *p)
{
    if (((struct Flags0201600C *)((char *)p + 0x140))->f) {
        return 1;
    }
    return 0;
}
