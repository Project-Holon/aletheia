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
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../arm9/script_vm_types.h"
#include "scrcmd_musical_shared_types.h"

struct ArcFile;

#include "field_encount_st_types.h"
typedef struct EncountRow EncountRow;

/* Field gimmick work (GAME_DATA_GetFieldGimmick). */
typedef struct FieldGimmickWork {
    u8 pad00[0x0C];
    u32 state;                            /* 0x0C */
} FieldGimmickWork;
struct GameData;

#include "../arm9/game_data.h"

/* overlay loading, heap, string helpers */
#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/mi_memory.h"
struct ArcHandle;

#include "../arm9/arc_tool.h"


                                                      
#include "../arm9/zonedata.h"

#include "../ov021/fieldmap.h"

#include "../ov021/field_encount_types.h"
#include "../ov021/effect_encount.h"

int FIELD_ENCOUNT_ST_LoadEncountData(EncountRow *row, struct ArcFile *arc, u32 zoneId, int seasonIndex);

void *FIELD_ENCOUNT_ST_Create(u32 heapId);

void FIELD_ENCOUNT_ST_Delete(void *encountState);

void FIELD_ENCOUNT_ST_GetEffectEncount(struct FieldMap *fieldMap);

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
    rowCount = ARC_TOOL_GetHandleMemberSize((struct ArcHandle *)arc, member) / 0xe8;
    if (rowCount != 1 && rowCount != 4) {
        return 0;
    }
    if (rowCount == 1) {
        seasonIndex = 0;
    }
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)arc, member, seasonIndex * 0xe8, 0xe8, row);
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
void FIELD_ENCOUNT_ST_GetEffectEncount(struct FieldMap *fieldMap)
{
    FieldEncount *obj;

    obj = FIELDMAP_GetEncount(fieldMap);
    EFFECT_ENCOUNT_LoadSetting(obj, obj->effectEncount);
}

/* Clear the state word (offset 0xC) of the field gimmick work and return the work. */
FieldGimmickWork *FIELD_ENCOUNT_ST_ResetGimmickState(struct GameData *gameData)
{
    FieldGimmickWork *gimmick;

    gimmick = (struct FieldGimmickWork *)GAME_DATA_GetFieldGimmick(gameData);
    gimmick->state = 0;
    return gimmick;
}
