/*
 * file:     bsubway_savedata.c
 * unit:     yes
 * function: func_0200DE5C, func_0200DE64, BSUBWAY_SAVEDATA_SetTrainers, func_0200DE94, BSUBWAY_SAVEDATA_GetTrainersTagB, func_0200DEA8, BSUBWAY_SAVEDATA_SetHistory, func_0200DF58, func_0200DF94, func_0200DFB4, BSUBWAY_SAVEDATA_InitStats, BSUBWAY_SAVEDATA_GetStat, BSUBWAY_SAVEDATA_SetStat, BSUBWAY_SAVEDATA_IncStat, func_0200E024, func_0200E06C, func_0200E090, func_0200E098, func_0200E0B0, func_0200E0BC, func_0200E0E8, func_0200E124, func_0200E164, func_0200E184, func_0200E18C, func_0200E1A8, func_0200E27C, func_0200E2BC, func_0200E368, func_0200E370, func_0200E394, func_0200E3A0, func_0200E3A4, func_0200E3E8, func_0200E440
 * address:  0x0200DE5C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02082D44  0x02082D44  arm
 *   MI_CpuFill8         0x02082BCC  arm
 *   sFileName_bsubway_savedata  0x020A71F8  data
 *   func_0203F2FC  0x0203F2FC  arm
 *   func_0203F328  0x0203F328  arm
 *   func_020071CC  0x020071CC  thumb
 *   sSymbolBandRanges  0x0209DE90  data
 *   g_0200E278_Off 0x00000848  data
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02030734     0x02030734  arm
 *   func_020307B0     0x020307B0  arm
 *   SAVE_CONTROL_ReadRecordFromFlash     0x02007248  thumb
 *   memcmp            0x0203EFC8  arm
 *   sFileName_symbol_save    0x020A720C  data
 *   func_02167380  0x02167380  thumb  ov010
 *   func_02167358  0x02167358  thumb  ov010
 */
#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)
struct SaveBlockTable;
typedef unsigned char  u8;


typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct HistoryEntry {
    u16 id;
    u8  name[0x12];
    u8  score_le[4];
    u8  trailer[0x0A];
};

struct HistoryBuf {
    struct HistoryEntry entries[30];
};

/* One 0xF0 byte stored team entry. */
struct TrainerEntry {
    u8 pokemon[0xB4];
    u8 trainer_name[0x10];
    u8 pad_C4[0x11];
    u8 gender;
    u8 greeting[8];
    u8 win_message[8];
    u8 lose_message[8];
    u8 pad_EE[2];
};

struct BsubwaySave {
    u8 header[0xFE];
    u8 trainers_present;
    u8 history_present;
    u8 trainers_tag_b;
    u8 trainers_tag_a;
    u8 history_tag_b;
    u8 history_tag_a;
    struct TrainerEntry trainers[7];
    struct HistoryBuf history;
};

typedef u16 StatRow[3];

typedef enum { BAND_FIRST = 0, BAND_COUNT = 4 } BandIdx;

struct BandRange { u16 first; u16 limit; };

/* Symbol save block, 0x850 bytes (func_0200E024 refreshes its checksum). */
struct SymbolSave {
    u32 records[530];
    u8  kind2_count;
    u8  rank;
    u8  pad_84A[2];
    u16 checksum;
    u16 seed;
};

/* Second save block, 0x284 bytes: a 0x280 byte bit table and four trailing bytes. */
struct SymbolBitSave {
    u8 bits[0x280];
    u8 descriptor[4];
};

/* One exported battle subway record: 0x30 byte header then the 0xB4 byte body. */
struct TrainerExport {
    u32 trainer_id;
    u16 gender;
    u8  pad_06[2];
    u8  trainer_name[0x10];
    u8  greeting[8];
    u8  win_message[8];
    u8  lose_message[8];
    u8  pokemon[0xB4];
};

/* One packed 32-bit record of SymbolSave.rec. */
struct SymbolRec {
    u32 id       : 11;
    u32 param    : 10;
    u32 flags    : 2;
    u32 category : 6;
    u32 status   : 3;
};

