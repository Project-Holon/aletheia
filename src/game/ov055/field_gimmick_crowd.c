/*
 * file:     field_gimmick_crowd.c
 * unit:     yes
 * function: CROWD_Init, CROWD_Exit, CROWD_Update, CROWD_DrawProc, CROWD_FindFreePerson, CROWD_FindPersonAtSpawn, CROWD_CreatePerson, CROWD_DeletePerson, CROWD_UpdatePerson, CROWD_StartPerson, CROWD_MakePersonSolid, CROWD_RemovePerson, CROWD_SidestepPerson, CROWD_LoadConfig, CROWD_FreeConfig, CROWD_UpdateSpawns, CROWD_SpawnPerson, CROWD_SpawnInitialPeople, CROWD_GetWalkCmdBase, CROWD_InitSolidPerson, CROWD_InitPlayerAwarePerson, CROWD_UpdateSolidPerson, CROWD_UpdatePlayerAwarePerson, CROWD_FindBlockingMmdl, CROWD_IsMmdlInFront, CROWD_IsTileInFront, CROWD_InitChatter, CROWD_ExitChatter, CROWD_CloseAllChatterSlots, CROWD_UpdateChatter, CROWD_InitChatterSlot, CROWD_OpenChatterSlot, CROWD_UpdateChatterSlot, CROWD_ClearChatterSlot, CROWD_CloseChatterSlot
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
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_CLOCK_GetTimeZone  0x021690B4  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_SetZoneEffectWork  0x02189A68  thumb  ov021
 *   FIELDMAP_GetTimeZone  0x02189A38  thumb  ov021
 *   FIELDMAP_IsEventActive  0x02189A2C  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   gCrowdMmdlHeader     0x021F4620  data  ov055  a4
 *   d_021F4620_b   0x021F4620  data  ov055  a4
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_SetMoveBitAttrEffectOff  0x0216DCCC  thumb  ov010
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_DeleteMmdl 0x0216CF2C thumb ov010
 *   gCrowdPersonUpdateFuncs 0x021F45C0 data a4
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   FLDMMDL_ChangeHeader  0x0216E0AC  thumb  ov010
 *   gCrowdPersonInitFuncs     0x021F45C8  data  ov055  a4
 *   FLDMMDL_GetEventId 0x0216D5B8 thumb ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   FLDMMDL_SetStatusBitHeightGetOff 0x0216DB4C thumb ov010
 *   FLDMMDL_SetStatusBitAttrGetOff 0x0216DC98 thumb ov010
 *   FLDMMDL_SetStatusBitFellowHit 0x0216DAE0 thumb ov010
 *   FLDMMDL_SetEventId 0x0216D5B4 thumb ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_CheckStatusBitVanish  0x0216DAB4  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   CROWD_CloseChatterSlot 0x021F45A4 thumb ov055
 *   MSGDATA_Delete 0x02045C04 arm
 *   gCrowdChatterSlotX 0x021F45E0 data a1
 *   gCrowdChatterSlotY 0x021F45D0 data a1
 *   FIELD_MSGBG_AddSubMsgWinMsg  0x02191870  thumb  ov021
 *   FIELD_MSGBG_DeleteSubMsgWin  0x0219196C  thumb  ov021
 *   CROWD_ClearChatterSlot  0x021F459C  thumb  ov055
 */
#include "../ov010/fldmmdl_types.h"
#include "../ov021/fieldmap_types.h"

/*
 * Crowd of passers-by that walk across the field map, with speech windows
 * popping up over them. Started from a script command (the sub process table
 * gCrowdSubprocTemplate in ov055, see scrcmd_pokemon_fld.c); the field map keeps the work
 * in FieldMap.zoneEffectWork. The per-zone setup comes from archive 0xba.
 */

struct FieldSubproc;
struct FieldPlayer;
struct MsgBank;
struct ArcFile;

#include "../types.h"

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
    struct MsgBank *msgData;     /* 0x08 */
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

