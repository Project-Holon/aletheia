/*
 * file:     intrude.c
 * unit:     yes
 * function: INTRUDE_GetSize, INTRUDE_Init, INTRUDE_InitOccupy, INTRUDE_GetMissionScore, INTRUDE_GetMissionBonusScore, INTRUDE_AddMissionScore, INTRUDE_AddMissionBonusScore, INTRUDE_GetFromSave, INTRUDE_StoreOccupy, INTRUDE_LoadOccupy, INTRUDE_AddLogEntry, INTRUDE_SetMonolithLevel, INTRUDE_GetMonolithLevel, INTRUDE_SetObtainedFlag, INTRUDE_GetObtainedFlags, INTRUDE_GetMissionClearCount, INTRUDE_IncrementMissionClearCount, INTRUDE_GetPlaySeconds, INTRUDE_UpdatePlaySeconds
 * address:  0x0200BDBC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_rec.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8          0x02082BCC  arm
 *   INTRUDE_COMM_ResetOutcomes   0x021763BC  thumb
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_02008654  0x02008654  thumb
 *   _ull_mul       0x0209C054  arm
 *   _PlayTimeLatch  0x02146170  data  a8
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 */
#include "battle_rec_types.h"
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int s32;
typedef unsigned short u16;

typedef unsigned long long u64;

/* Save block 0x35: the Entralink (intrude) record. */
struct IntrudeOccupy {
    u8  info[0x0C];
    u16 missionScore;
    u16 missionBonusScore;
};

/* 19 bytes rounded to 20 by the two-byte alignment; memberIds[8] is the
 * free-slot marker. */
struct IntrudeLogEntry {
    u16 memberIds[9];
    u8  kind;
};

struct IntrudeSave {
    struct IntrudeOccupy occupy;
    struct IntrudeLogEntry log[20];
    u8  monolithLevel;
    u8  obtainedFlags[2];
    u8  padding;
    u32 missionClearCount;
    u64 playSeconds;
};

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);

extern void INTRUDE_COMM_ResetOutcomes(struct IntrudeOccupy *occupy);

extern u16 STRBUF_GetEosChar(void);

extern u16 func_0200864C(const struct PlayTime *time);

extern u8 func_02008650(const struct PlayTime *time);

extern u8 func_02008654(const struct PlayTime *time);

u32 INTRUDE_GetSize(void);

void INTRUDE_Init(struct IntrudeSave *intrude);

void INTRUDE_InitOccupy(struct IntrudeSave *intrude);

u16 INTRUDE_GetMissionScore(struct IntrudeSave *intrude);

u16 INTRUDE_GetMissionBonusScore(struct IntrudeSave *intrude);

void INTRUDE_AddMissionScore(struct IntrudeSave *intrude, s32 add);

void INTRUDE_AddMissionBonusScore(struct IntrudeSave *intrude, s32 add);

struct IntrudeSave *INTRUDE_GetFromSave(struct SaveControl *save);

void INTRUDE_StoreOccupy(struct SaveControl *save, const u16 *src);

void INTRUDE_LoadOccupy(struct SaveControl *save, u16 *dest);

void INTRUDE_AddLogEntry(struct IntrudeSave *intrude, struct IntrudeLogEntry *entry);

void INTRUDE_SetMonolithLevel(struct IntrudeSave *intrude, u32 level);

u8 INTRUDE_GetMonolithLevel(struct IntrudeSave *intrude);

void INTRUDE_SetObtainedFlag(struct IntrudeSave *intrude, s32 id);

void INTRUDE_GetObtainedFlags(struct IntrudeSave *intrude, u8 *dest, u32 size);

u32 INTRUDE_GetMissionClearCount(struct IntrudeSave *intrude);

u32 INTRUDE_IncrementMissionClearCount(struct IntrudeSave *intrude);

u64 INTRUDE_GetPlaySeconds(struct IntrudeSave *intrude);

u64 INTRUDE_UpdatePlaySeconds(struct IntrudeSave *intrude, const struct PlayTime *time, u32 mode);

extern u64 _PlayTimeLatch;

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           INTRUDE_GetMissionBonusScore, INTRUDE_AddMissionScore, INTRUDE_AddMissionBonusScore
 *
 * 140 bytes, 0x0200BDBC..0x0200BE48, 7 functions, five of which carry no
 * label in the generated listing.
 *
 * A 0x1B0-byte record: INTRUDE_GetSize returns its size and INTRUDE_Init
 * clears exactly that many bytes, which is the block-file opening this region
 * keeps producing.  The constructor then seeds the byte at +0x1A0 with 0x30
 * and reaches it by subtracting 0x10 from the size it already has in a
 * register rather than materialising 0x1A0 again; that is the compiler's
 * doing and not a second constant in the source.
 *
 * INTRUDE_InitOccupy hands the first sixteen bytes to INTRUDE_COMM_ResetOutcomes, which lives
 * in overlay address space.  The call is attested because ov019's generated
 * listing carries a `func_` label at 0x021763BC and branches elsewhere in the
 * image reach it; see "Callees that live in an overlay" in docs/MATCHING.md.
 *
 * INTRUDE_AddMissionScore and INTRUDE_AddMissionBonusScore are the same clamped adder over two
 * neighbouring `u16` counters, and the ceiling 999 arrives from a literal
 * pool in each of them because it does not fit a Thumb immediate.  The
 * increment has to be written `field += add` with a **signed** parameter: the
 * comparison is a signed `ble`, and spelling the store as
 * `field = field + (u16)add` adds the truncation pair the store already does for
 * free.
 */