extern void MI_CpuCopy8(const void *src, void *dest, unsigned int size);
extern void func_02082D44(void *dst, const void *src, u32 n);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203F2FC(const void *p, u32 len);
extern void func_0203F328(void *p, u32 size, u32 seed);
extern void func_0203F37C(void *p, unsigned int size, unsigned int seed);
extern void func_02082BCC(void *p, u32 v, u32 size);
extern void *func_020071CC(struct SaveBlockTable *ctrl, u32 id);
extern int _s32_div_f(int a, int b);
extern u32 func_020307B0(void *p);
extern u32   SAVE_CONTROL_ReadRecordFromFlash(void *a, u32 b, u32 c, void *d, u32 e);
extern int   memcmp(const void *a, const void *b, u32 n);
extern u8 func_02167380(u32 id);
extern u8 func_02167358(u32 id);
u8 func_0200DE5C(struct BsubwaySave *save);
u8 func_0200DE64(struct BsubwaySave *save);
void BSUBWAY_SAVEDATA_SetTrainers(struct BsubwaySave *save, const void *src, u8 tag_a, u8 tag_b);
u8 func_0200DE94(struct BsubwaySave *save);
u8 BSUBWAY_SAVEDATA_GetTrainersTagB(struct BsubwaySave *save);
void BSUBWAY_SAVEDATA_ExportTrainer(struct BsubwaySave *save, struct TrainerExport *out, int index);
void BSUBWAY_SAVEDATA_SetHistory(struct BsubwaySave *save, const void *src, u8 tag_a, u8 tag_b);
int func_0200DF40(struct BsubwaySave *save);
u8 func_0200DF4C(struct BsubwaySave *save);
struct HistoryBuf *func_0200DF58(struct BsubwaySave *save, u32 heap_id);
u32 func_0200DF94(struct HistoryBuf *history);
u32 func_0200DFB4(struct HistoryEntry *entry);
void BSUBWAY_SAVEDATA_InitStats(void *stats);
u16 BSUBWAY_SAVEDATA_GetStat(StatRow *stats, int row, int col);
void BSUBWAY_SAVEDATA_SetStat(StatRow *stats, int row, int col, int value);
void BSUBWAY_SAVEDATA_IncStat(u8 *stats, int row, int col);
void func_0200E024(struct SymbolSave *save);
void func_0200E06C(struct SymbolSave *save);
u32 func_0200E090(void);
void func_0200E098(struct SymbolSave *save);
void *func_0200E0B0(void *savedata);
u32 func_0200E0BC(u32 value);
u32 func_0200E0E8(const struct SymbolRec *records, int band);
void func_0200E124(u32 *records, u32 index);
u32 func_0200E164(struct SymbolSave *save, u32 band);
unsigned int func_0200E184(unsigned int value);
void func_0200E18C(struct SymbolSave *save, u32 index);
void func_0200E1A8(struct SymbolSave *save, u16 id, u16 param, u8 flags, u8 category, u8 status, u32 kind);
void func_0200E27C(struct SymbolSave *save, int index);
u32 func_0200E2BC(void *savedata, u32 *key_word, void *heap_id, u32 match_mode);
int func_0200E368(void);
void func_0200E370(struct SymbolBitSave *save);
void *func_0200E394(void *savedata);
u8 *func_0200E3A0(struct SymbolBitSave *save);
u32 sub_0200E3A4(const u8 *bits, int field_id);
void sub_0200E3E8(u8 *bits, int field_id, u32 value);
void func_0200E440(struct SymbolBitSave *save, int value, int index);
extern const char sFileName_bsubway_savedata[];
extern const struct BandRange sSymbolBandRanges[];
extern char  sFileName_symbol_save[];











/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           BSUBWAY_SAVEDATA_GetTrainersTagB
 *
 * 76 bytes, 0x0200DE5C..0x0200DEA8, 5 functions, four of which carry no label
 * in the generated listing.
 *
 * One slot of a record that holds a 0x690-byte payload at +0x104 behind a
 * present flag at +0xFE and two byte tags at +0x100 and +0x101.
 * BSUBWAY_SAVEDATA_SetTrainers fills all four in one go, and the three constants it needs
 * are one constant in the compiled code: 0x104 is materialised once in r7 and
 * the two stores reach +0x101 and +0x100 as `subs r0, r7, #3` and
 * `subs r0, r7, #4`.  That is the compiler reusing a live value and not three
 * offsets in the source.
 *
 * The two getters are the same function at two neighbouring offsets and they
 * do not compile alike: +0x100 is `movs r1, #1` / `lsls r1, #8` and +0x101
 * needs a literal pool word, because the first is a shifted eight-bit
 * immediate and the second is not.  Neither offset fits a `ldrb` immediate,
 * whose reach is 31, so both are register-offset loads; see
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 */
u8 func_0200DE5C(struct BsubwaySave *save)
{
    return save->trainers_present;
}