#include "../ov021/fieldmap.h"
#include "../arm9/gamesystem.h"
#include "../ov010/field_clock.h"
#include "../ov010/fldmmdl.h"
#include "../arm9/gfl_use.h"
struct Mmdl;
struct VecFx32;
#include "../ov010/fldmmdl_move.h"
struct ArcHandle;
#include "../arm9/gfl_heap_wrap.h"
#include "../ov021/field_player.h"
struct MsgBank;
#include "../arm9/msgdata.h"
#include "../ov021/field_msgbg.h"
#include "../ov010/fldmmdl_poslog.h"
/* Original prototype (docs/ORIGINAL_BUGS.tsv): the DS caller passes the heap id of ARC_TOOL_CreateHandle as u16 */
#ifdef __MWERKS__
#define ARC_TOOL_CreateHandle ARC_TOOL_CreateHandle_header
#endif
#include "../arm9/arc_tool.h"
#ifdef __MWERKS__
#undef ARC_TOOL_CreateHandle
void *ARC_TOOL_CreateHandle(u32 archiveId, u16 heapId);
#endif
#include "field_gimmick_crowd.h"
void CROWD_Init(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work);
void CROWD_Exit(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work);
void CROWD_Update(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work);
void CROWD_DrawProc(CrowdWork *work);
CrowdPerson *CROWD_FindFreePerson(CrowdWork *work);
const CrowdPerson *CROWD_FindPersonAtSpawn(const CrowdWork *work, int x, int z, unsigned int dir, int unused, int *isOccupied);
void CROWD_CreatePerson(CrowdPerson *person, MmdlSys *mmdlSys, int zoneId, const CrowdConfig *config, int index);
void CROWD_DeletePerson(CrowdPerson *person);
void CROWD_UpdatePerson(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player);
void CROWD_StartPerson(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player, int kind, u16 gridX, u16 gridZ, u16 dir, u16 stepCount, const CrowdArea *area);
void CROWD_MakePersonSolid(CrowdPerson *person);
void CROWD_RemovePerson(CrowdPerson *person);
void CROWD_SidestepPerson(CrowdPerson *person, Mmdl *blocker);
void CROWD_LoadConfig(CrowdConfig *config, int timeZone, int zoneId, u16 heapId);
void CROWD_FreeConfig(CrowdConfig *config);
void CROWD_UpdateSpawns(CrowdConfig *config, CrowdWork *work, int timeZone);
void CROWD_SpawnPerson(const CrowdWork *work, const CrowdConfig *config, const CrowdArea *area, CrowdPerson *person, u16 stagger);
void CROWD_SpawnInitialPeople(CrowdConfig *config, CrowdWork *work, int timeZone);
u32 CROWD_GetWalkCmdBase(const CrowdConfig *config);
void CROWD_InitSolidPerson(CrowdPerson *person);
void CROWD_InitPlayerAwarePerson(CrowdPerson *person);
void CROWD_UpdateSolidPerson(CrowdPerson *person, MmdlSys *mmdlSys);
void CROWD_UpdatePlayerAwarePerson(CrowdPerson *person, MmdlSys *mmdlSys, u32 player);
int CROWD_FindBlockingMmdl(CrowdPerson *person, MmdlSys *mmdlSys, Mmdl **blocker, u16 maxDist, u16 minDist);
int CROWD_IsMmdlInFront(const CrowdPerson *person, Mmdl *other, u16 maxDist, u16 minDist);
int CROWD_IsTileInFront(int ownX, int ownZ, int otherX, int otherZ, u16 maxDist, u16 minDist, u16 dir);
void CROWD_InitChatter(CrowdChatter *chatter, struct FieldMsgBg *msgBg, const CrowdConfig *config, u32 timeZone, u16 heapId);
void CROWD_ExitChatter(CrowdChatter *chatter);
void CROWD_CloseAllChatterSlots(CrowdChatter *chatter);
void CROWD_UpdateChatter(CrowdChatter *chatter, const CrowdConfig *config, FieldMap *fieldMap);
void CROWD_InitChatterSlot(CrowdChatterSlot *slot, int index);
void CROWD_OpenChatterSlot(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg, struct MsgBank *msgData, u32 msgFirst, u32 msgCount);
void CROWD_UpdateChatterSlot(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg);
void CROWD_ClearChatterSlot(CrowdChatterSlot *slot);
/*
 * Template of the field model header, two symbols for the one object: the
 * store of the object code goes through the first, the model is created from
 * the second (one symbol for both gives a different literal pool).
 */
