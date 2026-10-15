/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200A6F8
 * packet:   pkt_0200A6F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MUSICAL_SAVE_ClearNewProps, MUSICAL_SAVE_CountOwnedProps, MUSICAL_SAVE_HasAllProps, MUSICAL_SAVE_GetProgram,
 *           MUSICAL_SAVE_GetShowCount, MUSICAL_SAVE_IncrementShowCount, MUSICAL_SAVE_GetTopRankCount, MUSICAL_SAVE_IncrementTopRankCount,
 *           MUSICAL_SAVE_GetEquippedProp, MUSICAL_SAVE_SetEquippedProp, MUSICAL_SAVE_GetSelectedProgram, MUSICAL_SAVE_SetSelectedProgram,
 *           MUSICAL_SAVE_GetScriptSetting, MUSICAL_SAVE_SetScriptSetting, MUSICAL_SAVE_GetHasDistData, MUSICAL_SAVE_SetHasDistData,
 *           MUSICAL_SAVE_AddFanPoints, MUSICAL_SAVE_GetStageData, MUSICAL_SAVE_GetFanPoints, MUSICAL_SAVE_GetFittingSetting,
 *           MUSICAL_SAVE_SetFittingSetting
 *
 * 328 bytes, 0x0200A6F8..0x0200A840, 21 functions, and the direct
 * continuation of src/matched/unit_0200A3FC.c: every one of them reaches the
 * same 0x2A4-byte `struct Big`, and the accessors here are what pin the last
 * quarter of its layout (three counters at 0x252, 0x254 and 0x256, a
 * four-entry byte array at 0x298 and four separate bytes at 0x29C..0x29F).
 *
 * Fourteen of the twenty-one carry no label in the generated listing: none of
 * them saves lr, so disasm.py's prologue sweep does not fire and the listing
 * prints their bytes as `.word` data.  They are the accessor half of the file
 * and were read out of those words, the same way the sixteen accessors of
 * unit_0200852C.c were.
 *
 * 0x0200A6F8 is the one docs/MATCHING.md already named under "The two
 * missing labels": the 28-byte loop that clears the second of the two
 * bitmaps MUSICAL_SAVE_AddProp sets a bit in.  It is in
 * layout/function_starts.txt, attested by the bl from ov133 at 0x021B62A2,
 * which is why it has a label here and its fourteen neighbours do not.
 *
 * 0x0200A714 counts how many of the 256 bit positions are set in the first
 * bitmap by calling MUSICAL_SAVE_IsPropOwned on every one of them, and 0x0200A73C asks
 * whether that count has reached 100, which is the same bound the three
 * bitmap routines in unit_0200A3FC.c check their index against.  So 100 is
 * the population of whatever the bitmap enumerates and this pair is its
 * "have you seen all of them" test.
 *
 * Two details pin source shapes here, both of them one-line fixes that look
 * like body diffs:
 *
 *  - in 0x0200A714 the accumulator has to be declared before the loop
 *    counter.  Declared the other way round the two locals swap registers,
 *    which is six differing bytes spread over the whole function and nothing
 *    else.  Same finding as docs/idioms/local-declaration-order-is-stack-
 *    order.md, one level up: the rule holds for register-allocated locals and
 *    not only for stack slots.
 *  - 0x0200A800 saturates at 0xFFFF, and the source tests `v < 0xFFFF` with
 *    the saturating store in the `else`.  Written the other way round the
 *    compiler emits `blt` where the original has `bge` and swaps the two
 *    stores, which is four bytes and reads as a different function.
 *
 * symbols:
 *   MUSICAL_SAVE_IsPropOwned  0x0200A644  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct BigSub6 { u8 unk0; u8 unk1[5]; };
struct BigSub4 { u8 unk0; u8 unk1[3]; };

struct Big {
    u8 unk000[0x1B0];
    struct BigSub6 unk1B0[8];
    struct BigSub4 unk1E0[10];
    u8  unk208[0x4A];
    u16 unk252;
    u16 unk254;
    u16 unk256;
    u8  unk258[0x20];
    u8  unk278[0x20];
    u8  unk298[4];
    u8  unk29C;
    u8  unk29D;
    u8  unk29E;
    u8  unk29F;
    u8  unk2A0[4];
};

extern u32 MUSICAL_SAVE_IsPropOwned(struct Big *p, u8 index);

u32 MUSICAL_SAVE_CountOwnedProps(struct Big *p);

void MUSICAL_SAVE_ClearNewProps(struct Big *p)
{
    u8 i;

    for (i = 0; i < 0x20; i++) {
        p->unk278[i] = 0;
    }
}

u32 MUSICAL_SAVE_CountOwnedProps(struct Big *p)
{
    u32 count;
    s32 i;

    count = 0;
    for (i = 0; i < 256; i++) {
        if (MUSICAL_SAVE_IsPropOwned(p, (u8)i) == 1) {
            count++;
        }
    }
    return count;
}

u32 MUSICAL_SAVE_HasAllProps(struct Big *p)
{
    if (MUSICAL_SAVE_CountOwnedProps(p) == 100) {
        return 1;
    }
    return 0;
}

struct BigSub4 *MUSICAL_SAVE_GetProgram(struct Big *p, u32 index)
{
    return &p->unk1E0[index];
}

u16 MUSICAL_SAVE_GetShowCount(struct Big *p)
{
    return p->unk252;
}

void MUSICAL_SAVE_IncrementShowCount(struct Big *p)
{
    if (p->unk252 < 0xFFFF) {
        p->unk252++;
    }
}

u16 MUSICAL_SAVE_GetTopRankCount(struct Big *p)
{
    return p->unk254;
}

void MUSICAL_SAVE_IncrementTopRankCount(struct Big *p)
{
    if (p->unk254 < 0xFFFF) {
        p->unk254++;
    }
}

u8 MUSICAL_SAVE_GetEquippedProp(struct Big *p, u32 index)
{
    return p->unk298[index];
}

void MUSICAL_SAVE_SetEquippedProp(struct Big *p, u32 index, u8 value)
{
    p->unk298[index] = value;
}

u8 MUSICAL_SAVE_GetSelectedProgram(struct Big *p)
{
    return p->unk29C;
}

void MUSICAL_SAVE_SetSelectedProgram(struct Big *p, u8 value)
{
    p->unk29C = value;
}

u8 MUSICAL_SAVE_GetScriptSetting(struct Big *p)
{
    return p->unk29D;
}

void MUSICAL_SAVE_SetScriptSetting(struct Big *p, u8 value)
{
    p->unk29D = value;
}

u8 MUSICAL_SAVE_GetHasDistData(struct Big *p)
{
    return p->unk29E;
}

void MUSICAL_SAVE_SetHasDistData(struct Big *p, u8 value)
{
    p->unk29E = value;
}

u8 *MUSICAL_SAVE_GetStageData(struct Big *p)
{
    return p->unk208;
}

void MUSICAL_SAVE_AddFanPoints(struct Big *p, s32 delta)
{
    s32 v = p->unk256 + delta;

    if (v < 0xFFFF) {
        p->unk256 = v;
    } else {
        p->unk256 = 0xFFFF;
    }
}

u16 MUSICAL_SAVE_GetFanPoints(struct Big *p)
{
    return p->unk256;
}

u32 MUSICAL_SAVE_GetFittingSetting(struct Big *p)
{
    return p->unk29F;
}

void MUSICAL_SAVE_SetFittingSetting(struct Big *p, u8 value)
{
    p->unk29F = value;
}
