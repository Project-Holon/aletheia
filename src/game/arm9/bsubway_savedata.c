/*
 * file:     bsubway_savedata.c
 * unit:     yes
 * function: BSUBWAY_SAVEDATA_GetTrainersPresent, BSUBWAY_SAVEDATA_GetHistoryPresent, BSUBWAY_SAVEDATA_SetTrainers, BSUBWAY_SAVEDATA_GetTrainersTagA, BSUBWAY_SAVEDATA_GetTrainersTagB, BSUBWAY_SAVEDATA_ExportTrainer, BSUBWAY_SAVEDATA_SetHistory, BSUBWAY_SAVEDATA_GetHistoryTagA, BSUBWAY_SAVEDATA_GetHistoryTagB, BSUBWAY_SAVEDATA_AllocHistoryCopy, BSUBWAY_SAVEDATA_CountHistoryEntries, BSUBWAY_SAVEDATA_GetHistoryEntryScore, BSUBWAY_SAVEDATA_InitStats, BSUBWAY_SAVEDATA_GetStat, BSUBWAY_SAVEDATA_SetStat, BSUBWAY_SAVEDATA_IncStat
 * address:  0x0200DE5C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from bsubway_savedata.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8         0x02082BCC  arm
 *   sFileName_bsubway_savedata  0x020A71F8  data
 *   GFL_HEAP_Alloc     0x02030734  arm
 */
#include "../types.h"
#include "bsubway_savedata.h"

struct BsubwayHistoryEntry {
    u16 id;
    u8  name[0x12];
    u8  scoreLe[4];
    u8  trailer[0x0A];
};

struct HistoryBuf {
    struct BsubwayHistoryEntry entries[30];
};

/* One 0xF0 byte stored team entry. */
struct TrainerEntry {
    u8 pokemon[0xB4];
    u8 trainerName[0x10];
    u8 reserved0[0x11];
    u8 gender;
    u8 greeting[8];
    u8 winMessage[8];
    u8 loseMessage[8];
    u8 reserved1[2];
};

struct BsubwaySave {
    u8 header[0xFE];
    u8 trainersPresent;
    u8 historyPresent;
    u8 trainersTagB;
    u8 trainersTagA;
    u8 historyTagB;
    u8 historyTagA;
    struct TrainerEntry trainers[7];
    struct HistoryBuf history;
};


/* One exported battle subway record: 0x30 byte header then the 0xB4 byte body. */
struct TrainerExport {
    u32 trainerId;
    u16 gender;
    u8  reserved2[2];
    u8  trainerName[0x10];
    u8  greeting[8];
    u8  winMessage[8];
    u8  loseMessage[8];
    u8  pokemon[0xB4];
};

#include "mi_memory.h"


#include "gfl_heap_wrap.h"

u8 BSUBWAY_SAVEDATA_GetTrainersPresent(struct BsubwaySave *save);

u8 BSUBWAY_SAVEDATA_GetHistoryPresent(struct BsubwaySave *save);

void BSUBWAY_SAVEDATA_SetTrainers(struct BsubwaySave *save, const void *src, u8 tagA, u8 tagB);

u8 BSUBWAY_SAVEDATA_GetTrainersTagA(struct BsubwaySave *save);

u8 BSUBWAY_SAVEDATA_GetTrainersTagB(struct BsubwaySave *save);

void BSUBWAY_SAVEDATA_ExportTrainer(struct BsubwaySave *save, struct TrainerExport *out, int index, u32 heapId);

void BSUBWAY_SAVEDATA_SetHistory(struct BsubwaySave *save, const void *src, u8 tagA, u8 tagB);

int BSUBWAY_SAVEDATA_GetHistoryTagA(struct BsubwaySave *save);

u8 BSUBWAY_SAVEDATA_GetHistoryTagB(struct BsubwaySave *save);

struct HistoryBuf *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct BsubwaySave *save, u32 heapId);

u32 BSUBWAY_SAVEDATA_CountHistoryEntries(struct HistoryBuf *history);

u32 BSUBWAY_SAVEDATA_GetHistoryEntryScore(struct BsubwayHistoryEntry *entry);

void BSUBWAY_SAVEDATA_InitStats(void *stats);

u32 BSUBWAY_SAVEDATA_GetStat(BsubwayStatRow *stats, u32 row, u32 col);

void BSUBWAY_SAVEDATA_SetStat(BsubwayStatRow *stats, int row, int col, int value);

void BSUBWAY_SAVEDATA_IncStat(u8 *stats, int row, int col);

extern const char sFileName_bsubway_savedata[];

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
u8 BSUBWAY_SAVEDATA_GetTrainersPresent(struct BsubwaySave *save)
{
    return save->trainersPresent;
}

u8 BSUBWAY_SAVEDATA_GetHistoryPresent(struct BsubwaySave *save)
{
    return save->historyPresent;
}

