/*
 * file:     unit_021F39C0.c
 * unit:     yes
 * function: func_021F39C0, func_021F3A64, func_021F3AA4, func_021F3B10, func_021F3B20, func_021F3B48, func_021F3C2C, func_021F3CE4, func_021F3CF4, func_021F3D0C, func_021F3D90, func_021F3DBC, func_021F3DD4, func_021F3E84, func_021F3F20, func_021F3F30, func_021F3F9C, func_021F405C, func_021F40F4, func_021F4124, func_021F414C, func_021F4174, func_021F41F0, func_021F42AC, func_021F4318, func_021F4388, func_021F43D8, func_021F4430, func_021F4458, func_021F4474, func_021F4510, func_021F4530, func_021F4574, func_021F459C
 * address:  0x021F39C0
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021690B4  0x021690B4  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189A68  0x02189A68  thumb  ov021
 *   func_02189A38  0x02189A38  thumb  ov021
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021F4620     0x021F4620  data  ov055  a4
 *   d_021F4620_b   0x021F4620  data  ov055  a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216CF2C 0x0216CF2C thumb ov010
 *   d_021F45C0 0x021F45C0 data a4
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   d_021F45C8     0x021F45C8  data  ov055  a4
 *   func_0216D5B8 0x0216D5B8 thumb ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_0216DB4C 0x0216DB4C thumb ov010
 *   func_0216DC98 0x0216DC98 thumb ov010
 *   func_0216DAE0 0x0216DAE0 thumb ov010
 *   func_0216D5B4 0x0216D5B4 thumb ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_02045B38  0x02045B38  arm
 *   func_021F45A4 0x021F45A4 thumb ov055
 *   func_02045C04 0x02045C04 arm
 *   d_021F45E0 0x021F45E0 data a1
 *   d_021F45D0 0x021F45D0 data a1
 *   func_02191870  0x02191870  thumb  ov021
 *   func_0219196C  0x0219196C  thumb  ov021
 */
#include "../ov010/fldmmdl_types.h"
#include "../ov021/fieldmap_types.h"

/*
 * Crowd of passers-by that walk across the field map, with speech windows
 * popping up over them. Started from a script command (the sub process table
 * d_021F45F0 in ov055, see scrcmd_pokemon_fld.c); the field map keeps the work
 * in FieldMap.zoneEffectWork. The per-zone setup comes from archive 0xba.
 */

struct FieldSubproc;
struct FieldPlayer;
struct MsgData;
struct ArcFile;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

#define CROWD_PERSON_MAX 32
#define CROWD_AREA_MAX 2
#define CROWD_TIME_ZONE_MAX 6
#define CROWD_CHATTER_SLOT_MAX 16

/* Behaviour of one person (CrowdPerson.kind, index into the handler tables). */
enum {
    CROWD_KIND_SOLID = 0,        /* collides with other field models */
    CROWD_KIND_PLAYER_AWARE = 1  /* passes through them, reacts to the player */
};

/* CrowdPerson.state */
enum {
    CROWD_STATE_WAIT_STEP = 0,   /* wait for the walk command to end */
    CROWD_STATE_NEXT_STEP = 1,   /* take the next step or sidestep */
    CROWD_STATE_LEAVE = 2        /* walked its whole length, remove */
};

/* Event id of a person nobody can talk to. */
#define CROWD_EVENT_NONE 2000

/*
 * Rectangle the people of one area walk in, plus the way they walk. People
 * enter along one edge and leave on the opposite side.
 */
typedef struct CrowdArea {
    u16 zMin;                    /* 0x00 */
    u16 zMax;                    /* 0x02 */
    u16 xMin;                    /* 0x04 */
    u16 xMax;                    /* 0x06 */
    u16 dir;                     /* 0x08 walk direction: 0 up, 1 down, 2 left, 3 right */
    u16 length;                  /* 0x0A steps a person walks before leaving */
} CrowdArea;

/* Row of the model table (archive 0xba member 6): the event ids a model can get (16 bytes). */
typedef struct CrowdModelEntry {
    int objCode;                 /* 0x00 */
    u16 eventIds[6];             /* 0x04 */
} CrowdModelEntry;

/*
 * Per-zone setup (0x40 bytes). The first 0x32 bytes are one file of archive
 * 0xba, the rest is filled at load time.
 */
