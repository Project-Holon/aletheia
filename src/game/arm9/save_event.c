/*
 * file:     save_event.c
 * unit:     yes
 * function: SAVE_EVENT_Write, SAVE_EVENT_WriteMode, SAVE_EVENT_StoreTodayDate, SAVE_EVENT_WriteWithDate, SAVE_EVENT_ClearVariant, SAVE_EVENT_WriteEventIdWithDate, SAVE_EVENT_StoreVariant, SAVE_EVENT_CopyVariant, SAVE_EVENT_StoreRecord, SAVE_EVENT_CopyDoneFlag, SAVE_EVENT_SetDoneFlag, SAVE_EVENT_IsStageDone, SAVE_EVENT_CheckStage, SAVE_EVENT_CommitStage, SAVE_EVENT_AdvanceStage
 * address:  0x0202F190
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from time_icon.c by tools/splitfile.py.
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   MYSTATUS_GetId   0x02008530  thumb
 *   POKE_TOOL_CastToBoxParam   0x020185F0  thumb
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   POKE_TOOL_IsBoxOwnedByPlayer  0x02018488  thumb
 *   POKE_TOOL_SetBoxValue   0x02017E64  thumb
 *   POKE_TOOL_GetBoxValue   0x02017E88  thumb
 *   ZONEDATA_IsRawZoneGroup4CTo69   0x02014034  thumb
 *   POKE_TOOL_IsBoxShiny  0x02017EB4  thumb
 *   MYSTATUS_CreateNameStrbuf  0x02008510  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 */
#include "../version.h"
#include "comm_player_support_shared_types.h"
#include "save_event_shared_types.h"

#include "strbuf.h"

#include "gf_standard.h"
struct MyStatus;

#include "mystatus.h"
struct PokemonParam;

#include "poke_tool.h"
struct BoxPokemon;






#include "zonedata.h"




void SAVE_EVENT_Write(void *gameData, u32 mode, const struct MyStatus *record, u32 eventId, u16 index);

void SAVE_EVENT_WriteMode(struct SaveData *save, u32 mode, const struct MyStatus *record, u32 eventId, u32 index);

void SAVE_EVENT_StoreTodayDate(struct SaveData *save);

void SAVE_EVENT_WriteWithDate(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day);

void SAVE_EVENT_ClearVariant(struct SaveData *save, u32 variant);

void SAVE_EVENT_WriteEventIdWithDate(struct SaveData *save, u32 eventId, u32 variant);

void SAVE_EVENT_StoreVariant(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day, u32 variant);

void SAVE_EVENT_CopyVariant(struct SaveData *save, u32 variant);

void SAVE_EVENT_StoreRecord(struct SaveData *save, const struct MyStatus *record, u32 index);

void SAVE_EVENT_CopyDoneFlag(struct SaveData *save);

void SAVE_EVENT_SetDoneFlag(struct SaveData *save);

int SAVE_EVENT_IsStageDone(void *gameData, int stage);

int SAVE_EVENT_CheckStage(struct SaveData *save, int stage);

void SAVE_EVENT_CommitStage(void *gameData, u32 stage);

void SAVE_EVENT_AdvanceStage(struct SaveData *save, u32 stage);

void SAVE_EVENT_Write(void *gameData, u32 mode, const struct MyStatus *record, u32 eventId, u16 index)
{
    SAVE_EVENT_WriteMode((struct SaveData *)POKE_TOOL_CastToBoxParam(gameData), mode, record, eventId, index);
}

/*
 * Seven-way mode switch around a POKE_TOOL_DecodeBoxParam / POKE_TOOL_EncodeBoxParam bracket.
 * Closed in wave 16: the 129-byte residue was NOT an allocator tie but the
 * source's gotos.  Every case is written out in full (no shared labels) and
 * case 2's guard carries the call run in BOTH arms; 1.1p1's own
 * cross-jumping then produces the image's `b` into case 0's
 * SAVE_EVENT_CopyDoneFlag/SAVE_EVENT_SetDoneFlag tail, the kept `bne; b` pair in case 2, and
 * the head that spills the selector and holds the fifth parameter in r7.
 * The call at +0x58 is attested by SAVE_EVENT_SetDoneFlag (same shard).  0x7532 is
 * a plain constant.
 */
