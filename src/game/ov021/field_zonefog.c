/*
 * file:     field_zonefog.c
 * unit:     yes
 * function: FIELD_ZONEFOG_Create, FIELD_ZONEFOG_Delete, FIELD_ZONEFOG_Main, FIELD_ZONEFOG_SetUp, FIELD_ZONEFOG_IsLoadRequest, FIELD_ZONEFOG_Clear, FIELD_ZONEFOG_IsFog, FIELD_ZONEFOG_IsLight, FIELD_ZONEFOG_GetFogOffset, FIELD_ZONEFOG_GetFogSlope, FIELD_ZONEFOG_GetLightId
 * address:  0x021A02C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_fog.c (CL110): __FILE__ anchor field_zonefog.c at 0x021A02C4; ends at the field_light.c anchor 0x021A03D0.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   d_021DDE28     0x021DDE28  data
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 */
#include "../types.h"

#define ZONEFOG_ID_NONE 0x0FFFFFFF
#define ZONEFOG_ARC_ID  0x51

/* One zone fog record loaded from archive ZONEFOG_ARC_ID. */
typedef struct {
    int fogOffset;
    int fogSlope;
} ZoneFogData;

/* Zone fog and light ids of the current zone (0x10 bytes). */
typedef struct FieldZoneFog {
    u8 loadRequest;
    s8 loadWait;
    u16 fogId;
    ZoneFogData *data;
    int lightId;
    void *arcHandle;
} FieldZoneFog;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
void FIELD_ZONEFOG_Clear(FieldZoneFog *zoneFog);
extern char d_021DDE28[];

FieldZoneFog *FIELD_ZONEFOG_Create(u16 heapId)
{
    FieldZoneFog *zoneFog = (FieldZoneFog *)GFL_HEAP_Alloc(heapId, sizeof(FieldZoneFog), 1, d_021DDE28, 0x51);
    zoneFog->lightId = ZONEFOG_ID_NONE;
    zoneFog->arcHandle = ARC_TOOL_CreateHandle(ZONEFOG_ARC_ID, heapId);
    return zoneFog;
}

int FIELD_ZONEFOG_Delete(FieldZoneFog *zoneFog)
{
    ARC_TOOL_DeleteHandle(zoneFog->arcHandle);
    FIELD_ZONEFOG_Clear(zoneFog);
    return GFL_HEAP_Free(zoneFog);
}

/* Loads the requested fog record once the wait count reaches zero. */
void FIELD_ZONEFOG_Main(FieldZoneFog *zoneFog, u16 heapId)
{
    if (zoneFog->loadRequest == 1) {
        zoneFog->loadWait--;
        if (zoneFog->loadWait <= 0) {
            zoneFog->data = ARC_UTIL_LoadHandleMember(zoneFog->arcHandle, zoneFog->fogId, 0, heapId);
            zoneFog->loadRequest = 0;
        }
    }
}

void FIELD_ZONEFOG_SetUp(FieldZoneFog *zoneFog, u32 fogId, u32 lightId, u8 loadWait)
{
    if (fogId != ZONEFOG_ID_NONE) {
        zoneFog->loadRequest = 1;
        zoneFog->fogId = fogId;
        zoneFog->loadWait = loadWait;
    }
    zoneFog->lightId = lightId;
}

u8 FIELD_ZONEFOG_IsLoadRequest(FieldZoneFog *zoneFog)
{
    return zoneFog->loadRequest;
}

void FIELD_ZONEFOG_Clear(FieldZoneFog *zoneFog)
{
    if (zoneFog->data != 0) {
        GFL_HEAP_Free(zoneFog->data);
        zoneFog->data = 0;
    }
    zoneFog->lightId = ZONEFOG_ID_NONE;
    if (zoneFog->loadRequest == 1) {
        zoneFog->loadRequest = 0;
    }
}

int FIELD_ZONEFOG_IsFog(FieldZoneFog *zoneFog)
{
    return zoneFog->data != 0 ? 1 : 0;
}

int FIELD_ZONEFOG_IsLight(FieldZoneFog *zoneFog)
{
    return zoneFog->lightId != ZONEFOG_ID_NONE ? 1 : 0;
}

int FIELD_ZONEFOG_GetFogOffset(FieldZoneFog *zoneFog)
{
    ZoneFogData *data = zoneFog->data;

    if (data != 0) {
        return data->fogOffset;
    }
    return ZONEFOG_ID_NONE;
}

int FIELD_ZONEFOG_GetFogSlope(FieldZoneFog *zoneFog)
{
    ZoneFogData *data = zoneFog->data;

    if (data != 0) {
        return data->fogSlope;
    }
    return ZONEFOG_ID_NONE;
}

int FIELD_ZONEFOG_GetLightId(FieldZoneFog *zoneFog)
{
    return zoneFog->lightId;
}
