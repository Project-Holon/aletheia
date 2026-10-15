/*
 * unit:     no
 * address:  0x02030BC8
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_FreeSystemChecked
 *
 * symbols:
 *   GFL_HEAP_FreeSystem  0x020305E4  arm
 *
 * A four-instruction tail call to GFL_HEAP_FreeSystem (src/matched/GFL_HEAP_FreeSystem.c,
 * pkt_02030534), attested by the `matched` class: GFL_HEAP_FreeSystem's own EXACT
 * entry pins its address, and this call is the only branch to it found in
 * the ROM.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_FreeSystemChecked.c \
 *       --func GFL_HEAP_FreeSystemChecked --addr 0x02030BC8 --cc 1.1p1
 */

typedef unsigned int u32;

extern int GFL_HEAP_FreeSystem(u32 idx);

int GFL_HEAP_FreeSystemChecked(u32 idx)
{
    return GFL_HEAP_FreeSystem(idx);
}
