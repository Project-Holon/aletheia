#ifndef GAME_ARM9_GAMESYSTEM_H
#define GAME_ARM9_GAMESYSTEM_H
struct TcbTask;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gamesystem.c, prototypes copied from their definitions. */

struct Proc;
struct GameSystem;
struct ProcData;
struct GameInitWork;
struct VecFx32;
struct GameData;
struct PlayerWork;
struct GameEvent;
struct GameComm;

#include "../types.h"
#include "../arm9/ica_anime_shared_types.h"

u32 GAMESYSTEM_CallIfSet(void (*func)(void));
void GAMESYSTEM_RandTwice(struct TcbTask * unused0, void * unused1);
void GAMESYSTEM_ApplyTamperPenalty(void);
void GAMESYSTEM_ProbeHeapCreate(void);
void GAMESYSTEM_ApplyTamperPenaltyRepeat(void);
u32 GAMESYSTEM_ProcInit(struct Proc *proc, u32 *seq, struct GameInitWork *initParam);
u32 GAMESYSTEM_ProcMain(struct Proc *proc, u32 *seq, struct GameInitWork *initParam, struct GameSystem *gameSystem);
u32 GAMESYSTEM_ProcEnd(struct Proc *proc, u32 *seq, struct GameInitWork *initParam, struct GameSystem *gameSystem);
struct GameInitWork *GAMESYSTEM_SetupInitWork(u32 mode, u16 zoneId, struct VecFx32 *position, int direction);
u32 GAMESYSTEM_GetWorkSize(void);
void GAMESYSTEM_Init(struct GameSystem *gameSystem, u16 heapId, struct GameInitWork *initParam);
void GAMESYSTEM_Exit(struct GameSystem *gameSystem);
void GAMESYSTEM_Setup(struct GameSystem *gameSystem, u16 heapId, struct GameInitWork *initParam);
int GAMESYSTEM_Main(struct GameSystem *gameSystem);
void GAMESYSTEM_UpdateAutoComm(struct GameSystem *gameSystem);
void GAMESYSTEM_Delete(struct GameSystem *gameSystem);
void GAMESYSTEM_SetEventCreator(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg);
void GAMESYSTEM_UpdateEventActiveFlag(struct GameSystem *gameSystem);
void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, const struct ProcData *procData, void *param);
void GAMESYSTEM_CallFieldProc(struct GameSystem *gameSystem);
int GAMESYSTEM_IsEventActive(struct GameSystem *gameSystem);
u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
struct PlayerWork *GAMESYSTEM_GetMyPlayerWork(const struct GameSystem *gameSystem);
struct GameEvent *GAMESYSTEM_GetEvent(const struct GameSystem *gameSystem);
void GAMESYSTEM_SetEvent(struct GameSystem *gameSystem, struct GameEvent *event);
void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
void GAMESYSTEM_SetFieldMap(struct GameSystem *gameSystem, void *fieldMap);
u32 GAMESYSTEM_IsFieldMapActive(const struct GameSystem *gameSystem);
void GAMESYSTEM_SetFieldMapState(struct GameSystem *gameSystem, u32 state);
u8 GAMESYSTEM_GetFieldMapState(const struct GameSystem *gameSystem);
void *GAMESYSTEM_GetIssSystem(const struct GameSystem *gameSystem);
struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
void GAMESYSTEM_SetCommBlocked(struct GameSystem *gameSystem, u32 blocked);
u8 GAMESYSTEM_IsCommBlocked(const struct GameSystem *gameSystem);
u32 GAMESYSTEM_IsAlwaysNetFlagSet(const struct GameSystem *gameSystem);
void GAMESYSTEM_SetAlwaysNetFlag(struct GameSystem *gameSystem, unsigned int on);
u32 GAMESYSTEM_CanStartAutoComm(struct GameSystem *gameSystem);
u32 GAMESYSTEM_TryStartAutoComm(struct GameSystem *gameSystem);
u32 GAMESYSTEM_IsNetOffBySleep(const struct GameSystem *gameSystem);
void GAMESYSTEM_ClearNetOffBySleep(struct GameSystem *gameSystem);
void GAMESYSTEM_OnSleep(void *arg);
void GAMESYSTEM_RegisterSleepCallback(struct GameSystem *gameSystem);
void GAMESYSTEM_ReleaseSleepCallback(struct GameSystem *gameSystem);
int GAMESYSTEM_IsSleepBlocked(void *arg);
void GAMESYSTEM_RegisterSleepCheck(struct GameSystem *gameSystem);
void GAMESYSTEM_ReleaseSleepCheck(struct GameSystem *gameSystem);
/* END mkheaders: generated region */

#endif