void SAVE_EVENT_WriteMode(struct SaveData *save, u32 mode, const struct MyStatus *record, u32 eventId, u32 index)
{
    u32 savedFlag = POKE_TOOL_DecodeBoxParam((struct BoxPokemon *)save);

    switch (mode) {
    case 0:
        SAVE_EVENT_ClearVariant(save, 0);
        SAVE_EVENT_WriteEventIdWithDate(save, eventId, 1);
        SAVE_EVENT_StoreRecord(save, record, index);
        SAVE_EVENT_CopyDoneFlag(save);
        SAVE_EVENT_SetDoneFlag(save);
        break;
    case 1:
        SAVE_EVENT_WriteEventIdWithDate(save, 0x7532, 1);
        SAVE_EVENT_CopyDoneFlag(save);
        SAVE_EVENT_SetDoneFlag(save);
        break;
    case 2:
        if (POKE_TOOL_IsBoxOwnedByPlayer((struct BoxPokemon *)save, (struct MyStatus *)record) == 1) {
            SAVE_EVENT_WriteEventIdWithDate(save, eventId, 1);
            SAVE_EVENT_StoreRecord(save, record, index);
        } else {
            SAVE_EVENT_CopyVariant(save, 1);
            SAVE_EVENT_WriteEventIdWithDate(save, eventId, 1);
            SAVE_EVENT_StoreRecord(save, record, index);
        }
        SAVE_EVENT_SetDoneFlag(save);
        break;
    case 3:
    case 4:
        break;
    case 5:
        SAVE_EVENT_WriteEventIdWithDate(save, eventId, 0);
        SAVE_EVENT_StoreRecord(save, record, index);
        SAVE_EVENT_SetDoneFlag(save);
        break;
    case 6:
        SAVE_EVENT_WriteEventIdWithDate(save, eventId, 1);
        break;
    }
    POKE_TOOL_EncodeBoxParam((struct BoxPokemon *)save, savedFlag);
}

/* Stores today's RTC date into save variables 0x92 to 0x94. */
void SAVE_EVENT_StoreTodayDate(struct SaveData *save)
{
    struct RtcDate date;

    GF_STANDARD_GetCachedDate(&date);

    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x92, date.year);
    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x93, date.month);
    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x94, date.day);
}

void SAVE_EVENT_WriteWithDate(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day)
{
    if (POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, 0xAA, 0) == 1)
        SAVE_EVENT_StoreVariant(save, eventId, year, month, day, 0);
    else
        SAVE_EVENT_StoreVariant(save, eventId, year, month, day, 1);
    SAVE_EVENT_CopyDoneFlag(save);
    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x6D, 1);
}

void SAVE_EVENT_ClearVariant(struct SaveData *save, u32 variant)
{
    SAVE_EVENT_StoreVariant(save, 0, 0, 0, 0, variant);
}

/* Stores the event id with today's date into the given variant. */
void SAVE_EVENT_WriteEventIdWithDate(struct SaveData *save, u32 eventId, u32 variant)
{
    struct RtcDate date;

    GF_STANDARD_GetCachedDate(&date);

    if (ZONEDATA_IsRawZoneGroup4CTo69((u16)eventId) == 1)
        SAVE_EVENT_StoreVariant(save, 0x753E, date.year, date.month, date.day, variant);
    else
        SAVE_EVENT_StoreVariant(save, eventId, date.year, date.month, date.day, variant);
}

/*
 * Installs the four save variables of one variant (event id, year, month,
 * day).  The base index is the variant flag plus 0x95 for the event id,
 * then that same flag times three plus 0x8f/0x90/0x91 for the date.
 */
void SAVE_EVENT_StoreVariant(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day, u32 variant)
{
    u8 base = (variant == 1);

    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, base + 0x95, eventId);
    base = (u8)(base * 3);
    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, base + 0x8F, year);
    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, base + 0x90, month);
    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, base + 0x91, day);
}

/*
 * Reads the four save variables of one variant and hands them, with the
 * opposite variant, to SAVE_EVENT_StoreVariant (copies a variant to the other one).
 */
void SAVE_EVENT_CopyVariant(struct SaveData *save, u32 variant)
{
    u8 base = (variant == 1);
    u32 eventId, year, month, otherVariant, day;

    eventId = POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, base + 0x95, 0);
    base = (u8)(base * 3);
    year = POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, base + 0x8F, 0);
    month = POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, base + 0x90, 0);
    day = POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, base + 0x91, 0);

    otherVariant = (variant == 0);
    SAVE_EVENT_StoreVariant(save, eventId, year, month, day, otherVariant);
}

/*
 * Stores the record's name (variable 0x8d), key (0x9a) and kind (7) and
 * frees the name string.
 */
