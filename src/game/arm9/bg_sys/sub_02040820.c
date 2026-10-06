/*
 * function: sub_02040820
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
 *   func_02042360  0x02042360  arm
 *   func_02040860  0x02040860  arm
 *   g_BgConfig     0x02146A44  data
 *
 * The affine entry point of the same BG scroll module as sub_02040618:
 * refresh the layer's record through func_02042360, then hand the affine
 * transform on to func_02040860, which picks the hardware block from the
 * layer number.
 *
 * Parameters 2 and 3 are genuinely dead here.  Nothing sets r1 or r2
 * before either call, and func_02042360 takes one argument (the same call
 * in sub_02040618 reaches it with r1 and r2 holding that function's own
 * untouched parameters), so this really is a wrapper that keeps an argument
 * shape it does not use rather than a forwarding call with extra arguments.
 * The four arguments func_02040860 does take are parameters 1, 4, 5 and 6,
 * the last two read back off the caller's stack at +0x10 and +0x14.
 *
 * The argument to func_02042360 is spelled with the constant added to the
 * table base before the scaled index, so that it parses as
 * ((base + 8) + index): here the compiler folds the whole thing into one
 * `add ip, ip, #8` and one `mla`, which is the direct confirmation that the
 * same expression in sub_02040618 has to be written the same way round.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02040820.c \
 *       --func sub_02040820 --addr 0x02040820 --cc 1.1p1 --arm
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

extern void func_02042360(void *p, u32 a, u32 b);
extern void func_02040860(u32 layer, u32 a, u32 b, u32 c);

void sub_02040820(u32 layer, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    func_02042360((u8 *)g_BgConfig + 8 + layer * sizeof(struct BgLayer), a, b);
    func_02040860(layer, c, d, e);
}

