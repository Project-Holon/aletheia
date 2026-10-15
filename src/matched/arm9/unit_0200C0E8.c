/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200C0E8
 * packet:   pkt_0200C0E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BEACON_GetFromSave, BEACON_GetBlock, BEACON_SetInputFlag, BEACON_GetInputFlag,
 *           BEACON_ClearInputFlags, BEACON_SetSelect, BEACON_GetSelect, BEACON_GetBestScore,
 *           BEACON_SetBestScore, BEACON_GetRank, BEACON_SetRank, BEACON_GetGreetCount,
 *           BEACON_IncrementGreetCount, BEACON_GetThanksCount, BEACON_IncrementThanksCount, BEACON_GetGreetMessage,
 *           BEACON_SetGreetMessage, BEACON_GetThanksMessage, BEACON_SetThanksMessage, BEACON_GetMode,
 *           BEACON_SetMode, BEACON_GetFlag, BEACON_SetFlag, BEACON_CountFlags,
 *           BEACON_GetPoints, BEACON_AddPoints, BEACON_SubPoints, BEACON_SetTeam,
 *           BEACON_GetTeam, BEACON_SetSlotState, BEACON_GetSlotState, BEACON_GetSlotStates,
 *           BEACON_SetSlotStates, BEACON_GetEntryCount, BEACON_SetEntryCount, BEACON_GetRecentId,
 *           BEACON_SetRecentId, BEACON_GetRecentValue, BEACON_SetRecentValue, BEACON_AddRecentValue,
 *           BEACON_GetLastTime, BEACON_SetLastTime, BEACON_SetHashedId, BEACON_GetHashedId,
 *           BEACON_GetGatePoints, BEACON_SetGatePoints, BEACON_SubGatePoints, BEACON_GetRecorderFlag,
 *           BEACON_SetRecorderFlag
 *
 * 780 bytes, 0x0200C0E8..0x0200C3F4, 49 functions, forty-four of which carry
 * no label in the generated listing: the file is almost entirely accessors
 * and none of them saves lr.
 *
 * The object is the save block with id 0x34: BEACON_GetBlock is the whole of
 * its lookup, `func_020071CC(sys, 0x34)`, and BEACON_GetFromSave is a wrapper
 * that forwards to it.  The layout below is read off the accessors and is
 * self-consistent to the byte from +0x00 to +0xE2; nothing here returns
 * sizeof, because the size getter of this block belongs to whatever file
 * precedes it, so the tail past +0xE2 is not pinned.
 *
 * Three things in it cost real time.
 *
 *  - BEACON_GetSelect takes a **const** pointer, and that is the whole
 *    difference between it and the twelve-byte-longer version.  Its three
 *    bitfield reads come out of one `ldrb` in the original, and through a
 *    non-const pointer this compiler reloads the byte before each of the two
 *    later ones, because the intervening `str` through a `u32 *` may alias
 *    it.  See docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *  - BEACON_SubGatePoints goes the other way and reads +0xE0 twice, once for the
 *    compare and once for the subtraction, with the address recomputed each
 *    time.  Nothing that leaves the field ordinary reproduces that: the
 *    compiler folds the two reads into one under every spelling of the
 *    branch, the arms, the cast and the pointer.  Declaring the field
 *    `volatile` is what keeps both reads, and it costs nothing in the getter
 *    and setter on either side of it, which touch it once each.
 *  - the pair at +0x50 is one `u64` read back as two words, the union of
 *    docs/idioms/long-long-aligns-to-four.md: BEACON_GetLastTime returns the
 *    64-bit value and BEACON_SetLastTime stores the two halves from two register
 *    arguments.
 *
 * symbols:
 *   STRBUF_ToChars  0x02045A38  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct U16Vec;
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

struct Ent58 {
    u16 v[6];
};

struct Bits0A {
    u8 f0 : 6;
    u8 f6 : 1;
    u8 f7 : 1;
};

union U64Pair {
    unsigned long long q;
    struct {
        u32 lo;
        u32 hi;
    } w;
};