void SAVE_EVENT_StoreRecord(struct SaveData *save, const struct MyStatus *record, u32 index)
{
    struct Strbuf *name = (struct Strbuf *)MYSTATUS_CreateNameStrbuf((u16 *)record, index);
    u32 kind = MYSTATUS_GetId((struct MyStatus *)record);
    u32 key = MYSTATUS_GetSex((struct MyStatus *)record);

    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x8d, (uptr)name);
    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x9a, key);
    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 7, kind);
    STRBUF_Delete(name);
}

/* Copies save variable 0x9e into 0x99. */
void SAVE_EVENT_CopyDoneFlag(struct SaveData *save)
{
    u32 value = POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, 0x9e, 0);

    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x99, value);
}

/*
 * Unlabelled 12-byte Thumb leaf (a tail call through a pool word to
 * POKE_TOOL_SetBoxValue with id 0x77, value 0x15) after SAVE_EVENT_CopyDoneFlag; filed as the
 * witness for SAVE_EVENT_WriteMode's call at +0x58, the only branch to it
 * image-wide.
 */
void SAVE_EVENT_SetDoneFlag(struct SaveData *save)
{
    POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x77, PM_VERSION_ID);
}

int SAVE_EVENT_IsStageDone(void *gameData, int stage)
{
    return SAVE_EVENT_CheckStage((struct SaveData *)POKE_TOOL_CastToBoxParam(gameData), stage);
}

/*
 * Nonzero when the save variables match the expected state of the given
 * stage (0 to 7): variable 5, the event id (0x96), the done flag (0x6d),
 * the count from POKE_TOOL_IsBoxShiny and whether any of the date variables is set.
 */
int SAVE_EVENT_CheckStage(struct SaveData *save, int stage)
{
    u32 savedFlag = POKE_TOOL_DecodeBoxParam((struct BoxPokemon *)save);
    int variable5 = POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, 5, 0);
    int eventId = POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, 0x96, 0);
    int done = POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, 0x6d, 0);
    int count = POKE_TOOL_IsBoxShiny((struct BoxPokemon *)save);
    int anyDate = 0;

    if (POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, 0x8f, anyDate) != 0
        || POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, 0x90, anyDate) != 0
        || POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, 0x91, anyDate) != 0
        || POKE_TOOL_GetBoxValue((struct BoxPokemon *)save, 0x95, anyDate) != 0) {
        anyDate = 1;
    }
    POKE_TOOL_EncodeBoxParam((struct BoxPokemon *)save, savedFlag);

    switch (stage) {
    case 0:
        if (variable5 == 0xfb && eventId == 0x753a && done == 1 && anyDate == 0 && count == 0) {
            return 1;
        }
        break;
    case 1:
        if (variable5 == 0xfb && eventId == 0x753b && done == 1 && anyDate == 0 && count == 0) {
            return 1;
        }
        break;
    case 2:
        if ((unsigned)(variable5 - 0xf3) <= 2 && eventId == 0x753c && count == 1 && done == 1
            && anyDate == 0) {
            return 1;
        }
        break;
    case 3:
        if ((unsigned)(variable5 - 0xf3) <= 2 && eventId == 0x753d && count == 1 && done == 1
            && anyDate == 0) {
            return 1;
        }
        /* fall through */
    case 4:
        if (variable5 == 0x287 && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    case 5:
        if (variable5 == 0x288 && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    case 6:
        if (variable5 == 0x289 && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    case 7:
        if (variable5 == 0x1ec && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Promoted out of src/pending: the callee SAVE_EVENT_AdvanceStage became a manifest
 * entry this pass, so the second call site resolves on `matched`.
 */
void SAVE_EVENT_CommitStage(void *gameData, u32 stage)
{
    SAVE_EVENT_AdvanceStage((struct SaveData *)POKE_TOOL_CastToBoxParam(gameData), stage);
}

/*
 * The two trailing pool words (0x753B / 0x753D, bare literals with no
 * relocation) are part of the compiled body, so the compared output is 72
 * bytes against the worklist's 62 code bytes; the listing extent runs to the
 * end of the packet.  All four call sites resolve on `label`.
 */
void SAVE_EVENT_AdvanceStage(struct SaveData *save, u32 stage)
{
    u32 savedFlag = POKE_TOOL_DecodeBoxParam((struct BoxPokemon *)save);

    if (SAVE_EVENT_CheckStage(save, stage) == 1) {
        switch (stage) {
        case 0:
            POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x96, 0x753B);
            break;
        case 2:
            POKE_TOOL_SetBoxValue((struct BoxPokemon *)save, 0x96, 0x753D);
            break;
        }
    }
    POKE_TOOL_EncodeBoxParam((struct BoxPokemon *)save, savedFlag);
}
