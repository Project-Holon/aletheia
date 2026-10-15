/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200DA64
 * packet:   pkt_0200D6D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GDS_PROFILE_GetScoreRecSize, GDS_PROFILE_ClearScoreRec, GDS_PROFILE_AddScoreRecTotal, GDS_PROFILE_SubScoreRecTotal,
 *           GDS_PROFILE_GetScoreRecTotal, GDS_PROFILE_MapScoreSlot, GDS_PROFILE_GetScoreRecCountA, GDS_PROFILE_GetScoreRecCountB,
 *           GDS_PROFILE_MaxScoreRecCountB, GDS_PROFILE_SetScoreRecCountA, GDS_PROFILE_ClearScoreRecCountC, GDS_PROFILE_SetScoreRecCountC,
 *           GDS_PROFILE_GetScoreRecCountC, GDS_PROFILE_IncScoreRecCountC, GDS_PROFILE_GetScoreRecCountCDec, GDS_PROFILE_ScoreRecFlag,
 *           GDS_PROFILE_IncScoreRecLevel, GDS_PROFILE_DecScoreRecLevel, GDS_PROFILE_GetScoreRecLevel, GDS_PROFILE_UpdateScoreRecStreak,
 *           GDS_PROFILE_SetScoreRecBlob, GDS_PROFILE_GetScoreRecBlob, GDS_PROFILE_CalcScoreRecScore, GDS_PROFILE_GetScoreRecScore,
 *           GDS_PROFILE_GetScoreRecScoreHigh
 *
 * 684 bytes, 0x0200DA64..0x0200DD10, 25 functions, eighteen of which carry no
 * label in the generated listing.
 *
 * A 0x1AC-byte save record of counters: one clamped total at +0x00, a streak
 * byte at +0x02, a level byte at +0x03 that the constructor seeds with 1, a
 * word of eleven flag bits at +0x04, three nine-entry `u16` arrays at +0x08,
 * +0x1A and +0x2C, a derived score at +0x3E, and two 0xB4-byte blobs at +0x44
 * and +0xF8.  The size getter and the constructor's `MI_CpuFill8(p, 0, 0x1AC)`
 * agree with 0xF8 + 0xB4, which is what pins the last field's length.
 *
 * Five things here are worth naming.
 *
 *  - GDS_PROFILE_MapScoreSlot is `bx lr` and nothing else, and it is a function, not
 *    padding: eight of the accessors `bl` it with the index in r0 and use
 *    the result.  It is `u32 f(u32 i) { return i; }`, an id-to-slot mapping
 *    that was never filled in, and the calls to it are what make the three
 *    arrays indexed rather than direct.
 *  - GDS_PROFILE_ScoreRecFlag takes a **signed** index, which the `blt` on the range
 *    check says and the `blo` inside the shift loop does not contradict: the
 *    loop counter is unsigned, so the comparison against it is unsigned too.
 *    Its switch bodies are emitted in the order 2, 1, 0, which is the order
 *    the source wrote them in; written 0, 1, 2 the case-2 body stops being
 *    the fall-through and the function grows a branch.
 *  - the mask is cleared with `~(u32)0 ^ mask`, not `~mask`: the original
 *    materialises the all-ones word with `movs r1, #0; mvns r1, r1` and then
 *    `eors`, which is two instructions where `mvns r1, r4` would have been
 *    one.
 *  - GDS_PROFILE_UpdateScoreRecStreak's two arms both end in a call to GDS_PROFILE_ScoreRecFlag followed
 *    by a store to +0x02, and the compiler cross-jumps them into one copy
 *    that each arm sets up its arguments for and branches to.  See
 *    docs/idioms/switch-arms-tail-merge.md.
 *  - in GDS_PROFILE_CalcScoreRecScore the two products are each truncated to `u16` and their
 *    sum is not.  Holding the sum in a `u16` adds a `lsls`/`lsrs` pair the
 *    original does not have, which is the whole of the difference between
 *    that function and EXACT.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

struct Blk1AC {
    u16 unk00;
    u8  unk02;
    u8  unk03;
    u32 unk04;
    u16 unk08[9];
    u16 unk1A[9];
    u16 unk2C[9];
    u16 unk3E;
    u32 unk40;
    u8  unk44[0xB4];
    u8  unkF8[0xB4];
};

struct Src {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u16 unk04;
    u16 unk06;
};

u32 GDS_PROFILE_MapScoreSlot(u32 i);
u32 GDS_PROFILE_ScoreRecFlag(struct Blk1AC *p, s32 i, u32 op);

u32 GDS_PROFILE_GetScoreRecSize(void)
{
    return sizeof(struct Blk1AC);
}

void GDS_PROFILE_ClearScoreRec(struct Blk1AC *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk1AC));
    p->unk03 = 1;
}

void GDS_PROFILE_AddScoreRecTotal(struct Blk1AC *p, s32 v)
{
    s32 n = p->unk00 + v;

    if (n > 9999) {
        p->unk00 = 9999;
    } else {
        p->unk00 = n;
    }
}

void GDS_PROFILE_SubScoreRecTotal(struct Blk1AC *p, u16 v)
{
    s16 n = (s16)p->unk00 - (s16)v;

    if (n >= 0) {
        p->unk00 = p->unk00 - v;
    } else {
        p->unk00 = 0;
    }
}

u16 GDS_PROFILE_GetScoreRecTotal(struct Blk1AC *p)
{
    return p->unk00;
}