struct Blk34 {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    struct Bits0A unk0A;
    u8  unk0B;
    u8  unk0C[8];
    u32 f14_0  : 28;
    u32 f14_28 : 4;
    u32 unk18;
    u32 unk1C;
    u16 unk20[9];
    u16 unk32[9];
    u8  unk44;
    u8  unk45;
    u8  unk46;
    u8  unk47[3];
    u16 unk4A[3];
    union U64Pair unk50;
    struct Ent58 unk58[8];
    u32 unkB8[8];
    u32 unkD8;
    u32 unkDC;
    volatile u16 unkE0;
    u16 unkE2;
};

void *BEACON_GetBlock(void *sys);

void *BEACON_GetFromSave(void *sys)
{
    return BEACON_GetBlock(sys);
}

void *BEACON_GetBlock(void *sys)
{
    return func_020071CC(sys, 0x34);
}

void BEACON_SetInputFlag(struct Blk34 *p, u32 i, u8 v)
{
    p->unk0C[i] = v;
}

u8 BEACON_GetInputFlag(struct Blk34 *p, u32 i)
{
    return p->unk0C[i];
}

void BEACON_ClearInputFlags(struct Blk34 *p)
{
    MI_CpuFill8(p->unk0C, 0, sizeof(p->unk0C));
}

void BEACON_SetSelect(struct Blk34 *p, u16 a, u32 b, u32 c, u32 d)
{
    p->unk08 = a;
    p->unk0A.f0 = b;
    p->unk0A.f6 = c;
    p->unk0A.f7 = (d == 1);
}

void BEACON_GetSelect(const struct Blk34 *p, u32 *a, u32 *b, u32 *c, u32 *d)
{
    *a = p->unk08;
    *b = p->unk0A.f0;
    *c = p->unk0A.f6;
    *d = p->unk0A.f7;
}

u32 BEACON_GetBestScore(struct Blk34 *p)
{
    return p->f14_0;
}

void BEACON_SetBestScore(struct Blk34 *p, u32 v)
{
    p->f14_0 = v;
}

u8 BEACON_GetRank(struct Blk34 *p)
{
    return p->f14_28;
}

void BEACON_SetRank(struct Blk34 *p, u32 v)
{
    p->f14_28 = v;
}

u32 BEACON_GetGreetCount(struct Blk34 *p)
{
    return p->unk18;
}

u32 BEACON_IncrementGreetCount(struct Blk34 *p)
{
    if (p->unk18 < 99999) {
        p->unk18++;
    }
    return p->unk18;
}

u32 BEACON_GetThanksCount(struct Blk34 *p)
{
    return p->unk1C;
}

u32 BEACON_IncrementThanksCount(struct Blk34 *p)
{
    if (p->unk1C < 99999) {
        p->unk1C++;
    }
    return p->unk1C;
}

u16 *BEACON_GetGreetMessage(struct Blk34 *p)
{
    return p->unk20;
}

void BEACON_SetGreetMessage(struct Blk34 *p, const u16 *src)
{
    STRBUF_ToChars((struct U16Vec *)src, p->unk20, 9);
}

u16 *BEACON_GetThanksMessage(struct Blk34 *p)
{
    return p->unk32;
}

void BEACON_SetThanksMessage(struct Blk34 *p, const u16 *src)
{
    STRBUF_ToChars((struct U16Vec *)src, p->unk32, 9);
}

u8 BEACON_GetMode(struct Blk34 *p)
{
    return p->unk44;
}

void BEACON_SetMode(struct Blk34 *p, u8 v)
{
    p->unk44 = v;
}

u32 BEACON_GetFlag(struct Blk34 *p, u32 bit)
{
    return (p->unk04 & (1 << bit)) != 0;
}

void BEACON_SetFlag(struct Blk34 *p, u32 bit)
{
    p->unk04 |= 1 << bit;
}