extern MmdlHeader gCrowdMmdlHeader;
extern MmdlHeader d_021F4620_b;
extern const u8 gCrowdChatterSlotX[];
extern const u8 gCrowdChatterSlotY[];
struct FieldMsgBg;
/* One speech window slot (8 bytes); same layout as CrowdChatterSlot in field_gimmick_crowd.c. */

/* Start of the sub process: load the zone setup, create the people and the chatter. */
void CROWD_Init(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work)
{
    int i;
    u16 heapId;
    struct FieldMsgBg *msgBg;
    struct GameData *gameData;
    int zoneId;
    int timeZone;

    msgBg = FIELDMAP_GetMsgBg(fieldMap);
    gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap));
    work->player = FIELDMAP_GetFieldPlayer(fieldMap);
    work->mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    zoneId = FIELDMAP_GetZoneId(fieldMap);
    timeZone = FIELD_CLOCK_GetTimeZone(gameData);
    heapId = FIELDMAP_GetHeapId(fieldMap);
    CROWD_LoadConfig(&work->config, timeZone, zoneId, heapId);
    for (i = 0; i < CROWD_PERSON_MAX; i++)
        CROWD_CreatePerson(&work->people[i], work->mmdlSys, zoneId, &work->config, i);
    CROWD_SpawnInitialPeople(&work->config, work, timeZone);
    CROWD_InitChatter(&work->chatter, msgBg, &work->config, timeZone, heapId);
    FIELDMAP_SetZoneEffectWork(fieldMap, work);
}

/* End of the sub process. */
void CROWD_Exit(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work)
{
    int i;

    FIELDMAP_SetZoneEffectWork(fieldMap, 0);
    for (i = 0; i < CROWD_PERSON_MAX; i++)
        CROWD_DeletePerson(&work->people[i]);
    CROWD_FreeConfig(&work->config);
    CROWD_ExitChatter(&work->chatter);
    work->player = 0;
    work->mmdlSys = 0;
}

/* Per frame: spawn people, move them, run the speech windows. */
void CROWD_Update(struct FieldSubproc *proc, FieldMap *fieldMap, CrowdWork *work)
{
    int i;

    CROWD_UpdateSpawns(&work->config, work, FIELDMAP_GetTimeZone(fieldMap));
    if (FIELDMAP_IsEventActive(fieldMap)) {
        for (i = 0; i < CROWD_PERSON_MAX; i++)
            CROWD_MakePersonSolid(&work->people[i]);
    }
    for (i = 0; i < CROWD_PERSON_MAX; i++)
        CROWD_UpdatePerson(&work->people[i], work->mmdlSys, work->player);
    CROWD_UpdateChatter(&work->chatter, &work->config, fieldMap);
}

/* Draw hook of the sub process: close the speech windows. */
void CROWD_DrawProc(CrowdWork *work)
{
    CROWD_CloseAllChatterSlots(&work->chatter);
}

