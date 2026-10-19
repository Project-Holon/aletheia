/*
 * file:     eventdata_system.c
 * unit:     yes
 * function: EVENTDATA_SYSTEM_Create, EVENTDATA_SYSTEM_Delete, EVENTDATA_SYSTEM_Clear, EVENTDATA_SYSTEM_Load, EVENTDATA_SYSTEM_LoadEventData, EVENTDATA_SYSTEM_LoadEncountData, EVENTDATA_SYSTEM_GetSpecialScriptData, EVENTDATA_SYSTEM_IsEncountDataLoaded, EVENTDATA_SYSTEM_DisableConnect, EVENTDATA_SYSTEM_CheckAutoPosEvent, EVENTDATA_SYSTEM_ReadEventFile, EVENTDATA_SYSTEM_ClearEventTables, EVENTDATA_SYSTEM_GetEncountData, EVENTDATA_SYSTEM_GetConnectCount, EVENTDATA_SYSTEM_SearchConnectIdByGridPos, EVENTDATA_SYSTEM_SearchConnectIdByRailLocation, EVENTDATA_SYSTEM_GetConnectData, EVENTDATA_SYSTEM_IsSpecialExitConnect, EVENTDATA_SYSTEM_SetConnectExitLocation, EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly, EVENTDATA_SYSTEM_GetConnectGridExitOffset, EVENTDATA_SYSTEM_GetConnectRailExitOffset, EVENTDATA_SYSTEM_IsConnectExitDir, EVENTDATA_SYSTEM_GetConnectExitType, EVENTDATA_SYSTEM_IsConnectDisabled, EVENTDATA_SYSTEM_SetConnectGridPos, EVENTDATA_SYSTEM_GetNpcHeaders, EVENTDATA_SYSTEM_GetNpcCount, EVENTDATA_SYSTEM_SetNpcGridPos, EVENTDATA_SYSTEM_SetNpcObjCode, EVENTDATA_SYSTEM_SetNpcEventId, EVENTDATA_SYSTEM_DirToPosEventType, EVENTDATA_SYSTEM_SearchPosEvent, EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight, EVENTDATA_SYSTEM_SearchAutoPosEvent, EVENTDATA_SYSTEM_SearchRailPosEvent, EVENTDATA_SYSTEM_GetPosEventScriptId, EVENTDATA_SYSTEM_GetAutoPosEventScriptId, EVENTDATA_SYSTEM_GetRailPosEventScriptId, EVENTDATA_SYSTEM_SearchBgEventScriptId, EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk, EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden, EVENTDATA_SYSTEM_GetConnectCenterPosThunk, EVENTDATA_SYSTEM_GetPosEventCenterPosThunk, EVENTDATA_SYSTEM_SetBgEventGridPos, EVENTDATA_SYSTEM_CalcExitOffset, EVENTDATA_SYSTEM_CalcConnectGridExitOffset, EVENTDATA_SYSTEM_CalcConnectRailExitOffset, EVENTDATA_SYSTEM_ConnectExitDirToDir, EVENTDATA_SYSTEM_GetConnectExitGridPos, EVENTDATA_SYSTEM_GetConnectCenterPos, EVENTDATA_SYSTEM_IsConnectGridHit, EVENTDATA_SYSTEM_GetConnectExitRailLocation, EVENTDATA_SYSTEM_IsConnectRailHit, EVENTDATA_SYSTEM_IsBgEventGridHit, EVENTDATA_SYSTEM_IsBgEventRailHit, EVENTDATA_SYSTEM_GetPosEventCenterPos, EVENTDATA_SYSTEM_IsPosEventGridHit, EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight, EVENTDATA_SYSTEM_IsPosEventRailHit
 * address:  0x0216237C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * The zone event data system (anchor: allocation of the 0xAA8-byte EventDataSystem).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   d_0217299C     0x0217299C  data  ov010  a1
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_ENCOUNT_ST_LoadEncountData  0x0215E2B8  thumb  ov010
 *   ZONEDATA_GetEventDataId  0x02013ECC  thumb
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   ZONEDATA_InitLocation 0x020140F8 thumb
 *   ZONEDATA_SetExitLocation 0x02014110 thumb
 *   ZONEDATA_SetExitRailLocation 0x02014134 thumb
 *   ZONEDATA_SetExitLocationIdOnly  0x0201416C  thumb
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb
 *   HIDDEN_ITEM_GetFlag  0x02164708  thumb  ov010
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   ZONEDATA_DirToRailKey 0x0201441C thumb
 *   FX_Div 0x0207C768 arm
 *   MI_CpuFill8    0x02082BCC  arm
 */

struct EncountData;
struct ArcFile;
struct EventRec;

#include "../ov021/fldmmdl_rail_types.h"
#include "fldmmdl_types.h"

typedef unsigned int u32;

/* The event file: four u8 counts (bg, npc, connect, pos), then the tables. */
typedef struct EventFileData {
    u8 counts[4];       /* 0x00 */
    u8 tables[1];       /* 0x04 */
} EventFileData;

struct EventRec {
    u16 scriptId;    /* 0x00 */
    u16 workValue;   /* 0x02: fires when the event work equals this */
    u16 workId;      /* 0x04: 0 = no work check */
    u16 checkType;   /* 0x06: 1..4 facing (EVENTDATA_SYSTEM_DirToPosEventType), 6 automatic */
    u16 posType;     /* 0x08: 0 grid, 1 rail */
    u16 area[6];     /* 0x0A: x, z, sizeX, sizeZ, y (s16), spare */
};

typedef int s32;

/* Grid area of a connect: a box of sizeX by sizeZ cells at (x, z), at height y. */
typedef struct ConnectGridArea {
    s16 x;              /* 0x08 */
    s16 y;              /* 0x0A */
    s16 z;              /* 0x0C */
    u16 sizeX;          /* 0x0E */
    u16 sizeZ;          /* 0x10 */
} ConnectGridArea;

/* Rail area of a connect: lineSize by widthSize grid steps on one rail. */
typedef struct ConnectRailArea {
    u16 railIndex;      /* 0x08 */
    u16 lineGrid;       /* 0x0A: first line step */
    s16 widthGrid;      /* 0x0C: first width step */
    u16 lineSize;       /* 0x0E */
    u16 widthSize;      /* 0x10 */
    u16 flipMode;       /* 0x12: 0 flip line, 1 flip width, 2 both, 3 none */
} ConnectRailArea;

