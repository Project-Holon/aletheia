#ifndef GAME_OV018_INTRUDE_SUBDISP_H
#define GAME_OV018_INTRUDE_SUBDISP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intrude_subdisp.c, prototypes copied from their definitions. */

struct IntrudeBrightFadeWork;
typedef struct IntrudeBrightFadeWork IntrudeBrightFadeWork;

#include "../ov018/intrude_field_types.h"
#include "../types.h"
#include "../ov011/intrude_comm_types.h"
#include "../ov018/event_comm_common_types.h"
#include "../ov018/intrude_subdisp_types.h"

void INTRUDE_FIELD_InitMmdlCopyAnime(PlayerSpinWork *spinWork, void *gameSystem, void *fieldMap, void *intrudeWork, u16 id, u8 kind, u8 flag, u16 idx, int place);
int INTRUDE_FIELD_MainMmdlCopyAnime(PlayerSpinWork *spinWork);
int INTRUDE_SUBDISP_MainRequestAnswerSeq(IntrudeCommSys *sys, EventCommCommonWork *work, u8 *state);
void *INTRUDE_SUBDISP_CreatePalaceWarpEvent(void *gameSystem);
void *INTRUDE_SUBDISP_CreateReturnPalaceEvent(int gameSystem);
struct GameEvent *INTRUDE_SUBDISP_CreateDisconnectEvent(void *gameSystem, int cause);
void *INTRUDE_SUBDISP_CreateGuideScriptEvent(void *gameSystem);
int INTRUDE_SUBDISP_GuideScriptEventMain(void *event, int *state);
void *INTRUDE_SUBDISP_CreateTownWarpEvent(void *gameSystem, void *fieldMap, u16 zoneId, int mode);
void *INTRUDE_SUBDISP_CreatePlayerWarpEvent(void *gameSystem, void *fieldMap, int netId);
void *INTRUDE_SUBDISP_CreateBrightFadeEvent(void *gameSystem, int fieldMap, int subscreen);
int INTRUDE_SUBDISP_BrightFadeEventMain(int event, int *state, IntrudeBrightFadeWork *work);
int INTRUDE_SUBDISP_ScriptAddAreaMmdls(void *unused, void *scriptWork);
int INTRUDE_SUBDISP_ScriptAddAreaMapsAndMarkers(int unused, int scriptWork);
IntrudeSubdispWork *INTRUDE_SUBDISP_Init(void *gameSystem);
void INTRUDE_SUBDISP_Exit(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_Update(IntrudeSubdispWork *work, int mode);
void INTRUDE_SUBDISP_Draw(IntrudeSubdispWork *work);
void *INTRUDE_SUBDISP_EventCheck(IntrudeSubdispWork *work, int touched, int param);
void INTRUDE_SUBDISP_VBlankTask(void *tcb, void *taskWork);
void INTRUDE_SUBDISP_SystemSetup(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_SystemExit(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_BgSetup(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_BgExit(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_BmpWinSetup(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_BmpWinExit(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_ClactResourceLoad(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_ClactResourceUnload(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_ClactActorCreate(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_ClactActorDelete(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_CreateTownActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreatePlayerMarkActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreateTownMarkActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreateMyPlayerActor(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreatePlayerIconActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreateInfoIconActor(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreateButtonActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_DeleteButtonBmpOam(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_UpdateTownActors(IntrudeSubdispWork *work, void *target);
void INTRUDE_SUBDISP_UpdatePlayerMarkActors(IntrudeSubdispWork *work, void *target);
void INTRUDE_SUBDISP_UpdatePlayerTownActors(IntrudeSubdispWork *work, IntrudeCommSys *sys, void *target);
void INTRUDE_SUBDISP_UpdateTownMarkPalette(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_UpdateMyPlayerActor(IntrudeSubdispWork *work, void *target, u16 zoneId);
void INTRUDE_SUBDISP_UpdateButtonActors(IntrudeSubdispWork *work, void *target);
void INTRUDE_SUBDISP_UpdateInfoIcon(IntrudeSubdispWork *work, void *target);
void INTRUDE_SUBDISP_PrintTitle(IntrudeSubdispWork *work, int zoneId);
void INTRUDE_SUBDISP_PrintInfoMessage(IntrudeSubdispWork *work, IntrudeCommSys *sys, u16 zoneId);
void *INTRUDE_SUBDISP_GetTargetPlayerData(IntrudeSubdispWork *work);
int INTRUDE_SUBDISP_IsZoneMatch(u16 zone, u16 zoneA, u16 zoneB);
void INTRUDE_SUBDISP_SetTouchRect(int x, int y, int halfWidth, int halfHeight, IntrudeSubdispRect *rect);
int INTRUDE_SUBDISP_IsInTouchRect(int x, int y, const IntrudeSubdispRect *rect);
void INTRUDE_SUBDISP_UpdateTouch(IntrudeCommSys *sys, IntrudeSubdispWork *work, int zoneId);
void INTRUDE_SUBDISP_ReloadBgScreens(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_UpdateBgPalette(IntrudeSubdispWork *work, IntrudeCommSys *sys);
void INTRUDE_SUBDISP_SetBgPalette(IntrudeSubdispWork *work, int homeSlot);
void INTRUDE_SUBDISP_InitTownState(IntrudeSubdispWork *work, IntrudeCommSys *sys);
void INTRUDE_SUBDISP_UpdateTownState(IntrudeSubdispWork *work, IntrudeCommSys *sys);
void INTRUDE_SUBDISP_StartTownBlink(IntrudeSubdispWork *work);
int INTRUDE_SUBDISP_IsTownBlinking(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_SetTownCursor(IntrudeSubdispWork *work, int index);
void INTRUDE_SUBDISP_StartButtonBlink(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_UpdateButtonBlink(IntrudeSubdispWork *work);
int INTRUDE_SUBDISP_IsInfoActive(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_ClearInfoPanel(void);
void INTRUDE_SUBDISP_DrawInfoPanel(IntrudeSubdispWork *work, int mode);
int INTRUDE_SUBDISP_IsAlone(IntrudeSubdispWork *work);
/* END mkheaders: generated region */

#endif
