/*
 * file:     field_palace_sys.c
 * unit:     yes
 * function: FIELD_PALACE_SYS_Create, FIELD_PALACE_SYS_Delete, FIELD_PALACE_SYS_GetPalTable, FIELD_PALACE_SYS_SetupPalTable, FIELD_PALACE_SYS_LoadPalTable, FIELD_PALACE_SYS_IsZoneFlagSet
 * address:  0x021D33A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes FIELD_PALACE_SYS_IsZoneFlagSet (the zone flag check, 021D3554) from the unplaced directory (lane FXC3: contiguous with the last function of this file).
 * Split from field_palace_sys.c at 0x021D33A8 (__FILE__ anchor field_palace_sys.c at 0x021D33A8).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_021DE6D4     0x021DE6D4  data  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   ZONEDATA_IsZoneGroup118To13C  0x02013D74  thumb
 *   FIELD_PALACE_SYS_IsZoneFlagSet  0x021D3554  thumb  ov021
 *   INTRUDE_COMM_GetAreaOwnerVersionClass  0x0215850C  thumb  ov010
 *   INTRUDE_COMM_GetAreaSlotFlag  0x02158468  thumb  ov010
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   sPalaceZoneFlags    0x021DD944 data
 *   _u32_div_f                   0x0209C2B0  arm
 */
struct GameSystem;
struct GameData;
struct GameComm;
struct EventWork;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

/* Entralink (palace) field state: owns the town palette table of the zone. */
typedef struct FieldPalaceSys {
    struct GameSystem *gameSystem;  /* 0x00 */
    void *fieldMap;                 /* 0x04 */
    u8 *palTable;                   /* 0x08: 0x20 bytes, or NULL */
} FieldPalaceSys;

/* One row of a palace palette file (arc 0xE0); row 0 is the default. */
typedef struct FieldPalacePalRecord {
    u8 areaGroup;                   /* 0xFF: any area */
    u8 season;                      /* 0xFF: any season */
    u8 padding[2];
    u8 palTable[0x20];
} FieldPalacePalRecord;

#define _PALACE_PAL_ARC_ID      0xE0
#define _PALACE_PAL_TABLE_SIZE  0x20

/* One palace zone and the event flag that tells whether its area is open (4 bytes each). */
typedef struct PalaceZoneFlag {
    u16 zoneId;
    u16 flagId;
} PalaceZoneFlag;

#define PALACE_ZONE_FLAG_COUNT 25

extern const char d_021DE6D4[];  /* "field_palace_sys.c" */
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern void ARC_TOOL_DeleteHandle(void *h);
extern struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
extern int ZONEDATA_IsZoneGroup118To13C(u32 zoneId);
extern int FIELD_PALACE_SYS_IsZoneFlagSet(struct GameData *gameData, int zoneId);
extern int INTRUDE_COMM_GetAreaOwnerVersionClass(struct GameComm *gameComm, struct GameData *gameData);
extern int INTRUDE_COMM_GetAreaSlotFlag(struct GameComm *gameComm);
extern u32 ZONEDATA_GetAreaId(u32 zoneId);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void MI_CpuCopy8(void *src, void *dst, u32 n);
FieldPalaceSys *FIELD_PALACE_SYS_Create(u16 heapId, struct GameSystem *gameSystem, void *fieldMap, u16 zoneId);
void FIELD_PALACE_SYS_Delete(FieldPalaceSys *sys);
u8 *FIELD_PALACE_SYS_GetPalTable(FieldPalaceSys *sys);
void FIELD_PALACE_SYS_SetupPalTable(FieldPalaceSys *sys, u16 zoneId, u16 heapId);
void FIELD_PALACE_SYS_LoadPalTable(FieldPalaceSys *sys, u32 fileId, int zoneId, int season, u16 heapId);
extern void *GAME_DATA_GetEventWork(const struct GameData *gameData);
extern u32 ZONEDATA_CheckEventFlag(struct EventWork *eventWork, s32 flagId);
extern PalaceZoneFlag sPalaceZoneFlags[];

/*
 * Created by the field map on load (fieldmap.c); the palette table goes to
 * the build models and the 3D object control.
 */
FieldPalaceSys *FIELD_PALACE_SYS_Create(u16 heapId, struct GameSystem *gameSystem, void *fieldMap, u16 zoneId)
{
    FieldPalaceSys *sys = GFL_HEAP_Alloc(heapId, sizeof(FieldPalaceSys), 1, d_021DE6D4, 0x43);

    sys->gameSystem = gameSystem;
    sys->fieldMap = fieldMap;
    sys->palTable = 0;
    FIELD_PALACE_SYS_SetupPalTable(sys, zoneId, heapId);
    return sys;
}