/* A connect (warp) record, 0x14 bytes. */
typedef struct ConnectData {
    u16 zoneId;         /* 0x00: destination zone, 0xFFFF when disabled */
    u16 exitId;         /* 0x02: destination exit, 0x100 marks a special exit */
    u8 exitDir;         /* 0x04: 0..4, see EVENTDATA_SYSTEM_ConnectExitDirToDir */
    u8 exitType;        /* 0x05 */
    u16 posType;        /* 0x06: 0 grid, 1 rail */
    union {
        ConnectGridArea grid;
        ConnectRailArea rail;
    } area;             /* 0x08 */
} ConnectData;

/* Grid place of a bg event: one cell, height within 2. */
typedef struct BgEventGridPos {
    s32 x;              /* 0x08 */
    s32 z;              /* 0x0C */
    s32 y;              /* 0x10 */
} BgEventGridPos;

/* Rail place of a bg event. */
typedef struct BgEventRailPos {
    u16 railIndex;      /* 0x08 */
    u16 lineGrid;       /* 0x0A */
    s16 widthGrid;      /* 0x0C */
} BgEventRailPos;

/* A bg event record (sign, hidden item), 0x14 bytes. */
typedef struct BgEventData {
    u16 scriptId;       /* 0x00 */
    u16 type;           /* 0x02: 2 hidden item */
    u16 dir;            /* 0x04: which talk directions fire it, 0..6 */
    u16 posType;        /* 0x06: 0 grid, 1 rail */
    union {
        s32 word[3];
        BgEventGridPos grid;
        BgEventRailPos rail;
    } pos;              /* 0x08 */
} BgEventData;

typedef struct EventDataSystem {
    u32 reserved;
    struct ArcFile *eventArc;     /* 0x04: arc 0x7D, zone event files */
    void *encountArc;             /* 0x08: arc 0x7E, encounter tables */
    void *auxArc;                 /* 0x0C: arc 0x39 */
    u16 zoneId;                   /* 0x10 */
    u16 bgCount;                  /* 0x12 */
    u16 npcCount;                 /* 0x14 */
    u16 connectCount;             /* 0x16 */
    u16 posCount;                 /* 0x18 */
    u16 pad1A;
    BgEventData *bgEvents;          /* 0x1C: 0x14-byte records */
    MmdlHeader *npcHeaders;       /* 0x20: 0x24-byte records */
    ConnectData *connects;          /* 0x24: 0x14-byte records */
    struct EventRec *posEvents;   /* 0x28: 0x16-byte records */
    u16 loadedBgCount;            /* 0x2C: counts as read from the file */
    u16 loadedNpcCount;
    u16 loadedConnectCount;
    u16 loadedPosCount;
    u32 encountLoaded;            /* 0x34 */
    u8 encountHead[7];            /* 0x38: encounter data, read by FIELD_ENCOUNT_ST_LoadEncountData */
    u8 encountLow : 7;
    u8 encountFlag : 1;           /* 0x3F */
    u8 encountRest[0x120 - 0x40];
    char *specialScripts;         /* 0x120: end of the event file data */
    int fileSize;                 /* 0x124 */
    EventFileData fileData;       /* 0x128 */
} EventDataSystem;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern int GFL_HEAP_Free();
extern int FIELD_ENCOUNT_ST_LoadEncountData(struct EncountData *encount, int a, int b, int n);
extern unsigned ZONEDATA_GetEventDataId(unsigned);
extern unsigned ARC_TOOL_GetHandleMemberSize(struct ArcFile *, unsigned);
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *, unsigned, unsigned, unsigned, void *);
extern void ZONEDATA_InitLocation(int loc);
extern void ZONEDATA_SetExitLocation(int *, u16, s16, u16, int, unsigned, unsigned, unsigned);
extern void ZONEDATA_SetExitRailLocation(int *, u16, s16, u16, int, u16, u16, s16);
extern int ZONEDATA_SetExitLocationIdOnly(int loc, int zoneId, int exitId, int exitOffset);
extern u32 ZONEDATA_GetEventWorkAddress(u32 a, u32 b);
extern u16 HIDDEN_ITEM_GetFlag(u16 id);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern u8 ZONEDATA_DirToRailKey(int m);
extern u32 FX_Div(u32 a, u32 b);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
EventDataSystem *EVENTDATA_SYSTEM_Create(int heapId);
void EVENTDATA_SYSTEM_Delete(EventDataSystem *system);
void EVENTDATA_SYSTEM_Clear(EventDataSystem *system);
void EVENTDATA_SYSTEM_Load(EventDataSystem *system, u16 zoneId, u8 encountParam);
void EVENTDATA_SYSTEM_LoadEventData(EventDataSystem *system, u16 zoneId, u8 unused);
void EVENTDATA_SYSTEM_LoadEncountData(EventDataSystem *system, int zoneId, int encountParam);
u32 EVENTDATA_SYSTEM_GetSpecialScriptData(EventDataSystem *system);
u32 EVENTDATA_SYSTEM_IsEncountDataLoaded(EventDataSystem *system);
void EVENTDATA_SYSTEM_DisableConnect(EventDataSystem *system, u16 index);
int EVENTDATA_SYSTEM_CheckAutoPosEvent(EventDataSystem *system, int *pos);
void EVENTDATA_SYSTEM_ReadEventFile(EventDataSystem *system, int zoneId);
void EVENTDATA_SYSTEM_ClearEventTables(EventDataSystem *system);
u32 EVENTDATA_SYSTEM_GetEncountData(u32 systemAddr);
u16 EVENTDATA_SYSTEM_GetConnectCount(EventDataSystem *system);
int EVENTDATA_SYSTEM_SearchConnectIdByGridPos(EventDataSystem *system, const int *pos);
int EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(EventDataSystem *system, RailLocation *location);
ConnectData *EVENTDATA_SYSTEM_GetConnectData(const EventDataSystem *system, unsigned index);
int EVENTDATA_SYSTEM_IsSpecialExitConnect(ConnectData *connect);
int EVENTDATA_SYSTEM_SetConnectExitLocation(const EventDataSystem *system, int *exitInfo, int connectIndex, int exitOffset);
void EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(ConnectData *connect, int exitInfo, int exitOffset);
u16 EVENTDATA_SYSTEM_GetConnectGridExitOffset(ConnectData *connect, int *pos);
u16 EVENTDATA_SYSTEM_GetConnectRailExitOffset(ConnectData *connect, RailLocation *location);
int EVENTDATA_SYSTEM_IsConnectExitDir(ConnectData *connect, int dir);
u8 EVENTDATA_SYSTEM_GetConnectExitType(ConnectData *connect);
int EVENTDATA_SYSTEM_IsConnectDisabled(ConnectData *connect);
void EVENTDATA_SYSTEM_SetConnectGridPos(EventDataSystem *system, u32 index, u16 gridX, u32 height, u16 gridZ);
u32 EVENTDATA_SYSTEM_GetNpcHeaders(EventDataSystem *system);
u16 EVENTDATA_SYSTEM_GetNpcCount(EventDataSystem *system);
void EVENTDATA_SYSTEM_SetNpcGridPos(EventDataSystem *system, u32 index, u16 dir, u16 gx, u32 y, u16 gz);
void EVENTDATA_SYSTEM_SetNpcObjCode(EventDataSystem *system, unsigned index, u16 objCode);
void EVENTDATA_SYSTEM_SetNpcEventId(EventDataSystem *system, unsigned index, u16 eventId);
u16 EVENTDATA_SYSTEM_DirToPosEventType(int mode);
struct EventRec *EVENTDATA_SYSTEM_SearchPosEvent(EventDataSystem *system, void *eventWork, int *pos, int mode);
struct EventRec *EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(EventDataSystem *system, void *eventWork, int *pos, int mode);
struct EventRec *EVENTDATA_SYSTEM_SearchAutoPosEvent(EventDataSystem *system, void *eventWork, int *pos);
struct EventRec *EVENTDATA_SYSTEM_SearchRailPosEvent(EventDataSystem *system, void *eventWork, RailLocation *location);
u16 EVENTDATA_SYSTEM_GetPosEventScriptId(EventDataSystem *system, void *eventWork, int *pos, int mode);
u16 EVENTDATA_SYSTEM_GetAutoPosEventScriptId(EventDataSystem *system, void *eventWork, int *pos);
u16 EVENTDATA_SYSTEM_GetRailPosEventScriptId(EventDataSystem *system, void *eventWork, RailLocation *location);
u16 EVENTDATA_SYSTEM_SearchBgEventScriptId(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing);
u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing);
u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing);
void EVENTDATA_SYSTEM_GetConnectCenterPosThunk(const ConnectData *connect, VecFx32 *pos);
void EVENTDATA_SYSTEM_GetPosEventCenterPosThunk(const struct EventRec *event, int *pos);
void EVENTDATA_SYSTEM_SetBgEventGridPos(const EventDataSystem *system, u32 index, u32 gridX, u32 height, u16 gridZ);
u16 EVENTDATA_SYSTEM_CalcExitOffset(int exitInfo, int playerDir, int isRail, int flipMode, u16 arrivalSize);
u16 EVENTDATA_SYSTEM_CalcConnectGridExitOffset(ConnectData *connect, int *pos);
u16 EVENTDATA_SYSTEM_CalcConnectRailExitOffset(ConnectData *connect, RailLocation *location);
int EVENTDATA_SYSTEM_ConnectExitDirToDir(ConnectData *connect);
void EVENTDATA_SYSTEM_GetConnectExitGridPos(ConnectData *connect, int exitOffset, int *pos);
void EVENTDATA_SYSTEM_GetConnectCenterPos(const ConnectData *connect, VecFx32 *pos);
int EVENTDATA_SYSTEM_IsConnectGridHit(const ConnectData *connect, const int *pos);
void EVENTDATA_SYSTEM_GetConnectExitRailLocation(const ConnectData *connect, int exitOffset, RailLocation *location);
int EVENTDATA_SYSTEM_IsConnectRailHit(ConnectData *connect, RailLocation *location);
int EVENTDATA_SYSTEM_IsBgEventGridHit(BgEventData *bg, const VecFx32 *pos);
int EVENTDATA_SYSTEM_IsBgEventRailHit(BgEventData *bg, const RailLocation *location);
void EVENTDATA_SYSTEM_GetPosEventCenterPos(const struct EventRec *event, int *pos);
int EVENTDATA_SYSTEM_IsPosEventGridHit(struct EventRec *event, int *pos);
int EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight(struct EventRec *event, int *pos);
int EVENTDATA_SYSTEM_IsPosEventRailHit(struct EventRec *event, RailLocation *location);
extern char d_0217299C[];

