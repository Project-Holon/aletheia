/*
 * unit:     no
 * function: func_02021548
 * address:  0x02021548
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fill one 0x14-byte slot of the palette-animation buffer array: the two
 * buffer pointers and their common size.  No relocations.
 *
 * The fifth argument arrives on the stack; with two registers pushed and no
 * frame it reads back at [sp, #8].
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021548.c \
 *       --func func_02021548 --addr 0x02021548 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct PalAnmSlot {
    void *unk_00;
    void *unk_04;
    u32   size;
    u32   unk_0c;
    u32   unk_10;
};

void func_02021548(struct PalAnmSlot *slots, u32 idx, void *a, void *b,
                   u32 size)
{
    slots[idx].unk_00 = a;
    slots[idx].unk_04 = b;
    slots[idx].size = size;
}
