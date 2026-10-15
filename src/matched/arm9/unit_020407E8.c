/*
 * unit:     yes
 * function: BG_SYS_GetScrollX, BG_SYS_GetScrollY
 * address:  0x020407E8
 * packet:   pkt_02040618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_BgConfig  0x02146A44  data
 *
 * The two scroll-register accessors for the BG configuration table, both of
 * them leaf functions that save nothing and therefore carry no `func_` label
 * in the listing at all: they print as an anonymous run of `.word`s between
 * the literal pool of BG_SYS_FillScrollArea and the next labelled function at
 * 0x02040820 (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * They were found by sweeping the address range, not by reading labels.
 *
 * Both index the same 0x2C-byte per-layer record hanging off the single
 * pointer at 0x02146A44, and return the horizontal (+0x14) and vertical
 * (+0x18) scroll values that BG_SYS_FillScrollArea flushes to the hardware.  The
 * `mla r1, r0, r1, r2` is the array subscript: 0x2C is not a shift, so the
 * scale is a real multiply folded into the base add.
 *
 * Kept as one unit rather than two files because the pair is contiguous and
 * the whole 56-byte range, both literal pools included, reproduces exactly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020407E8.c \
 *       --addr 0x020407E8 --arm --cc 1.1p1
 */

typedef unsigned int u32;

struct BgLayer {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 scrollX;
    u32 scrollY;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
};

extern struct BgLayer *g_BgConfig;

u32 BG_SYS_GetScrollX(u32 layer)
{
    return g_BgConfig[layer].scrollX;
}

u32 BG_SYS_GetScrollY(u32 layer)
{
    return g_BgConfig[layer].scrollY;
}
