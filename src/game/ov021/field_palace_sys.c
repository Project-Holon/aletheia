/*
 * file:     field_palace_sys.c
 * unit:     yes
 * function: func_021D33A8, func_021D33E0, func_021D33F8, func_021D33FC, func_021D3478, func_021D3554
 * address:  0x021D33A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes func_021D3554 (the zone flag check, 021D3554) from the unplaced directory (lane FXC3: contiguous with the last function of this file).
 * Split from field_palace_sys.c at 0x021D33A8 (__FILE__ anchor field_palace_sys.c at 0x021D33A8).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02049238  0x02049238  arm
 *   d_021DE6D4     0x021DE6D4  data  ov021
 *   func_02012138  0x02012138  thumb
 *   func_02013D74  0x02013D74  thumb
 *   func_021D3554  0x021D3554  thumb  ov021
 *   func_0215850C  0x0215850C  thumb  ov010
 *   func_02158468  0x02158468  thumb  ov010
 *   func_02013B38  0x02013B38  thumb
 *   func_0204A39C  0x0204A39C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   g_021DD944    0x021DD944 data
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
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern void func_02049238(void *h);
extern struct GameComm *func_02012138(const struct GameSystem *gameSystem);
extern int func_02013D74(u32 zoneId);
extern int func_021D3554(struct GameData *gameData, int zoneId);
extern int func_0215850C(struct GameComm *gameComm, struct GameData *gameData);
extern int func_02158468(struct GameComm *gameComm);
extern u32 func_02013B38(u32 zoneId);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void func_02082D44(void *src, void *dst, u32 n);
FieldPalaceSys *func_021D33A8(u16 heapId, struct GameSystem *gameSystem, void *fieldMap, u16 zoneId);
void func_021D33E0(FieldPalaceSys *sys);
u8 *func_021D33F8(FieldPalaceSys *sys);
void func_021D33FC(FieldPalaceSys *sys, u16 zoneId, u16 heapId);
void func_021D3478(FieldPalaceSys *sys, u32 fileId, int zoneId, int season, u16 heapId);
extern struct EventWork *func_0201296C(const struct GameData *gameData);
extern u32 func_020142E8(struct EventWork *eventWork, s32 flagId);
extern PalaceZoneFlag g_021DD944[];
int func_021D3554(struct GameData *gameData, int zoneId);

/*
 * Created by the field map on load (fieldmap.c); the palette table goes to
 * the build models and the 3D object control.
 */
FieldPalaceSys *func_021D33A8(u16 heapId, struct GameSystem *gameSystem, void *fieldMap, u16 zoneId)
{
    FieldPalaceSys *sys = func_02030734(heapId, sizeof(FieldPalaceSys), 1, d_021DE6D4, 0x43);

    sys->gameSystem = gameSystem;
    sys->fieldMap = fieldMap;
    sys->palTable = 0;
    func_021D33FC(sys, zoneId, heapId);
    return sys;
}

void func_021D33E0(FieldPalaceSys *sys)
{
    if (sys->palTable != 0) {
        func_020307B0(sys->palTable);
    }
    func_020307B0(sys);
}

u8 *func_021D33F8(FieldPalaceSys *sys)
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
void func_021D33FC(FieldPalaceSys *sys, u16 zoneId, u16 heapId)
{
    struct GameComm *gameComm;
    int flagSet;
    struct GameData *gameData;
    int versionClass;
    int fileId;

    gameComm = func_02012138(sys->gameSystem);
    if (func_02013D74(zoneId) != 1)
        return;
    if (gameComm == 0)
        return;
    gameData = func_020120F4(sys->gameSystem);
    flagSet = func_021D3554(gameData, zoneId);
    versionClass = func_0215850C(gameComm, gameData);
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
    func_021D3478(sys, fileId, zoneId, func_02158468(gameComm), heapId);
}

/*
 * Loads palette file fileId and copies the table of the first row whose
 * area group and season match (0xFF matches any); row 0 is the fallback.
 */
void func_021D3478(FieldPalaceSys *sys, u32 fileId, int zoneId, int season, u16 heapId)
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
    arc = func_020490F4(_PALACE_PAL_ARC_ID, tempHeapId & 0xffff);
    areaGroup = ((int)func_02013B38(zoneId) - 2) / 4 + 1;
    records = func_0204A39C(arc, fileId, 0, (u16)tempHeapId, &size);
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
    sys->palTable = func_02030734(heapId, _PALACE_PAL_TABLE_SIZE, 0, d_021DE6D4, 0xd4);
    func_02082D44(records[i].palTable, sys->palTable, _PALACE_PAL_TABLE_SIZE);
    func_020307B0(records);
    func_02049238(arc);
}

/* 1 when the zone's flag is set. Zones of other groups and zones without a
 * table row count as set. */
int func_021D3554(struct GameData *gameData, int zoneId)
{
    struct EventWork *eventWork = func_0201296C(gameData);

    if (func_02013D74(zoneId) == 1) {
        unsigned int i;
        for (i = 0; i < PALACE_ZONE_FLAG_COUNT; i++) {
            if (zoneId == g_021DD944[i].zoneId) {
                if (func_020142E8(eventWork, g_021DD944[i].flagId) == 1) {
                    return 1;
                }
                return 0;
            }
        }
    }
    return 1;
}
