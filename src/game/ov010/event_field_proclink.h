#ifndef GAME_OV010_EVENT_FIELD_PROCLINK_H
#define GAME_OV010_EVENT_FIELD_PROCLINK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_field_proclink.c, prototypes copied from their definitions. */

struct ZukanParam;
struct BagParam;
struct TrainerCardViewWork;
struct TownMapParam;
struct ConfigParam;
struct TrainerCardParam;
struct ReportParam;
struct ObjAnimWork;
struct ZoneFlagSetting;
struct ProcLinkReturnList;
struct ProcLinkEntry;
typedef struct ZukanParam ZukanParam;
typedef struct BagParam BagParam;
typedef struct TrainerCardViewWork TrainerCardViewWork;
typedef struct TownMapParam TownMapParam;
typedef struct ConfigParam ConfigParam;
typedef struct TrainerCardParam TrainerCardParam;
typedef struct ReportParam ReportParam;
typedef struct ObjAnimWork ObjAnimWork;
typedef struct ZoneFlagSetting ZoneFlagSetting;
typedef struct ProcLinkReturnList ProcLinkReturnList;
typedef struct ProcLinkEntry ProcLinkEntry;

#include "../ov010/field_event_types.h"
#include "../ov010/field_event_types.h"
#include "../ov131/p_status_types.h"
#include "../ov006/event_wificlub_types.h"

PokeListParam *EVENT_FIELD_PROCLINK_CreatePokeListParam(ProcLinkWork *work, int kind, int mode, void *source);
int EVENT_FIELD_PROCLINK_ReturnPokeList(ProcLinkWork *work, PokeListParam *listResult);
ZukanParam *EVENT_FIELD_PROCLINK_CreateZukanParam(ProcLinkWork *work, int startSpecies);
Bool EVENT_FIELD_PROCLINK_ReturnZukan(ProcLinkWork *work, ZukanParam *param);
PStatusParam *EVENT_FIELD_PROCLINK_CreatePokeStatusParam(ProcLinkWork *work, int page, int mode, PokeListParam *listResult);
int EVENT_FIELD_PROCLINK_ReturnPokeStatus(ProcLinkWork *work, PStatusParam *param);
BagParam *EVENT_FIELD_PROCLINK_CreateBagParam(ProcLinkWork *work, int lastFieldPocket, int bagMode, const PokeListParam *listResult);
int EVENT_FIELD_PROCLINK_ReturnBag(ProcLinkWork *work, PokeListParam *listResult);
void EVENT_FIELD_PROCLINK_CreateTrainerCardView(ProcLinkWork *work, int startPage);
int EVENT_FIELD_PROCLINK_ReturnTrainerCardView(ProcLinkWork *work, TrainerCardViewWork *param);
TownMapParam *EVENT_FIELD_PROCLINK_CreateTownMapParam(ProcLinkWork *work);
int EVENT_FIELD_PROCLINK_ReturnTownMapSelect(ProcLinkWork *work, TownMapParam *param);
ConfigParam *EVENT_FIELD_PROCLINK_CreateConfigParam(ProcLinkWork *work);
int EVENT_FIELD_PROCLINK_ReturnConfig(int unused, ConfigParam *param);
void EVENT_FIELD_PROCLINK_StartConfigEvent(ProcLinkWork *work);
TrainerCardParam *EVENT_FIELD_PROCLINK_CreateTrainerCardParam(ProcLinkWork *work);
int EVENT_FIELD_PROCLINK_ReturnTrainerCard(ProcLinkWork *work, TrainerCardParam *param);
int EVENT_FIELD_PROCLINK_CreateMailParam(ProcLinkWork *work, int kind, int mode, const PokeListParam *listResult);
int EVENT_FIELD_PROCLINK_ReturnMail(ProcLinkWork *work, void *mailParam);
void EVENT_FIELD_PROCLINK_UnloadMailOverlay(void *mailParam);
EvolutionRequest *EVENT_FIELD_PROCLINK_CreateEvolutionParam(ProcLinkWork *work, int kind, int mode, const PokeListParam *listResult);
int EVENT_FIELD_PROCLINK_ReturnEvolution(ProcLinkWork *work);
ReportParam *EVENT_FIELD_PROCLINK_CreateReportParam(ProcLinkWork *work);
int EVENT_FIELD_PROCLINK_ReturnReport(ProcLinkWork *work, ReportParam *param);
int EVENT_FIELD_PROCLINK_FreeEventMain(void *event, int *state, ReportEventWork *work);
void EVENT_FIELD_PROCLINK_FreeAnimWork(void);
int EVENT_FIELD_PROCLINK_ObjAnimEventMain(void *task, int *state, ObjAnimWork *work);
void *EVENT_FIELD_PROCLINK_InitAnimNode(void *fieldObjects, unsigned int objectId);
void EVENT_FIELD_PROCLINK_ClearAnimNode(ObjAnimWork *work);
ObjAnimWork *EVENT_FIELD_PROCLINK_IsAnimNodeDone(ObjAnimWork *work, int handle);
int EVENT_FIELD_PROCLINK_UpdateAnimNode(ObjAnimWork *work);
int EVENT_FIELD_PROCLINK_StartHopAnim(void *fieldObject);
int EVENT_FIELD_PROCLINK_IsHopAnimDone(int handle);
int EVENT_FIELD_PROCLINK_ApplyZoneChangeEnable(ZoneFlagSetting *setting);
void EVENT_FIELD_PROCLINK_InitEventdataSystem(ProcLinkReturnList *list);
ProcLinkEntry *EVENT_FIELD_PROCLINK_GetEventdataEntry(ProcLinkReturnList *list, int id, unsigned mode);
/* END mkheaders: generated region */

#endif
