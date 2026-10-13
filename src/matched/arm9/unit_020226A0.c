/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020226A0
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WIPE_SUB_ClearSys, WIPE_SUB_PatternFadeOut
 *
 * symbols:
 *   WIPE_SUB_FadeStart  0x020229A4  thumb
 *   WIPE_SUB_FadeMain  0x02022A44  thumb
 *
 * WIPE_SUB_ClearSys is five back-to-back MI_CpuFill8 zero-fills over five
 * sub-ranges of one object (sizes 0x14, 0x30, 0x30, 0x18, 0xC0 at offsets
 * 0, 0x14, 0x44, 0x74, 0x8C); it is one of the "0x0209F5xx/0x0209F6xx"
 * cluster's neighbours and clears the object the setup functions in
 * src/matched/WIPE_SUB_PatternBoxOpenOut.c and siblings configure.
 *
 * WIPE_SUB_PatternFadeOut checks a delegate pointer at +0xc, the same guard shape as
 * that cluster: when set, the call forwards to WIPE_SUB_FadeMain and returns
 * its result; the fall-through has to be written on the guard's
 * complement (`== 0`) with the delegate call left unconditional after it,
 * or the two blocks come out in the wrong order.  The fall-through sets
 * the flag pair at +0x28 and +0x2c to (1, 1) and calls WIPE_SUB_FadeStart(p, 1).
 *
 * WIPE_SUB_PatternFadeIn, immediately after this range, is the same shape again
 * with (0, 1) and mode 0 (src/matched/WIPE_SUB_PatternFadeIn.c); it is kept in its
 * own file specifically so that its calls to WIPE_SUB_FadeStart and
 * WIPE_SUB_FadeMain stay outside this range and keep attesting them, and vice
 * versa (docs/MATCHING.md, "the label class" and "the pairwise case across
 * two files").  Bundling all three into one file drops both relocations to
 * MATCH, because each one's only other witness is then inside the same
 * compared range.
 *
 * WIPE_SUB_ClearSys alone comes out EXACT* against `one`: its own extent runs
 * two bytes into the ordinary linker fill in front of WIPE_SUB_PatternFadeOut, which
 * is a real, separately-matched function and not an unlabelled follower.
 * Pairing the two in one translation unit lets `tu` lay out both sections
 * with that fill in between, which reproduces cleanly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020226A0.c \
 *       --addr 0x020226A0 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *dst, u8 data, u32 size);

void WIPE_SUB_ClearSys(u8 *p)
{
    MI_CpuFill8(p, 0, 0x14);
    MI_CpuFill8(p + 0x14, 0, 0x30);
    MI_CpuFill8(p + 0x44, 0, 0x30);
    MI_CpuFill8(p + 0x74, 0, 0x18);
    MI_CpuFill8(p + 0x8C, 0, 0xC0);
}

struct Obj {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x28 - 0x10];
    u32 unk28;
    u32 unk2C;
};

struct Task;
extern void WIPE_SUB_FadeStart(struct Task *t, u32 dir);
extern u32 WIPE_SUB_FadeMain(struct Task *t);

u32 WIPE_SUB_PatternFadeOut(struct Obj *p)
{
    if (p->unk0C == 0) {
        p->unk28 = 1;
        p->unk2C = 1;
        WIPE_SUB_FadeStart((struct Task *)p, 1);
        return 0;
    }
    return WIPE_SUB_FadeMain((struct Task *)p);
}
