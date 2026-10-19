/*
 * file:     player_location.c
 * unit:     yes
 * function: PLAYER_LOCATION_GetSize, PLAYER_LOCATION_Init, PLAYER_LOCATION_Nop, PLAYER_LOCATION_GetLocationA, PLAYER_LOCATION_GetLocationB, PLAYER_LOCATION_GetShortData, PLAYER_LOCATION_GetData, PLAYER_LOCATION_SetRecordFromBuffer, PLAYER_LOCATION_CopyRecordToBuffer, PLAYER_LOCATION_CopyRecord, PLAYER_LOCATION_ReadFlashActiveFrom, PLAYER_LOCATION_WriteFlashActiveTo, PLAYER_LOCATION_SetSeason, PLAYER_LOCATION_GetSeason, PLAYER_LOCATION_SetWeatherId, PLAYER_LOCATION_GetWeatherId, PLAYER_LOCATION_SetEggStepCounter, PLAYER_LOCATION_GetEggStepCounter, PLAYER_LOCATION_GetWalkCounter, PLAYER_LOCATION_SetWalkCounter, PLAYER_LOCATION_SetStepMessageCount, PLAYER_LOCATION_GetStepMessageCount, PLAYER_LOCATION_GetZoneId, PLAYER_LOCATION_SetZoneId
 * address:  0x02008828
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from playtime.c by tools/splitfile.py.
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock    0x020071CC  thumb
 *   MI_CpuFill8   0x02082BCC  arm
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   FIELD_STATUS_IsFlashActive  0x02014468  thumb
 */
#include "config_shared_types.h"

typedef signed short       s16;

/* A three-word position, moved as one ldm/stm unit. */
struct Position {
    u32 x;
    u32 y;
    u32 z;
};

/* The 0x1C-byte record the block keeps at +0x80. */
struct LocationRecord {
    u16 zone_id;
    struct Position position;
    u16 facing;
    u16 entrance_id;
    u16 form;
    u16 look;
    s16 height_offset;
    u8  kind;
    u8  flags;
};

/* The buffer the record is exchanged with.  Its first 0x1C bytes line up with
 * the record, but height_offset is unsigned and the record's last two bytes come from
 * flags and flags_word. */
struct LocationRecordBuf {
    u16 zone_id;
    struct Position position;
    u16 facing;
    u16 entrance_id;
    u16 form;
    u16 look;
    u16 height_offset;
    u8  kind;
    u8  flags;
    u8  reserved1C[0x24];
    u32 flags_word;
};

/* Save block 0x1C, 0x9C bytes. */
struct PlayerLocationData {
    u8  reserved00[0x38];
    u8  location_a[0x1C];
    u8  location_b[0x1C];
    u8  short_data[2];
    u8  flashActive;
    u8  season;
    u8  weatherId;
    u8  reserved75;
    u16 zone_id;
    u32 eggStepCounter;
    u16 walkCounter;
    u16 stepMessageCount;
    struct LocationRecord record;
};

#define BLOCK_ID_1C 0x1C

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
struct FieldStatus;

extern void FIELD_STATUS_SetFlashActive(struct FieldStatus *fs, u8 flashActive);

extern u8 FIELD_STATUS_IsFlashActive(struct FieldStatus *fs);
struct SaveControl;

/* Save-block lookup: returns the block with the given id. */
extern void *SAVE_CONTROL_GetBlock(struct SaveControl *saveControl, u32 blockId);

struct PlayerLocationData *PLAYER_LOCATION_GetData(void *save);

/*
 * Save block 0x1C, 0x9C bytes.  The record at +0x80 and the buffer
 * PLAYER_LOCATION_SetRecordFromBuffer fills it from are different types: the record's +0x1A comes
 * from the buffer's +0x1B, and the record's +0x1B from the buffer's +0x40, a
 * word truncated to a byte.  As one struct assignment the function collapses
 * to an ldm/stm run and is 80 bytes short.  The record's +0x18 is signed
 * (`movs r0, #0x98; ldrsh` in PLAYER_LOCATION_CopyRecordToBuffer, since ldrsh has no immediate
 * form) and the buffer's is not.
 */
u32 PLAYER_LOCATION_GetSize(void)
{
    return sizeof(struct PlayerLocationData);
}

void PLAYER_LOCATION_Init(struct PlayerLocationData *location_data)
{
    MI_CpuFill8(location_data, 0, sizeof(struct PlayerLocationData));
    location_data->zone_id = 0x1AB;
}

void PLAYER_LOCATION_Nop(void)
{
}

