/*
 * file:     eventdata_system.c
 * unit:     yes
 * function: func_0216237C, func_021623BC, func_021623DC, func_02162408, func_0216242C, func_02162438, func_02162450, func_02162458, func_0216245C, func_02162478, func_021624B0, func_02162530, func_0216255C, func_02162560, func_02162564, func_02162598, func_021625CC, func_021625E8, func_021625FC, func_02162694, func_021626A8, func_021626B0, func_021626B8, func_021626E8, func_021626EC, func_02162708, func_02162740, func_02162744, func_02162748, func_02162774, func_02162788, func_0216279C, func_021627C8, func_0216282C, func_02162890, func_021628E4, func_02162928, func_02162940, func_02162958, func_02162970, func_02162A54, func_02162A5C, func_02162A64, func_02162A6C, func_02162A74, func_02162AA4, func_02162B68, func_02162BCC, func_02162C54, func_02162C84, func_02162CE8, func_02162D2C, func_02162D90, func_02162E00, func_02162E48, func_02162E9C, func_02162ECC, func_02162F0C, func_02162F74, func_02162FC8
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
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_0217299C     0x0217299C  data  ov010  a1
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0215E2B8  0x0215E2B8  thumb  ov010
 *   func_02013ECC  0x02013ECC  thumb
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_020140F8 0x020140F8 thumb
 *   func_02014110 0x02014110 thumb
 *   func_02014134 0x02014134 thumb
 *   func_0201416C  0x0201416C  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_02164708  0x02164708  thumb  ov010
 *   func_020142E8  0x020142E8  thumb
 *   func_0201441C 0x0201441C thumb
 *   func_0207C768 0x0207C768 arm
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
    u16 checkType;   /* 0x06: 1..4 facing (func_0216279C), 6 automatic */
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
    u8 exitDir;         /* 0x04: 0..4, see func_02162C54 */
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
    u8 encountHead[7];            /* 0x38: encounter data, read by func_0215E2B8 */
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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(void *arc);
extern int func_020307B0();
extern int func_0215E2B8(struct EncountData *encount, int a, int b, int n);
extern unsigned func_02013ECC(unsigned);
extern unsigned func_020493D4(struct ArcFile *, unsigned);
extern void func_0204944C(struct ArcFile *, unsigned, unsigned, unsigned, void *);
extern void func_020140F8(int p0);
extern void func_02014110(int *, u16, s16, u16, int, unsigned, unsigned, unsigned);
extern void func_02014134(int *, u16, s16, u16, int, u16, u16, s16);
extern int func_0201416C(int a0, int a1, int a2, int a3);
extern u32 func_020143CC(u32 a, u32 b);
extern u16 func_02164708(u16 id);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u8 func_0201441C(int m);
extern u32 func_0207C768(u32 a, u32 b);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
EventDataSystem *func_0216237C(int heapId);
void func_021623BC(EventDataSystem *system);
void func_021623DC(EventDataSystem *system);
void func_02162408(EventDataSystem *system, u16 zoneId, u8 encountParam);
void func_0216242C(EventDataSystem *system, u16 zoneId, u8 unused);
void func_02162438(EventDataSystem *system, int zoneId, int encountParam);
u32 func_02162450(EventDataSystem *system);
u32 func_02162458(EventDataSystem *system);
void func_0216245C(EventDataSystem *system, u16 index);
int func_02162478(EventDataSystem *system, int *pos);
void func_021624B0(EventDataSystem *system, int zoneId);
void func_02162530(EventDataSystem *system);
u32 func_0216255C(u32 systemAddr);
u16 func_02162560(EventDataSystem *system);
int func_02162564(EventDataSystem *system, const int *pos);
int func_02162598(EventDataSystem *system, RailLocation *location);
ConnectData *func_021625CC(const EventDataSystem *system, unsigned index);
int func_021625E8(ConnectData *connect);
int func_021625FC(const EventDataSystem *system, int *exitInfo, int connectIndex, int exitOffset);
void func_02162694(ConnectData *connect, int exitInfo, int exitOffset);
u16 func_021626A8(ConnectData *connect, int *pos);
u16 func_021626B0(ConnectData *connect, RailLocation *location);
int func_021626B8(ConnectData *connect, int dir);
u8 func_021626E8(ConnectData *connect);
int func_021626EC(ConnectData *connect);
void func_02162708(EventDataSystem *system, u32 index, u16 gridX, u32 height, u16 gridZ);
u32 func_02162740(EventDataSystem *system);
u16 func_02162744(EventDataSystem *system);
void func_02162748(EventDataSystem *system, u32 index, u16 dir, u16 gx, u32 y, u16 gz);
void func_02162774(EventDataSystem *system, unsigned index, u16 objCode);
void func_02162788(EventDataSystem *system, unsigned index, u16 eventId);
u16 func_0216279C(int mode);
struct EventRec *func_021627C8(EventDataSystem *system, void *eventWork, int *pos, int mode);
struct EventRec *func_0216282C(EventDataSystem *system, void *eventWork, int *pos, int mode);
struct EventRec *func_02162890(EventDataSystem *system, void *eventWork, int *pos);
struct EventRec *func_021628E4(EventDataSystem *system, void *eventWork, RailLocation *location);
u16 func_02162928(EventDataSystem *system, void *eventWork, int *pos, int mode);
u16 func_02162940(EventDataSystem *system, void *eventWork, int *pos);
u16 func_02162958(EventDataSystem *system, void *eventWork, RailLocation *location);
u16 func_02162970(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing);
u16 func_02162A54(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing);
u16 func_02162A5C(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing);
void func_02162A64(const ConnectData *connect, VecFx32 *pos);
void func_02162A6C(const struct EventRec *event, int *pos);
void func_02162A74(const EventDataSystem *system, u32 index, u32 gridX, u32 height, u16 gridZ);
u16 func_02162AA4(int exitInfo, int playerDir, int isRail, int flipMode, u16 arrivalSize);
u16 func_02162B68(ConnectData *connect, int *pos);
u16 func_02162BCC(ConnectData *connect, RailLocation *location);
int func_02162C54(ConnectData *connect);
void func_02162C84(ConnectData *connect, int exitOffset, int *pos);
void func_02162CE8(const ConnectData *connect, VecFx32 *pos);
int func_02162D2C(const ConnectData *connect, const int *pos);
void func_02162D90(const ConnectData *connect, int exitOffset, RailLocation *location);
int func_02162E00(ConnectData *connect, RailLocation *location);
int func_02162E48(BgEventData *bg, const VecFx32 *pos);
int func_02162E9C(BgEventData *bg, const RailLocation *location);
void func_02162ECC(const struct EventRec *event, int *pos);
int func_02162F0C(struct EventRec *event, int *pos);
int func_02162F74(struct EventRec *event, int *pos);
int func_02162FC8(struct EventRec *event, RailLocation *location);
extern char d_0217299C[];