/* The first person slot that is not in use, or 0. */
CrowdPerson *CROWD_FindFreePerson(CrowdWork *work)
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
const CrowdPerson *CROWD_FindPersonAtSpawn(const CrowdWork *work, int x, int z, unsigned int dir, int unused, int *isOccupied)
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
            personX = FLDMMDL_GetGridNowX(work->people[i].mmdl);
            personZ = FLDMMDL_GetGridNowZ(work->people[i].mmdl);
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
void CROWD_CreatePerson(CrowdPerson *person, MmdlSys *mmdlSys, int zoneId, const CrowdConfig *config, int index)
{
    u32 i;
    u32 rand;
    u16 objCode;

    i = 0;
    objCode = config->modelCodes[GFL_USE_GetRandom(0) % config->modelCount];
    gCrowdMmdlHeader.objCode = objCode;
    rand = GFL_USE_GetRandom(0);
    person->mmdlId = index + 0x30;
    for (i = 0; i < config->modelTableCount; i++) {
        if (objCode == config->modelTable[i].objCode) {
            person->eventId = config->modelTable[i].eventIds[rand % 6];
            break;
        }
    }
    person->mmdl = FLDMMDL_AddMmdl(mmdlSys, &d_021F4620_b, zoneId);
    person->isActive = 0;
    person->state = 0;
    person->kind = 0;
    person->dir = 0;
    person->walkCmdBase = CROWD_GetWalkCmdBase(config);
    FLDMMDL_SetStatusBitVanish(person->mmdl, 1);
    FLDMMDL_SetMoveBitAttrEffectOff(person->mmdl, 1);
    {
        int drawOffset[3] = {0, 0, 0};
        drawOffset[0] = GFL_USE_GetRandom(0x8000) - 0x4000;
        FLDMMDL_SetDrawOffset(person->mmdl, (struct VecFx32 *)drawOffset);
    }
}

/* Delete the field model of a person. */
void CROWD_DeletePerson(CrowdPerson *person) { FLDMMDL_DeleteMmdl(person->mmdl); person->mmdl=0; }

/* Per-kind update handlers, indexed by CrowdPerson.kind. */
extern void (*gCrowdPersonUpdateFuncs[])(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player);

/* Run the update handler of an active person. */
void CROWD_UpdatePerson(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player) { if (person->isActive) gCrowdPersonUpdateFuncs[person->kind](person, mmdlSys, player); }

/* Per-kind start handlers, indexed by CrowdPerson.kind. */
extern void (* const gCrowdPersonInitFuncs[])(CrowdPerson *person);

/* Put a person on the map at the grid position, walking in direction dir. */
void CROWD_StartPerson(CrowdPerson *person, MmdlSys *mmdlSys, struct FieldPlayer *player, int kind, u16 gridX, u16 gridZ, u16 dir, u16 stepCount, const CrowdArea *area)
{
    MmdlHeader header;

    person->isActive = 1;
    FLDMMDL_SetStatusBitVanish(person->mmdl, 0);
    header = gCrowdMmdlHeader;
    header.objCode = FLDMMDL_GetObjCode(person->mmdl);
    header.dirHeader = dir;
    header.objId = person->mmdlId;
    FLDMMDL_InitPosRecord(&header, gridX, gridZ, 0);
    FLDMMDL_ChangeHeader(person->mmdl, &header);
    person->kind = kind;
    person->dir = dir;
    person->state = 0;
    person->stepsLeft = stepCount;
    person->isSidestepping = 0;
    person->sidestepDir = 0;
    FLDMMDL_SetMoveBitAttrEffectOff(person->mmdl, 1);
    person->area = area;
    gCrowdPersonInitFuncs[kind](person);
}

/* While a game event runs, a player-aware person with no event of its own becomes a solid one. */
void CROWD_MakePersonSolid(CrowdPerson *person) { if (person->isActive==1 && person->kind==CROWD_KIND_PLAYER_AWARE && FLDMMDL_GetEventId(person->mmdl)==CROWD_EVENT_NONE) { person->kind=CROWD_KIND_SOLID; CROWD_InitSolidPerson(person); } }

