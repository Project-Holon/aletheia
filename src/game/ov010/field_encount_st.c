/*
 * file:     field_encount_st.c
 * unit:     yes
 * function: FIELD_ENCOUNT_ST_LoadEncountData, FIELD_ENCOUNT_ST_Create, FIELD_ENCOUNT_ST_Delete, FIELD_ENCOUNT_ST_GetEffectEncount, FIELD_ENCOUNT_ST_ResetGimmickState
 * address:  0x0215E2B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_musical.c, move_pokemon.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ZONEDATA_GetEncountId  0x02013EC0  thumb
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   d_02172928 0x02172928 data a1
 *   FIELDMAP_GetEncount  0x02188CE8  thumb
 *   EFFECT_ENCOUNT_LoadSetting  0x021AA7DC  thumb
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 */
#include "../arm9/script_vm_types.h"
#include "scrcmd_musical_shared_types.h"

struct ArcFile;

/* Reads the 0xE8-byte encounter table row of a zone. */
typedef struct EncountRow {
    u8 data0[7];
    u8 flags;                             /* 0x07: 0x80 set after load */
} EncountRow;

/* Object returned by FIELDMAP_GetEncount (field map, offset 0x90). */
typedef struct EffectEncountObj {
    u8 pad00[0x10];
    int encountParam;                     /* 0x10 */
} EffectEncountObj;

/* Field gimmick work (GAME_DATA_GetFieldGimmick). */
typedef struct FieldGimmickWork {
    u8 pad00[0x0C];
    u32 state;                            /* 0x0C */
} FieldGimmickWork;

extern struct FieldGimmickWork *GAME_DATA_GetFieldGimmick(struct GameData *gameData);

/* overlay loading, heap, string helpers */
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);

extern u32 GFL_HEAP_Free(void *ptr);

extern void MI_CpuFill8(void *dst, u8 value, u32 size);

extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);

extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dest);

/* field encounter and field objects (ov021, ov010) */
extern int ZONEDATA_GetEncountId(u32 zoneId);

extern struct EffectEncountObj *FIELDMAP_GetEncount(struct FieldMap *fieldMap);

extern int EFFECT_ENCOUNT_LoadSetting(struct EffectEncountObj *obj, int param);

int FIELD_ENCOUNT_ST_LoadEncountData(EncountRow *row, struct ArcFile *arc, u32 zoneId, int seasonIndex);

void *FIELD_ENCOUNT_ST_Create(u32 heapId);

void FIELD_ENCOUNT_ST_Delete(void *encountState);

int FIELD_ENCOUNT_ST_GetEffectEncount(struct FieldMap *fieldMap);

FieldGimmickWork *FIELD_ENCOUNT_ST_ResetGimmickState(struct GameData *gameData);

extern const char d_02172928[];

/*
 * Read the encounter row of a zone from the encounter archive into `row`
 * (0xE8 bytes). Zones with one row use it for every season, zones with four
 * rows use the row of the season index. Returns 0 when the zone has no row
 * or the member has another size.
 */
int FIELD_ENCOUNT_ST_LoadEncountData(EncountRow *row, struct ArcFile *arc, u32 zoneId, int seasonIndex)
{
    u32 rowCount;
    int member;

    MI_CpuFill8(row, 0, 0xe8);
    member = ZONEDATA_GetEncountId(zoneId);
    if (member == 0xffff) {
        return 0;
    }
    rowCount = ARC_TOOL_GetHandleMemberSize(arc, member) / 0xe8;
    if (rowCount != 1 && rowCount != 4) {
        return 0;
    }
    if (rowCount == 1) {
        seasonIndex = 0;
    }
    ARC_TOOL_ReadHandleMemberRange(arc, member, seasonIndex * 0xe8, 0xe8, row);
    row->flags |= 0x80;
    return 1;
}

/* Allocate the 0x20-byte field encounter state. */
void *FIELD_ENCOUNT_ST_Create(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, 32, 1, d_02172928, 45);
}

void FIELD_ENCOUNT_ST_Delete(void *encountState)
{
    GFL_HEAP_Free(encountState);
}

/* Result of the effect-encounter query for the field effect object of `fieldMap`. */
int FIELD_ENCOUNT_ST_GetEffectEncount(struct FieldMap *fieldMap)
{
    EffectEncountObj *obj;

    obj = FIELDMAP_GetEncount(fieldMap);
    return EFFECT_ENCOUNT_LoadSetting(obj, obj->encountParam);
}

/* Clear the state word (offset 0xC) of the field gimmick work and return the work. */
FieldGimmickWork *FIELD_ENCOUNT_ST_ResetGimmickState(struct GameData *gameData)
{
    FieldGimmickWork *gimmick;

    gimmick = GAME_DATA_GetFieldGimmick(gameData);
    gimmick->state = 0;
    return gimmick;
}
