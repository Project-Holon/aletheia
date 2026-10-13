/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005E30
 * packet:   pkt_02005DAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_FadeOutBgm
 *
 * symbols:
 *   sub_02005E30_State  0x020AA260  data
 *   GFL_USE_FlushBgmChange        0x02005FBC  thumb
 *   GFL_USE_GetCurrentSndHandle        0x0200590C  thumb
 *   NNS_SndHandleMoveVolume       0x02072F5C  arm
 *
 * The one-level form of src/matched/unit_02005DF8.c's GFL_USE_FadeInBgm: the same
 * state settle, one call instead of two, and the same word of the state block
 * written back.
 *
 * Its own byte range for an evidence reason and not a source one.  The three
 * `blx` sites that reach NNS_SndHandleMoveVolume image wide are 0x02005E16, 0x02005E22
 * and 0x02005E40; the first two are in unit_02005DF8.c and the third is this
 * function, so the two files witness each other's calls and neither may hold
 * all three.  See the header of unit_02005DF8.c and
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * The function after this range, GFL_USE_IsBgmFading, is already matched on its own
 * as src/matched/GFL_USE_IsBgmFading.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005E30.c \
 *       --addr 0x02005E30 --thumb
 */

typedef unsigned int u32;

struct Sub02005E30State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};

extern struct Sub02005E30State sub_02005E30_State;

extern void GFL_USE_FlushBgmChange(void);
extern u32 *GFL_USE_GetCurrentSndHandle(void);
struct Obj02072F5C;
extern void NNS_SndHandleMoveVolume(struct Obj02072F5C * volatile *pp, u32 a, u32 b);

void GFL_USE_FadeOutBgm(u32 a)
{
    GFL_USE_FlushBgmChange();
    NNS_SndHandleMoveVolume((struct Obj02072F5C * volatile*)GFL_USE_GetCurrentSndHandle(), 0, a);
    sub_02005E30_State.unk08 = a;
}