/* Take a person off the map: inactive and hidden. */
void CROWD_RemovePerson(CrowdPerson *person) { person->isActive=0; person->kind=0; person->dir=0; person->state=0; FLDMMDL_SetStatusBitVanish(person->mmdl,1); }

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
void CROWD_SidestepPerson(CrowdPerson *person, Mmdl *blocker)
{
    u32 newDir;
    u32 blockerDir;
    int posX;
    int nextZ;
    int posZ;
    const CrowdArea *area;
    blockerDir = FLDMMDL_GetDirDisp(blocker);
    posX = FLDMMDL_GetGridNowX(person->mmdl);
    posZ = FLDMMDL_GetGridNowZ(person->mmdl);
    if (person->isSidestepping != 0) {
        newDir = person->sidestepDir;
    } else {
        if (blockerDir == person->dir || person->dir == FLDMMDL_MOVE_GetDirTableValue(blockerDir)) {
            if (GFL_USE_GetRandom(2) == 0) {
                newDir = (u16)(blockerDir + 2);
            } else {
                newDir = FLDMMDL_MOVE_GetDirTableValue((u16)(blockerDir + 2));
            }
        } else {
            newDir = FLDMMDL_MOVE_GetDirTableValue(blockerDir);
        }
    }
    posX = (s16)(posX + FLDMMDL_MOVE_GetDirAddGridX(newDir));
    nextZ = (s16)(posZ + FLDMMDL_MOVE_GetDirAddGridZ(newDir));
    if (newDir <= 1) {
        area = person->area;
        if (nextZ < area->zMin || nextZ > area->zMax) {
            newDir = FLDMMDL_MOVE_GetDirTableValue(newDir);
        }
    } else {
        area = person->area;
        if (posX < area->xMin || posX > area->xMax) {
            newDir = FLDMMDL_MOVE_GetDirTableValue(newDir);
        }
    }
    FLDMMDL_SetAcmd(person->mmdl, (u16)(person->walkCmdBase + newDir));
    person->isSidestepping = 1;
    person->sidestepDir = newDir;
}
#pragma opt_lifetimes reset

/* Read the setup of the current zone from archive 0xba. */
void CROWD_LoadConfig(CrowdConfig *config, int timeZone, int zoneId, u16 heapId)
{
    struct ArcFile *arc;
    int *zoneTable;
    u32 count, i;
    u32 tempHeapId;
    int j;

    tempHeapId = (heapId & 0x7fff) | 0x8000;
    arc = ARC_TOOL_CreateHandle(0xba, tempHeapId);
    zoneTable = ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc, 5, (u16)tempHeapId);
    count = ARC_TOOL_GetHandleMemberSize((struct ArcHandle *)arc, 5) >> 2;
    for (i = 0; i < count; i++) {
        if (zoneId == zoneTable[i])
            break;
    }
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)arc, i, 0, 0x32, config);
    GFL_HEAP_Free(zoneTable);
    count = ARC_TOOL_GetHandleMemberSize((struct ArcHandle *)arc, 6);
    config->modelTable = ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc, 6, (u16)heapId);
    config->modelTableCount = count >> 4;
    ARC_TOOL_DeleteHandle(arc);
    for (j = 0; j < CROWD_AREA_MAX; j++)
        config->spawnCounter[j] = 0;
}

/* Free the model table of the setup. */
void CROWD_FreeConfig(CrowdConfig *config) { GFL_HEAP_Free(config->modelTable); config->modelTable=0; }