u8 func_0200DE64(struct BsubwaySave *save)
{
    return save->history_present;
}




void BSUBWAY_SAVEDATA_SetTrainers(struct BsubwaySave *save, const void *src, u8 tag_a, u8 tag_b)
{
    MI_CpuCopy8(src, save->trainers, sizeof(save->trainers));
    save->trainers_tag_a = tag_a;
    save->trainers_tag_b = tag_b;
    save->trainers_present = 1;
}




u8 func_0200DE94(struct BsubwaySave *save)
{
    return save->trainers_tag_a;
}




u8 BSUBWAY_SAVEDATA_GetTrainersTagB(struct BsubwaySave *save)
{
    return save->trainers_tag_b;
}






void BSUBWAY_SAVEDATA_ExportTrainer(struct BsubwaySave *save, struct TrainerExport *out, int index)
{
    struct TrainerEntry *trainer = &save->trainers[index];

    out->trainer_id = 0xffff;
    out->gender = trainer->gender;
    func_02082D44(trainer->trainer_name, out->trainer_name, 0x10);
    func_02082D44(trainer->greeting, out->greeting, 8);
    func_02082D44(trainer->win_message, out->win_message, 8);
    func_02082D44(trainer->lose_message, out->lose_message, 8);
    func_02082D44(trainer->pokemon, out->pokemon, 0xb4);
}






/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200DF94, func_0200DFB4, BSUBWAY_SAVEDATA_InitStats
 *
 * 200 bytes, 0x0200DF10..0x0200DFD8, 7 functions, five of which carry no
 * label in the generated listing.
 *
 * alias: 0x020A71F8 spells "bsubway_savedata.c", the fifth original source
 * file name this project has recovered, attested by the `string` class off
 * the terminator of "gds_profile.c" at 0x020A71F5.  func_0200DF58 passes it
 * to the debug allocator at 0x02030734 with line 0x508.
 *
 * The second slot of the record whose first slot is
 * src/matched/unit_0200DE5C.c: a 0x3FC-byte payload at +0x794 behind a
 * present flag at +0xFF and two byte tags at +0x102 and +0x103.  0x3FC is
 * thirty entries of 0x22 bytes, which is what func_0200DF94 walks, so the
 * payload's element type is pinned by the stride rather than assumed.
 *
 * Three details are worth having.
 *
 *  - func_0200DF58 allocates a copy of the payload and returns it; the size
 *    0x3FC is live in r6 across the allocation and is used again as the copy
 *    length, which is what writing it as `sizeof` at both sites gives.
 *  - in func_0200DF94 the loop index is declared **before** the counter even
 *    though the counter is the one assigned first in the output.  Declared
 *    the other way round the two swap registers and nothing else moves; see
 *    docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *  - func_0200DFB4 assembles a little-endian word out of four bytes and the
 *    compiler schedules the loads 0x16, 0x17, 0x14, 0x15, which is not the
 *    source order.  Every spelling tried, field by field or through an array,
 *    with or without casts on the operands, produces exactly these bytes, so
 *    the schedule says nothing about how it was written.
 */
void BSUBWAY_SAVEDATA_SetHistory(struct BsubwaySave *save, const void *src, u8 tag_a, u8 tag_b)
{
    MI_CpuCopy8(src, &save->history, sizeof(save->history));
    save->history_tag_a = tag_a;
    save->history_tag_b = tag_b;
    save->history_present = 1;
}




int func_0200DF40(struct BsubwaySave *save)
{
    return save->history_tag_a;
}




u8 func_0200DF4C(struct BsubwaySave *save)
{
    return save->history_tag_b;
}




struct HistoryBuf *func_0200DF58(struct BsubwaySave *save, u32 heap_id)
{
    struct HistoryBuf *copy = func_02030734(heap_id, sizeof(save->history), 1,
                                        sFileName_bsubway_savedata, 0x508);

