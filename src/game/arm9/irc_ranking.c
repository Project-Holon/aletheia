/*
 * file:     irc_ranking.c
 * unit:     yes
 * function: IRC_RANKING_GetFromSave, IRC_RANKING_GetEntryCount, IRC_RANKING_GetEntry, IRC_RANKING_GetEntryScore, IRC_RANKING_GetEntryMeetCount, IRC_RANKING_GetEntryGender, IRC_RANKING_GetEntryProfile, IRC_RANKING_GetLastSlot, IRC_RANKING_FindClosestEntry, IRC_RANKING_IsEntryNew, IRC_RANKING_HasEntry, IRC_RANKING_GetDateScore, IRC_RANKING_AddEntry, IRC_RANKING_ClearNewFlags, IRC_RANKING_GetSize, IRC_RANKING_Init, IRC_RANKING_InsertEntry, IRC_RANKING_HasEntryByTrainerId, IRC_RANKING_InitEntry, IRC_RANKING_FindEntryByTrainerId, IRC_RANKING_UpdateEntryMeetCount
 * address:  0x0200A8A0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_data.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   GFL_USE_GetRandom   0x020056EC  thumb
 *   FX_SinCosTable_   0x020A1B38  data
 *   _u32_div_f     0x0209C2B0  arm
 *   WORDSET_CopyString   0x0201F41C  thumb
 *   GF_STANDARD_SetupRtc_F540  0x0203F540  arm
 */
#include "wifilist_tail_shared_types.h"
#include "musical_save_shared_types.h"
#include "irc_ranking_shared_types.h"

/*
 * Save block 0x2C, the infrared compatibility ranking (0x34C bytes): 30
 * entries sorted by score, then the slot of the last insert.
 */
struct IrcRankEntry {
    u16 name[8];
    u32 score : 7;
    u32 meetCount : 10;
    u32 gender : 1;
    u32 language : 4;
    u32 version : 4;
    u32 padding : 5;
    u32 isValid : 1;
    u32 trainerId;
    u16 profileWord;
    u8  profileByte;
    u8  profileBits : 6;
    u8  profileFlag : 1;
    u8  isNew : 1;
};

struct IrcRankSave {
    struct IrcRankEntry entries[30];
    u32 lastSlot : 8;
    u32 reserved : 24;
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern s32  GF_STANDARD_SetupRtc_F540(struct RTCDate *date);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);

extern u32  GFL_USE_GetRandom(u32 range);

extern void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);

struct IrcRankSave *IRC_RANKING_GetFromSave(struct SaveControl *save);

s32 IRC_RANKING_GetEntryCount(struct IrcRankSave *rank);

struct IrcRankEntry *IRC_RANKING_GetEntry(struct IrcRankSave *rank, u32 index);

u8 IRC_RANKING_GetEntryScore(struct IrcRankSave *rank, u32 index);

u16 IRC_RANKING_GetEntryMeetCount(struct IrcRankSave *rank, u32 index);

u32 IRC_RANKING_GetEntryGender(struct IrcRankSave *rank, u32 index);

void IRC_RANKING_GetEntryProfile(const struct IrcRankEntry *entries, u32 index, u16 *outWord, u8 *outByte, u8 *outBits, u8 *outFlag);

u8 IRC_RANKING_GetLastSlot(struct IrcRankSave *rank);

int IRC_RANKING_FindClosestEntry(struct IrcRankSave *rank, u32 month, u32 day, struct RTCDate *today);

int IRC_RANKING_IsEntryNew(struct IrcRankEntry *entries, u32 trainerId);

int IRC_RANKING_HasEntry(struct IrcRankEntry *entries, u32 trainerId);

u8 IRC_RANKING_GetDateScore(u32 month, u32 day, struct RTCDate *today);

u8 IRC_RANKING_AddEntry(struct IrcRankSave *rank, const void *name, u16 score, u8 gender,
                u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag);

void IRC_RANKING_ClearNewFlags(struct IrcRankEntry *entries);

int IRC_RANKING_GetSize(void);

void IRC_RANKING_Init(struct IrcRankSave *rank);

u8 IRC_RANKING_InsertEntry(struct IrcRankEntry *list, s32 count, struct IrcRankEntry *entry);

int IRC_RANKING_HasEntryByTrainerId(struct IrcRankEntry *list, int count, struct IrcRankEntry *entry);