EventDataSystem *EVENTDATA_SYSTEM_Create(int heapId)
{
    EventDataSystem *system = GFL_HEAP_Alloc(heapId, 0xAA8, 1, d_0217299C, 0xAF);
    system->eventArc = ARC_TOOL_CreateHandle(0x7D, heapId);
    system->encountArc = ARC_TOOL_CreateHandle(0x7E, heapId);
    system->auxArc = ARC_TOOL_CreateHandle(0x39, heapId);
    return system;
}

void EVENTDATA_SYSTEM_Delete(EventDataSystem *system)
{
    ARC_TOOL_DeleteHandle((void *)system->eventArc);
    ARC_TOOL_DeleteHandle((void *)system->encountArc);
    ARC_TOOL_DeleteHandle((void *)system->auxArc);
    GFL_HEAP_Free(system);
}

void EVENTDATA_SYSTEM_Clear(EventDataSystem *system) { EVENTDATA_SYSTEM_ClearEventTables(system); (system->specialScripts)=(char *)system+0x2328; system->encountLoaded=0; system->encountFlag=0; }

void EVENTDATA_SYSTEM_Load(EventDataSystem *system, u16 zoneId, u8 encountParam)
{
    EVENTDATA_SYSTEM_Clear(system);
    EVENTDATA_SYSTEM_LoadEventData(system, zoneId, encountParam);
    EVENTDATA_SYSTEM_LoadEncountData(system, zoneId, encountParam);
}

/*
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into EVENTDATA_SYSTEM_ReadEventFile, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/EVENTDATA_SYSTEM_LoadEventData.c \
 *       --func EVENTDATA_SYSTEM_LoadEventData --addr 0x0216242C --region ov010 --cc dsi/1.1p1 --thumb
 */
void EVENTDATA_SYSTEM_LoadEventData(EventDataSystem *system, u16 zoneId, u8 unused)
{
    system->zoneId = zoneId;
    EVENTDATA_SYSTEM_ReadEventFile(system, zoneId);
}

void EVENTDATA_SYSTEM_LoadEncountData(EventDataSystem *system, int zoneId, int encountParam)
{
    FIELD_ENCOUNT_ST_LoadEncountData((struct EncountData *)system->encountHead, (int)system->encountArc, zoneId, encountParam);
    system->encountLoaded = 1;
}

/*
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/EVENTDATA_SYSTEM_GetSpecialScriptData.c \
 *       --func EVENTDATA_SYSTEM_GetSpecialScriptData --addr 0x02162450 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 EVENTDATA_SYSTEM_GetSpecialScriptData(EventDataSystem *system) { return (u32)system->specialScripts; }

/*
 * Unlabelled thumb leaf (ldr r0,[r0,0x34]; bx lr), the sole blocker of
 * ov021 FIELDMAP_UpdateZoneChange.
 * Addresses are Black-image addresses.
 */