    MI_CpuCopy8(&save->history, copy, sizeof(save->history));
    return copy;
}




u32 func_0200DF94(struct HistoryBuf *history)
{
    s32 i;
    u32 count = 0;

    for (i = 0; i < 30; i++) {
        if (history->entries[i].id != 0) {
            count++;
        }
    }
    return count;
}




u32 func_0200DFB4(struct HistoryEntry *entry)
{
    return entry->score_le[0] | (entry->score_le[1] << 8) | (entry->score_le[2] << 16)
           | (entry->score_le[3] << 24);
}




void BSUBWAY_SAVEDATA_InitStats(void *stats)
{
    MI_CpuFill8(stats, 0, 0x42);
}






/*
 * Two leaves after BSUBWAY_SAVEDATA_InitStats on a table of three-halfword records:
 * read entry [row][col], and write it clamped to 0..0xFFFF (signed
 * compares, so the value is an int). Seeded from ov175 (0x021D62E8,
 * 0x021D6502, 0x021D9DA2 and their siblings).
 */
u16 BSUBWAY_SAVEDATA_GetStat(StatRow *stats, int row, int col)
{
    return stats[row][col];
}






void BSUBWAY_SAVEDATA_SetStat(StatRow *stats, int row, int col, int value)
{
    if (value > 0xFFFF) {
        value = 0xFFFF;
    } else if (value < 0) {
        value = 0;
    }
    stats[row][col] = value;
}






/*
 * Unlabelled Thumb leaf: increment a clamped u16 counter.  Each record of the
 * table is six bytes; the counter for (a, idx) sits at base + a*6 + idx*2 and
 * is bumped by one only while it is below 0xFFFF.
 */
void BSUBWAY_SAVEDATA_IncStat(u8 *stats, int row, int col)
{
    u16 *counter = (u16 *)(stats + row * 6 + col * 2);

    if (*counter < 0xFFFFu) {
        *counter = (u16)(*counter + 1);
    }
}






/*
 * The 0x84C-byte save block's commit, and the second instance of the
 * 0x02FFFC3C idiom (see src/matched/unit_02008C58.c, which is the same block
 * 0x1E0 bytes smaller): the shared word is read TWICE and the two reads are not
 * commoned up, which is a `volatile` read and nothing else, and the two halves
 * are combined as `a << 8 | b`.
 *
 * The write at +0x84E is followed by a readback test against 0 and a store of 1
 * if it came back 0 -- the field is volatile all the way through, which is why
 * the `ldrh` is not folded away.  The checksum pair is the same shape as the
 * one in unit_02008C58.c: func_0203F2FC computes it over (obj, 0x84C) and
 * func_0203F328 writes it back with the +0x84E halfword as the high word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E024.c \
 *       --func func_0200E024 --addr 0x0200E024 --cc 1.1p1 --thumb
 */
void func_0200E024(struct SymbolSave *save)
{
    u32 hi = unk_02FFFC3C;
    u32 lo = unk_02FFFC3C;

    save->seed = hi << 8 | lo;
    if (save->seed == 0) {
        save->seed = 1;
    }
    save->checksum = func_0203F2FC(save, 0x84c);
    func_0203F328(save, 0x84c,
                  save->checksum +
                  (save->seed << 16));
}





void func_0200E06C(struct SymbolSave *save)
{
    func_0203F37C(save, 0x84c,
        save->checksum + (save->seed << 16));
    save->seed = 0;
}






/*
 * Save-table size callback: returns 0x850, the size of the block whose
 * init is func_0200E098.  Pointer word 0x0200E091 at 0x0209DD08.
 */
u32 func_0200E090(void)
{
    return 0x850;
}






/*
 * Zeroes 0x850 bytes then runs the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E098.c \
 *       --func func_0200E098 --addr 0x0200E098 --thumb --cc 1.1p1
 */
void func_0200E098(struct SymbolSave *save)
{
    func_02082BCC(save, 0, 0x850);
    func_0200E024(save);
}





/*
 * Unlabelled leaf: tail-calls func_020071CC(p, 0x3d).
 */
void *func_0200E0B0(void *savedata)
{
    return func_020071CC(savedata, 0x3d);
}