typedef struct CrowdConfig {
    s16 intervalByTimeZone[CROWD_TIME_ZONE_MAX];    /* 0x00 frames between spawns, also chatter interval bound */
    u8 areaCount;                                   /* 0x0C */
    u8 modelCount;                                  /* 0x0D */
    u16 modelCodes[4];                              /* 0x0E object codes a person can look like */
    u8 chatterMsgFirst;                             /* 0x16 first message id of the speech windows */
    u8 chatterMsgCount;                             /* 0x17 */
    u8 walkFrames;                                  /* 0x18 frames per step: 2, 4, 6, 8 or 16 */
    u8 pad19;                                       /* 0x19 */
    CrowdArea areas[CROWD_AREA_MAX];                /* 0x1A */
    s16 spawnCounter[CROWD_AREA_MAX];               /* 0x32 frames since the last spawn, per area */
    u8 pad36[2];                                    /* 0x36 */
    CrowdModelEntry *modelTable;                    /* 0x38 member 6 of the archive */
    u32 modelTableCount;                            /* 0x3C */
} CrowdConfig;

/* One walking person (0x18 bytes) and its field model. */
typedef struct CrowdPerson {
    u8 isActive;                 /* 0x00 */
    u8 state;                    /* 0x01 CROWD_STATE_* */
    u8 kind;                     /* 0x02 CROWD_KIND_* */
    u8 dir;                      /* 0x03 */
    u16 stepsLeft;               /* 0x04 */
    u16 eventId;                 /* 0x06 event the player starts by facing the person */
    u16 mmdlId;                  /* 0x08 object id of the field model */
    u16 walkCmdBase;             /* 0x0A walk command of direction 0 */
    Mmdl *mmdl;                  /* 0x0C */
    const CrowdArea *area;       /* 0x10 */
    u16 isSidestepping;          /* 0x14 */
    u16 sidestepDir;             /* 0x16 */
} CrowdPerson;

/* One speech window slot (8 bytes). */
typedef struct CrowdChatterSlot {
    u16 isOpen;                  /* 0x00 */
    u8 x;                        /* 0x02 window position in tiles */
    u8 y;                        /* 0x03 */
    u16 windowId;                /* 0x04 */
    s16 frames;                  /* 0x06 frames the window has been open */
} CrowdChatterSlot;

/* Speech windows (0x90 bytes). */
typedef struct CrowdChatter {
    s16 timer;                   /* 0x00 */
    s16 interval;                /* 0x02 frames until the next window opens */
    u32 nextSlot;                /* 0x04 */
    struct MsgData *msgData;     /* 0x08 */
    struct FieldMsgBg *msgBg;    /* 0x0C */
    CrowdChatterSlot slots[CROWD_CHATTER_SLOT_MAX]; /* 0x10 */
} CrowdChatter;

/* Work of the sub process (0x3D8 bytes), FieldMap.zoneEffectWork. */
typedef struct CrowdWork {
    struct FieldPlayer *player;  /* 0x000 */
    MmdlSys *mmdlSys;            /* 0x004 */
    CrowdPerson people[CROWD_PERSON_MAX]; /* 0x008 */
    CrowdConfig config;          /* 0x308 */
    CrowdChatter chatter;        /* 0x348 */
} CrowdWork;

