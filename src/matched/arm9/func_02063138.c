/*
 * function: NNSi_G2dReserveOamManagerSpan
 * address:  0x02063138
 * packet:   pkt_02063000
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Reserves a span of OAM entries in bank g_02146BC8[which]: checks that
 * slotsA[first..last] are all free (0xFFFF), stamps them with the next
 * allocation id out of g_02146BC4, then does the same on the coarse
 * slotsB table at 1/4 granularity, fills the span record *s and returns 1
 * (0 as soon as either range is taken).
 *
 * WHAT CLOSED IT (wave 10), from 165 bytes out: the body is two inline
 * helpers used twice each, IsFree(tbl, first, last) (a pointer walk from
 * &tbl[first] to &tbl[last]) and Fill(tbl, first, last, id) (the
 * MIi_CpuClear16 call), with each check written `if (IsFree(..)) {...}
 * else return 0;` -- then-block first, which is what gives the image's two
 * branched-to `mov r0,#0; pop` failure tails.  Two register levers on top:
 *  - Fill's destination is spelled `(u8 *)tbl + first * 2`, a different
 *    expression from IsFree's `&tbl[first]`, so the image recomputes the
 *    address (`add r1, r4, r7, lsl #1`) instead of carrying a CSE copy
 *    across the loop;
 *  - the coarse table base is bound to a local (`coarse = bank->slotsB`),
 *    which becomes the image's in-place `add r4, r4, #0x500`.
 * ../2.0/sp2 as for the rest of the cluster.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G2dReserveOamManagerSpan.c
 *       --func NNSi_G2dReserveOamManagerSpan --addr 0x02063138 --arm --cc ../2.0/sp2
 *
 * symbols:
 *   g_02146BC8      0x02146BC8  data
 *   g_02146BC4      0x02146BC4  data  a2
 *   MIi_CpuClear16  0x02082A48  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct OamEntry { u16 attr0, attr1, attr2, affine; };
struct Bank { u16 slotsA[0x80]; struct OamEntry oam[0x80]; u16 slotsB[0x20]; };
struct Span {
    u32 which;
    u16 first;
    u16 last;
    u16 cur;
    u16 afirst;
    u16 alast;
    u16 acur;
    u16 id;
    u16 pad_12;
    u32 live;
};

extern struct Bank g_02146BC8[3];
extern u16 g_02146BC4;
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);

static inline void Fill(u16 *tbl, u16 first, u16 last, u16 id)
{
    MIi_CpuClear16(id, (u8 *)tbl + first * 2, (last - first + 1) * 2);
}

static inline u32 IsFree(u16 *tbl, u16 first, u16 last)
{
    u16 *p = &tbl[first];
    u16 *end = &tbl[last];
    for (; p <= end; p++) {
        if (*p != 0xFFFF)
            return 0;
    }
    return 1;
}

u32 NNSi_G2dReserveOamManagerSpan(struct Span *s, u16 first, u16 count, u32 which)
{
    struct Bank *bank = &g_02146BC8[which];
    u16 last = first + (count - 1);
    u16 afirst, alast;
    u16 *coarse;

    if (IsFree(bank->slotsA, first, last)) {
        s->id = g_02146BC4++;
        s->first = first;
        s->last = last;
        s->cur = first;
        Fill(bank->slotsA, first, last, s->id);
    } else {
        return 0;
    }

    afirst = first >> 2;
    alast = afirst + ((u16)(count >> 2) - 1);
    coarse = bank->slotsB;
    if (IsFree(coarse, afirst, alast)) {
        s->afirst = afirst;
        s->alast = alast;
        s->acur = afirst;
        Fill(coarse, afirst, alast, s->id);
    } else {
        return 0;
    }

    s->live = 1;
    s->which = which;
    return 1;
}