/*
 * Band lookup: the index of the first of four records whose .b bound is
 * above value, or 3. func_0200E124 indexes the same table with the result.
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 44/44, 9 out, the "pool load
 * in the preheader" wall of docs/notes/pkt_0200E0BC.c.txt): the counter AND
 * the result are enum-typed, as in src/matched/GPOWER_CountDownTimers.c. An enum
 * induction variable keeps the unfolded `cmp #4; bhs` entry guard with the
 * table load after it, and no redundant `if (i >= 4) break;` is needed. The
 * bound is compared unsigned (`(u32)BAND_COUNT`) for the image's bhs/blo; with
 * that compare a u32 result swaps r3/r4, an enum result does not.
 */
u32 func_0200E0BC(u32 value)
{
    BandIdx band;
    BandIdx result = 3;

    for (band = 0; band < (u32)BAND_COUNT; band++) {
        if (value < sSymbolBandRanges[band].limit) {
            result = band;
            break;
        }
    }
    return result;
}





/*
 * Wave 17 lane untried_small. Three levers together: the range table read as
 * `struct BandRange { u16 first; u16 limit; }` (two pool words, tbl and tbl + 2, as in
 * func_0200E124); the slot word read as an 11-bit bitfield (the image masks
 * with `lsls #21; lsrs #21`, which `& 0x7ff` never produces); and an element
 * pointer walked beside the index in a `while` loop.
 */
u32 func_0200E0E8(const struct SymbolRec *records, int band)
{
    u32 found = 0xffff;
    u32 i = sSymbolBandRanges[band].first;
    u32 end = sSymbolBandRanges[band].limit;
    const struct SymbolRec *rec = &records[i];

    while (i < end) {
        if (rec->id == 0) {
            found = i;
            break;
        }
        i++;
        rec++;
    }
    return found;
}






/*
 * The third pass's one in-lane conversion (lane 1 of the 0-64 byte band).
 * The two earlier attempts on this address both stopped at MATCH/DIFF on the
 * *pool word* rather than on any instruction: the entry point is a two-field
 * record table, and the field the original reads is the SECOND one, so its
 * `ldr r0, [pc, #0x28]` loads `sSymbolBandRanges + 2` (the address of `.b`), not the
 * table base.  Reading `struct BandRange { u16 first; u16 limit; } sSymbolBandRanges[]` and taking
 * `.b` folds that +2 into the pool word exactly as the original does;
 * reading the same address as `u16[]` at `[i * 2]` gives `.a` (the wrong
 * field, one byte off in the pool) and `[i * 2 + 1]` gives 68 bytes instead
 * of 64.  See `docs/idioms/table-field-offset-folds-into-the-pool-word.md`
 * for the lever and docs/notes/pkt_0200E0BC.c.txt for the two residues.
 *
 * `u32 *o = obj;` is load-bearing: without it mwcc strength-reduces
 * `obj + (idx + 1)` to `(obj + idx) + 4`, which is the same address but a
 * different instruction order in the argument set-up.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E124.c \
 *       --func func_0200E124 --addr 0x0200E124 --cc 1.1p1 --thumb
 */
void func_0200E124(u32 *records, u32 index)
{
    u32 hi = sSymbolBandRanges[func_0200E0BC(index)].limit;
    u32 *base = records;

    if (index < hi)
        func_02082D44(base + (index + 1), base + index, (hi - (index + 1)) * 4);
    base[hi - 1] &= 0xfffff800;
}






/*
 * Runs func_0200E06C, then func_0200E0E8, then the initialiser, returning
 * the middle result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E164.c \
 *       --func func_0200E164 --addr 0x0200E164 --thumb --cc 1.1p1
 */
u32 func_0200E164(struct SymbolSave *save, u32 band)
{
    func_0200E06C(save);
    {
        u32 found = func_0200E0E8((const struct SymbolRec *)save->records, (int)band);

        func_0200E024(save);
        return found;
    }
}




/*
 * notes:    Thumb thunk (ldr r3,[pc]; bx r3) to func_0200E0BC; a tail call. Witness for the call in ov010 func_0216628C (2026-10-05, lane W-B).
 */
unsigned int func_0200E184(unsigned int value)
{
    return func_0200E0BC(value);
}





/*
 * Runs func_0200E06C, then func_0200E124, then the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E18C.c \
 *       --func func_0200E18C --addr 0x0200E18C --thumb --cc 1.1p1
 */