u32 INTRUDE_GetSize(void)
{
    return sizeof(struct IntrudeSave);
}

void INTRUDE_Init(struct IntrudeSave *intrude)
{
    MI_CpuFill8(intrude, 0, sizeof(struct IntrudeSave));
    INTRUDE_InitOccupy(intrude);
    intrude->monolithLevel = 0x30;
}

void INTRUDE_InitOccupy(struct IntrudeSave *intrude)
{
    MI_CpuFill8(&intrude->occupy, 0, sizeof(intrude->occupy));
    INTRUDE_COMM_ResetOutcomes(&intrude->occupy);
}

u16 INTRUDE_GetMissionScore(struct IntrudeSave *intrude)
{
    return intrude->occupy.missionScore;
}

u16 INTRUDE_GetMissionBonusScore(struct IntrudeSave *intrude)
{
    return intrude->occupy.missionBonusScore;
}

void INTRUDE_AddMissionScore(struct IntrudeSave *intrude, s32 add)
{
    if (intrude->occupy.missionScore + add > 999) {
        intrude->occupy.missionScore = 999;
    } else {
        intrude->occupy.missionScore += add;
    }
}

void INTRUDE_AddMissionBonusScore(struct IntrudeSave *intrude, s32 add)
{
    if (intrude->occupy.missionBonusScore + add > 999) {
        intrude->occupy.missionBonusScore = 999;
    } else {
        intrude->occupy.missionBonusScore += add;
    }
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 60 bytes, 0x0200BE48..0x0200BE84, 3 functions, one of which carries no
 * label in the generated listing.
 *
 * The lookup of the save block with id 0x35 and the two directions of an
 * eight halfword copy in and out of it.  Both loops count **down** from 8
 * with `subs`/`bne` and no compare at all, which a `for (i = 0; i < 8; i++)`
 * does not produce: that spelling keeps the induction variable and costs a
 * `cmp` and a `blt`.  `for (i = 8; i != 0; i--)` over an unsigned counter is
 * what gives the original's six instruction body, and so does the equivalent
 * `do`/`while (--i != 0)`.
 */
struct IntrudeSave *INTRUDE_GetFromSave(struct SaveControl *save)
{
    return SAVE_CONTROL_GetBlock(save, 0x35);
}

void INTRUDE_StoreOccupy(struct SaveControl *save, const u16 *src)
{
    u16 *dest = (u16 *)&INTRUDE_GetFromSave(save)->occupy;
    u32 i;

    for (i = 8; i != 0; i--) {
        *dest++ = *src++;
    }
}

void INTRUDE_LoadOccupy(struct SaveControl *save, u16 *dest)
{
    const u16 *src = (const u16 *)&INTRUDE_GetFromSave(save)->occupy;
    u32 i;

    for (i = 8; i != 0; i--) {
        *dest++ = *src++;
    }
}

/*
 * Add a log entry to the 20-entry intrude log at +0x10 when the own id is
 * one of its member ids: into the first free entry (memberIds[8] == 0), else
 * drop the oldest entry and append.
 *
 * The entry is 19 bytes rounded to 20 by its two-byte alignment, which is
 * why `*log = *entry;` is a 10-iteration ldrh/strh loop and not a five-word
 * ldm/stm pair: an align-2 aggregate has no four-byte move to use.
 *
 * Declaration order decides the register plan here, and it is not the
 * order the statements run in: with `u16 ownId;` declared before
 * `log = intrude->log;` the same body compiles to the same 130 bytes with a
 * different allocation (p in r5, q in r4, the cursor demoted to the
 * scratch r2, 47 bytes out).  Declaring `log` first makes the cursor's live
 * range start before the STRBUF_GetEosChar call, so it earns a
 * callee-saved register (intrude -> r6, entry -> r5, log -> r4) and the whole
 * prologue lines up.  See docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *
 * STRBUF_GetEosChar takes no arguments and returns the u16 bank mask
 * (src/calib/gx_getbankforlcdc.c); the `blx` is a Thumb -> ARM call, so
 * the symbol is declared `arm`.
 *
 * EXACT*: the listing's extent for 0x0200BE84 runs to 0x0200BFA4 because
 * the seven functions at 0x0200BF08..0x0200BFA4 save no lr and carry no
 * label; the compared range is the 130 bytes of this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/INTRUDE_AddLogEntry.c \
 *       --func INTRUDE_AddLogEntry --addr 0x0200BE84 --cc 1.1p1 --thumb
 */
void INTRUDE_AddLogEntry(struct IntrudeSave *intrude, struct IntrudeLogEntry *entry)
{
    struct IntrudeLogEntry *log = intrude->log;
    u16 ownId;
    int i;

    ownId = STRBUF_GetEosChar();

    for (i = 0; i < 8; i++) {
        if (ownId == entry->memberIds[i]) {
            break;
        }
    }
    if (i == 8) {
        return;
    }
    if (entry->kind >= 0x12) {
        return;
    }
    for (i = 0; i < 20; i++, log++) {
        if (log->memberIds[8] == 0) {
            *log = *entry;
            return;
        }
    }
    for (i = 1; i < 20; i++) {
        intrude->log[i - 1] = intrude->log[i];
    }
    intrude->log[19] = *entry;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           INTRUDE_GetMissionClearCount, INTRUDE_IncrementMissionClearCount, INTRUDE_GetPlaySeconds
 *
 * 156 bytes, 0x0200BF08..0x0200BFA4, 7 functions, none of which carries a
 * label in the generated listing.
 *
 * The tail of the 0x1B0-byte record whose size getter and constructor are
 * src/matched/unit_0200BDBC.c: a byte at +0x1A0, a two-byte bitmap at +0x1A1,
 * a clamped counter at +0x1A4 and a `u64` at +0x1A8, which is 0x1B0 exactly.
 * INTRUDE_GetPlaySeconds is the tell for the last of those: it returns +0x1A8 in r0
 * and +0x1AC in r1, which is one 64-bit value and not two out-parameters.
 * See docs/idioms/long-long-aligns-to-four.md.
 *
 * INTRUDE_SetObtainedFlag sets one bit of the bitmap for an id in 0x21..0x26, and the
 * index arithmetic is signed: `lsrs #0x1F` / `lsls #0x1D` / `subs` /
 * `rors #0x1D` is `% 8` on a signed value, exactly as in
 * src/matched/sub_0200A6BC.c, and `& 7` would have been a two-instruction
 * `movs`/`ands`.  The two range tests branch to one exit, so they are one
 * conjunction rather than two early returns.
 *
 * The base address 0x1A1 arrives from a literal pool in both functions that
 * touch the bitmap, because a register-offset `ldrb`/`strb` has no immediate
 * at all; that is the forced case of
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md
 * and not evidence of a second object.
 */
void INTRUDE_SetMonolithLevel(struct IntrudeSave *intrude, u32 level)
{
    intrude->monolithLevel = level;
}

u8 INTRUDE_GetMonolithLevel(struct IntrudeSave *intrude)
{
    return intrude->monolithLevel;
}

void INTRUDE_SetObtainedFlag(struct IntrudeSave *intrude, s32 id)
{
    s32 bit = id - 0x21;

    if (bit >= 0 && id <= 0x26) {
        intrude->obtainedFlags[bit / 8] |= (u8)(1 << (bit % 8));
    }
}

void INTRUDE_GetObtainedFlags(struct IntrudeSave *intrude, u8 *dest, u32 size)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        dest[i] = intrude->obtainedFlags[i];
    }
}

