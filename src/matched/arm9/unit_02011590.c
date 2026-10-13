/*
 * unit:     yes
 * function: ICA_ANIME_IncFrameLoop
 * address:  0x02011590
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ICA_ANIME_LoadFrames     0x0201183C  thumb
 *
 * ica_anime.c, 0x02011590..0x02011610: the frame-clock advance and its two
 * neighbours, plus the two four-byte getters that sit between them (they
 * carry no label because they have no prologue, so they are written here as
 * what they are).
 *
 *   ICA_ANIME_IncFrameLoop   advance the clock, reset it if the frame count is
 *                   reached, and poke the animation when the new frame falls
 *                   outside [f14, f14 + f18)
 *   ICA_ANIME_IncFrameNoLoop   the same advance but returning "already finished" when
 *                   the frame at entry is past the count
 *   ICA_ANIME_SetFrame   set the clock outright
 *   (0x02011608)    getter: +0x0C
 *   (0x0201160C)    getter: +0x10
 *
 * The range check is one disjunction in every case: the original reaches the
 * single `bl ICA_ANIME_LoadFrames` from both compares.
 *
 * Signedness: the frame is `f10 >> 12` with an arithmetic shift (asrs), but
 * the compare against f0c is unsigned (bhi/bhs), so f0c is a u32 field while
 * the clock and the frame bounds are s32.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011590.c \
 *       --addr 0x02011590 --thumb
 */

typedef unsigned char  u8;
typedef signed int     s32;
typedef unsigned int  u32;

struct IcaAnime {
    u8  pad00[0x0C];
    u32 f0c;        /* +0x0C */
    s32 f10;        /* +0x10 */
    s32 f14;        /* +0x14 */
    s32 f18;        /* +0x18 */
};

extern void ICA_ANIME_LoadFrames(struct IcaAnime *p, s32 v);

u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32 v)
{
    s32 f;
    u32 r = 0;

    p->f10 = p->f10 + v;
    f = p->f10 >> 12;
    if (p->f0c <= (u32)f) {
        p->f10 = 0;
        f = 0;
        r = 1;
    }
    if (f < p->f14 || (p->f14 + p->f18) <= f)
        ICA_ANIME_LoadFrames(p, p->f10);
    return r;
}

u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *p, s32 v)
{
    s32 f = p->f10 >> 12;

    if ((u32)f < p->f0c) {
        p->f10 = p->f10 + v;
        f = p->f10 >> 12;
        if (f < p->f14 || (p->f14 + p->f18) <= f)
            ICA_ANIME_LoadFrames(p, p->f10);
        return 0;
    }
    return 1;
}

void ICA_ANIME_SetFrame(struct IcaAnime *p, s32 v)
{
    s32 f = v >> 12;

    p->f10 = v;
    if (f < p->f14 || (p->f14 + p->f18) <= f)
        ICA_ANIME_LoadFrames(p, v);
}

u32 ICA_ANIME_GetFrameNum(struct IcaAnime *p)
{
    return p->f0c;
}

s32 ICA_ANIME_GetFrame(struct IcaAnime *p)
{
    return p->f10;
}
