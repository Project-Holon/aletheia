/*
 * file:     map_replace.c
 * unit:     yes
 * function: MAP_REPLACE_Create, MAP_REPLACE_GetRecordCount, MAP_REPLACE_LoadRecord, MAP_REPLACE_Delete, MAP_REPLACE_CheckRecord, MAP_REPLACE_GetFlagIndex, MAP_REPLACE_SetupFlags, MAP_REPLACE_FindFlagEntry, MAP_REPLACE_SetFlag, MAP_REPLACE_CheckFlag, MAP_REPLACE_GetDefaultWarpId, MAP_REPLACE_IsValidWarpId, MAP_REPLACE_GetWarpFlagId, MAP_REPLACE_ApplyWarpLocation, MAP_REPLACE_FindFlyTargetIndex, MAP_REPLACE_SetArriveFlag, MAP_REPLACE_SetDirectLocation, MAP_REPLACE_WarpIdToIndex
 * address:  0x02159D84
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Range 0x02159F80..0x0215A064 (warp/fly table d_02170FEC users) is from an
 * unknown original file; it stays here until its home is known.
 *
 * symbols:
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   d_021728BC  0x021728BC  data
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_02170FB0 0x02170FB0 data
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   COMM_PLAYER_SUPPORT_GetInfoCode  0x0202E83C  thumb
 *   INTRUDE_COMM_GetAreaOwnerVersion  0x0215843C  thumb  ov010
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb
 *   MAP_REPLACE_FindFlagEntry 0x02159F04 thumb ov010
 *   d_02170FF4 0x02170FF4 data a2
 *   d_02170FEC 0x02170FEC data
 *   d_02170FF0 0x02170FF0 data
 *   ZONEDATA_SetDirectLocation 0x02014184 thumb
 *   MAP_REPLACE_IsValidWarpId  0x02159F84  thumb  ov010
 *   MAP_REPLACE_GetDefaultWarpId  0x02159F80  thumb  ov010
 *   MAP_REPLACE_SetFlag  0x02159F28  thumb  ov010
 *   MAP_REPLACE_CheckFlag  0x02159F54  thumb  ov010
 */
struct BigObj;
struct Ctx;
struct ArcFile;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

/*
 * One 16-byte record of the replace archive (a/0/1/0 member 0).  ids[0] is
 * the map index the matrix holds; ids[variant] is the one to put in its place.
 */
typedef struct MapReplaceRecord {
    u16 matrixId;           /* matrix the record applies to */
    u8 kind;                /* 0: swap one map index, 1: reload the matrix */
    u8 selector;            /* which variant byte picks the id: 0..2, else a flag table id */
    u16 ids[6];
} MapReplaceRecord;

/* Map replace state (0x2C bytes), created per matrix load and deleted after it. */
typedef struct MapReplace {
    u16 heapId;
    u16 pad02;
    struct ArcFile *arc;
    u32 recordCount;
    /*
     * Variant index per selector: [0] info code, [1] 1 unless the field
     * map reports 0x15, [2] info code + 1 when [1] is set, [3 + i] 1 when
     * event work d_02170FB0[i] holds its value.
     */
    u8 variant[13];
    MapReplaceRecord record;    /* last record read by MAP_REPLACE_LoadRecord */
} MapReplace;

/* Entry of the 10-entry flag table d_02170FB0. */
typedef struct MapReplaceFlagEntry {
    u8 selector;            /* record selector this entry answers */
    u8 flagNo;              /* number callers use to set or test it */
    u16 workId;             /* event work id */
    u16 value;              /* event work value that means "set" */
} MapReplaceFlagEntry;

/* Entry of the 17-entry warp table d_02170FEC (0x14 bytes, home file unknown). */
typedef struct WarpDataEntry {
    u16 arriveFlag;         /* event flag set on arrival */
    u16 isFlyTarget : 1;
    u16 setsFlagOnEntry : 1;
    u16 unusedBits : 14;
    u16 zoneId;             /* zone the warp lands in */
    u16 gridX : 8;
    u16 gridZ : 8;
    u16 entryZoneId;        /* zone whose entry sets arriveFlag */
    char pad0A[10];
} WarpDataEntry;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void ZONEDATA_SetEventFlag(char *, int);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void ARC_TOOL_DeleteHandle(void *arc);
int MAP_REPLACE_GetFlagIndex(int selector);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int COMM_PLAYER_SUPPORT_GetInfoCode(void *a0);
extern int INTRUDE_COMM_GetAreaOwnerVersion(void *p);
extern u32 ZONEDATA_GetEventWorkAddress(u32 a, u32 b);
void MAP_REPLACE_SetupFlags(u8 *variant, int gameSystem);
MapReplaceFlagEntry *MAP_REPLACE_FindFlagEntry(int unused, int flagNo);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Constant leaf: `movs r0, N; bx lr`. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/MAP_REPLACE_GetDefaultWarpId.c \ * --func MAP_REPLACE_GetDefaultWarpId --addr 0x02159F80 --region ov010 --cc dsi/1.1p1 --thumb */ int MAP_REPLACE_GetDefaultWarpId(void);
int MAP_REPLACE_IsValidWarpId(int warpId);
extern void ZONEDATA_SetDirectLocation(void *, int, int, int, int, int);
/* * evidence: owner commit f860957 supplies the matched ARM9 Thumb02014184 * witness. Recheck the caller against that witness; no owner C compiled. * prototype: owner's u16 id is widened to int here because original r1 * is passed unchanged without narrowing. Remaining payloads retain 32 bits. * prior: wave49 one MATCH; tu --suggest-split left caller OUT. */ void MAP_REPLACE_SetDirectLocation(void *location, int zoneId, int unused, unsigned gridX, u16 gridZ);
int MAP_REPLACE_WarpIdToIndex(int warpId);
extern const char d_021728BC[];
extern MapReplaceFlagEntry d_02170FB0[];
extern u16 d_02170FF4[][10];
extern const WarpDataEntry d_02170FEC[];
extern const u16 d_02170FF0[][10];