EventDataSystem *func_0216237C(int heapId)
{
    EventDataSystem *system = func_02030734(heapId, 0xAA8, 1, d_0217299C, 0xAF);
    system->eventArc = func_020490F4(0x7D, heapId);
    system->encountArc = func_020490F4(0x7E, heapId);
    system->auxArc = func_020490F4(0x39, heapId);
    return system;
}

void func_021623BC(EventDataSystem *system)
{
    func_02049238((void *)system->eventArc);
    func_02049238((void *)system->encountArc);
    func_02049238((void *)system->auxArc);
    func_020307B0(system);
}

void func_021623DC(EventDataSystem *system) { func_02162530(system); (system->specialScripts)=(char *)system+0x2328; system->encountLoaded=0; system->encountFlag=0; }

void func_02162408(EventDataSystem *system, u16 zoneId, u8 encountParam)
{
    func_021623DC(system);
    func_0216242C(system, zoneId, encountParam);
    func_02162438(system, zoneId, encountParam);
}

/*
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_021624B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216242C.c \
 *       --func func_0216242C --addr 0x0216242C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216242C(EventDataSystem *system, u16 zoneId, u8 unused)
{
    system->zoneId = zoneId;
    func_021624B0(system, zoneId);
}

void func_02162438(EventDataSystem *system, int zoneId, int encountParam)
{
    func_0215E2B8((struct EncountData *)system->encountHead, (int)system->encountArc, zoneId, encountParam);
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
 *   python tools/match.py one --src src/matched/func_02162450.c \
 *       --func func_02162450 --addr 0x02162450 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02162450(EventDataSystem *system) { return (u32)system->specialScripts; }

/*
 * Unlabelled thumb leaf (ldr r0,[r0,0x34]; bx lr), the sole blocker of
 * ov021 func_021892CC.
 * Addresses are Black-image addresses.
 */
/*
 * Unlabelled thumb leaf (ldr r0,[r0,#0x34]; bx lr), the sole blocker of
 * ov021 func_021892CC.
 * Addresses are Black-image addresses.
 */
u32 func_02162458(EventDataSystem *system)
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
void func_0216245C(EventDataSystem *system, u16 index)
{
    ConnectData *connect = system->connects;

    if (system->connectCount > index) {
        connect[index].zoneId = 0xFFFF;
        connect[index].exitId = 0xFFFF;
    }
}