/* Per frame: count up the spawn timers and put a new person on the map when one runs out. */
void CROWD_UpdateSpawns(CrowdConfig *config, CrowdWork *work, int timeZone)
{
    int i;

    for (i = 0; i < config->areaCount; i++) {
        CrowdPerson *person;
        if (config->spawnCounter[i] >= config->intervalByTimeZone[timeZone]) {
            person = CROWD_FindFreePerson(work);
            if (person) {
                CROWD_SpawnPerson(work, config, &config->areas[i], person, 0);
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
 * Levers, each measured: CROWD_StartPerson's u16 parameters (its own file) put
 * y in r7 and spill x; the else arm's x is an if/else, not a ternary (the
 * shared truncation then stays ahead of the area loads); u8 kind moves
 * the stack parameter's load to the front of the prologue; const work and
 * area let the final call's field loads rise above the argument stores.
 */
void CROWD_SpawnPerson(const CrowdWork *work, const CrowdConfig *config, const CrowdArea *area, CrowdPerson *person, u16 stagger)
{
    int isOccupied;
    u16 gridX;
    u16 gridZ;
    u8 kind;
    u32 rand;
    u16 dir;

    kind = 0;
    rand = GFL_USE_GetRandom(0);
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
    if (CROWD_FindPersonAtSpawn(work, gridX, gridZ, dir, 1, &isOccupied) == 0) {
        if (rand % 10 == 0)
            kind = 1;
    }
    if (isOccupied == 0)
        CROWD_StartPerson(person, work->mmdlSys, work->player, kind, gridX, gridZ, area->dir, (u16)(area->length - stagger), area);
}

/* Fill the areas with people when the zone is entered: the number follows the spawn interval. */
void CROWD_SpawnInitialPeople(CrowdConfig *config, CrowdWork *work, int timeZone)
{
    int i, j, count, offset;

    for (i = 0; i < config->areaCount; i++) {
        count = (config->areas[i].length * 6) / config->intervalByTimeZone[timeZone];
        offset = 0;
        for (j = 0; j < count; j++) {
            CrowdPerson *person = CROWD_FindFreePerson(work);
            if (person) {
                CROWD_SpawnPerson(work, config, &config->areas[i], person, (u16)(offset / 6));
                offset += config->intervalByTimeZone[timeZone];
            }
        }
    }
}

/* Walk command of direction 0 for the step length of the setup. */
u32 CROWD_GetWalkCmdBase(const CrowdConfig *config)
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
void CROWD_InitSolidPerson(CrowdPerson *person) { FLDMMDL_SetStatusBitHeightGetOff(person->mmdl,1); FLDMMDL_SetStatusBitAttrGetOff(person->mmdl,1); FLDMMDL_SetStatusBitFellowHit(person->mmdl,0); FLDMMDL_SetEventId(person->mmdl,CROWD_EVENT_NONE); }

/* Start handler of the player-aware kind: passes through other field models, no event. */
void CROWD_InitPlayerAwarePerson(CrowdPerson *person) { FLDMMDL_SetStatusBitHeightGetOff(person->mmdl,1); FLDMMDL_SetStatusBitAttrGetOff(person->mmdl,1); FLDMMDL_SetStatusBitFellowHit(person->mmdl,1); FLDMMDL_SetEventId(person->mmdl,CROWD_EVENT_NONE); }

/* Update handler of the solid kind: walk on, sidestep a blocker, leave at the end. */
void CROWD_UpdateSolidPerson(CrowdPerson *person, MmdlSys *mmdlSys)
{
    Mmdl *blocker;
    switch (person->state) {
    case CROWD_STATE_WAIT_STEP:
        if (FLDMMDL_CheckEndAcmd(person->mmdl) == 0) {
            return;
        }
        person->state = person->state + 1;
    case CROWD_STATE_NEXT_STEP:
        if (person->stepsLeft == 0) {
            person->state = CROWD_STATE_LEAVE;
            return;
        }
        if (CROWD_FindBlockingMmdl(person, mmdlSys, &blocker, 2, 0)) {
            CROWD_SidestepPerson(person, blocker);
        } else {
            FLDMMDL_SetAcmd(person->mmdl, (u16)(person->walkCmdBase + person->dir));
            person->stepsLeft = person->stepsLeft - 1;
        }
        person->state = CROWD_STATE_WAIT_STEP;
        return;
    case CROWD_STATE_LEAVE:
        CROWD_RemovePerson(person);
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
void CROWD_UpdatePlayerAwarePerson(CrowdPerson *person, MmdlSys *mmdlSys, u32 player)
{
    Mmdl *blocker;
    Mmdl *playerMmdl;
    switch (person->state) {
    case CROWD_STATE_WAIT_STEP:
        if (FLDMMDL_CheckEndAcmd(person->mmdl) == 0) {
            return;
        }
        person->state = person->state + 1;
    case CROWD_STATE_NEXT_STEP:
        if (person->stepsLeft == 0) {
            person->state = CROWD_STATE_LEAVE;
            return;
        }
        playerMmdl = FIELD_PLAYER_GetMmdl((struct FieldPlayer *)player);
        player = 1;
        if (CROWD_IsMmdlInFront(person, playerMmdl, 1, 1)) {
            FLDMMDL_SetEventId(person->mmdl, person->eventId);
            return;
        }
        if (CROWD_FindBlockingMmdl(person, mmdlSys, &blocker, player, 0)) {
            CROWD_SidestepPerson(person, blocker);
            FLDMMDL_SetEventId(person->mmdl, CROWD_EVENT_NONE);
            CROWD_MakePersonSolid(person);
        } else {
            FLDMMDL_SetAcmd(person->mmdl, (u16)(person->walkCmdBase + person->dir));
            person->stepsLeft = person->stepsLeft - 1;
            FLDMMDL_SetEventId(person->mmdl, CROWD_EVENT_NONE);
        }
        person->state = CROWD_STATE_WAIT_STEP;
        return;
    case CROWD_STATE_LEAVE:
        CROWD_RemovePerson(person);
        return;
    }
}

/*
 * Find another field model within minDist..maxDist tiles in front of the
 * person; *blocker gets it.
 *
 * maxDist and minDist are u16, as are CROWD_IsMmdlInFront's last two parameters (its
 * own file): with u32 the stack parameter's load (ldr r6, [sp, #0x20]) sinks to
 * the first call instead of leading the prologue.
 */
int CROWD_FindBlockingMmdl(CrowdPerson *person, MmdlSys *mmdlSys, Mmdl **blocker, u16 maxDist, u16 minDist)
{
    u32 iter = 0;
    Mmdl *other;
    while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &other, &iter) == 1) {
        if (person->mmdl != other && FLDMMDL_CheckStatusBit(other, 0x80) == 0 &&
            FLDMMDL_CheckStatusBitVanish(other) == 0 && CROWD_IsMmdlInFront(person, other, maxDist, minDist) != 0) {
            *blocker = other;
            return 1;
        }
    }
    return 0;
}

/* Whether a field model (at its current or its previous tile) is in front of the person. */
int CROWD_IsMmdlInFront(const CrowdPerson *person, Mmdl *other, u16 maxDist, u16 minDist)
{
    int otherX = FLDMMDL_GetGridNowX(other);
    int otherZ = FLDMMDL_GetGridNowZ(other);
    int ownX = FLDMMDL_GetGridNowX(person->mmdl);
    int ownZ = FLDMMDL_GetGridNowZ(person->mmdl);
    int prevX;
    int prevZ;

    if (CROWD_IsTileInFront(ownX, ownZ, otherX, otherZ, maxDist, minDist, person->dir)) {
        return 1;
    }
    prevX = FLDMMDL_GetGridOldX(other);
    prevZ = FLDMMDL_GetGridOldZ(other);
    return CROWD_IsTileInFront(ownX, ownZ, prevX, prevZ, maxDist, minDist, person->dir);
}

/* Whether the other tile is in the same lane, minDist..maxDist tiles ahead in direction dir. */
int CROWD_IsTileInFront(int ownX, int ownZ, int otherX, int otherZ, u16 maxDist, u16 minDist, u16 dir)
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
void CROWD_InitChatter(CrowdChatter *chatter, struct FieldMsgBg *msgBg, const CrowdConfig *config, u32 timeZone, u16 heapId)
{
    int i;
    u32 rand;
    s16 interval;

    i = 0;
    rand = GFL_USE_GetRandom(0);
    interval = config->intervalByTimeZone[timeZone];
    chatter->timer = i;
    chatter->interval = 0x10 + rand % interval;
    chatter->msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 3, 0x9f, heapId);
    chatter->msgBg = msgBg;
    chatter->nextSlot = rand & 0xf;
    for (i = 0; i < CROWD_CHATTER_SLOT_MAX; i++) {
        CROWD_InitChatterSlot(&chatter->slots[i], (u16)i);
    }
}

/* Close the windows and free the message data. */
void CROWD_ExitChatter(CrowdChatter *chatter) { int i; for (i=0;i<CROWD_CHATTER_SLOT_MAX;i++) CROWD_CloseChatterSlot(&chatter->slots[i],chatter->msgBg); chatter->msgBg=0; MSGDATA_Delete((struct MsgBank *)chatter->msgData); chatter->msgData=0; }

/* Close all open windows. */
void CROWD_CloseAllChatterSlots(CrowdChatter *chatter) { int i; for (i=0;i<CROWD_CHATTER_SLOT_MAX;i++) CROWD_CloseChatterSlot(&chatter->slots[i],chatter->msgBg); }

/* Per frame: open a window when the timer runs out (not during an event), age the open ones. */
void CROWD_UpdateChatter(CrowdChatter *chatter, const CrowdConfig *config, FieldMap *fieldMap)
{
    int i;
    u32 rand;
    int timeZone;

    i = 0;
    rand = GFL_USE_GetRandom(0);
    timeZone = FIELDMAP_GetTimeZone(fieldMap);
    if (FIELDMAP_IsEventActive(fieldMap) == 0) {
        chatter->timer = chatter->timer + 1;
        if (chatter->timer >= chatter->interval) {
            CROWD_OpenChatterSlot(&chatter->slots[chatter->nextSlot], chatter->msgBg, chatter->msgData,
                          config->chatterMsgFirst, config->chatterMsgCount);
            chatter->timer = i;
            chatter->nextSlot = (chatter->nextSlot + 1) & 0xf;
            chatter->interval = 0x10 + rand % config->intervalByTimeZone[timeZone];
        }
        i = 0;
        for (; i < CROWD_CHATTER_SLOT_MAX; i++) {
            CROWD_UpdateChatterSlot(&chatter->slots[i], chatter->msgBg);
        }
    } else {
        for (i = 0; i < CROWD_CHATTER_SLOT_MAX; i++) {
            CROWD_CloseChatterSlot(&chatter->slots[i], chatter->msgBg);
        }
    }
}

/* Set up a speech window slot: closed, at its fixed position. */
void CROWD_InitChatterSlot(CrowdChatterSlot *slot, int index)
{
    slot->isOpen = 0;
    slot->x = gCrowdChatterSlotX[index];
    slot->y = gCrowdChatterSlotY[index];
    slot->windowId = index;
    slot->frames = 0;
}

/* Open the speech window of a slot with a random message. */
void CROWD_OpenChatterSlot(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg, struct MsgBank *msgData, u32 msgFirst, u32 msgCount)
{
    u32 rand = GFL_USE_GetRandom(0);
    slot->isOpen = 1;
    slot->frames = 0;
    FIELD_MSGBG_AddSubMsgWinMsg(msgBg, msgData, msgFirst + rand % msgCount, slot->windowId, slot->x, slot->y, 8, 2);
}

/*
 * Age an open speech window; it closes after 16 frames.
 * Unlabelled leaf callee of CROWD_UpdateChatter.
 */
void CROWD_UpdateChatterSlot(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg)
{
    if (slot->isOpen != 0) {
        s16 *frames = &slot->frames;
        *frames = *frames + 1;
        if (*frames >= 0x10) {
            FIELD_MSGBG_DeleteSubMsgWin(msgBg, slot->windowId);
            CROWD_ClearChatterSlot(slot);
        }
    }
}

/* Mark a speech window slot closed. */
void CROWD_ClearChatterSlot(CrowdChatterSlot *slot)
{
    slot->frames = 0;
    slot->isOpen = 0;
}

/* Closes the speech window of an open slot and clears the slot. */
void CROWD_CloseChatterSlot(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg)
{
    if (slot->isOpen != 0) {
        FIELD_MSGBG_DeleteSubMsgWin(msgBg, slot->windowId);
        CROWD_ClearChatterSlot(slot);
    }
}