void func_0200E18C(struct SymbolSave *save, u32 index)
{
    func_0200E06C(save);
    func_0200E124(save->records, index);
    func_0200E024(save);
}






/*
 * The record writer of the same two-field table object func_0200E124 walks:
 * it appends (or overwrites) one 32-bit packed record in the ring at
 * obj[slot] and then runs the checksum refresh at func_0200E024.
 *
 * The record is six unsigned bitfields in one u32, laid out 11 / 10 / 2 /
 * 6 / 3 from bit 0; the pool masks 0xFFFFF800, 0xFFE007FF, 0xFF9FFFFF,
 * 0xE07FFFFF and 0x1FFFFFFF are the complement of each field in turn, which
 * is what a plain unsigned bitfield store compiles to.  The three `str
 * r2, [r0]` in the middle of the sequence are the statement boundaries: the
 * first three fields fold into one store, the fourth and the fifth each get
 * their own.
 *
 * sSymbolBandRanges is the { u16 first; u16 limit; } record table of
 * src/matched/func_0200E124.c; this function reads BOTH fields of the same
 * row (a into the stack slot at sp+0xC, b into r7), so the two pool words
 * 0x0209DE90 and 0x0209DE92 are one symbol at two field offsets, not two
 * symbols.  See docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * The parameter widths are the whole of the codegen here, not a guess: the
 * spill order in the prologue (`str r1, [sp]` and `str r2, [sp, #4]` BEFORE
 * `ldr r4, [sp, #0x30]`, with `str r3, [sp, #8]` after it) only comes out
 * right when a1/a2 are u16 and a3 is u8.  Every wider spelling tried --
 * (u32,u32,u32), (u32,u32,u8), (u16,u16,u32), (int,int,int) -- reproduces
 * all 212 bytes but swaps those two instruction pairs, three or four bytes
 * wrong in the first ten.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E1A8.c \
 *       --func func_0200E1A8 --addr 0x0200E1A8 --cc 1.1p1 --thumb
 */
void func_0200E1A8(struct SymbolSave *save, u16 id, u16 param, u8 flags, u8 category, u8 status, u32 kind)
{
    struct SymbolRec *rec;
    u32 limit, first, slot;
    u32 band;

    func_0200E06C(save);
    band = kind;
    first = sSymbolBandRanges[band].first;
    limit = sSymbolBandRanges[band].limit;
    slot = func_0200E0E8((const struct SymbolRec *)save->records, band);
    if (slot == 0xFFFF) {
        func_0200E124(save->records, first);
        rec = (struct SymbolRec *)(save->records + (limit - 1));
    } else {
        rec = (struct SymbolRec *)(save->records + slot);
    }

    rec->id = id;
    rec->param = param;
    rec->flags = flags;
    rec->category = category;
    rec->status = status;

    if (band == 2) {
        if (save->kind2_count < 1)
            save->kind2_count++;
    } else if (band == 3) {
        func_0200E27C(save, (u16)slot);
    }
    func_0200E024(save);
}






/*
 * Slot-index arithmetic for the 0x84A/u8 table at +0x849: the byte written is
 * `(idx - 0x32) / 0x3c - 1` clamped to 6, and the three guards answer for
 * 0xffff, below 0xaa and above 0x212.  The divide is SIGNED (`_s32_div_f` at
 * 0x0209C0A4) while the two range tests are UNSIGNED, so the index parameter is
 * an `int` and the guards cast it to u32; spelling the parameter u32 instead
 * moves the divide to `_u32_div_f` and loses the site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E27C.c \
 *       --func func_0200E27C --addr 0x0200E27C --cc 1.1p1 --thumb
 */
void func_0200E27C(struct SymbolSave *save, int index)
{
    u8 rank = (index - 0x32) / 0x3c - 1;

    if (index == 0xffff) {
        return;
    }
    if ((u32)index < 0xaa) {
        return;
    }
    if ((u32)index > 0x212) {
        return;
    }
    if (rank > 6) {
        rank = 6;
    }
    save->rank = rank;
}