void FIELD_PALACE_SYS_Delete(FieldPalaceSys *sys)
{
    if (sys->palTable != 0) {
        GFL_HEAP_Free(sys->palTable);
    }
    GFL_HEAP_Free(sys);
}

u8 *FIELD_PALACE_SYS_GetPalTable(FieldPalaceSys *sys)
{
    return sys->palTable;
}

/*
 * In a palace zone with a link session, picks the palette file from the
 * version class of the area owner (2 and 1 give files 0/1 and 2/3) and from
 * the zone event flag check, then loads the table for the owner's season.
 * zoneId and heapId are u16: the narrow parameters pin their home stores to
 * the front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 */
void FIELD_PALACE_SYS_SetupPalTable(FieldPalaceSys *sys, u16 zoneId, u16 heapId)
{
    struct GameComm *gameComm;
    int flagSet;
    struct GameData *gameData;
    int versionClass;
    int fileId;

    gameComm = GAMESYSTEM_GetGameComm(sys->gameSystem);
    if (ZONEDATA_IsZoneGroup118To13C(zoneId) != 1)
        return;
    if (gameComm == 0)
        return;
    gameData = GAMESYSTEM_GetGameData(sys->gameSystem);
    flagSet = FIELD_PALACE_SYS_IsZoneFlagSet(gameData, zoneId);
    versionClass = INTRUDE_COMM_GetAreaOwnerVersionClass(gameComm, gameData);
    fileId = 0xffff;
    if (versionClass == 2) {
        if (flagSet == 1)
            fileId = 1;
        else
            fileId = 0;
    } else if (versionClass == 1) {
        if (flagSet == 1)
            fileId = 3;
        else
            fileId = 2;
    }
    if (fileId == 0xffff)
        return;
    FIELD_PALACE_SYS_LoadPalTable(sys, fileId, zoneId, INTRUDE_COMM_GetAreaSlotFlag(gameComm), heapId);
}

/*
 * Loads palette file fileId and copies the table of the first row whose
 * area group and season match (0xFF matches any); row 0 is the fallback.
 */
void FIELD_PALACE_SYS_LoadPalTable(FieldPalaceSys *sys, u32 fileId, int zoneId, int season, u16 heapId)
{
    u32 size;
    int found;
    void *arc;
    u32 i;
    FieldPalacePalRecord *records;
    u32 tempHeapId;
    u16 areaGroup;

    found = 0;
    tempHeapId = (heapId & 0x7fff) | 0x8000;
    arc = ARC_TOOL_CreateHandle(_PALACE_PAL_ARC_ID, tempHeapId & 0xffff);
    areaGroup = ((int)ZONEDATA_GetAreaId(zoneId) - 2) / 4 + 1;
    records = ARC_UTIL_LoadHandleMemberWithSize(arc, fileId, 0, (u16)tempHeapId, &size);
    for (i = 1; i < size / sizeof(FieldPalacePalRecord); i++) {
        if ((areaGroup == records[i].areaGroup || records[i].areaGroup == 0xff)
            && (season == records[i].season || records[i].season == 0xff)) {
            found = 1;
            break;
        }
    }
    if (!found) {
        i = 0;
    }
    sys->palTable = GFL_HEAP_Alloc(heapId, _PALACE_PAL_TABLE_SIZE, 0, d_021DE6D4, 0xd4);
    MI_CpuCopy8(records[i].palTable, sys->palTable, _PALACE_PAL_TABLE_SIZE);
    GFL_HEAP_Free(records);
    ARC_TOOL_DeleteHandle(arc);
}

/* 1 when the zone's flag is set. Zones of other groups and zones without a
 * table row count as set. */
int FIELD_PALACE_SYS_IsZoneFlagSet(struct GameData *gameData, int zoneId)
{
    struct EventWork *eventWork = GAME_DATA_GetEventWork(gameData);

    if (ZONEDATA_IsZoneGroup118To13C(zoneId) == 1) {
        unsigned int i;
        for (i = 0; i < PALACE_ZONE_FLAG_COUNT; i++) {
            if (zoneId == sPalaceZoneFlags[i].zoneId) {
                if (ZONEDATA_CheckEventFlag(eventWork, sPalaceZoneFlags[i].flagId) == 1) {
                    return 1;
                }
                return 0;
            }
        }
    }
    return 1;
}