void IRC_RANKING_InitEntry(struct IrcRankEntry *entry, const void *name, u32 score, u32 meetCount,
                  u8 gender, u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag);

struct IrcRankEntry *IRC_RANKING_FindEntryByTrainerId(struct IrcRankEntry *list, int count, int trainerId);

void IRC_RANKING_UpdateEntryMeetCount(struct IrcRankEntry *list, int total, struct IrcRankEntry *entry);

extern s16  FX_SinCosTable_[];

struct IrcRankSave *IRC_RANKING_GetFromSave(struct SaveControl *save)
{
    return SAVE_CONTROL_GetBlock(save, 0x2C);
}

s32 IRC_RANKING_GetEntryCount(struct IrcRankSave *rank)
{
    s32 i;
    for (i = 0; i < 30; i++) {
        if (rank->entries[i].isValid == 0) {
            break;
        }
    }
    return i;
}

struct IrcRankEntry *IRC_RANKING_GetEntry(struct IrcRankSave *rank, u32 index)
{
    return &rank->entries[index];
}

u8 IRC_RANKING_GetEntryScore(struct IrcRankSave *rank, u32 index)
{
    return rank->entries[index].score;
}

u16 IRC_RANKING_GetEntryMeetCount(struct IrcRankSave *rank, u32 index)
{
    return rank->entries[index].meetCount;
}

u32 IRC_RANKING_GetEntryGender(struct IrcRankSave *rank, u32 index)
{
    return rank->entries[index].gender;
}

/*
 * Unlabelled Thumb leaf: reads record i (28 bytes) and writes its u16, u8
 * and two bitfields to four out pointers.
 */
void IRC_RANKING_GetEntryProfile(const struct IrcRankEntry *entries, u32 index, u16 *outWord, u8 *outByte, u8 *outBits, u8 *outFlag)
{
    *outWord = entries[index].profileWord;
    *outByte = entries[index].profileByte;
    *outBits = entries[index].profileBits;
    *outFlag = entries[index].profileFlag;
}

/*
 * Unlabelled Thumb leaf: low byte of the word at +0x348.
 */
u8 IRC_RANKING_GetLastSlot(struct IrcRankSave *rank)
{
    return rank->lastSlot;
}

