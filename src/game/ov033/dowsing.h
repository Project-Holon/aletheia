#ifndef GAME_OV033_DOWSING_H
#define GAME_OV033_DOWSING_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dowsing.c, prototypes copied from their definitions. */

#include "../ov033/dowsing_types.h"
#include "../types.h"
#include "../ov021/field_subscreen_types.h"

struct TcbTask;

DowsingSearch *DOWSING_CreateSearch(u32 heapId, void *eventFlags, void *eventData);
void DOWSING_DeleteSearch(DowsingSearch *search);
int DOWSING_IsTargetAvailable(DowsingSearch *search, DowsingTarget *target);
void DOWSING_ResetSearch(DowsingSearch *search);
int DOWSING_FindNextTarget(DowsingSearch *search, DowsingTarget *out, int mode);
DowsingWork *DOWSING_Create(u32 heapId, u32 ownerHeapId, FieldSubscreen *subscreen, void *fieldMap);
void DOWSING_Delete(DowsingWork *work);
void DOWSING_Update(DowsingWork *work, int isOn);
void DOWSING_UpdateDisplay(DowsingWork *work, int draw);
void DOWSING_TaskTransferPalettes(struct TcbTask *task, void *taskWork);
void DOWSING_InitBgsAndActorUnit(DowsingWork *work);
void DOWSING_ExitBgsAndActorUnit(DowsingWork *work);
void DOWSING_LoadBackground(DowsingWork *work);
void DOWSING_FreeBackground(DowsingWork *work);
void DOWSING_CreateParts(DowsingWork *work);
void DOWSING_DeleteParts(DowsingWork *work);
void DOWSING_CreateCloseButton(DowsingWork *work);
void DOWSING_DeleteCloseButton(DowsingWork *work);
void DOWSING_UpdateCloseButton(DowsingWork *work);
void DOWSING_InitFade(DowsingWork *work);
void DOWSING_ExitFade(DowsingWork *work);
void DOWSING_UpdateFade(DowsingWork *work);
/* END mkheaders: generated region */

#endif