u32 GDS_PROFILE_MapScoreSlot(u32 i)
{
    return i;
}

u16 GDS_PROFILE_GetScoreRecCountA(struct Blk1AC *p, u32 i)
{
    return p->unk08[GDS_PROFILE_MapScoreSlot(i)];
}

u16 GDS_PROFILE_GetScoreRecCountB(struct Blk1AC *p, u32 i)
{
    return p->unk1A[GDS_PROFILE_MapScoreSlot(i)];
}

void GDS_PROFILE_MaxScoreRecCountB(struct Blk1AC *p, u32 i, u16 v)
{
    u32 k = GDS_PROFILE_MapScoreSlot(i);

    if (p->unk1A[k] < v) {
        p->unk1A[k] = v;
    }
}

void GDS_PROFILE_SetScoreRecCountA(struct Blk1AC *p, u32 i, u16 v)
{
    p->unk08[GDS_PROFILE_MapScoreSlot(i)] = v;
}

void GDS_PROFILE_ClearScoreRecCountC(struct Blk1AC *p, u32 i)
{
    p->unk2C[GDS_PROFILE_MapScoreSlot(i)] = 0;
}

void GDS_PROFILE_SetScoreRecCountC(struct Blk1AC *p, u32 i)
{
    p->unk2C[GDS_PROFILE_MapScoreSlot(i)] = 1;
}

u32 GDS_PROFILE_GetScoreRecCountC(struct Blk1AC *p, u32 i)
{
    if (p->unk2C[GDS_PROFILE_MapScoreSlot(i)] != 0) {
        return 1;
    }
    return 0;
}

void GDS_PROFILE_IncScoreRecCountC(struct Blk1AC *p, u32 i)
{
    u32 k = GDS_PROFILE_MapScoreSlot(i);

    if (p->unk2C[k] < 0xFFFE) {
        p->unk2C[k] = p->unk2C[k] + 1;
    }
}

u16 GDS_PROFILE_GetScoreRecCountCDec(struct Blk1AC *p, u32 i)
{
    u16 n = p->unk2C[GDS_PROFILE_MapScoreSlot(i)] - 1;

    if ((s16)n < 0) {
        n = 0;
    }
    return n;
}

u32 GDS_PROFILE_ScoreRecFlag(struct Blk1AC *p, s32 i, u32 op)
{
    u32 j;
    u32 mask = 1;

    if (i >= 11) {
        return 0;
    }
    for (j = 0; j < i; j++) {
        mask <<= 1;
    }
    switch (op) {
    case 2:
        p->unk04 &= ~(u32)0 ^ mask;
        break;
    case 1:
        p->unk04 |= mask;
        break;
    case 0:
        return (p->unk04 >> i) & 1;
    }
    return 0;
}

void GDS_PROFILE_IncScoreRecLevel(struct Blk1AC *p)
{
    if (p->unk03 < 10) {
        p->unk03 = p->unk03 + 1;
    }
}

void GDS_PROFILE_DecScoreRecLevel(struct Blk1AC *p)
{
    if (p->unk03 > 1) {
        p->unk03 = p->unk03 - 1;
    }
}

u8 GDS_PROFILE_GetScoreRecLevel(struct Blk1AC *p)
{
    return p->unk03;
}

u8 GDS_PROFILE_UpdateScoreRecStreak(struct Blk1AC *p, u32 kind)
{
    switch (kind) {
    case 2:
        GDS_PROFILE_ScoreRecFlag(p, 0, 2);
        p->unk02 = 0;
        break;
    case 3:
        if (GDS_PROFILE_ScoreRecFlag(p, 0, 0)) {
            if (p->unk02 < 0xFF) {
                p->unk02 = p->unk02 + 1;
            }
        } else {
            GDS_PROFILE_ScoreRecFlag(p, 0, 1);
            p->unk02 = 1;
        }
        break;
    }
    return p->unk02;
}

void GDS_PROFILE_SetScoreRecBlob(struct Blk1AC *p, u32 which, const void *src)
{
    if (which == 0) {
        MI_CpuCopy8(src, p->unkF8, sizeof(p->unkF8));
    } else {
        MI_CpuCopy8(src, p->unk44, sizeof(p->unk44));
    }
}

void GDS_PROFILE_GetScoreRecBlob(struct Blk1AC *p, u32 which, void *dest)
{
    if (which == 0) {
        MI_CpuCopy8(p->unkF8, dest, sizeof(p->unkF8));
    } else {
        MI_CpuCopy8(p->unk44, dest, sizeof(p->unk44));
    }
}

void GDS_PROFILE_CalcScoreRecScore(struct Blk1AC *p, const struct Src *q)
{
    u16 a;
    u16 c;
    u16 d;
    s32 t;

    a = (q->unk02 - 1) * 1000;
    t = (u16)(q->unk04 * 10) + (u16)(q->unk03 * 20);
    if (t > 950) {
        c = 0;
    } else {
        c = 950 - t;
    }
    if (q->unk06 > 970) {
        d = 0;
    } else {
        d = (1000 - q->unk06) / 30;
    }
    p->unk3E = a + c + d;
}

u16 GDS_PROFILE_GetScoreRecScore(struct Blk1AC *p)
{
    return p->unk3E;
}

u8 GDS_PROFILE_GetScoreRecScoreHigh(struct Blk1AC *p)
{
    return p->unk3E / 1000;
}