int func_02162478(EventDataSystem *system, int *pos)
{
    struct EventRec *event = system->posEvents;
    u16 count;
    u16 i;
    if (event) {
        count = system->posCount;
        for (i = 0; i < count; i++, event++) {
            if (func_02162F0C(event, pos) && event->checkType == 6) return 1;
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
void func_021624B0(EventDataSystem *system, int zoneId)
{
    int fileId;
    unsigned fileSize;
    unsigned tableBase;
    unsigned offset;
    const EventFileData *fileData;

    fileId = func_02013ECC(zoneId);
    fileSize = func_020493D4(system->eventArc, fileId);
    func_0204944C(system->eventArc, fileId, 0, fileSize, &system->fileSize);
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

void func_02162530(EventDataSystem *system)
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
u32 func_0216255C(u32 systemAddr)
{
    return systemAddr + 0x38;
}

/*
 * Unlabelled leaf getter: the halfword at +0x16.  Blocker of ov061
 * func_021F388C.
 */
u16 func_02162560(EventDataSystem *system)
{
    return system->connectCount;
}

/*
 * note: same shape as func_02162598 with the callee func_02162D2C.
 */
int func_02162564(EventDataSystem *system, const int *pos)
{
    int i;
    ConnectData *connect;
    i = 0;
    connect = system->connects;
    for (; i < system->connectCount; i++, connect++) {
        if (func_02162D2C(connect, pos)) return i;
    }
    return 0xffff;
}

int func_02162598(EventDataSystem *system, RailLocation *location)
{
    int i;
    ConnectData *connect;
    i = 0;
    connect = system->connects;
    for (; i < system->connectCount; i++, connect++) {
        if (func_02162E00(connect, location)) return i;
    }
    return 0xffff;
}

ConnectData *func_021625CC(const EventDataSystem *system, unsigned index)
{
    ConnectData *connect = system->connects;
    if (!connect) return 0;
    if (index >= system->connectCount) return 0;
    return connect + index;
}

/*
 * Unlabelled leaf, callee of ov020 func_02185360.
 */
int func_021625E8(ConnectData *connect)
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
int func_021625FC(const EventDataSystem *system, int *exitInfo, int connectIndex, int exitOffset)
{
    ConnectData *connect;
    VecFx32 gridPos;
    RailLocation railPos;
    connect = func_021625CC(system, connectIndex);
    if (connect == 0) return 0;
    func_020140F8((int)exitInfo);
    if (connect->exitId == 0x100) *exitInfo = 3;
    else *exitInfo = 2;
    if (connect->posType == 0) {
        func_02162C84(connect, exitOffset, (int *)(&gridPos));
        func_02014110(exitInfo, system->zoneId, connectIndex, connect->exitDir, exitOffset, gridPos.x, gridPos.y, gridPos.z);
    } else {
        func_02162D90(connect, exitOffset, &railPos);
        func_02014134(exitInfo, system->zoneId, connectIndex, connect->exitDir, exitOffset, railPos.railIndex, railPos.lineGrid, railPos.widthGrid);
    }
    return 1;
}

void func_02162694(ConnectData *connect, int exitInfo, int exitOffset)
{
    func_0201416C(exitInfo, connect->zoneId, connect->exitId, exitOffset);
}

/*
 * Unlabelled leaf, blocker of ov021 func_0218AD80: compiler tail call (ldr r3,=; bx r3) of
 * func_02162B68; not a linker veneer.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u16 func_021626A8(ConnectData *connect, int *pos)
{
    return func_02162B68(connect, pos);
}

/*
 * Unlabelled tail-call wrapper over func_02162BCC (a pool word plus bx r3,
 * no prologue); witness for ov021 func_0218B2E8.
 */
u16 func_021626B0(ConnectData *connect, RailLocation *location)
{
    return func_02162BCC(connect, location);
}

/*
 * Recursive MATCH unblocker: ABS32 target of func_0218AECC (ov021) +0004.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 */
int func_021626B8(ConnectData *connect, int dir)
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
u8 func_021626E8(ConnectData *connect)
{
    return connect->exitType;
}

/*
 * Unlabelled leaf (a .word run in the ov010 listing): true when either of
 * the first two halfwords is 0xFFFF.  Callee of ov021 func_0218B0CC.
 * Addresses are Black-image addresses.
 */
int func_021626EC(ConnectData *connect)
{
    if (connect->zoneId == 0xFFFF || connect->exitId == 0xFFFF)
        return 1;
    return 0;
}

void func_02162708(EventDataSystem *system, u32 index, u16 gridX, u32 height, u16 gridZ)
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
u32 func_02162740(EventDataSystem *system)
{
    return (u32)system->npcHeaders;
}

/*
 * Reads the halfword field at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162744(EventDataSystem *system)
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
void func_02162748(EventDataSystem *system, u32 index, u16 dir, u16 gx, u32 y, u16 gz)
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

void func_02162774(EventDataSystem *system, unsigned index, u16 objCode)
{
    if (index < system->npcCount)
        system->npcHeaders[index].objCode = objCode;
}

void func_02162788(EventDataSystem *system, unsigned index, u16 eventId)
{
    if (index < system->npcCount)
        system->npcHeaders[index].eventId = eventId;
}

u16 func_0216279C(int mode) {
    switch(mode) { case 0: return 1; case 1: return 2; case 2: return 3; case 3: return 4; default: return 0; }
}

struct EventRec *func_021627C8(EventDataSystem *system, void *eventWork, int *pos, int mode)
{
    struct EventRec *event = system->posEvents;
    u16 workValue;
    u16 checkType;
    u16 i;
    u16 count;
    if (event != 0) {
        checkType = func_0216279C(mode);
        i = 0;
        count = system->posCount;
        for (; i < count; i++, event++) {
            if (func_02162F0C(event, pos) != 0 && event->checkType == checkType) {
                if (event->workId == 0)
                    return event;
                workValue = *((u16 *)func_020143CC((u32)eventWork, event->workId));
                if (workValue == event->workValue)
                    return event;
            }
        }
    }
    return 0;
}

struct EventRec *func_0216282C(EventDataSystem *system, void *eventWork, int *pos, int mode)
{
    struct EventRec *event = system->posEvents;
    u16 workValue;
    u16 checkType;
    u16 i;
    u16 count;
    if (event != 0) {
        checkType = func_0216279C(mode);
        i = 0;
        count = system->posCount;
        for (; i < count; i++, event++) {
            if (func_02162F74(event, pos) != 0 && event->checkType == checkType) {
                if (event->workId == 0)
                    return event;
                workValue = *((u16 *)func_020143CC((u32)eventWork, event->workId));
                if (workValue == event->workValue)
                    return event;
            }
        }
    }
    return 0;
}

struct EventRec *func_02162890(EventDataSystem *system, void *eventWork, int *pos)
{
    struct EventRec *event = system->posEvents;
    u16 i;
    u16 count;
    u16 workValue;
    if (event != 0) {
        count = system->posCount;
        for (i = 0; i < count; i++, event++) {
            if (func_02162F0C(event, pos) != 0 && event->checkType == 6) {
                if (event->workId == 0)
                    return event;
                workValue = *((u16 *)func_020143CC((u32)eventWork, event->workId));
                if (workValue == event->workValue)
                    return event;
            }
        }
    }
    return 0;
}

struct EventRec *func_021628E4(EventDataSystem *system, void *eventWork, RailLocation *location)
{
    struct EventRec *event = system->posEvents;
    u16 i;
    u16 count;
    u16 workValue;
    if (event != 0) {
        count = system->posCount;
        for (i = 0; i < count; i++, event++) {
            if (func_02162FC8(event, location) != 0) {
                workValue = *((u16 *)func_020143CC((u32)eventWork, event->workId));
                if (workValue == event->workValue)
                    return event;
            }
        }
    }
    return 0;
}

u16 func_02162928(EventDataSystem *system, void *eventWork, int *pos, int mode) { u16 *event=(u16 *)func_021627C8(system,eventWork,pos,mode); if(event) return *event; return 0xffff; }

u16 func_02162940(EventDataSystem *system, void *eventWork, int *pos) { u16 *event=(u16 *)func_02162890(system,eventWork,pos); if(event) return *event; return 0xffff; }

u16 func_02162958(EventDataSystem *system, void *eventWork, RailLocation *location)
{
    u16 *event = (u16 *)func_021628E4(system, eventWork, location);
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
u16 func_02162970(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing)
{
    BgEventData *bgEvent;
    u16 i;
    u32 count;

    bgEvent = system->bgEvents;
    if (bgEvent != 0) {
    count = system->bgCount;
    for (i = 0; i < count; i++, bgEvent++) {
        if (bgEvent->posType == 0) {
            if (!func_02162E48(bgEvent, pos))
                continue;
        } else {
            if (!func_02162E9C(bgEvent, pos))
                continue;
        }
        if (bgEvent->type == 2) {
            if (func_020142E8(eventFlags, func_02164708(bgEvent->scriptId)) == 0)
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
 * arguments to func_02162970.  Callee of ov021 func_02189BD0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162A54(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing)
{
    return func_02162970(system, eventFlags, pos, facing);
}

/*
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to func_02162970.  Callee of ov021 func_0218A278.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162A5C(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing)
{
    return func_02162970(system, eventFlags, pos, facing);
}

/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162CE8.  Blocker of ov061 func_021F388C.
 */
void func_02162A64(const ConnectData *connect, VecFx32 *pos)
{
    func_02162CE8(connect, pos);
}

/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162ECC.  Blocker of ov021 func_021AFDAC.
 */
void func_02162A6C(const struct EventRec *event, int *pos)
{
    func_02162ECC(event, pos);
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
void func_02162A74(const EventDataSystem *system, u32 index, u32 gridX, u32 height, u16 gridZ)
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
u16 func_02162AA4(int exitInfo, int playerDir, int isRail, int flipMode, u16 arrivalSize)
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

u16 func_02162B68(ConnectData *connect, int *pos)
{
    ConnectGridArea *grid;
    int dir = func_02162C54(connect);
    grid = &connect->area.grid;
    if (grid->sizeX > 1)
        return (grid->sizeX << 4) | (((pos[0] >> 12) - grid->x) / 16) | (dir << 8);
    if (grid->sizeZ > 1)
        return (grid->sizeZ << 4) | (((pos[2] >> 12) - grid->z) / 16) | (dir << 8);
    return (dir << 8) | 0x10;
}

u16 func_02162BCC(ConnectData *connect, RailLocation *location)
{
    ConnectRailArea *rail = &connect->area.rail;
    int flipLine = 0;
    int flipWidth = 0;
    int dir = func_02162C54(connect);
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
int func_02162C54(ConnectData *connect)
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

void func_02162C84(ConnectData *connect, int exitOffset, int *pos)
{
    ConnectGridArea *grid = &connect->area.grid;
    int dir = func_02162C54(connect);
    pos[0] = connect->area.grid.x << 12;
    pos[1] = grid->y << 12;
    pos[2] = grid->z << 12;
    if (grid->sizeX > 1) {
        pos[0] += func_02162AA4(exitOffset, dir, 0, 0, grid->sizeX) << 16;
    } else if (grid->sizeZ > 1) {
        pos[2] += func_02162AA4(exitOffset, dir, 0, 0, grid->sizeZ) << 16;
    }
}

/*
 * Unlabelled leaf (push {r3, r4} with no lr), reached through the ov010
 * tail-call thunk func_02162A64.  Blocker of ov061 func_021F388C.
 * The const on both pointers keeps the first ldrsh ahead of the base
 * copy; the lsrs needs the u32 casts.
 */
void func_02162CE8(const ConnectData *connect, VecFx32 *pos)
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
int func_02162D2C(const ConnectData *connect, const int *pos)
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
void func_02162D90(const ConnectData *connect, int exitOffset, RailLocation *location)
{
    const ConnectRailArea *rail = &connect->area.rail;
    int dir = func_02162C54((ConnectData *)connect);
    u16 flipMode;
    location->railIndex = connect->area.rail.railIndex;
    location->type = 1;
    location->key = func_0201441C(dir);
    location->widthGrid = rail->widthGrid;
    flipMode = rail->flipMode;
    location->lineGrid = rail->lineGrid;
    if (rail->widthSize > 1) {
        location->widthGrid = location->widthGrid + (s16)func_02162AA4(exitOffset, dir, 1, flipMode, rail->widthSize);
    } else if (rail->lineSize > 1) {
        location->lineGrid = location->lineGrid + func_02162AA4(exitOffset, dir, 1, flipMode, rail->lineSize);
    }
}

int func_02162E00(ConnectData *connect, RailLocation *location)
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
int func_02162E48(BgEventData *bg, const VecFx32 *pos)
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
int func_02162E9C(BgEventData *bg, const RailLocation *location)
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
void func_02162ECC(const struct EventRec *event, int *pos)
{
    const u16 *areaWords = (const u16 *)event->area;
    int y, x, z;
    z = func_0207C768(areaWords[3] << 16, 0x2000);
    z = ((unsigned)areaWords[1] << 16) + z;
    y = ((const s16 *)areaWords)[4] << 12;
    x = func_0207C768(areaWords[2] << 16, 0x2000);
    pos[2] = z;
    pos[0] = ((unsigned)event->area[0] << 16) + x;
    pos[1] = y;
}

int func_02162F0C(struct EventRec *event, int *pos)
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

int func_02162F74(struct EventRec *event, int *pos)
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

int func_02162FC8(struct EventRec *event, RailLocation *location)
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