MapReplace *MAP_REPLACE_Create(int heapId, int gameSystem)
{
    MapReplace *replace = func_02030734(heapId, sizeof(MapReplace), 1, d_021728BC, 0x77);
    replace->heapId = heapId;
    replace->arc = func_020490F4(10, heapId);
    replace->recordCount = (u16)ARC_TOOL_GetHandleMemberSize(replace->arc, 0) / sizeof(MapReplaceRecord);
    MAP_REPLACE_SetupFlags(replace->variant, gameSystem);
    return replace;
}



u32 MAP_REPLACE_GetRecordCount(MapReplace *replace) { return replace->recordCount; }



/* Read record `index` into replace->record and return its matrix id. */
u32 MAP_REPLACE_LoadRecord(MapReplace *replace, int index)
{
    ARC_TOOL_ReadHandleMemberRange(replace->arc, 0, index * sizeof(MapReplaceRecord), sizeof(MapReplaceRecord), &replace->record);
    return replace->record.matrixId;
}



int MAP_REPLACE_Delete(MapReplace *replace)
{
    ARC_TOOL_DeleteHandle(replace->arc);
    return func_020307B0(replace);
}



/*
 * Check the loaded record: returns 0 when the chosen id equals ids[0],
 * 2 for a reload record (kind 1), 1 for a swap record (kind 0).
 */
int MAP_REPLACE_CheckRecord(MapReplace *replace, u32 *oldId, u32 *newId)
{
    MapReplaceRecord *record = &replace->record;
    u8 *variant = replace->variant;
    int selector = record->selector;
    u32 baseId = record->ids[0];
    int index;
    u32 id;
    switch (selector) {
    case 0:
        index = variant[0];
        break;
    case 1:
        index = variant[1];
        break;
    case 2:
        index = variant[2];
        break;
    default:
        index = (variant + MAP_REPLACE_GetFlagIndex(selector))[3];
        break;
    }
    id = record->ids[index];
    *oldId = baseId;
    *newId = id;
    if (baseId == id)
        return 0;
    if (record->kind == 1)
        return 2;
    if (record->kind == 0)
        return 1;
    return 0;
}



int MAP_REPLACE_GetFlagIndex(int selector)
{
    unsigned int i;
    for (i = 0; i < 10; i++) {
        if (selector == d_02170FB0[i].selector)
            return i;
    }
    return -1;
}



void MAP_REPLACE_SetupFlags(u8 *variant, int gameSystem)
{
    int eventWork = GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData((const struct Ctx *)gameSystem));
    int fieldMap = GAMESYSTEM_GetGameComm((const struct Ctx *)gameSystem);
    int infoCode = COMM_PLAYER_SUPPORT_GetInfoCode((void *)gameSystem);
    int i;
    variant[0] = infoCode;
    variant[1] = (INTRUDE_COMM_GetAreaOwnerVersion((void *)fieldMap) != 0x15);
    variant[2] = (variant[1] == 0) ? 0 : infoCode + 1;
    for (i = 0; i < 10; i++) {
        MapReplaceFlagEntry *entry = &d_02170FB0[i];
        u16 *work = (u16 *)ZONEDATA_GetEventWorkAddress(eventWork, entry->workId);
        if (*work == entry->value)
            variant[3 + i] = 1;
        else
            variant[3 + i] = 0;
    }
}



MapReplaceFlagEntry *MAP_REPLACE_FindFlagEntry(int unused, int flagNo)
{
    unsigned int i;
    for (i = 0; i < 10; i++) {
        MapReplaceFlagEntry *entry = &d_02170FB0[i];
        if (entry->flagNo == flagNo)
            return entry;
    }
    return 0;
}



/*
 * extent: two bytes of zero alignment padding at 0x02159F52.
 */
