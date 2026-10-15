/*
 * function: BG_SYS_SetScroll
 * address:  0x02040820
 * packet:   pkt_02040618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetScrollField  0x02042360  arm
 *   BG_SYS_SetScrollRegs  0x02040860  arm
 *   g_BgConfig     0x02146A44  data
 *
 * The affine entry point of the same BG scroll module as BG_SYS_FillScrollArea:
 * refresh the layer's record through BG_SYS_SetScrollField, then hand the affine
 * transform on to BG_SYS_SetScrollRegs, which picks the hardware block from the
 * layer number.
 *
 * Parameters 2 and 3 are genuinely dead here.  Nothing sets r1 or r2
 * before either call, and BG_SYS_SetScrollField takes one argument (the same call
 * in BG_SYS_FillScrollArea reaches it with r1 and r2 holding that function's own
 * untouched parameters), so this really is a wrapper that keeps an argument
 * shape it does not use rather than a forwarding call with extra arguments.
 * The four arguments BG_SYS_SetScrollRegs does take are parameters 1, 4, 5 and 6,
 * the last two read back off the caller's stack at +0x10 and +0x14.
 *
 * The argument to BG_SYS_SetScrollField is spelled with the constant added to the
 * table base before the scaled index, so that it parses as
 * ((base + 8) + index): here the compiler folds the whole thing into one
 * `add ip, ip, #8` and one `mla`, which is the direct confirmation that the
 * same expression in BG_SYS_FillScrollArea has to be written the same way round.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_SetScroll.c \
 *       --func BG_SYS_SetScroll --addr 0x02040820 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct BgLayer {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 scrollX;
    u32 scrollY;
    u8  mode;
    u8  unk1D;
    u8  unk1E;
    u8  unk1F;
    u32 unk20;
    u32 unk24;
    u32 unk28;
};

extern struct BgLayer *g_BgConfig;

extern void BG_SYS_SetScrollField(void *p, u32 a, u32 b);
extern void BG_SYS_SetScrollRegs(u32 layer, u32 a, u32 b, u32 c);

void BG_SYS_SetScroll(u32 layer, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    BG_SYS_SetScrollField((u8 *)g_BgConfig + 8 + layer * sizeof(struct BgLayer), a, b);
    BG_SYS_SetScrollRegs(layer, c, d, e);
}

