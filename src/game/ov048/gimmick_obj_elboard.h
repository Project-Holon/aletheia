#ifndef GAME_OV048_GIMMICK_OBJ_ELBOARD_H
#define GAME_OV048_GIMMICK_OBJ_ELBOARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gimmick_obj_elboard.c, prototypes copied from their definitions. */

struct ElboardMessage;
struct ElboardHighlights;
struct ScriptContext;
struct ScrCmdWork;
struct GimmickObjElboard;
struct ElboardConfig;
struct ElboardLine;
struct GameEvent;
struct GameSystem;
struct FieldMap;
typedef struct ElboardMessage ElboardMessage;
typedef struct ElboardHighlights ElboardHighlights;
typedef struct GimmickObjElboard GimmickObjElboard;
typedef struct ElboardConfig ElboardConfig;
typedef struct ElboardLine ElboardLine;

#include "../ov048/field_gimmick_gate_types.h"
#include "../ov048/field_gimmick_gate_types.h"
#include "../types.h"

void GIMMICK_OBJ_ELBOARD_AddMessage(GateWork *work, ElboardMessage *msg, int kind, GateNewsEntry *entry);
void GIMMICK_OBJ_ELBOARD_FillMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_FillDefaultMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_FillSavedListMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_FillNoticeMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddDateMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddPlaceListMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddDailyMessage1(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddDailyMessage2(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddDailyMessage3(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddWeekdayMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddNoticeMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddNoticeMessage(GateWork *work, GateNewsEntry *entry, int lane);
void GIMMICK_OBJ_ELBOARD_AddNoticeList(GateWork *work);
int GIMMICK_OBJ_ELBOARD_CountHighlights(ElboardHighlights *highlights);
void GIMMICK_OBJ_ELBOARD_ClearHighlights(ElboardHighlights *highlights);
void GIMMICK_OBJ_ELBOARD_CollectHighlights(GateWork *work, ElboardHighlights *out);
void GIMMICK_OBJ_ELBOARD_CollectTableHighlights(GateWork *work, ElboardHighlights *out);
void GIMMICK_OBJ_ELBOARD_CollectGPowerHighlight(GateWork *work, ElboardHighlights *out);
int GIMMICK_OBJ_ELBOARD_CmdStartCameraEvent(struct ScriptContext *ctx, struct ScrCmdWork *cmdWork);
GimmickObjElboard *GIMMICK_OBJ_ELBOARD_Create(ElboardConfig *config);
void GIMMICK_OBJ_ELBOARD_AddLine(GimmickObjElboard *board, const ElboardMessage *msg);
void GIMMICK_OBJ_ELBOARD_Delete(GimmickObjElboard *board);
void GIMMICK_OBJ_ELBOARD_Advance(GimmickObjElboard *board, int step);
int GIMMICK_OBJ_ELBOARD_GetScroll(GimmickObjElboard *board);
u16 GIMMICK_OBJ_ELBOARD_GetHeapId(GimmickObjElboard *board);
int GIMMICK_OBJ_ELBOARD_GetLineCount(GimmickObjElboard *board);
void GIMMICK_OBJ_ELBOARD_SetScroll(GimmickObjElboard *board, int scroll);
ElboardLine *GIMMICK_OBJ_ELBOARD_CreateLine(GimmickObjElboard *board, const ElboardMessage *msg, int lineIndex);
void GIMMICK_OBJ_ELBOARD_DeleteLine(ElboardLine *line);
void GIMMICK_OBJ_ELBOARD_StartLine(ElboardLine *line);
void GIMMICK_OBJ_ELBOARD_UpdateLine(GimmickObjElboard *board, ElboardLine *line, int step);
void GIMMICK_OBJ_ELBOARD_StopLine(ElboardLine *line);
int GIMMICK_OBJ_ELBOARD_ReadGateInfo(void *dst, u32 archiveId, u32 memberIndex);
int GIMMICK_OBJ_ELBOARD_CameraEventMain(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *GIMMICK_OBJ_ELBOARD_CreateCameraEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int frames);
int GIMMICK_OBJ_ELBOARD_ReadGateEntry(void *dst, u32 archiveId, u32 memberIndex);
int GIMMICK_OBJ_ELBOARD_CheckEntryZone(GateNewsEntry *entry, int zoneId);
int GIMMICK_OBJ_ELBOARD_CheckEntryGPower(GateNewsEntry *entry);
/* END mkheaders: generated region */

#endif