/*
 * Unlabelled thumb leaf (ldr r0,[r0,#0x34]; bx lr), the sole blocker of
 * ov021 FIELDMAP_UpdateZoneChange.
 * Addresses are Black-image addresses.
 */
u32 EVENTDATA_SYSTEM_IsEncountDataLoaded(EventDataSystem *system)
{
    return system->encountLoaded;
}

/*
 * Unlabelled leaf: when idx is below the halfword count at +0x16, marks the
 * first two halfwords of the 0x14-byte record idx in the table at +0x24 as
 * 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
void EVENTDATA_SYSTEM_DisableConnect(EventDataSystem *system, u16 index)
{
    ConnectData *connect = system->connects;

    if (system->connectCount > index) {
        connect[index].zoneId = 0xFFFF;
        connect[index].exitId = 0xFFFF;
    }
}

int EVENTDATA_SYSTEM_CheckAutoPosEvent(EventDataSystem *system, int *pos)
{
    struct EventRec *event = system->posEvents;
    u16 count;
    u16 i;
    if (event) {
        count = system->posCount;
        for (i = 0; i < count; i++, event++) {
            if (EVENTDATA_SYSTEM_IsPosEventGridHit(event, pos) && event->checkType == 6) return 1;
        }
    }
    return 0;
}

/*
 * The file is read
 * into o->fileSize, then the header is parsed: o->specialScripts is the end of the data, and four sections follow the
 * four count bytes. Each section is its own block with a u8 count local, written in one uniform shape:
 * store the count, store the table pointer d + off, then add count * record size to off. The first
 * pointer is d + 0 (folded), the last section has no step. With this shape the zero offset, the 0x14
 * constant (r7) and h/d (r3/r2) get the original's registers.
 */
void EVENTDATA_SYSTEM_ReadEventFile(EventDataSystem *system, int zoneId)
{
    int fileId;
    unsigned fileSize;
    unsigned tableBase;
    unsigned offset;
    const EventFileData *fileData;

    fileId = ZONEDATA_GetEventDataId(zoneId);
    fileSize = ARC_TOOL_GetHandleMemberSize(system->eventArc, fileId);
    ARC_TOOL_ReadHandleMemberRange(system->eventArc, fileId, 0, fileSize, &system->fileSize);
    offset = 0;
    fileData = &system->fileData;
    tableBase = (unsigned)fileData + 4;
    system->specialScripts = (char *)fileData + system->fileSize;
    {
        u8 count = fileData->counts[0];
        system->bgCount = count;
        system->bgEvents = (BgEventData *)(tableBase + offset);
        offset += count * 0x14;
    }
    {
        u8 count = fileData->counts[1];
        system->npcCount = count;
        system->npcHeaders = (MmdlHeader *)(tableBase + offset);
        offset += count * 0x24;
    }
    {
        u8 count = fileData->counts[2];
        system->connectCount = count;
        system->connects = (ConnectData *)(tableBase + offset);
        offset += count * 0x14;
    }
    {
        u8 count = fileData->counts[3];
        system->posCount = count;
        system->posEvents = (struct EventRec *)(tableBase + offset);
    }
    system->loadedBgCount = system->bgCount;
    system->loadedNpcCount = system->npcCount;
    system->loadedConnectCount = system->connectCount;
    system->loadedPosCount = system->posCount;
}

void EVENTDATA_SYSTEM_ClearEventTables(EventDataSystem *system)
{
    system->loadedBgCount = 0;
    system->loadedNpcCount = 0;
    system->loadedConnectCount = 0;
    system->loadedPosCount = 0;
    system->bgCount = 0;
    system->npcCount = 0;
    system->connectCount = 0;
    system->posCount = 0;
    system->bgEvents = 0;
    system->npcHeaders = 0;
    system->connects = 0;
    system->posEvents = 0;
    MI_CpuFill8((char *)system + 0x128, 0, 0x880);
}

/*
 * Addresses are Black-image addresses.
 */
u32 EVENTDATA_SYSTEM_GetEncountData(u32 systemAddr)
{
    return systemAddr + 0x38;
}

/*
 * Unlabelled leaf getter: the halfword at +0x16.  Blocker of ov061
 * FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers.
 */
u16 EVENTDATA_SYSTEM_GetConnectCount(EventDataSystem *system)
{
    return system->connectCount;
}

/*
 * note: same shape as EVENTDATA_SYSTEM_SearchConnectIdByRailLocation with the callee EVENTDATA_SYSTEM_IsConnectGridHit.
 */
int EVENTDATA_SYSTEM_SearchConnectIdByGridPos(EventDataSystem *system, const int *pos)
{
    int i;
    ConnectData *connect;
    i = 0;
    connect = system->connects;
    for (; i < system->connectCount; i++, connect++) {
        if (EVENTDATA_SYSTEM_IsConnectGridHit(connect, pos)) return i;
    }
    return 0xffff;
}

int EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(EventDataSystem *system, RailLocation *location)
{
    int i;
    ConnectData *connect;
    i = 0;
    connect = system->connects;
    for (; i < system->connectCount; i++, connect++) {
        if (EVENTDATA_SYSTEM_IsConnectRailHit(connect, location)) return i;
    }
    return 0xffff;
}

ConnectData *EVENTDATA_SYSTEM_GetConnectData(const EventDataSystem *system, unsigned index)
{
    ConnectData *connect = system->connects;
    if (!connect) return 0;
    if (index >= system->connectCount) return 0;
    return connect + index;
}

/*
 * Unlabelled leaf, callee of ov020 EVENT_MAPCHANGE_CreateExitWarpEvent.
 */
int EVENTDATA_SYSTEM_IsSpecialExitConnect(ConnectData *connect)
{
    if (connect->exitId == 0x100) {
        return 1;
    }
    return 0;
}

/*
 * extent: 150-byte function followed by two alignment bytes at 02162692.
 * lever: read-only const source parameter schedules the final signed-id
 * truncation after the argument loads; exact callee widths keep B on r1.
 * interface: callee argument id is s16 as caller's explicit asrs shows;
 * k stays full-width because the original forwards it without truncation.
 */
int EVENTDATA_SYSTEM_SetConnectExitLocation(const EventDataSystem *system, int *exitInfo, int connectIndex, int exitOffset)
{
    ConnectData *connect;
    VecFx32 gridPos;
    RailLocation railPos;
    connect = EVENTDATA_SYSTEM_GetConnectData(system, connectIndex);
    if (connect == 0) return 0;
    ZONEDATA_InitLocation((int)exitInfo);
    if (connect->exitId == 0x100) *exitInfo = 3;
    else *exitInfo = 2;
    if (connect->posType == 0) {
        EVENTDATA_SYSTEM_GetConnectExitGridPos(connect, exitOffset, (int *)(&gridPos));
        ZONEDATA_SetExitLocation(exitInfo, system->zoneId, connectIndex, connect->exitDir, exitOffset, gridPos.x, gridPos.y, gridPos.z);
    } else {
        EVENTDATA_SYSTEM_GetConnectExitRailLocation(connect, exitOffset, &railPos);
        ZONEDATA_SetExitRailLocation(exitInfo, system->zoneId, connectIndex, connect->exitDir, exitOffset, railPos.railIndex, railPos.lineGrid, railPos.widthGrid);
    }
    return 1;
}

void EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(ConnectData *connect, int exitInfo, int exitOffset)
{
    ZONEDATA_SetExitLocationIdOnly(exitInfo, connect->zoneId, connect->exitId, exitOffset);
}

/*
 * Unlabelled leaf, blocker of ov021 FIELD_EVENT_CHECK_StartConnectEvent: compiler tail call (ldr r3,=; bx r3) of
 * EVENTDATA_SYSTEM_CalcConnectGridExitOffset; not a linker veneer.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u16 EVENTDATA_SYSTEM_GetConnectGridExitOffset(ConnectData *connect, int *pos)
{
    return EVENTDATA_SYSTEM_CalcConnectGridExitOffset(connect, pos);
}

/*
 * Unlabelled tail-call wrapper over EVENTDATA_SYSTEM_CalcConnectRailExitOffset (a pool word plus bx r3,
 * no prologue); witness for ov021 FIELD_EVENT_CHECK_StartRailConnectEvent.
 */
u16 EVENTDATA_SYSTEM_GetConnectRailExitOffset(ConnectData *connect, RailLocation *location)
{
    return EVENTDATA_SYSTEM_CalcConnectRailExitOffset(connect, location);
}

/*
 * Recursive MATCH unblocker: ABS32 target of FIELD_EVENT_CHECK_IsConnectExitDir (ov021) +0004.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 */
int EVENTDATA_SYSTEM_IsConnectExitDir(ConnectData *connect, int dir)
{
    if ((dir == 0 && connect->exitDir == 2) ||
        (dir == 1 && connect->exitDir == 1) ||
        (dir == 2 && connect->exitDir == 4) ||
        (dir == 3 && connect->exitDir == 3))
        return 1;
    return 0;
}

/*
 * Reads the byte field at +0x5.
 *
 * Addresses are Black-image addresses.
 */
u8 EVENTDATA_SYSTEM_GetConnectExitType(ConnectData *connect)
{
    return connect->exitType;
}

/*
 * Unlabelled leaf (a .word run in the ov010 listing): true when either of
 * the first two halfwords is 0xFFFF.  Callee of ov021 FIELD_EVENT_CHECK_CheckRailConnect.
 * Addresses are Black-image addresses.
 */
int EVENTDATA_SYSTEM_IsConnectDisabled(ConnectData *connect)
{
    if (connect->zoneId == 0xFFFF || connect->exitId == 0xFFFF)
        return 1;
    return 0;
}

void EVENTDATA_SYSTEM_SetConnectGridPos(EventDataSystem *system, u32 index, u16 gridX, u32 height, u16 gridZ)
{
    ConnectData *connect;
    if (system->connectCount >= index && system->connects != 0) {
        connect = &system->connects[index];
        if (connect->posType == 0) {
            ConnectGridArea *grid = &connect->area.grid;
            grid->x = (gridX << 4) + 8;
            grid->y = height << 4;
            grid->z = (gridZ << 4) + 8;
        }
    }
}

/*
 * Reads the word field at +0x20.
 *
 * Addresses are Black-image addresses.
 */
u32 EVENTDATA_SYSTEM_GetNpcHeaders(EventDataSystem *system)
{
    return (u32)system->npcHeaders;
}

/*
 * Reads the halfword field at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u16 EVENTDATA_SYSTEM_GetNpcCount(EventDataSystem *system)
{
    return system->npcCount;
}

/*
 * Unlabelled leaf: when idx is below the halfword count at +0x14 and the
 * 0x24-byte record idx in the table at +0x20 has a zero word at +0x18, fills
 * the record: halfword at +0xC, then a sub-record at +0x1C (halfword, halfword,
 * word). The last two arguments are stack arguments (word, halfword).
 *
 * The guard reads o->npcHeaders[idx].posType and the body takes
 * &o->npcHeaders[idx] again. Taking the pointer once before the guard gives the
 * table load before the 0x24 constant (7 bytes off).
 *
 * Addresses are Black-image addresses.
 */
void EVENTDATA_SYSTEM_SetNpcGridPos(EventDataSystem *system, u32 index, u16 dir, u16 gx, u32 y, u16 gz)
{
    if (index < system->npcCount) {
        if (system->npcHeaders[index].posType == 0) {
            MmdlHeader *header = &system->npcHeaders[index];
            MmdlHeaderGridPos *pos = (MmdlHeaderGridPos *)header->pos;
            header->dirHeader = dir;
            pos->gridX = gx;
            pos->posY = y;
            pos->gridZ = gz;
        }
    }
}

void EVENTDATA_SYSTEM_SetNpcObjCode(EventDataSystem *system, unsigned index, u16 objCode)
{
    if (index < system->npcCount)
        system->npcHeaders[index].objCode = objCode;
}

void EVENTDATA_SYSTEM_SetNpcEventId(EventDataSystem *system, unsigned index, u16 eventId)
{
    if (index < system->npcCount)
        system->npcHeaders[index].eventId = eventId;
}

u16 EVENTDATA_SYSTEM_DirToPosEventType(int mode) {
    switch(mode) { case 0: return 1; case 1: return 2; case 2: return 3; case 3: return 4; default: return 0; }
}

struct EventRec *EVENTDATA_SYSTEM_SearchPosEvent(EventDataSystem *system, void *eventWork, int *pos, int mode)
{
    struct EventRec *event = system->posEvents;
    u16 workValue;
    u16 checkType;
    u16 i;
    u16 count;
    if (event != 0) {
        checkType = EVENTDATA_SYSTEM_DirToPosEventType(mode);
        i = 0;
        count = system->posCount;
        for (; i < count; i++, event++) {
            if (EVENTDATA_SYSTEM_IsPosEventGridHit(event, pos) != 0 && event->checkType == checkType) {
                if (event->workId == 0)
                    return event;
                workValue = *((u16 *)ZONEDATA_GetEventWorkAddress((u32)eventWork, event->workId));
                if (workValue == event->workValue)
                    return event;
            }
        }
    }
    return 0;
}