extern struct FieldMsgBg *func_02188C54(FieldMap *fieldMap);
extern struct GameSystem *func_02188C80(FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern MmdlSys *func_02188C7C(FieldMap *fieldMap);
extern u16 func_02188C9C(FieldMap *fieldMap);
extern int func_021690B4(struct GameData *gameData);
extern u16 func_02188C84(FieldMap *fieldMap);
extern void func_02189A68(FieldMap *fieldMap, void *zoneEffectWork);
extern int func_02189A38(FieldMap *fieldMap);
extern int func_02189A2C(FieldMap *fieldMap);
extern int func_0216D83C(Mmdl *mmdl);
extern int func_0216D86C(Mmdl *mmdl);
extern u32 func_020056EC(u32);
extern Mmdl *func_0216CE60(MmdlSys *mmdlSys, const MmdlHeader *header, int zoneId);
extern void func_0216DAC8(Mmdl *mmdl, int flag);
extern int func_0216DCCC(Mmdl *mmdl, int flag);
extern void func_0216D8C0(Mmdl *mmdl, int *offset);
extern void func_0216CF2C(Mmdl *mmdl);
extern u16 func_0216D598(Mmdl *mmdl);
extern void func_0216E618(MmdlHeader *header, int x, int z, int y);
extern void func_0216E0AC(Mmdl *mmdl, MmdlHeader *header);
extern u32 func_0216D5B8(Mmdl *mmdl);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern u16 func_021642A4(int dir);
extern int func_021641E8(int dir);
extern int func_021641F8(int dir);
extern void func_0216D410(Mmdl *mmdl, u16 walkCmd);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern int func_0216DB4C(Mmdl *mmdl, int flag);
extern int func_0216DC98(Mmdl *mmdl, int flag);
extern void func_0216DAE0(Mmdl *mmdl, int flag);
extern void func_0216D5B4(Mmdl *mmdl, u16 eventId);
extern int func_0216D454();
extern Mmdl *func_021A3074(struct FieldPlayer *player);
extern int func_0216DD1C(MmdlSys *mmdlSys, Mmdl **out, u32 *iter);
extern int func_0216D55C(Mmdl *mmdl, int bit);
extern int func_0216DAB4(Mmdl *mmdl);
extern int func_0216D804(Mmdl *mmdl);
extern int func_0216D81C(Mmdl *mmdl);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021F45A4(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg);
extern u32 func_02045C04(struct MsgData *msgData);
extern void func_02191870(struct FieldMsgBg *msgBg, struct MsgData *msgData, u32 msgId, u32 windowId, u8 x, u8 y, u8 width, u8 height);
extern void func_0219196C(struct FieldMsgBg *msgBg, u32 windowId);
void func_021F39C0(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work);
void func_021F3A64(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work);
void func_021F3AA4(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work);
void func_021F3B10(CrowdWork *work);
CrowdPerson *func_021F3B20(CrowdWork *work);
const CrowdPerson *func_021F3B48(const CrowdWork *work, int x, int z, unsigned int dir, int unused, int *isOccupied);
void func_021F3C2C(CrowdPerson *person, MmdlSys *mmdlSys, int zoneId, const CrowdConfig *config, int index);
void func_021F3CE4(CrowdPerson *person);
void func_021F3CF4(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player);
void func_021F3D0C(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player, int kind, u16 gridX, u16 gridZ, u16 dir, u16 stepCount, const CrowdArea *area);
void func_021F3D90(CrowdPerson *person);
void func_021F3DBC(CrowdPerson *person);
void func_021F3DD4(CrowdPerson *person, Mmdl *blocker);
void func_021F3E84(CrowdConfig *config, int timeZone, int zoneId, u16 heapId);
void func_021F3F20(CrowdConfig *config);
void func_021F3F30(CrowdConfig *config, CrowdWork *work, int timeZone);
void func_021F3F9C(const CrowdWork *work, const CrowdConfig *config, const CrowdArea *area, CrowdPerson *person, u16 stagger);
void func_021F405C(CrowdConfig *config, CrowdWork *work, int timeZone);
u32 func_021F40F4(const CrowdConfig *config);
void func_021F4124(CrowdPerson *person);
void func_021F414C(CrowdPerson *person);
void func_021F4174(CrowdPerson *person, MmdlSys *mmdlSys);
void func_021F41F0(CrowdPerson *person, MmdlSys *mmdlSys, u32 player);
int func_021F42AC(CrowdPerson *person, MmdlSys *mmdlSys, Mmdl **blocker, u16 maxDist, u16 minDist);
int func_021F4318(const CrowdPerson *person, Mmdl *other, u16 maxDist, u16 minDist);
int func_021F4388(int ownX, int ownZ, int otherX, int otherZ, u16 maxDist, u16 minDist, u16 dir);
void func_021F43D8(CrowdChatter *chatter, struct FieldMsgBg *msgBg, const CrowdConfig *config, u32 timeZone, u16 heapId);
void func_021F4430(CrowdChatter *chatter);
void func_021F4458(CrowdChatter *chatter);
void func_021F4474(CrowdChatter *chatter, const CrowdConfig *config, FieldMap *fieldMap);
void func_021F4510(CrowdChatterSlot *slot, int index);
void func_021F4530(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg, struct MsgData *msgData, u32 msgFirst, u32 msgCount);
void func_021F4574(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg);
void func_021F459C(CrowdChatterSlot *slot);
/*
 * Template of the field model header, two symbols for the one object: the
 * store of the object code goes through the first, the model is created from
 * the second (one symbol for both gives a different literal pool).
 */
extern MmdlHeader d_021F4620;
extern MmdlHeader d_021F4620_b;
extern const u8 d_021F45E0[];
extern const u8 d_021F45D0[];

/* Start of the sub process: load the zone setup, create the people and the chatter. */
void func_021F39C0(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work)
{
    int i;
    u16 heapId;
    struct FieldMsgBg *msgBg;
    struct GameData *gameData;
    int zoneId;
    int timeZone;

    msgBg = func_02188C54(fieldMap);
    gameData = func_020120F4(func_02188C80(fieldMap));
    work->player = func_02188CB4(fieldMap);
    work->mmdlSys = func_02188C7C(fieldMap);
    zoneId = func_02188C9C(fieldMap);
    timeZone = func_021690B4(gameData);
    heapId = func_02188C84(fieldMap);
    func_021F3E84(&work->config, timeZone, zoneId, heapId);
    for (i = 0; i < CROWD_PERSON_MAX; i++)
        func_021F3C2C(&work->people[i], work->mmdlSys, zoneId, &work->config, i);
    func_021F405C(&work->config, work, timeZone);
    func_021F43D8(&work->chatter, msgBg, &work->config, timeZone, heapId);
    func_02189A68(fieldMap, work);
}

/* End of the sub process. */
void func_021F3A64(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work)
{
    int i;

    func_02189A68(fieldMap, 0);
    for (i = 0; i < CROWD_PERSON_MAX; i++)
        func_021F3CE4(&work->people[i]);
    func_021F3F20(&work->config);
    func_021F4430(&work->chatter);
    work->player = 0;
    work->mmdlSys = 0;
}

/* Per frame: spawn people, move them, run the speech windows. */
void func_021F3AA4(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work)
{
    int i;

    func_021F3F30(&work->config, work, func_02189A38(fieldMap));
    if (func_02189A2C(fieldMap)) {
        for (i = 0; i < CROWD_PERSON_MAX; i++)
            func_021F3D90(&work->people[i]);
    }
    for (i = 0; i < CROWD_PERSON_MAX; i++)
        func_021F3CF4(&work->people[i], work->mmdlSys, work->player);
    func_021F4474(&work->chatter, &work->config, fieldMap);
}

/* Draw hook of the sub process: close the speech windows. */
void func_021F3B10(CrowdWork *work)
{
    func_021F4458(&work->chatter);
}

/* The first person slot that is not in use, or 0. */
CrowdPerson *func_021F3B20(CrowdWork *work)
{
    int i;

    for (i = 0; i < CROWD_PERSON_MAX; i++) {
        if (work->people[i].isActive == 0) {
            return &work->people[i];
        }
    }
    return 0;
}

/*
 * Look for a player-aware person that stands on the spawn tile (x, z), which
 * sets *isOccupied, or on the line from it in walking direction dir; returns
 * that person.
 *
 * The switch lists case 3 before case 2: the original lays the dx = 1 arm
 * out ahead of the dx = -1 arm.
 */
const CrowdPerson *func_021F3B48(const CrowdWork *work, int x, int z, unsigned int dir, int unused, int *isOccupied)
{
    int dx;
    int dz;
    int i;
    s16 signX;
    s16 signZ;
    int personX;
    int personZ;

    switch (dir) {
    case 0:
        dx = 0;
        dz = -1;
        break;
    case 1:
        dx = 0;
        dz = 1;
        break;
    case 3:
        dx = 1;
        dz = 0;
        break;
    case 2:
        dx = -1;
        dz = 0;
        break;
    }
    *isOccupied = 0;
    for (i = 0; i < CROWD_PERSON_MAX; i++) {
        if (work->people[i].isActive != 0 && work->people[i].kind == CROWD_KIND_PLAYER_AWARE) {
            personX = func_0216D83C(work->people[i].mmdl);
            personZ = func_0216D86C(work->people[i].mmdl);
            signX = personX - x;
            signZ = personZ - z;
            if (signX != 0) {
                signX = signX / (signX < 0 ? -signX : signX);
            }
            if (signZ != 0) {
                signZ = signZ / (signZ < 0 ? -signZ : signZ);
            }
            if (signX == 0 && signZ == 0) {
                *isOccupied = 1;
                return &work->people[i];
            }
            if (signX == dx && signZ == dz) {
                return &work->people[i];
            }
        }
    }
    return 0;
}

/* Create the hidden field model of a person: random look, event and position jitter. */
void func_021F3C2C(CrowdPerson *person, MmdlSys *mmdlSys, int zoneId, const CrowdConfig *config, int index)
{
    u32 i;
    u32 rand;
    u16 objCode;

    i = 0;
    objCode = config->modelCodes[func_020056EC(0) % config->modelCount];
    d_021F4620.objCode = objCode;
    rand = func_020056EC(0);
    person->mmdlId = index + 0x30;
    for (i = 0; i < config->modelTableCount; i++) {
        if (objCode == config->modelTable[i].objCode) {
            person->eventId = config->modelTable[i].eventIds[rand % 6];
            break;
        }
    }
    person->mmdl = func_0216CE60(mmdlSys, &d_021F4620_b, zoneId);
    person->isActive = 0;
    person->state = 0;
    person->kind = 0;
    person->dir = 0;
    person->walkCmdBase = func_021F40F4(config);
    func_0216DAC8(person->mmdl, 1);
    func_0216DCCC(person->mmdl, 1);
    {
        int drawOffset[3] = {0, 0, 0};
        drawOffset[0] = func_020056EC(0x8000) - 0x4000;
        func_0216D8C0(person->mmdl, drawOffset);
    }
}

/* Delete the field model of a person. */
void func_021F3CE4(CrowdPerson *person) { func_0216CF2C(person->mmdl); person->mmdl=0; }

/* Per-kind update handlers, indexed by CrowdPerson.kind. */
extern void (*d_021F45C0[])(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player);

/* Run the update handler of an active person. */
void func_021F3CF4(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player) { if (person->isActive) d_021F45C0[person->kind](person, mmdlSys, player); }

/* Per-kind start handlers, indexed by CrowdPerson.kind. */
extern void (* const d_021F45C8[])(CrowdPerson *person);

/* Put a person on the map at the grid position, walking in direction dir. */
void func_021F3D0C(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player, int kind, u16 gridX, u16 gridZ, u16 dir, u16 stepCount, const CrowdArea *area)
{
    MmdlHeader header;

    person->isActive = 1;
    func_0216DAC8(person->mmdl, 0);
    header = d_021F4620;
    header.objCode = func_0216D598(person->mmdl);
    header.dirHeader = dir;
    header.objId = person->mmdlId;
    func_0216E618(&header, gridX, gridZ, 0);
    func_0216E0AC(person->mmdl, &header);
    person->kind = kind;
    person->dir = dir;
    person->state = 0;
    person->stepsLeft = stepCount;
    person->isSidestepping = 0;
    person->sidestepDir = 0;
    func_0216DCCC(person->mmdl, 1);
    person->area = area;
    d_021F45C8[kind](person);
}

/* While a game event runs, a player-aware person with no event of its own becomes a solid one. */
void func_021F3D90(CrowdPerson *person) { if (person->isActive==1 && person->kind==CROWD_KIND_PLAYER_AWARE && func_0216D5B8(person->mmdl)==CROWD_EVENT_NONE) { person->kind=CROWD_KIND_SOLID; func_021F4124(person); } }

/* Take a person off the map: inactive and hidden. */
void func_021F3DBC(CrowdPerson *person) { person->isActive=0; person->kind=0; person->dir=0; person->state=0; func_0216DAC8(person->mmdl,1); }

#pragma opt_lifetimes off

/*
 * Pick a new walking direction for a person whose way is blocked by another
 * field model, keep it inside the area and start the walk command.
 *
 * `#pragma opt_lifetimes off` is needed here: with it the function is exact.
 * Without it the registers of person and newDir are swapped (26 bytes).
 * Many source forms were tried, none changes that; see the register
 * allocator notes in the lane log.
 */
void func_021F3DD4(CrowdPerson *person, Mmdl *blocker)
{
    u32 newDir;
    u32 blockerDir;
    int posX;
    int nextZ;
    int posZ;
    const CrowdArea *area;
    blockerDir = func_0216D5F8(blocker);
    posX = func_0216D83C(person->mmdl);
    posZ = func_0216D86C(person->mmdl);
    if (person->isSidestepping != 0) {
        newDir = person->sidestepDir;
    } else {
        if (blockerDir == person->dir || person->dir == func_021642A4(blockerDir)) {
            if (func_020056EC(2) == 0) {
                newDir = (u16)(blockerDir + 2);
            } else {
                newDir = func_021642A4((u16)(blockerDir + 2));
            }
        } else {
            newDir = func_021642A4(blockerDir);
        }
    }
    posX = (s16)(posX + func_021641E8(newDir));
    nextZ = (s16)(posZ + func_021641F8(newDir));
    if (newDir <= 1) {
        area = person->area;
        if (nextZ < area->zMin || nextZ > area->zMax) {
            newDir = func_021642A4(newDir);
        }
    } else {
        area = person->area;
        if (posX < area->xMin || posX > area->xMax) {
            newDir = func_021642A4(newDir);
        }
    }
    func_0216D410(person->mmdl, (u16)(person->walkCmdBase + newDir));
    person->isSidestepping = 1;
    person->sidestepDir = newDir;
}
#pragma opt_lifetimes reset

/* Read the setup of the current zone from archive 0xba. */
void func_021F3E84(CrowdConfig *config, int timeZone, int zoneId, u16 heapId)
{
    struct ArcFile *arc;
    int *zoneTable;
    u32 count, i;
    u32 tempHeapId;
    int j;

    tempHeapId = (heapId & 0x7fff) | 0x8000;
    arc = func_020490F4(0xba, tempHeapId);
    zoneTable = func_02049250(arc, 5, (u16)tempHeapId);
    count = func_020493D4(arc, 5) >> 2;
    for (i = 0; i < count; i++) {
        if (zoneId == zoneTable[i])
            break;
    }
    func_0204944C(arc, i, 0, 0x32, config);
    func_020307B0(zoneTable);
    count = func_020493D4(arc, 6);
    config->modelTable = func_02049250(arc, 6, (u16)heapId);
    config->modelTableCount = count >> 4;
    func_02049238(arc);
    for (j = 0; j < CROWD_AREA_MAX; j++)
        config->spawnCounter[j] = 0;
}

/* Free the model table of the setup. */
void func_021F3F20(CrowdConfig *config) { func_020307B0(config->modelTable); config->modelTable=0; }

/* Per frame: count up the spawn timers and put a new person on the map when one runs out. */
void func_021F3F30(CrowdConfig *config, CrowdWork *work, int timeZone)
{
    int i;

    for (i = 0; i < config->areaCount; i++) {
        CrowdPerson *person;
        if (config->spawnCounter[i] >= config->intervalByTimeZone[timeZone]) {
            person = func_021F3B20(work);
            if (person) {
                func_021F3F9C(work, config, &config->areas[i], person, 0);
                config->spawnCounter[i] = 0;
            }
        } else {
            config->spawnCounter[i]++;
        }
    }
}

/*
 * Put a person on the entry edge of the area, stagger steps back along the
 * walking direction; skipped when the entry tile is occupied. One person in
 * ten (when none is ahead of it) is player-aware.
 *
 * Levers, each measured: func_021F3D0C's u16 parameters (its own file) put
 * y in r7 and spill x; the else arm's x is an if/else, not a ternary (the
 * shared truncation then stays ahead of the area loads); u8 kind moves
 * the stack parameter's load to the front of the prologue; const work and
 * area let the final call's field loads rise above the argument stores.
 */
void func_021F3F9C(const CrowdWork *work, const CrowdConfig *config, const CrowdArea *area, CrowdPerson *person, u16 stagger)
{
    int isOccupied;
    u16 gridX;
    u16 gridZ;
    u8 kind;
    u32 rand;
    u16 dir;

    kind = 0;
    rand = func_020056EC(0);
    dir = area->dir;
    if (dir <= 1) {
        gridX = area->xMin + rand % (area->xMax - area->xMin + 1);
        if (dir == 0)
            gridZ = area->zMin - stagger;
        else
            gridZ = area->zMin + stagger;
    } else {
        if (dir == 2)
            gridX = area->xMin - stagger;
        else
            gridX = area->xMin + stagger;
        gridZ = area->zMin + rand % (area->zMax - area->zMin + 1);
    }
    if (func_021F3B48(work, gridX, gridZ, dir, 1, &isOccupied) == 0) {
        if (rand % 10 == 0)
            kind = 1;
    }
    if (isOccupied == 0)
        func_021F3D0C(person, work->mmdlSys, work->player, kind, gridX, gridZ, area->dir, (u16)(area->length - stagger), area);
}

/* Fill the areas with people when the zone is entered: the number follows the spawn interval. */
void func_021F405C(CrowdConfig *config, CrowdWork *work, int timeZone)
{
    int i, j, count, offset;

    for (i = 0; i < config->areaCount; i++) {
        count = (config->areas[i].length * 6) / config->intervalByTimeZone[timeZone];
        offset = 0;
        for (j = 0; j < count; j++) {
            CrowdPerson *person = func_021F3B20(work);
            if (person) {
                func_021F3F9C(work, config, &config->areas[i], person, (u16)(offset / 6));
                offset += config->intervalByTimeZone[timeZone];
            }
        }
    }
}

/* Walk command of direction 0 for the step length of the setup. */
u32 func_021F40F4(const CrowdConfig *config)
{
    u32 walkFrames = config->walkFrames;
    if (walkFrames == 2)  return 0x14;
    if (walkFrames == 4)  return 0x10;
    if (walkFrames == 6)  return 0x4c;
    if (walkFrames == 8)  return 0xc;
    if (walkFrames == 16) return 8;
    return 0xc;
}

/* Start handler of the solid kind: collides with other field models, no event. */
void func_021F4124(CrowdPerson *person) { func_0216DB4C(person->mmdl,1); func_0216DC98(person->mmdl,1); func_0216DAE0(person->mmdl,0); func_0216D5B4(person->mmdl,CROWD_EVENT_NONE); }

/* Start handler of the player-aware kind: passes through other field models, no event. */
void func_021F414C(CrowdPerson *person) { func_0216DB4C(person->mmdl,1); func_0216DC98(person->mmdl,1); func_0216DAE0(person->mmdl,1); func_0216D5B4(person->mmdl,CROWD_EVENT_NONE); }

/* Update handler of the solid kind: walk on, sidestep a blocker, leave at the end. */
void func_021F4174(CrowdPerson *person, MmdlSys *mmdlSys)
{
    Mmdl *blocker;
    switch (person->state) {
    case CROWD_STATE_WAIT_STEP:
        if (func_0216D454(person->mmdl) == 0) {
            return;
        }
        person->state = person->state + 1;
    case CROWD_STATE_NEXT_STEP:
        if (person->stepsLeft == 0) {
            person->state = CROWD_STATE_LEAVE;
            return;
        }
        if (func_021F42AC(person, mmdlSys, &blocker, 2, 0)) {
            func_021F3DD4(person, blocker);
        } else {
            func_0216D410(person->mmdl, (u16)(person->walkCmdBase + person->dir));
            person->stepsLeft = person->stepsLeft - 1;
        }
        person->state = CROWD_STATE_WAIT_STEP;
        return;
    case CROWD_STATE_LEAVE:
        func_021F3DBC(person);
        return;
    }
}

/*
 * Update handler of the player-aware kind: like the solid one, but a player
 * right in front gets the person's own event (so it can be talked to).
 *
 * stand-in: player is a u32 parameter and is reused as the distance 1 of the
 * blocker search, as in the original; as a pointer the call gets a u16
 * truncation the original does not have.
 */
void func_021F41F0(CrowdPerson *person, MmdlSys *mmdlSys, u32 player)
{
    Mmdl *blocker;
    Mmdl *playerMmdl;
    switch (person->state) {
    case CROWD_STATE_WAIT_STEP:
        if (func_0216D454(person->mmdl) == 0) {
            return;
        }
        person->state = person->state + 1;
    case CROWD_STATE_NEXT_STEP:
        if (person->stepsLeft == 0) {
            person->state = CROWD_STATE_LEAVE;
            return;
        }
        playerMmdl = func_021A3074((struct FieldPlayer *)player);
        player = 1;
        if (func_021F4318(person, playerMmdl, 1, 1)) {
            func_0216D5B4(person->mmdl, person->eventId);
            return;
        }
        if (func_021F42AC(person, mmdlSys, &blocker, player, 0)) {
            func_021F3DD4(person, blocker);
            func_0216D5B4(person->mmdl, CROWD_EVENT_NONE);
            func_021F3D90(person);
        } else {
            func_0216D410(person->mmdl, (u16)(person->walkCmdBase + person->dir));
            person->stepsLeft = person->stepsLeft - 1;
            func_0216D5B4(person->mmdl, CROWD_EVENT_NONE);
        }
        person->state = CROWD_STATE_WAIT_STEP;
        return;
    case CROWD_STATE_LEAVE:
        func_021F3DBC(person);
        return;
    }
}

/*
 * Find another field model within minDist..maxDist tiles in front of the
 * person; *blocker gets it.
 *
 * maxDist and minDist are u16, as are func_021F4318's last two parameters (its
 * own file): with u32 the stack parameter's load (ldr r6, [sp, #0x20]) sinks to
 * the first call instead of leading the prologue.
 */
int func_021F42AC(CrowdPerson *person, MmdlSys *mmdlSys, Mmdl **blocker, u16 maxDist, u16 minDist)
{
    u32 iter = 0;
    Mmdl *other;
    while (func_0216DD1C(mmdlSys, &other, &iter) == 1) {
        if (person->mmdl != other && func_0216D55C(other, 0x80) == 0 &&
            func_0216DAB4(other) == 0 && func_021F4318(person, other, maxDist, minDist) != 0) {
            *blocker = other;
            return 1;
        }
    }
    return 0;
}

/* Whether a field model (at its current or its previous tile) is in front of the person. */
int func_021F4318(const CrowdPerson *person, Mmdl *other, u16 maxDist, u16 minDist)
{
    int otherX = func_0216D83C(other);
    int otherZ = func_0216D86C(other);
    int ownX = func_0216D83C(person->mmdl);
    int ownZ = func_0216D86C(person->mmdl);
    int prevX;
    int prevZ;

    if (func_021F4388(ownX, ownZ, otherX, otherZ, maxDist, minDist, person->dir)) {
        return 1;
    }
    prevX = func_0216D804(other);
    prevZ = func_0216D81C(other);
    return func_021F4388(ownX, ownZ, prevX, prevZ, maxDist, minDist, person->dir);
}

/* Whether the other tile is in the same lane, minDist..maxDist tiles ahead in direction dir. */
int func_021F4388(int ownX, int ownZ, int otherX, int otherZ, u16 maxDist, u16 minDist, u16 dir)
{
    int ahead, side;
    switch (dir) {
    case 0:
        ahead = ownZ - otherZ;
        side = ownX - otherX;
        break;
    case 1:
        ahead = otherZ - ownZ;
        side = ownX - otherX;
        break;
    case 2:
        ahead = ownX - otherX;
        side = ownZ - otherZ;
        break;
    case 3:
        ahead = otherX - ownX;
        side = ownZ - otherZ;
        break;
    }
    if (ahead <= maxDist && ahead >= minDist && side == 0) {
        return 1;
    }
    return 0;
}

/* Set up the speech windows: first interval, message data, slot table. */
void func_021F43D8(CrowdChatter *chatter, struct FieldMsgBg *msgBg, const CrowdConfig *config, u32 timeZone, u16 heapId)
{
    int i;
    u32 rand;
    s16 interval;

    i = 0;
    rand = func_020056EC(0);
    interval = config->intervalByTimeZone[timeZone];
    chatter->timer = i;
    chatter->interval = 0x10 + rand % interval;
    chatter->msgData = func_02045B38(0, 3, 0x9f, heapId);
    chatter->msgBg = msgBg;
    chatter->nextSlot = rand & 0xf;
    for (i = 0; i < CROWD_CHATTER_SLOT_MAX; i++) {
        func_021F4510(&chatter->slots[i], (u16)i);
    }
}

/* Close the windows and free the message data. */
void func_021F4430(CrowdChatter *chatter) { int i; for (i=0;i<CROWD_CHATTER_SLOT_MAX;i++) func_021F45A4(&chatter->slots[i],chatter->msgBg); chatter->msgBg=0; func_02045C04(chatter->msgData); chatter->msgData=0; }

/* Close all open windows. */
void func_021F4458(CrowdChatter *chatter) { int i; for (i=0;i<CROWD_CHATTER_SLOT_MAX;i++) func_021F45A4(&chatter->slots[i],chatter->msgBg); }

/* Per frame: open a window when the timer runs out (not during an event), age the open ones. */
void func_021F4474(CrowdChatter *chatter, const CrowdConfig *config, FieldMap *fieldMap)
{
    int i;
    u32 rand;
    int timeZone;

    i = 0;
    rand = func_020056EC(0);
    timeZone = func_02189A38(fieldMap);
    if (func_02189A2C(fieldMap) == 0) {
        chatter->timer = chatter->timer + 1;
        if (chatter->timer >= chatter->interval) {
            func_021F4530(&chatter->slots[chatter->nextSlot], chatter->msgBg, chatter->msgData,
                          config->chatterMsgFirst, config->chatterMsgCount);
            chatter->timer = i;
            chatter->nextSlot = (chatter->nextSlot + 1) & 0xf;
            chatter->interval = 0x10 + rand % config->intervalByTimeZone[timeZone];
        }
        i = 0;
        for (; i < CROWD_CHATTER_SLOT_MAX; i++) {
            func_021F4574(&chatter->slots[i], chatter->msgBg);
        }
    } else {
        for (i = 0; i < CROWD_CHATTER_SLOT_MAX; i++) {
            func_021F45A4(&chatter->slots[i], chatter->msgBg);
        }
    }
}

/* Set up a speech window slot: closed, at its fixed position. */
void func_021F4510(CrowdChatterSlot *slot, int index)
{
    slot->isOpen = 0;
    slot->x = d_021F45E0[index];
    slot->y = d_021F45D0[index];
    slot->windowId = index;
    slot->frames = 0;
}

/* Open the speech window of a slot with a random message. */
void func_021F4530(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg, struct MsgData *msgData, u32 msgFirst, u32 msgCount)
{
    u32 rand = func_020056EC(0);
    slot->isOpen = 1;
    slot->frames = 0;
    func_02191870(msgBg, msgData, msgFirst + rand % msgCount, slot->windowId, slot->x, slot->y, 8, 2);
}

/*
 * Age an open speech window; it closes after 16 frames.
 * Unlabelled leaf callee of func_021F4474.
 */
void func_021F4574(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg)
{
    if (slot->isOpen != 0) {
        s16 *frames = &slot->frames;
        *frames = *frames + 1;
        if (*frames >= 0x10) {
            func_0219196C(msgBg, slot->windowId);
            func_021F459C(slot);
        }
    }
}

/* Mark a speech window slot closed. */
void func_021F459C(CrowdChatterSlot *slot)
{
    slot->frames = 0;
    slot->isOpen = 0;
}