int IRC_RANKING_FindClosestEntry(struct IrcRankSave *rank, u32 month, u32 day, struct RTCDate *today)
{
    u32 count = IRC_RANKING_GetEntryCount(rank);
    int target = IRC_RANKING_GetDateScore(month, day, today);
    int best = 0;
    u32 bestDiff = 0xffffffffu;
    u32 i;
    for (i = 0; i < count; i++) {
        int diff = IRC_RANKING_GetEntryScore(rank, i) - target;
        if (diff < 0) {
            diff = -diff;
        }
        if (bestDiff == diff) {
            u32 pick[2];
            pick[0] = (u32)best;
            pick[1] = (u32)i;
            best = (int)pick[GFL_USE_GetRandom(2)];
        } else if (bestDiff > diff) {
            best = i;
            bestDiff = diff;
        }
    }
    return best;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The two helpers between IRC_RANKING_FindClosestEntry and IRC_RANKING_GetDateScore, both invisible
 * to the worklist: each saves registers but not lr and nothing branches to
 * either from outside, so disasm.py prints the pair as a single run of
 * `.word` (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * The 92 bytes here cover the whole gap.
 *
 * Both walk the same array of 0x1e records of 0x1c bytes that
 * IRC_RANKING_FindClosestEntry above them indexes, and both accept a record on the same
 * pair of tests: the u32 at +0x14 equal to the key and bit 31 of the u32
 * at +0x10 set.  The first returns bit 7 of the byte at +0x1b of the
 * matching record, the second returns 1.
 */
int IRC_RANKING_IsEntryNew(struct IrcRankEntry *entries, u32 trainerId)
{
    int i;
    for (i = 0; i < 0x1e; i++) {
        if (entries[i].trainerId == trainerId && entries[i].isValid == 1)
            return entries[i].isNew;
    }
    return 0;
}

int IRC_RANKING_HasEntry(struct IrcRankEntry *entries, u32 trainerId)
{
    int i;
    for (i = 0; i < 0x1e; i++) {
        if (entries[i].trainerId == trainerId && entries[i].isValid == 1)
            return 1;
    }
    return 0;
}

/*
 * A date interpolation: copy the caller's 16-byte date record onto the
 * stack (the `ldm/stm` pair of docs/idioms/aggregate-assignment-is-ldm-stm.md),
 * take its day number with GF_STANDARD_SetupRtc_F540, overwrite the two fields at +4 and
 * +8 with the two scalar arguments, take the day number again, and wrap the
 * difference into a year.  The tail is the fixed-point sine lookup
 * src/matched/GF_STANDARD_Get_F684.c already evidences -- the same 4096-entry signed
 * halfword table at 0x020A1B38 indexed at `2 * i`, with 30 in place of 360 --
 * scaled to a percentage: `(sin + 0x1000) * 50 >> 12`, truncated to u8.
 *
 * Two things were load-bearing and cost the run:
 *
 *  - `asrs r0, r0, #4` after the second (UNSIGNED) divide.  The division is
 *    _u32_div_f at both sites, so the expression is unsigned, but the shift
 *    is arithmetic: the quotient has to be bound to an `s32` local first.
 *    Writing the whole chain inline gives `lsrs`; making the division itself
 *    signed swaps the helper to _s32_div_f and loses the call.
 *  - `cmp r4, r0` and not `cmp r0, r4`: the guard is written `if (a >= b)`,
 *    naming the FIRST day number first.  The equivalent `if (b <= a)` is two
 *    bytes wrong (cmp operands swapped and blo becomes bhi).  This is
 *    docs/idioms/cmp-operand-order-names-the-temporary.md, and it is the same
 *    lever src/matched/IRC_RANKING_HasEntryByTrainerId.c in this family already records.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/IRC_RANKING_GetDateScore.c \
 *       --func IRC_RANKING_GetDateScore --addr 0x0200AA00 --cc 1.1p1 --thumb
 */
u8 IRC_RANKING_GetDateScore(u32 month, u32 day, struct RTCDate *today)
{
    struct RTCDate date = *today;
    u32 todayNum, dayNum;
    todayNum = GF_STANDARD_SetupRtc_F540(&date);
    date.month = month;
    date.day = day;
    dayNum = GF_STANDARD_SetupRtc_F540(&date);
    if (todayNum >= dayNum) {
        dayNum += 365;
    }
    {
        s32 phase = (s32)((((dayNum - todayNum) % 30) * 0xFFFF) / 30);
        return (u8)((FX_SinCosTable_[2 * (phase >> 4)] + 0x1000) * 50 >> 12);
    }
}

/*
 * EXACT*: the listing extent is 196 bytes because the two unlabelled leaves
 * at 0x0200AB04 and 0x0200AB24 follow without a label; they are already
 * matched separately as src/matched/unit_0200AB04.c.  This file reproduces
 * the 154 bytes of IRC_RANKING_AddEntry itself.
 *
 * The orchestrator of the family (see docs/families/mystery_data.h).  Find an
 * existing Entry with the caller's key (sub_0200ACD0), take its 10-bit
 * counter if there is one, build a fresh Entry on the stack from that counter
 * and the caller's eleven arguments (IRC_RANKING_InitEntry), insert it in key order
 * (sub_0200AB50) recording the slot in the low byte of the record's flag word
 * at +0x348, and if the new entry duplicates one already present
 * (sub_0200ABE0) bump every matching entry's counter (IRC_RANKING_UpdateEntryMeetCount).  It
 * returns the slot back out of the flag word.
 *
 * This row was the "unfilable" one of docs/notes/pkt_0200AA00.c.txt (misfiled
 * under that name; it is about 0x0200AA68).  That note's verdict was that
 * every one of the five call sites is unwitnessed outside the compared range
 * and the row therefore caps at MATCH.  THAT IS NO LONGER TRUE, for two
 * independent reasons: all five callees are matched today, and the
 * `sole-ref/code` class introduced 2026-09-21 carries a code target that is
 * exactly a traced function start with no outside-branch requirement, which
 * is precisely the single-caller-callee shape here.  All five sites now
 * resolve as `sole-ref`, and the row is EXACT* rather than MATCH.
 *
 * Three declaration-level levers, none of them a statement shape:
 *
 *  1. IRC_RANKING_InitEntry takes EIGHT SEPARATE SCALAR PARAMETERS, not one 0x20-byte
 *     struct by value (see the header of src/matched/func_0200AC14.c, which
 *     this wave re-read the same way).  Passing a struct makes this caller
 *     emit an ldm/stm block copy where the original stores each field into
 *     its own outgoing word with `str`; the scalar form is what produces the
 *     `ldrb r1, [r0, #4] / str r1, [sp, #8]` ladder at +0x28..+0x48.
 *  2. `a2` is u16, not u32.  This is the one the permuter found:
 *       --mode hill --budget 800 --types, 189 single mutations tried,
 *       191st compile: type:p(a2:u32->u16), 74 concrete bytes out -> 46,
 *       and it aligned the whole first 0x5C bytes of the function.
 *     Nothing about the disassembly says a2 is narrow directly; it says so
 *     only through the register allocation downstream of it, which is exactly
 *     the residue class permuter.py exists for.
 *  3. The +0x348 flag word is read and written as an 8-bit BITFIELD, not
 *     masked by hand.  `((Flags *)&r->f348)->b0 = sub_0200AB50(...)` gives
 *     the interleaved `lsls r0, #0x18 / ... / lsrs r0, #0x18 / orrs r0, r2`
 *     the original has; the hand-written `r->f348 = (r->f348 & ~0xff) | slot`
 *     hoists the truncation out of the mask work and is 4 bytes short.  The
 *     read at the end needs the same bitfield, which is where the SECOND
 *     `lsls #0x18 / lsrs #0x18` pair at +0x92 comes from -- a plain
 *     `(u8)(r->f348 & 0xff)` folds the two pairs into one.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AA68.c \
 *       --func IRC_RANKING_AddEntry --addr 0x0200AA68 --cc 1.1p1 --thumb
 */
u8 IRC_RANKING_AddEntry(struct IrcRankSave *rank, const void *name, u16 score, u8 gender,
                u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag)
{
    struct IrcRankEntry entry;
    struct IrcRankEntry *known;
    u16 meetCount = 0;
    known = IRC_RANKING_FindEntryByTrainerId(rank->entries, 30, trainerId);
    if (known != 0) {
        meetCount = known->meetCount;
    }
    IRC_RANKING_InitEntry(&entry, name, score, meetCount, gender, language, version, trainerId, profileWord, profileByte, profileBits, profileFlag);
    {
    rank->lastSlot = IRC_RANKING_InsertEntry(rank->entries, 30, &entry);
    }
    if (IRC_RANKING_HasEntryByTrainerId(rank->entries, 30, &entry) != 0) {
        IRC_RANKING_UpdateEntryMeetCount(rank->entries, 30, &entry);
    }
    {
        u8 slot = rank->lastSlot;
        return slot;
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Two unlabelled leaves at the end of the packet, after func_0200AA68:
 * `push {r4, r5}` with no lr for the first, nothing at all for the second,
 * so both print as `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The first clears bit 7 of the byte at +0x1b of each of the same 0x1e
 * records of 0x1c bytes the two helpers at 0x0200A9A4 index (that byte's
 * bit 7 is the flag IRC_RANKING_IsEntryNew returns); the second is a four-byte
 * constant getter for 0x34c, which Thumb spells `movs r0, #0xd3; lsls
 * r0, r0, #2`.
 */
void IRC_RANKING_ClearNewFlags(struct IrcRankEntry *entries)
{
    int i;
    for (i = 0; i < 0x1e; i++)
        entries[i].isNew = 0;
}

int IRC_RANKING_GetSize(void)
{
    return sizeof(struct IrcRankSave);
}

void IRC_RANKING_Init(struct IrcRankSave *rank)
{
    MI_CpuFill8(rank, 0, sizeof(struct IrcRankSave));
    rank->lastSlot = 0x7f;
}

u8 IRC_RANKING_InsertEntry(struct IrcRankEntry *list, s32 count, struct IrcRankEntry *entry)
{
    s32 i;
    s32 slot = -1;
    s32 k;
    for (i = 0; i < count; i++) {
        if (list[i].isValid != 0) {
            if (list[i].score > entry->score) continue;
        }
        slot = i;
        break;
    }
    if (slot == -1) return 0xff;
    for (k = count - 1; k > slot; k--) {
        if (list[k].meetCount != 0 || list[k - 1].meetCount != 0) MI_CpuCopy8(&list[k - 1], &list[k], sizeof(struct IrcRankEntry));
    }
    MI_CpuCopy8(entry, &list[slot], sizeof(struct IrcRankEntry));
    return slot;
}

/*
 * The comparison has to be written with the *caller's* object on the left
 * (`*(u32 *)(b + 0x14) == *(u32 *)(p + 0x14)`): both sides are loads, and the
 * one the source names first is the one that lands in `cmp`'s left slot, so
 * swapping them is one byte (`cmp r2, r5` against `cmp r5, r2`).  Leaving the
 * invariant load in the condition rather than hoisting it into a local is
 * also load-bearing: as a local it is materialised before the `n <= 0` guard
 * and the entry test moves.  EXACT*: the 2-byte linker filler at 0x0200AC12
 * is inside the packet but the listing extent runs to the next label.
 */
int IRC_RANKING_HasEntryByTrainerId(struct IrcRankEntry *list, int count, struct IrcRankEntry *entry)
{
    int i;
    for (i = 0; i < count; i++) {
        struct IrcRankEntry *other = &list[i];
        if (entry->trainerId == other->trainerId && other->isValid == 1)
            return 1;
    }
    return 0;
}

/*
 * The Entry constructor of the family (see docs/families/mystery_data.h):
 * clear the 0x1C-byte record, copy 8 halfwords from `src` into the first
 * 16 bytes with WORDSET_CopyString, then fill the packed word at +0x10, the key at
 * +0x14, the halfword at +0x18, the byte at +0x1A and the two bit-packed
 * fields of +0x1B, and finally set the top bit of +0x10 and bit 7 of +0x1B.
 *
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200AC14.c.txt had this row at DIFF
 * with three independent residue groups, "no recoverable source in this note"
 * on the 2026-09-21 re-verify).  The note read the eight stack words at
 * sp+0x18..sp+0x34 as ONE 0x20-byte parameter block passed BY VALUE, because
 * the function takes its address once (`add r0, sp, #0x18`) and then reads
 * fields off it with `ldrb r1, [r0, #4]`, `ldrh r1, [r0, #0xc]` and so on.
 * That reading is wrong, and it is what produced all three residues.
 *
 * They are EIGHT SEPARATE SCALAR PARAMETERS of narrow types:
 *
 *     u8 p0, u8 p1, u8 p2, u32 p3, u16 p4, u8 p5, u8 p6, u8 p7
 *
 * Each occupies its own word of the incoming argument area (the ABI passes
 * every stack argument in a word slot regardless of width), so the OFFSETS
 * are identical to the struct reading and the disassembly cannot tell the two
 * apart by offset alone.  What tells them apart is the LOAD WIDTH: a struct
 * member of declared type u8 and a u8 parameter both read `ldrb`, but only
 * the scalar form lets the compiler base every one of them off a single
 * `add r0, sp, #0x18` while keeping p3 as a plain `ldr r0, [sp, #0x24]`
 * scheduled ahead of the +0x10 store -- which is residue 1 of the note,
 * unreachable from the struct form.  Residues 2 and 3 fall out with it: the
 * a3 insert accumulates into the keep register and the bit-6 insert keeps its
 * explicit `& 1` and `(u8)` cast, both of which the struct form folded.
 *
 * The permuter confirms the struct form is a dead end rather than a spelling
 * problem: on the 188-byte, 10-concrete-bytes-out struct version,
 *   --mode hill  --budget 800  --types: 158 single mutations, no improvement
 *   --mode anneal --budget 3000 --types: 3000 compiles in 204s, completely
 *   flat at asm=400 bytes-out=10 the whole way, never once leaving the
 *   plateau.
 * A residue no mutation of the statement shape can reach is a residue in the
 * DECLARATIONS, and re-reading the parameter list was what closed it.
 *
 * The bitfield widths of Self are the ones src/matched/unit_0200A864.c
 * already evidences for this family's Entry record (7 / 10 / 1 at +0x10,
 * 6 / 1 / 1 at +0x1B); the four extra sub-fields between them (4 / 4 / 5)
 * are read off this function's own mask pool words 0xFFFDFFFF, 0xFFC3FFFF
 * and 0xFC3FFFFF at 0x0200ACC0..0x0200ACCC.
 *
 * The top bit at the end must be written `(f10 & 0x7FFFFFFF) | 0x80000000`
 * -- which is what the `b6 : 1` bitfield assignment compiles to -- and not
 * `f10 |= 0x80000000`, which loses the `ldr r0, =0x7FFFFFFF / adds r0, r0, #1`
 * pair at +0x96.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AC14.c \
 *       --func IRC_RANKING_InitEntry --addr 0x0200AC14 --cc 1.1p1 --thumb
 */
void IRC_RANKING_InitEntry(struct IrcRankEntry *entry, const void *name, u32 score, u32 meetCount,
                  u8 gender, u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag)
{
    MI_CpuFill8(entry, 0, sizeof(struct IrcRankEntry));
    WORDSET_CopyString(name, entry->name, 8);
    entry->score = score;
    entry->trainerId = trainerId;
    entry->gender = gender;
    entry->language = language;
    entry->version = version;
    entry->meetCount = meetCount;
    entry->profileWord = profileWord;
    entry->profileByte = profileByte;
    entry->profileBits = profileBits;
    entry->profileFlag = (u8)(profileFlag & 1u);
    entry->isValid = 1;
    entry->isNew = 1;
}

struct IrcRankEntry *IRC_RANKING_FindEntryByTrainerId(struct IrcRankEntry *list, int count, int trainerId)
{
    int i;
    for (i = 0; i < count; i++) {
        struct IrcRankEntry *other = &list[i];
        if (trainerId == other->trainerId) {
            if (other->isValid == 1)
                return other;
        }
    }
    return 0;
}

/*
 * EXACT*: the listing extent runs to 156 bytes because the function at
 * 0x0200AD6C that follows saves nothing and therefore carries no label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); this file
 * reproduces the 108 bytes of IRC_RANKING_UpdateEntryMeetCount itself, code and both pool words.
 * The unlabelled follower at 0x0200AD6C should be seeded into
 * layout/function_starts.txt by the integrator.
 *
 * Another linear scan over the family's 0x1C-byte Entry records (see
 * docs/families/mystery_data.h): for every entry whose u32 at +0x14 matches
 * the reference's, bump the 10-bit counter at bit 7 of the packed word at
 * +0x10, set bit 7 of the byte at +0x1B, and clamp the counter to 999.
 *
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200AD00.c.txt had this row at DIFF,
 * 104 bytes against 156, 94 concrete bytes out -- effectively a whole-function
 * mismatch).  The note's C did the field access by hand:
 *
 *     v = *(u32 *)(e + 0x10);
 *     *(u32 *)(e + 0x10) = (v & 0xfffe007fu) | ((((v >> 7) & 0x3ff) + 1) << 7);
 *
 * which compiles to `lsrs #7; ands <0x3ff>` for the read and a pool word for
 * the 0x3FF, three instructions and a constant the original never
 * materialises.  The original reads the field as `lsls #0xf / lsrs #0x16` and
 * writes it back as `lsls #0x16 / lsrs #0xf`: an EQUAL-width shift pair with
 * no matching type, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md -- a 10-bit
 * unsigned BITFIELD at bit 7, not a hand-rolled mask.  Declaring the whole
 * packed word as the `struct Entry` bitfields the family header already
 * evidences (IRC_RANKING_GetEntryScore/A8E4/A8F8 in src/matched/unit_0200A864.c prove the
 * 7/10/1 widths) takes the row from 94 concrete bytes out to 2 in one edit,
 * and also drops the lr push: the hand-written version needed a spill the
 * bitfield form does not.
 *
 * The last two bytes were the operand order of the guard.  Both sides are
 * loads, and the side the SOURCE names first lands in the left register:
 * `ref->unk14 != e->unk14` gives `ldr r2, [r6, #0x14]` then `ldr r1, [r5,
 * #0x14]`, and the natural-reading `e->unk14 != ref->unk14` gives them the
 * other way round.  This is docs/idioms/cmp-operand-order-names-the-temporary.md
 * and it is the THIRD function in this family to turn on it
 * (src/matched/IRC_RANKING_HasEntryByTrainerId.c and src/matched/IRC_RANKING_GetDateScore.c are the others).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AD00.c \
 *       --func IRC_RANKING_UpdateEntryMeetCount --addr 0x0200AD00 --cc 1.1p1 --thumb
 */
void IRC_RANKING_UpdateEntryMeetCount(struct IrcRankEntry *list, int total, struct IrcRankEntry *entry)
{
    int i;
    for (i = 0; i < total; i++) {
        struct IrcRankEntry *other = &list[i];
        u32 count;
        if (entry->trainerId != other->trainerId) {
            continue;
        }
        other->meetCount = other->meetCount + 1;
        other->isNew = 1;
        count = other->meetCount;
        if (count > 999) {
            count = 999;
        }
        other->meetCount = count;
    }
}