struct EventRec *EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(EventDataSystem *system, void *eventWork, int *pos, int mode)
{
    struct EventRec *event = system->posEvents;
    u16 workValue;
    u16 checkType;
    u16 i;
    u16 count;
    if (event != 0) {
        checkType = EVENTDATA_SYSTEM_DirToPosEventType(mode);
        i = 0;
        count = system->posCount;
        for (; i < count; i++, event++) {
            if (EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight(event, pos) != 0 && event->checkType == checkType) {
                if (event->workId == 0)
                    return event;
                workValue = *((u16 *)ZONEDATA_GetEventWorkAddress((u32)eventWork, event->workId));
                if (workValue == event->workValue)
                    return event;
            }
        }
    }
    return 0;
}

struct EventRec *EVENTDATA_SYSTEM_SearchAutoPosEvent(EventDataSystem *system, void *eventWork, int *pos)
{
    struct EventRec *event = system->posEvents;
    u16 i;
    u16 count;
    u16 workValue;
    if (event != 0) {
        count = system->posCount;
        for (i = 0; i < count; i++, event++) {
            if (EVENTDATA_SYSTEM_IsPosEventGridHit(event, pos) != 0 && event->checkType == 6) {
                if (event->workId == 0)
                    return event;
                workValue = *((u16 *)ZONEDATA_GetEventWorkAddress((u32)eventWork, event->workId));
                if (workValue == event->workValue)
                    return event;
            }
        }
    }
    return 0;
}

struct EventRec *EVENTDATA_SYSTEM_SearchRailPosEvent(EventDataSystem *system, void *eventWork, RailLocation *location)
{
    struct EventRec *event = system->posEvents;
    u16 i;
    u16 count;
    u16 workValue;
    if (event != 0) {
        count = system->posCount;
        for (i = 0; i < count; i++, event++) {
            if (EVENTDATA_SYSTEM_IsPosEventRailHit(event, location) != 0) {
                workValue = *((u16 *)ZONEDATA_GetEventWorkAddress((u32)eventWork, event->workId));
                if (workValue == event->workValue)
                    return event;
            }
        }
    }
    return 0;
}

u16 EVENTDATA_SYSTEM_GetPosEventScriptId(EventDataSystem *system, void *eventWork, int *pos, int mode) { u16 *event=(u16 *)EVENTDATA_SYSTEM_SearchPosEvent(system,eventWork,pos,mode); if(event) return *event; return 0xffff; }

u16 EVENTDATA_SYSTEM_GetAutoPosEventScriptId(EventDataSystem *system, void *eventWork, int *pos) { u16 *event=(u16 *)EVENTDATA_SYSTEM_SearchAutoPosEvent(system,eventWork,pos); if(event) return *event; return 0xffff; }

u16 EVENTDATA_SYSTEM_GetRailPosEventScriptId(EventDataSystem *system, void *eventWork, RailLocation *location)
{
    u16 *event = (u16 *)EVENTDATA_SYSTEM_SearchRailPosEvent(system, eventWork, location);
    if (event != 0) return *event;
    return 0xffff;
}

/*
 * Finds the trigger that fires at a place: walks the 0x14-byte entries,
 * tests position (mode 0) or map cell (mode 1), then filters by entry
 * kind against the facing/type argument. Answers the entry id or 0xFFFF.
 *
 * Levers: one guarded body (single 0xFFFF
 * exit), the count held in a u32 local (a u16 local is re-read from its
 * spill slot before the guard), and case 5 as `type == 2 || type == 3`,
 * which 1.1p1 folds to a loop-hoisted `(u16)(type + 0xFFFE) <= 1`
 * (`(u16)(type - 2) <= 1` gives `subs 2` instead).
 */
u16 EVENTDATA_SYSTEM_SearchBgEventScriptId(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing)
{
    BgEventData *bgEvent;
    u16 i;
    u32 count;

    bgEvent = system->bgEvents;
    if (bgEvent != 0) {
    count = system->bgCount;
    for (i = 0; i < count; i++, bgEvent++) {
        if (bgEvent->posType == 0) {
            if (!EVENTDATA_SYSTEM_IsBgEventGridHit(bgEvent, pos))
                continue;
        } else {
            if (!EVENTDATA_SYSTEM_IsBgEventRailHit(bgEvent, pos))
                continue;
        }
        if (bgEvent->type == 2) {
            if (ZONEDATA_CheckEventFlag(eventFlags, HIDDEN_ITEM_GetFlag(bgEvent->scriptId)) == 0)
                return bgEvent->scriptId;
            continue;
        }
        switch (bgEvent->dir) {
        case 0:
            if (facing == 0)
                return bgEvent->scriptId;
            break;
        case 1:
            if (facing == 3)
                return bgEvent->scriptId;
            break;
        case 2:
            if (facing == 2)
                return bgEvent->scriptId;
            break;
        case 3:
            if (facing == 1)
                return bgEvent->scriptId;
            break;
        case 4:
            return bgEvent->scriptId;
        case 5:
            if (facing == 2 || facing == 3)
                return bgEvent->scriptId;
            break;
        case 6:
            if (facing <= 1)
                return bgEvent->scriptId;
            break;
        }
    }
    }
    return 0xFFFF;
}

/*
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to EVENTDATA_SYSTEM_SearchBgEventScriptId.  Callee of ov021 FIELD_EVENT_CHECK_CheckGridEvents.
 *
 * Addresses are Black-image addresses.
 */
u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing)
{
    return EVENTDATA_SYSTEM_SearchBgEventScriptId(system, eventFlags, pos, facing);
}

/*
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to EVENTDATA_SYSTEM_SearchBgEventScriptId.  Callee of ov021 FIELD_EVENT_CHECK_CheckRailEvents.
 *
 * Addresses are Black-image addresses.
 */
u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing)
{
    return EVENTDATA_SYSTEM_SearchBgEventScriptId(system, eventFlags, pos, facing);
}

/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * EVENTDATA_SYSTEM_GetConnectCenterPos.  Blocker of ov061 FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers.
 */
void EVENTDATA_SYSTEM_GetConnectCenterPosThunk(const ConnectData *connect, VecFx32 *pos)
{
    EVENTDATA_SYSTEM_GetConnectCenterPos(connect, pos);
}

/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * EVENTDATA_SYSTEM_GetPosEventCenterPos.  Blocker of ov021 SCRCMD_WarpToPositionEvent.
 */
void EVENTDATA_SYSTEM_GetPosEventCenterPosThunk(const struct EventRec *event, int *pos)
{
    EVENTDATA_SYSTEM_GetPosEventCenterPos(event, pos);
}

static inline void setBgEventGridPos(BgEventData *bgEvent, u32 gridX, u32 height, u16 gridZ)
{
    s32 *words = (s32 *)((u8 *)bgEvent + 8);
    bgEvent->pos.word[0] = gridX;
    words[1] = gridZ;
    words[2] = height << 4;
}

