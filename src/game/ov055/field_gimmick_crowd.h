#ifndef GAME_OV055_FIELD_GIMMICK_CROWD_H
#define GAME_OV055_FIELD_GIMMICK_CROWD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_crowd.c, prototypes copied from their definitions. */

struct FieldSubproc;
struct CrowdWork;
struct CrowdPerson;
struct CrowdConfig;
struct FieldPlayer;
struct CrowdArea;
struct CrowdChatter;
struct FieldMsgBg;
struct CrowdChatterSlot;
struct MsgBank;
typedef struct CrowdWork CrowdWork;
typedef struct CrowdPerson CrowdPerson;
typedef struct CrowdConfig CrowdConfig;
typedef struct CrowdArea CrowdArea;
typedef struct CrowdChatter CrowdChatter;
typedef struct CrowdChatterSlot CrowdChatterSlot;

#include "../ov021/field_flash_shared_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../types.h"

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
void CROWD_CloseChatterSlot(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg);
/* END mkheaders: generated region */

#endif