void MAP_REPLACE_SetFlag(int gameData, int flagNo, int set)
{
    MapReplaceFlagEntry *entry = MAP_REPLACE_FindFlagEntry(gameData, flagNo);
    u16 *work;
    if (entry) {
        work = (u16 *)ZONEDATA_GetEventWorkAddress(GAME_DATA_GetEventWork((const struct BigObj *)gameData), entry->workId);
        if (set)
            *work = entry->value;
        else
            *work = 0;
    }
}



int MAP_REPLACE_CheckFlag(int gameData, int flagNo)
{
    MapReplaceFlagEntry *entry = MAP_REPLACE_FindFlagEntry(gameData, flagNo);
    u16 *work;
    if (entry) {
        work = (u16 *)ZONEDATA_GetEventWorkAddress(GAME_DATA_GetEventWork((const struct BigObj *)gameData), entry->workId);
        if (entry->value == *work)
            return 1;
        else
            return 0;
    }
    return 0;
}



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MAP_REPLACE_GetDefaultWarpId.c \
 *       --func MAP_REPLACE_GetDefaultWarpId --addr 0x02159F80 --region ov010 --cc dsi/1.1p1 --thumb
 */
/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, #N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MAP_REPLACE_GetDefaultWarpId.c \
 *       --func MAP_REPLACE_GetDefaultWarpId --addr 0x02159F80 --region ov010 --cc dsi/1.1p1 --thumb
 */
int MAP_REPLACE_GetDefaultWarpId(void) { return 1; }





/* 1 when warpId is a valid 1-based index of the 17-entry warp table (stand-in: goto form). */
int MAP_REPLACE_IsValidWarpId(int warpId)
{

    if (warpId <= 0) goto invalid;
validRangeCheck:
    if ((unsigned)warpId <= (unsigned)0x11) goto valid;
invalid:
warpId = 0;
    return warpId;
valid:
warpId = 1;
    return warpId;}


/*
 * addressing: getter result converted to unsigned; scale/add modulo 32 bits
 * preserves the original muls/add address without assuming a valid array index.
 */
u16 MAP_REPLACE_GetWarpFlagId(int warpId) { return *(u16 *)((unsigned)d_02170FF4 + (unsigned)MAP_REPLACE_WarpIdToIndex(warpId) * 20u); }


/*
 * extent: followed by independently matched ov010_func_02159FE0.c.
 * lever: const table declarations hoist the second table load before the stack argument.
 * prototype: both payload bytes come out of the halfword as bit fields, so the
 * u16 fifth input needs no extra truncation.
 */
void MAP_REPLACE_ApplyWarpLocation(int warpId, int location)
{
    int index = MAP_REPLACE_WarpIdToIndex(warpId);
    const WarpDataEntry *entry = &d_02170FEC[index];
    u32 zoneId = d_02170FF0[index][0];
    MAP_REPLACE_SetDirectLocation((void *)location, zoneId, 0, entry->gridX, entry->gridZ);
}









/*
 * Unlabelled leaf (push {r4,r5} only, so disasm.py prints it as .word
 * data): a 1-based index lookup over a 17-entry, 0x14-byte table.
 * Callee of ov020 EVENT_MAPCHANGE_ApplyLocation.
 */
int MAP_REPLACE_FindFlyTargetIndex(int zoneId)
{
    unsigned int i;

    for (i = 0; i < 17; i++) {
        if (zoneId == d_02170FEC[i].zoneId && d_02170FEC[i].isFlyTarget)
            return i + 1;
    }
    return 0;
}








void MAP_REPLACE_SetArriveFlag(void *gameData, int zoneId)
{
    unsigned i;
    const WarpDataEntry *entry;
    for (i = 0; i < 17; i++) {
        entry = &d_02170FEC[i];
        if (zoneId == entry->entryZoneId && entry->setsFlagOnEntry) {
            ZONEDATA_SetEventFlag((char *)GAME_DATA_GetEventWork(gameData), entry->arriveFlag);
            return;
        }
    }
}








/*
 * evidence: owner commit f860957 supplies the matched ARM9 Thumb02014184
 * witness. Recheck the caller against that witness; no owner C compiled.
 * prototype: owner's u16 id is widened to int here because original r1
 * is passed unchanged without narrowing. Remaining payloads retain 32 bits.
 * prior: wave49 one MATCH; tu --suggest-split left caller OUT.
 */
void MAP_REPLACE_SetDirectLocation(void *location, int zoneId, int unused, unsigned gridX, u16 gridZ)
{
    ZONEDATA_SetDirectLocation(location, zoneId, 1, gridX << 16, 0, (unsigned)gridZ << 16);
}









/* Table index of a 1-based warp id; an out-of-range id falls back to the default id. */
int MAP_REPLACE_WarpIdToIndex(int warpId)
{
    if (MAP_REPLACE_IsValidWarpId(warpId) == 0)
        warpId = MAP_REPLACE_GetDefaultWarpId();
    return warpId - 1;
}