u32 BEACON_CountFlags(struct Blk34 *p)
{
    u32 n = 0;
    u32 v;

    for (v = p->unk04; v != 0; v >>= 1) {
        if (v & 1) {
            n++;
        }
    }
    return n;
}

u32 BEACON_GetPoints(struct Blk34 *p)
{
    return p->unk00;
}

u32 BEACON_AddPoints(struct Blk34 *p, u32 v)
{
    if (v > 9999999) {
        p->unk00 = 9999999;
    } else {
        p->unk00 += v;
    }
    if (p->unk00 > 9999999) {
        p->unk00 = 9999999;
    }
    return p->unk00;
}

u32 BEACON_SubPoints(struct Blk34 *p, u32 v)
{
    if (p->unk00 < v) {
        p->unk00 = 0;
    } else {
        p->unk00 -= v;
    }
    return p->unk00;
}

void BEACON_SetTeam(struct Blk34 *p, u32 i, const u16 *src)
{
    s32 j;

    for (j = 0; j < 6; j++) {
        p->unk58[i].v[j] = src[j];
    }
}

void BEACON_GetTeam(struct Blk34 *p, u32 i, u16 *dest)
{
    s32 j;

    for (j = 0; j < 6; j++) {
        dest[j] = p->unk58[i].v[j];
    }
}

void BEACON_SetSlotState(struct Blk34 *p, u32 i, u8 v)
{
    p->unk45 |= (u8)(v << (i * 2));
}

u8 BEACON_GetSlotState(struct Blk34 *p, u32 i)
{
    return (u8)((p->unk45 >> (i * 2)) & 3);
}

u8 BEACON_GetSlotStates(struct Blk34 *p)
{
    return p->unk45;
}

void BEACON_SetSlotStates(struct Blk34 *p, u8 v)
{
    p->unk45 = v;
}

u8 BEACON_GetEntryCount(struct Blk34 *p)
{
    return p->unk46;
}

void BEACON_SetEntryCount(struct Blk34 *p, u8 v)
{
    p->unk46 = v;
}

int BEACON_GetRecentId(struct Blk34 *p, u32 i)
{
    return p->unk47[i];
}

void BEACON_SetRecentId(struct Blk34 *p, u8 i, u8 v)
{
    p->unk47[i] = v;
}

u16 BEACON_GetRecentValue(struct Blk34 *p, u32 i)
{
    return p->unk4A[i];
}

void BEACON_SetRecentValue(struct Blk34 *p, u32 i, int v)
{
    p->unk4A[i] = v;
}

void BEACON_AddRecentValue(struct Blk34 *p, u8 i, int v)
{
    u32 n = p->unk4A[i];

    n += v;
    if (n > 0xFFFF) {
        n = 0xFFFF;
    }
    p->unk4A[i] = n;
}

unsigned long long BEACON_GetLastTime(struct Blk34 *p)
{
    return p->unk50.q;
}

void BEACON_SetLastTime(struct Blk34 *p, u32 lo, u32 hi)
{
    p->unk50.w.lo = lo;
    p->unk50.w.hi = hi;
}

void BEACON_SetHashedId(struct Blk34 *p, s32 i, u32 v)
{
    if (i < 8) {
        p->unkB8[i] = v;
    }
}

u32 BEACON_GetHashedId(struct Blk34 *p, s32 i)
{
    if (i >= 8) {
        return 0;
    }
    return p->unkB8[i];
}

u16 BEACON_GetGatePoints(struct Blk34 *p)
{
    return p->unkE0;
}

void BEACON_SetGatePoints(struct Blk34 *p, u16 v)
{
    p->unkE0 = v;
}

void BEACON_SubGatePoints(struct Blk34 *p, u16 v)
{
    if (v <= p->unkE0) {
        p->unkE0 = p->unkE0 - v;
    } else {
        p->unkE0 = 0;
    }
}

u8 BEACON_GetRecorderFlag(struct Blk34 *p)
{
    return p->unkDC;
}

void BEACON_SetRecorderFlag(struct Blk34 *p, u32 v)
{
    p->unkDC = v;
}