/*
 * extent: 46 code bytes followed by two zero alignment bytes.
 * lever: inline setter takes the whole BgEventData and all three position inputs;
 * its own word pointer preserves the parent base and explicit +8 copy.
 * domain: unsigned index comparison and modular word address arithmetic.
 */
void EVENTDATA_SYSTEM_SetBgEventGridPos(const EventDataSystem *system, u32 index, u32 gridX, u32 height, u16 gridZ)
{
    BgEventData *bgEvent;
    if (system->bgCount >= index && system->bgEvents != 0) {
        bgEvent = (BgEventData *)((u32)system->bgEvents + index * 20u);
        if (bgEvent->posType == 0) {
            setBgEventGridPos(bgEvent, gridX, height, gridZ);
        }
    }
}

/*
 * The branch-to-branch stubs are the tail `a = hw + (a - h)` written out in each arm
 * (cross-jumped later). `long w = n` keeps the final `a >= n` reload from the stack slot;
 * `hw` is unsigned (lsrs). The function has a 2-byte trailing pad.
 */
u16 EVENTDATA_SYSTEM_CalcExitOffset(int exitInfo, int playerDir, int isRail, int flipMode, u16 arrivalSize)
{
    int size, offset, exitDir;
    unsigned halfSize, halfArrival;
    int sizeDiff;
    long arrivalWidth;
    if (exitInfo == 0)
        return 0;
    size = (exitInfo & 0xf0) >> 4;
    offset = exitInfo & 0xf;
    exitDir = (exitInfo & 0xf00) >> 8;
    if ((exitDir == 0 && playerDir == 3) || (exitDir == 1 && playerDir == 2) || (exitDir == 3 && playerDir == 0) || (exitDir == 2 && playerDir == 1))
        offset = (size - 1) - offset;
    if (isRail != 0) {
        switch (flipMode) {
        case 0:
            if ((unsigned)(exitDir - 2) <= 1)
                offset = (size - 1) - offset;
            break;
        case 1:
            if ((unsigned)exitDir <= 1)
                offset = (size - 1) - offset;
            break;
        case 2:
            offset = (size - 1) - offset;
            break;
        }
    }
    arrivalWidth = arrivalSize;
    halfSize = (unsigned)size / 2;
    sizeDiff = arrivalWidth - size;
    halfArrival = (unsigned)arrivalWidth / 2;
    if (sizeDiff != 0) {
        if (sizeDiff % 2 != 0) {
            if (arrivalWidth % 2 != 0) {
                if (offset < halfSize) {
                    halfSize = halfSize - 1;
                    offset = halfArrival + (offset - halfSize);
                } else {
                    offset = halfArrival + (offset - halfSize);
                }
            } else {
                if (offset <= halfSize) {
                    offset = (halfArrival - 1) + (offset - halfSize);
                    goto clamp;
                } else {
                    offset = halfArrival + (offset - halfSize);
                }
            }
        } else {
            offset = halfArrival + (offset - halfSize);
        }
    }
clamp:
    if (offset < 0)
        offset = 0;
    else if (offset >= arrivalSize)
        offset = arrivalWidth - 1;
    return offset;
}

u16 EVENTDATA_SYSTEM_CalcConnectGridExitOffset(ConnectData *connect, int *pos)
{
    ConnectGridArea *grid;
    int dir = EVENTDATA_SYSTEM_ConnectExitDirToDir(connect);
    grid = &connect->area.grid;
    if (grid->sizeX > 1)
        return (grid->sizeX << 4) | (((pos[0] >> 12) - grid->x) / 16) | (dir << 8);
    if (grid->sizeZ > 1)
        return (grid->sizeZ << 4) | (((pos[2] >> 12) - grid->z) / 16) | (dir << 8);
    return (dir << 8) | 0x10;
}

u16 EVENTDATA_SYSTEM_CalcConnectRailExitOffset(ConnectData *connect, RailLocation *location)
{
    ConnectRailArea *rail = &connect->area.rail;
    int flipLine = 0;
    int flipWidth = 0;
    int dir = EVENTDATA_SYSTEM_ConnectExitDirToDir(connect);
    int gridOffset;
    switch (rail->flipMode) {
    case 0:
        flipLine = 1;
        break;
    case 1:
        flipWidth = 1;
        break;
    case 2:
        flipLine = 1;
        flipWidth = 1;
        break;
    case 3:
        break;
    }
    if (rail->widthSize > 1) {
        gridOffset = location->widthGrid - rail->widthGrid;
        if (flipWidth != 0)
            gridOffset = rail->widthSize - 1 - gridOffset;
        return (rail->widthSize << 4) | gridOffset | (dir << 8);
    }
    if (rail->lineSize > 1) {
        gridOffset = location->lineGrid - rail->lineGrid;
        if (flipLine != 0)
            gridOffset = rail->lineSize - 1 - gridOffset;
        return (rail->lineSize << 4) | gridOffset | (dir << 8);
    }
    return 0x10 | (dir << 8);
}

/*
 * lever: case 0 falls through into default at the final shared return.
 */
int EVENTDATA_SYSTEM_ConnectExitDirToDir(ConnectData *connect)
{
    switch (connect->exitDir) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    case 0:
    default: return 1;
    }
}

void EVENTDATA_SYSTEM_GetConnectExitGridPos(ConnectData *connect, int exitOffset, int *pos)
{
    ConnectGridArea *grid = &connect->area.grid;
    int dir = EVENTDATA_SYSTEM_ConnectExitDirToDir(connect);
    pos[0] = connect->area.grid.x << 12;
    pos[1] = grid->y << 12;
    pos[2] = grid->z << 12;
    if (grid->sizeX > 1) {
        pos[0] += EVENTDATA_SYSTEM_CalcExitOffset(exitOffset, dir, 0, 0, grid->sizeX) << 16;
    } else if (grid->sizeZ > 1) {
        pos[2] += EVENTDATA_SYSTEM_CalcExitOffset(exitOffset, dir, 0, 0, grid->sizeZ) << 16;
    }
}

/*
 * Unlabelled leaf (push {r3, r4} with no lr), reached through the ov010
 * tail-call thunk EVENTDATA_SYSTEM_GetConnectCenterPosThunk.  Blocker of ov061 FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers.
 * The const on both pointers keeps the first ldrsh ahead of the base
 * copy; the lsrs needs the u32 casts.
 */
void EVENTDATA_SYSTEM_GetConnectCenterPos(const ConnectData *connect, VecFx32 *pos)
{
    const ConnectGridArea *grid = &connect->area.grid;
    pos->x = grid->x << 12;
    pos->y = grid->y << 12;
    pos->z = grid->z << 12;
    if (grid->sizeX > 1) {
        pos->x += ((u32)grid->sizeX >> 1) << 16;
    } else if (grid->sizeZ > 1) {
        pos->z += ((u32)grid->sizeZ >> 1) << 16;
    }
}

