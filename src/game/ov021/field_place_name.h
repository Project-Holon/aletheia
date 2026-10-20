#ifndef GAME_OV021_FIELD_PLACE_NAME_H
#define GAME_OV021_FIELD_PLACE_NAME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_place_name.c, prototypes copied from their definitions. */

struct FieldMsgContext;
struct ArcFile;
typedef struct ArcFile ArcFile;

#include "../ov021/field_place_name_types.h"
#include "../ov021/bsubway_scr_types.h"
#include "../types.h"
#include "../arm9/strbuf_types.h"

FieldPlaceName *FIELD_PLACE_NAME_Create(GameSystem *gameSystem, u32 heapId, struct FieldMsgContext *msgContext);
void FIELD_PLACE_NAME_Delete(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_Main(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_Draw(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_OnZoneChange(FieldPlaceName *placeName, int zoneId);
void FIELD_PLACE_NAME_ShowForZone(FieldPlaceName *placeName, int zoneId);
void FIELD_PLACE_NAME_ForceShowForZone(FieldPlaceName *placeName, int zoneId);
int FIELD_PLACE_NAME_Cancel(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_RestoreWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetupWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ReleaseWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_LoadPaletteFile(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_FreePaletteFile(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_TransferPalette(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_AllocBgChars(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_FreeBgChars(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ClearWindow(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateClactRenderer(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteClactRenderer(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_RegisterClactPalette(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ReleaseClactPalette(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateClactUnit(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteClactUnit(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetClactUnitRenderer(FieldPlaceName *placeName, int unitIndex);
void FIELD_PLACE_NAME_CreateLetters(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteLetters(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateArcHandle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteArcHandle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetSpawnCounts(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SpawnNextLetter(FieldPlaceName *placeName);
int FIELD_PLACE_NAME_IsAllSpawned(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_HideLetters(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_LaunchNextLetter(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_UpdateLetters(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateBmpOamSys(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteBmpOamSys(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetBlitCount(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_BlitNextLetter(FieldPlaceName *placeName);
int FIELD_PLACE_NAME_IsAllBlitted(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_RequestForceShow(FieldPlaceName *placeName);
FieldPlaceName *FIELD_PLACE_NAME_ClearForceShowRequest(FieldPlaceName *placeName);
u32 FIELD_PLACE_NAME_GetZoneChangeRequest(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetZoneChangeRequest(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ClearZoneChangeRequest(FieldPlaceName *placeName);
u32 FIELD_PLACE_NAME_GetForceShowRequest(FieldPlaceName *placeName);
int FIELD_PLACE_NAME_HasPlaceNameChanged(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_LoadMessage(FieldPlaceName *placeName);
int FIELD_PLACE_NAME_UsesIntrudeTemplate(FieldPlaceName *placeName, int zoneId);
void FIELD_PLACE_NAME_SetState(FieldPlaceName *placeName, int newState);
void FIELD_PLACE_NAME_Interrupt(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateIdle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StatePrepare(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateFadeIn(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateFadeInWait(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateLettersLaunch(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateLettersLand(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_StateFadeOut(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawIdle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawPrepare(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawFadeIn(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawFadeInWait(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawLettersLaunch(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawLettersLand(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DrawFadeOut(FieldPlaceName *placeName);
FieldPlaceName *FIELD_PLACE_NAME_AllocWork(u32 heapId);
void FIELD_PLACE_NAME_InitWork(FieldPlaceName *placeName, GameSystem *gameSystem);
void FIELD_PLACE_NAME_FreeWork(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateWordSet(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateMsgData(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateMessage(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_CreateBmpWin(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteWordSet(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteMsgData(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteMessage(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_DeleteBmpWin(FieldPlaceName *placeName);
u16 FIELD_PLACE_NAME_GetHeapId(FieldPlaceName *placeName);
ArcFile *FIELD_PLACE_NAME_GetArcHandle(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetHeapId(FieldPlaceName *placeName, int heapId);
void FIELD_PLACE_NAME_SetStateRaw(FieldPlaceName *placeName, int state);
u32 FIELD_PLACE_NAME_GetState(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetFrame(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_IncrementFrame(FieldPlaceName *placeName);
u8 FIELD_PLACE_NAME_GetStep(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_ResetStep(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_IncrementStep(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_LoadZoneFromSave(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SaveZoneToSave(FieldPlaceName *placeName);
u16 FIELD_PLACE_NAME_GetZoneId(FieldPlaceName *placeName);
void FIELD_PLACE_NAME_SetZoneId(FieldPlaceName *placeName, u16 zoneId);
Strbuf *FIELD_PLACE_NAME_GetMessage(FieldPlaceName *placeName);
u8 FIELD_PLACE_NAME_GetMessageLength(FieldPlaceName *placeName);
u32 FIELD_PLACE_NAME_HasWindow(u32 zoneId);
/* END mkheaders: generated region */

#endif
