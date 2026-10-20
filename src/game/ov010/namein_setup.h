#ifndef GAME_OV010_NAMEIN_SETUP_H
#define GAME_OV010_NAMEIN_SETUP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of namein_setup.c, prototypes copied from their definitions. */

struct FallEventWork;
struct LandEventWork;
struct PartyTaskWork;
struct EncounterContext;
struct NameBalloonWork;
struct NameBalloonRecord;
struct HistoryScreenWork;
struct ProcSys;
struct ProcCallWork;
struct TransitionInfo;
struct SceneEventWork;
typedef struct FallEventWork FallEventWork;
typedef struct LandEventWork LandEventWork;
typedef struct PartyTaskWork PartyTaskWork;
typedef struct EncounterContext EncounterContext;
typedef struct NameBalloonWork NameBalloonWork;
typedef struct NameBalloonRecord NameBalloonRecord;
typedef struct HistoryScreenWork HistoryScreenWork;
typedef struct ProcCallWork ProcCallWork;
typedef struct TransitionInfo TransitionInfo;
typedef struct SceneEventWork SceneEventWork;

#include "../ov010/namein_args.h"
#include "../arm9/strbuf_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../types.h"

NameInArgs *NAMEIN_SETUP_CreateArgs(unsigned short heapId, int kind, short species, short traits, int maxLen, Strbuf *initialName, void *pokedex);
NameInArgs *NAMEIN_SETUP_CreateMonArgs(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, void *pokedex);
NameInArgs *NAMEIN_SETUP_CreateCaptureArgs(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, Strbuf *boxName, void *boxManager, int boxIndex, void *pokedex);
void NAMEIN_SETUP_FreeArgs(NameInArgs *args);
void NAMEIN_SETUP_CopyName(NameInArgs *args, Strbuf *dest);
int NAMEIN_SETUP_IsCanceled(NameInArgs *args);
int NAMEIN_SETUP_RunFallEvent(GameEvent *event, u32 *state, FallEventWork *work);
GameEvent *NAMEIN_SETUP_StartFallEvent(GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_StepLandAnim(LandEventWork *work);
void *NAMEIN_SETUP_SyncObjHeightToAnim(LandEventWork *work);
void NAMEIN_SETUP_SnapObjToGrid(LandEventWork *work);
int NAMEIN_SETUP_RunLandEvent(GameEvent *event, u32 *state, LandEventWork *work);
GameEvent *NAMEIN_SETUP_StartLandEvent(GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_RunPartyPickEvent(GameEvent *event, int *state, PartyTaskWork *work);
GameEvent *NAMEIN_SETUP_StartPartyPickEvent(EncounterContext *ctx, GameSystem *gameSystem, u8 useOwnParty);
void NAMEIN_SETUP_StartEncounterScene(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_RunNameBalloonEvent(GameEvent *event, int *state, NameBalloonWork *work, u32 extra);
GameEvent *NAMEIN_SETUP_StartNameBalloonFromRecord(NameBalloonRecord *records, GameSystem *gameSystem, u32 recordIndex, u16 npcId, u8 dir);
int NAMEIN_SETUP_RunHistoryScreenEvent(GameEvent *event, int *state, HistoryScreenWork *work);
GameEvent *NAMEIN_SETUP_StartHistoryScreenEvent(GameSystem *gameSystem);
int NAMEIN_SETUP_InitHostProc(void *proc, int *seq, void *pwk, void *mywk);
int NAMEIN_SETUP_ExitHostProc(void *proc, int *seq, void *pwk, void **mywk);
int NAMEIN_SETUP_MainHostProc(void *proc, int *seq, int *pwk, struct ProcSys **mywk);
int NAMEIN_SETUP_RunProcCallEvent(GameEvent *event, int *state, ProcCallWork *work);
GameEvent *NAMEIN_SETUP_StartProcCallEvent(GameSystem *gameSystem, TransitionInfo *transitionInfo, void *extra);
int NAMEIN_SETUP_RunSceneEvent(GameEvent *event, int *state, SceneEventWork *work);
GameEvent *NAMEIN_SETUP_StartSceneEvent(GameSystem *gameSystem, FieldMap *fieldMap, TransitionInfo *transitionInfo, void *extra);
void NAMEIN_SETUP_StartEncounterTransition(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_RunNameBalloonWaitEvent(GameEvent *event, int *state, NameBalloonWork *work);
GameEvent *NAMEIN_SETUP_StartNameBalloonFromHistory(GameSystem *gameSystem, int recordIndex, u8 npcId);
int NAMEIN_SETUP_ScrCmdSetFieldSaveFlag(void *scriptCtx, void *scriptWork);
void NAMEIN_SETUP_SetFieldSaveFlag(GameSystem *gameSystem);
/* END mkheaders: generated region */

#endif
