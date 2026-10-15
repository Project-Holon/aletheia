/*
 * unit:     no
 * function: BG_SYS_DecodeTile
 * address:  0x02040AE0
 * packet:   pkt_020409E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_DecodeTileSource  0x02040AF0  arm
 *
 * A four-instruction forwarder that binds the tile offset of BG_SYS_DecodeTileSource
 * to zero.  It has no label in the listing: the prologue saves nothing, so
 * disasm.py's rule does not see it and the whole function reads as part of
 * BG_SYS_PushTileSource's literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  This is
 * also why BG_SYS_PushTileSource verifies EXACT*, its inferred extent running on
 * to 0x02040AF0; 0x02040AE0 wants seeding into
 * layout/function_starts.txt.
 *
 * The tail call is the usual pool word and `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), through ip rather than
 * r3 so the fourth argument register is still free to carry the zero
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DecodeTile.c \
 *       --func BG_SYS_DecodeTile --addr 0x02040AE0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void BG_SYS_DecodeTileSource(u32 index, const void *src, u32 mode, u32 offset);

void BG_SYS_DecodeTile(u32 index, const void *src, u32 mode)
{
    BG_SYS_DecodeTileSource(index, src, mode, 0);
}
