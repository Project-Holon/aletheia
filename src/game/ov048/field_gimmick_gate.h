#ifndef GAME_OV048_FIELD_GIMMICK_GATE_H
#define GAME_OV048_FIELD_GIMMICK_GATE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_gate.c, prototypes copied from their definitions. */

#include "../ov021/fieldmap_types.h"
#include "../types.h"
#include "../ov048/field_gimmick_gate_types.h"

void FIELD_GIMMICK_GATE_Init(FieldMap *fieldMap);
void FIELD_GIMMICK_GATE_Exit(FieldMap *fieldMap);
void FIELD_GIMMICK_GATE_Update(FieldMap *fieldMap);
u8 FIELD_GIMMICK_GATE_GetBoardFacing(FieldMap *fieldMap);
GateSave *FIELD_GIMMICK_GATE_GetSave(FieldMap *fieldMap);
void FIELD_GIMMICK_GATE_SaveState(GateWork *work);
void FIELD_GIMMICK_GATE_LoadState(GateWork *work);
void FIELD_GIMMICK_GATE_StoreGatePoints(GateWork *work);
void FIELD_GIMMICK_GATE_RestoreLoggedFlags(GateWork *work);
void FIELD_GIMMICK_GATE_ApplyBoardScroll(GateWork *work);
GateWork *FIELD_GIMMICK_GATE_CreateWork(FieldMap *fieldMap);
void FIELD_GIMMICK_GATE_DeleteWork(GateWork *work);
void FIELD_GIMMICK_GATE_InitGatePoints(GateWork *work);
void FIELD_GIMMICK_GATE_LoadBoardRecord(GateWork *work);
void FIELD_GIMMICK_GATE_FreeBoardRecord(GateWork *work);
void FIELD_GIMMICK_GATE_StartBoardAnime(GateWork *work);
void FIELD_GIMMICK_GATE_PlaceBoardModel(GateWork *work);
void FIELD_GIMMICK_GATE_LogMessage(GateWork *work, int messageType, int flagId);
int FIELD_GIMMICK_GATE_HasMessagesToShow(GateWork *work);
int FIELD_GIMMICK_GATE_IsSaveBlockListOn(GateWork *work);
int FIELD_GIMMICK_GATE_IsExtraSaveListOn(GateWork *work);
void FIELD_GIMMICK_GATE_ReadExtraSaveValues(const GateWork *work, u32 *values, int *count);
void FIELD_GIMMICK_GATE_ReadSaveBlockValues(GateWork *work, u32 *values, int *count);
void FIELD_GIMMICK_GATE_LoadNewsList(GateWork *work);
void FIELD_GIMMICK_GATE_FreeNewsList(GateWork *work);
GateNewsEntry *FIELD_GIMMICK_GATE_FindNewsEntry(GateWork *work);
GateNewsEntry *FIELD_GIMMICK_GATE_FindListNewsEntry(GateWork *work);
/* END mkheaders: generated region */

#endif