/*
 * following: two-byte alignment padding at 02162D8E.
 * lever: assign the Sub_02162C54 pointer before the position loads; signed x0 has
 * the field's s16 width.
 */
int EVENTDATA_SYSTEM_IsConnectGridHit(const ConnectData *connect, const int *pos)
{
    const ConnectGridArea *grid;
    s16 areaX;
    int gridZ;
    int gridY;
    int gridX;
    if ((int)(connect->posType == 1)) return 0;
    grid = &connect->area.grid;
    gridX = pos[0] >> 12;
    gridY = pos[1] >> 12;
    gridZ = pos[2] >> 12;
    areaX = connect->area.grid.x;
    if (areaX <= gridX && areaX + (grid->sizeX - 1) * 16 >= gridX
        && grid->y - 2 <= gridY && grid->y + 2 >= gridY
        && grid->z <= gridZ && grid->z + (grid->sizeZ - 1) * 16 >= gridZ)
        return 1;
    return 0;
}

/*
 * lever: const source pointer schedules fa between the signed load and output store.
 * following: two-byte alignment padding at 0x02162DFE.
 */
void EVENTDATA_SYSTEM_GetConnectExitRailLocation(const ConnectData *connect, int exitOffset, RailLocation *location)
{
    const ConnectRailArea *rail = &connect->area.rail;
    int dir = EVENTDATA_SYSTEM_ConnectExitDirToDir((ConnectData *)connect);
    u16 flipMode;
    location->railIndex = connect->area.rail.railIndex;
    location->type = 1;
    location->key = ZONEDATA_DirToRailKey(dir);
    location->widthGrid = rail->widthGrid;
    flipMode = rail->flipMode;
    location->lineGrid = rail->lineGrid;
    if (rail->widthSize > 1) {
        location->widthGrid = location->widthGrid + (s16)EVENTDATA_SYSTEM_CalcExitOffset(exitOffset, dir, 1, flipMode, rail->widthSize);
    } else if (rail->lineSize > 1) {
        location->lineGrid = location->lineGrid + EVENTDATA_SYSTEM_CalcExitOffset(exitOffset, dir, 1, flipMode, rail->lineSize);
    }
}

int EVENTDATA_SYSTEM_IsConnectRailHit(ConnectData *connect, RailLocation *location)
{
    ConnectRailArea *rail;
    if (connect->posType == 0)
        return 0;
    rail = &connect->area.rail;
    if (rail->railIndex == location->railIndex && rail->lineGrid <= location->lineGrid && rail->lineGrid + rail->lineSize > location->lineGrid
        && rail->widthGrid <= location->widthGrid && rail->widthGrid + rail->widthSize > location->widthGrid)
        return 1;
    return 0;
}

/*
 * Position trigger test: an entry of mode 0 matches when the grid cell of
 * pos equals (x, z) and its height is within 2 of the entry's.
 */
int EVENTDATA_SYSTEM_IsBgEventGridHit(BgEventData *bg, const VecFx32 *pos)
{
    s32 gx;
    s32 gy;
    s32 gz;
    BgEventGridPos *grid;
    if (bg->posType == 1)
        return 0;
    grid = &bg->pos.grid;
    gz = (pos->z >> 4) / 4096;
    gy = pos->y >> 12;
    gx = (pos->x >> 4) / 4096;
    if (grid->x == gx && grid->z == gz && grid->y - 2 <= gy && grid->y + 2 > gy)
        return 1;
    return 0;
}

/*
 * Map-cell trigger test: an entry of mode 1 matches the three location
 * halfwords of p.
 */
int EVENTDATA_SYSTEM_IsBgEventRailHit(BgEventData *bg, const RailLocation *location)
{
    BgEventRailPos *rail;
    if (bg->posType == 0)
        return 0;
    rail = &bg->pos.rail;
    if (rail->railIndex == location->railIndex && rail->lineGrid == location->lineGrid && rail->widthGrid == location->widthGrid)
        return 1;
    return 0;
}

/*
 * lever: const source pointer hoists the last halfword load before the output store.
 */
void EVENTDATA_SYSTEM_GetPosEventCenterPos(const struct EventRec *event, int *pos)
{
    const u16 *areaWords = (const u16 *)event->area;
    int y, x, z;
    z = FX_Div(areaWords[3] << 16, 0x2000);
    z = ((unsigned)areaWords[1] << 16) + z;
    y = ((const s16 *)areaWords)[4] << 12;
    x = FX_Div(areaWords[2] << 16, 0x2000);
    pos[2] = z;
    pos[0] = ((unsigned)event->area[0] << 16) + x;
    pos[1] = y;
}

int EVENTDATA_SYSTEM_IsPosEventGridHit(struct EventRec *event, int *pos)
{
    u16 *areaWords;
    int x, y, z;

    if (event->posType == 1) {
        return 0;
    }
    areaWords = (u16 *)((u8 *)event + 10);
    x = (pos[0] >> 4) / 0x1000;
    z = (pos[2] >> 4) / 0x1000;
    y = pos[1] >> 12;
    if (event->area[0] <= x && event->area[0] + areaWords[2] > x
        && areaWords[1] <= z && areaWords[1] + areaWords[3] > z
        && ((s16 *)areaWords)[4] - 2 <= y && ((s16 *)areaWords)[4] + 2 > y) {
        return 1;
    }
    return 0;
}

int EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight(struct EventRec *event, int *pos)
{
    u16 *areaWords;
    int x, z;

    if (event->posType == 1) {
        return 0;
    }
    areaWords = (u16 *)((u8 *)event + 10);
    x = (pos[0] >> 4) / 0x1000;
    z = (pos[2] >> 4) / 0x1000;
    if (event->area[0] <= x && event->area[0] + areaWords[2] > x
        && areaWords[1] <= z && areaWords[1] + areaWords[3] > z) {
        return 1;
    }
    return 0;
}

int EVENTDATA_SYSTEM_IsPosEventRailHit(struct EventRec *event, RailLocation *location)
{
    u16 *areaWords;

    if (event->posType == 0) {
        return 0;
    }
    areaWords = (u16 *)((u8 *)event + 10);
    if (event->area[0] == location->railIndex && areaWords[1] <= location->lineGrid && areaWords[1] + areaWords[3] > location->lineGrid
        && ((s16 *)areaWords)[2] <= location->widthGrid && ((s16 *)areaWords)[2] + areaWords[4] > location->widthGrid) {
        return 1;
    }
    return 0;
}