u32 func_0200E2BC(void *savedata, u32 *key_word, void *heap_id, u32 match_mode)
{
    struct SymbolSave *save;
    struct SymbolRec *key = (struct SymbolRec *)key_word;
    u32 found = 0;
    s32 i;
    s32 j;

    save = func_02030734((u32)heap_id, 0x850, 1, sFileName_symbol_save, 0x1ac);
    for (i = 0; i < 2; i++) {
        if (SAVE_CONTROL_ReadRecordFromFlash(savedata, 0x3d, i, save, 0x850) == 1) {
            func_0200E06C(save);
            for (j = 0; j < 530; j++) {
                if (match_mode == 1) {
                    if (key->id != ((struct SymbolRec *)save->records)[j].id) continue;
                    if (key->category != ((struct SymbolRec *)save->records)[j].category) continue;
                    found = 1;
                    break;
                } else {
                    if (memcmp(&save->records[j], key_word, 4) != 0) continue;
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1) break;
    }
    func_020307B0(save);
    return found;
}




int func_0200E368(void)
{
    return 0xa1 * 4;
}





/*
 * Zeroes 0x284 bytes and sets the three trailing descriptor bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E370.c \
 *       --func func_0200E370 --addr 0x0200E370 --thumb --cc 1.1p1
 */
void func_0200E370(struct SymbolBitSave *save)
{
    func_02082BCC(save, 0, 0x284);
    save->descriptor[0] = 0;
    save->descriptor[1] = 8;
    save->descriptor[2] = 0x1d;
}




void *func_0200E394(void *savedata)
{
    return func_020071CC(savedata, 0x3f);
}





/*
 * Returns the argument plus 0xd2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E3A0.c \
 *       --func func_0200E3A0 --addr 0x0200E3A0 --thumb --cc 1.1p1
 */
u8 *func_0200E3A0(struct SymbolBitSave *save)
{
    return &save->bits[0xd2];
}





/*
 * note:     wave 16: promoted.  0x02167380 and 0x02167358 are unlabelled ov010
 *           leaves matched in src/matched/func_02167380.c and func_02167358.c
 *           (ov010/pkt_02167358); both attest as `matched, overlay`.
 */
u32 sub_0200E3A4(const u8 *bits, int field_id)
{
    u32 bit_pos  = func_02167380(field_id);
    u32 width    = func_02167358(field_id);
    u32 byte_index = bit_pos >> 3;
    u32 bit_in_byte    = bit_pos & 7;
    u32 result  = 0;
    u32 i    = 0;

    while (width != 0) {
        result |= (u32)((bits[byte_index] >> bit_in_byte) & 1) << i;
        if (++bit_in_byte > 7) {
            byte_index++;
            bit_in_byte = 0;
        }
        i++;
        width--;
    }
    return result;
}





/*
 * note:     wave 16: promoted.  0x02167380 and 0x02167358 are unlabelled ov010
 *           leaves matched in src/matched/func_02167380.c and func_02167358.c
 *           (ov010/pkt_02167358); both attest as `matched, overlay`.
 *
 * near miss resolved (wave 4, permuter): the note's 88-byte version was a
 * six-register permutation away. Two spellings closed it, neither of which
 * the permuter's mutation set can reach (both change the emitted
 * instruction kinds, not the allocation):
 *   - the clear mask is (u8)(0xFFu ^ (1u << b)), which emits
 *     `movs r6,#0xff; eors r6,r7`; the ~ spelling emits a single `mvns`
 *     and is the whole 2-byte size gap.
 *   - inside the wrap test, `byte++` must precede `b = 0`; the reverse
 *     order emits `movs #0` before the `adds` and shifts the allocation.
 */
void sub_0200E3E8(u8 *bits, int field_id, u32 value)
{
    u32 bit_pos = func_02167380(field_id);
    u32 width   = func_02167358(field_id);
    u32 byte_index = bit_pos >> 3;
    u32 bit_in_byte    = bit_pos & 7;

    while (width != 0) {
        bits[byte_index] &= (u8)(0xFFu ^ (1u << bit_in_byte));
        bits[byte_index] |= (u8)((value & 1) << bit_in_byte);
        bit_in_byte++;
        if (bit_in_byte > 7) {
            byte_index++;
            bit_in_byte = 0;
        }
        value >>= 1;
        width--;
    }
}


void func_0200E440(struct SymbolBitSave *save, int value, int index)
{
    save->descriptor[index] = value;
}