void *PLAYER_LOCATION_GetLocationA(struct PlayerLocationData *location_data)
{
    return location_data->location_a;
}

void *PLAYER_LOCATION_GetLocationB(struct PlayerLocationData *location_data)
{
    return location_data->location_b;
}

void *PLAYER_LOCATION_GetShortData(struct PlayerLocationData *location_data)
{
    return location_data->short_data;
}

struct PlayerLocationData *PLAYER_LOCATION_GetData(void *save)
{
    return SAVE_CONTROL_GetBlock(save, BLOCK_ID_1C);
}

void PLAYER_LOCATION_SetRecordFromBuffer(void *save, const struct LocationRecordBuf *src)
{
    struct PlayerLocationData *location_data = PLAYER_LOCATION_GetData(save);

    location_data->record.zone_id = src->zone_id;
    location_data->record.position = src->position;
    location_data->record.facing = src->facing;
    location_data->record.entrance_id = src->entrance_id;
    location_data->record.form = src->form;
    location_data->record.look = src->look;
    location_data->record.height_offset = src->height_offset;
    location_data->record.kind = src->flags;
    location_data->record.flags = src->flags_word;
}

void PLAYER_LOCATION_CopyRecordToBuffer(void *save, struct LocationRecordBuf *dest)
{
    struct PlayerLocationData *location_data = PLAYER_LOCATION_GetData(save);

    dest->zone_id = location_data->record.zone_id;
    dest->position = location_data->record.position;
    dest->facing = location_data->record.facing;
    dest->entrance_id = location_data->record.entrance_id;
    dest->form = location_data->record.form;
    dest->look = location_data->record.look;
    dest->height_offset = location_data->record.height_offset;
    dest->flags = location_data->record.kind;
    dest->flags_word = location_data->record.flags;
}

void PLAYER_LOCATION_CopyRecord(void *save, struct LocationRecord *dest)
{
    struct PlayerLocationData *location_data = PLAYER_LOCATION_GetData(save);

    *dest = location_data->record;
}

/* The getter/setter pair on some other object's byte at +6, through which the
 * +0x72 field of this block is exchanged (FIELD_STATUS_IsFlashActive and FIELD_STATUS_SetFlashActive, two
 * four-byte leaves in a literal-pool run). */
void PLAYER_LOCATION_ReadFlashActiveFrom(struct PlayerLocationData *location_data, const void *src)
{
    location_data->flashActive = FIELD_STATUS_IsFlashActive((struct FieldStatus *)src);
}

void PLAYER_LOCATION_WriteFlashActiveTo(const struct PlayerLocationData *location_data, void *dest)
{
    FIELD_STATUS_SetFlashActive(dest, location_data->flashActive);
}

void PLAYER_LOCATION_SetSeason(struct PlayerLocationData *location_data, u8 value)
{
    location_data->season = value;
}

void PLAYER_LOCATION_GetSeason(const struct PlayerLocationData *location_data, u8 *out)
{
    *out = location_data->season;
}

void PLAYER_LOCATION_SetWeatherId(struct PlayerLocationData *location_data, u8 value)
{
    location_data->weatherId = value;
}

void PLAYER_LOCATION_GetWeatherId(const struct PlayerLocationData *location_data, u8 *out)
{
    *out = location_data->weatherId;
}

void PLAYER_LOCATION_SetEggStepCounter(struct PlayerLocationData *location_data, u32 value)
{
    location_data->eggStepCounter = value;
}

void PLAYER_LOCATION_GetEggStepCounter(const struct PlayerLocationData *location_data, u32 *out)
{
    *out = location_data->eggStepCounter;
}

u16 PLAYER_LOCATION_GetWalkCounter(const struct PlayerLocationData *location_data)
{
    return location_data->walkCounter;
}

void PLAYER_LOCATION_SetWalkCounter(struct PlayerLocationData *location_data, u16 value)
{
    location_data->walkCounter = value;
}

void PLAYER_LOCATION_SetStepMessageCount(struct PlayerLocationData *location_data, u16 value)
{
    location_data->stepMessageCount = value;
}

u16 PLAYER_LOCATION_GetStepMessageCount(const struct PlayerLocationData *location_data)
{
    return location_data->stepMessageCount;
}

u16 PLAYER_LOCATION_GetZoneId(const struct PlayerLocationData *location_data)
{
    return location_data->zone_id;
}

void PLAYER_LOCATION_SetZoneId(struct PlayerLocationData *location_data, u16 value)
{
    location_data->zone_id = value;
}