u32 INTRUDE_GetMissionClearCount(struct IntrudeSave *intrude)
{
    return intrude->missionClearCount;
}

u32 INTRUDE_IncrementMissionClearCount(struct IntrudeSave *intrude)
{
    if (intrude->missionClearCount < 99999) {
        intrude->missionClearCount++;
    }
    return intrude->missionClearCount;
}

u64 INTRUDE_GetPlaySeconds(struct IntrudeSave *intrude)
{
    return intrude->playSeconds;
}

/*
 * battle_rec.c, 0x0200BFA4..0x0200C058: the play-clock accumulator and the
 * unlabelled 4-byte follower BEACON_GetSize (`return 0xEC;`, a size getter).
 *
 * INTRUDE_UpdatePlaySeconds converts the h:m:s clock at q to seconds and, by mode,
 * latches it (0), adds the elapsed delta into the u64 at +0x1A8 (1), or
 * returns that total plus the delta without storing it (2).  What closed it
 * after docs/notes/pkt_0200BFA4.c.txt (79 out, 4 bytes short):
 *   - the three clock fields are u64 LOCALS: the image zeroes the high half
 *     (`movs r4, #0`) right after the first call and keeps four stack
 *     words, which a u32 t[3] never gives;
 *   - the sum is written minutes first, `mm * 60 + hh * 3600 + ss` (the
 *     _ull_mul calls follow source order);
 *   - mode 2 returns `total + (v - g)`, not `total - g` (the four missing
 *     bytes were that add).
 *
 * Integrator: seed 0x0200C054 (unlabelled follower, member of this unit).
 */
u64 INTRUDE_UpdatePlaySeconds(struct IntrudeSave *intrude, const struct PlayTime *time, u32 mode)
{
    u64 hours, minutes, seconds;
    u64 now;

    hours = func_0200864C(time);
    minutes = func_02008650(time);
    seconds = func_02008654(time);
    now = minutes * 60 + hours * 3600 + seconds;

    switch (mode) {
    case 0:
        _PlayTimeLatch = now;
        break;
    case 1:
        intrude->playSeconds = intrude->playSeconds + (now - _PlayTimeLatch);
        break;
    case 2:
        return intrude->playSeconds + (now - _PlayTimeLatch);
    }
    return intrude->playSeconds;
}