void BSUBWAY_SAVEDATA_SetTrainers(struct BsubwaySave *save, const void *src, u8 tagA, u8 tagB)
{
    MI_CpuCopy8(src, save->trainers, sizeof(save->trainers));
    save->trainersTagA = tagA;
    save->trainersTagB = tagB;
    save->trainersPresent = 1;
}

u8 BSUBWAY_SAVEDATA_GetTrainersTagA(struct BsubwaySave *save)
{
    return save->trainersTagA;
}

u8 BSUBWAY_SAVEDATA_GetTrainersTagB(struct BsubwaySave *save)
{
    return save->trainersTagB;
}

void BSUBWAY_SAVEDATA_ExportTrainer(struct BsubwaySave *save, struct TrainerExport *out, int index, u32 heapId)
{
    struct TrainerEntry *trainer = &save->trainers[index];

    out->trainerId = 0xffff;
    out->gender = trainer->gender;
    MI_CpuCopy8(trainer->trainerName, out->trainerName, 0x10);
    MI_CpuCopy8(trainer->greeting, out->greeting, 8);
    MI_CpuCopy8(trainer->winMessage, out->winMessage, 8);
    MI_CpuCopy8(trainer->loseMessage, out->loseMessage, 8);
    MI_CpuCopy8(trainer->pokemon, out->pokemon, 0xb4);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           BSUBWAY_SAVEDATA_CountHistoryEntries, BSUBWAY_SAVEDATA_GetHistoryEntryScore, BSUBWAY_SAVEDATA_InitStats
 *
 * 200 bytes, 0x0200DF10..0x0200DFD8, 7 functions, five of which carry no
 * label in the generated listing.
 *
 * alias: 0x020A71F8 spells "bsubway_savedata.c", the fifth original source
 * file name this project has recovered, attested by the `string` class off
 * the terminator of "gds_profile.c" at 0x020A71F5.  BSUBWAY_SAVEDATA_AllocHistoryCopy passes it
 * to the debug allocator at 0x02030734 with line 0x508.
 *
 * The second slot of the record whose first slot is
 * src/matched/unit_0200DE5C.c: a 0x3FC-byte payload at +0x794 behind a
 * present flag at +0xFF and two byte tags at +0x102 and +0x103.  0x3FC is
 * thirty entries of 0x22 bytes, which is what BSUBWAY_SAVEDATA_CountHistoryEntries walks, so the
 * payload's element type is pinned by the stride rather than assumed.
 *
 * Three details are worth having.
 *
 *  - BSUBWAY_SAVEDATA_AllocHistoryCopy allocates a copy of the payload and returns it; the size
 *    0x3FC is live in r6 across the allocation and is used again as the copy
 *    length, which is what writing it as `sizeof` at both sites gives.
 *  - in BSUBWAY_SAVEDATA_CountHistoryEntries the loop index is declared **before** the counter even
 *    though the counter is the one assigned first in the output.  Declared
 *    the other way round the two swap registers and nothing else moves; see
 *    docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *  - BSUBWAY_SAVEDATA_GetHistoryEntryScore assembles a little-endian word out of four bytes and the
 *    compiler schedules the loads 0x16, 0x17, 0x14, 0x15, which is not the
 *    source order.  Every spelling tried, field by field or through an array,
 *    with or without casts on the operands, produces exactly these bytes, so
 *    the schedule says nothing about how it was written.
 */
void BSUBWAY_SAVEDATA_SetHistory(struct BsubwaySave *save, const void *src, u8 tagA, u8 tagB)
{
    MI_CpuCopy8(src, &save->history, sizeof(save->history));
    save->historyTagA = tagA;
    save->historyTagB = tagB;
    save->historyPresent = 1;
}

int BSUBWAY_SAVEDATA_GetHistoryTagA(struct BsubwaySave *save)
{
    return save->historyTagA;
}

u8 BSUBWAY_SAVEDATA_GetHistoryTagB(struct BsubwaySave *save)
{
    return save->historyTagB;
}

struct HistoryBuf *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct BsubwaySave *save, u32 heapId)
{
    struct HistoryBuf *copy = GFL_HEAP_Alloc(heapId, sizeof(save->history), 1,
                                        sFileName_bsubway_savedata, 0x508);

    MI_CpuCopy8(&save->history, copy, sizeof(save->history));
    return copy;
}

u32 BSUBWAY_SAVEDATA_CountHistoryEntries(struct HistoryBuf *history)
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

u32 BSUBWAY_SAVEDATA_GetHistoryEntryScore(struct BsubwayHistoryEntry *entry)
{
    return entry->scoreLe[0] | (entry->scoreLe[1] << 8) | (entry->scoreLe[2] << 16)
           | (entry->scoreLe[3] << 24);
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
u32 BSUBWAY_SAVEDATA_GetStat(BsubwayStatRow *stats, u32 row, u32 col)
{
    return stats[row][col];
}

void BSUBWAY_SAVEDATA_SetStat(BsubwayStatRow *stats, int row, int col, int value)
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
