#ifndef GAME_OV021_FIELD_FLASH_H
#define GAME_OV021_FIELD_FLASH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_flash.c, prototypes copied from their definitions. */

#include "../ov021/field_flash_shared_types.h"
#include "../types.h"

FieldFlash *FIELD_FLASH_Create(u32 heapId);
void FIELD_FLASH_Delete(FieldFlash *flash);
void FIELD_FLASH_Update(FieldFlash *flash);
void FIELD_FLASH_Apply(FieldFlash *flash);
void FIELD_FLASH_SetPendingCommand(FieldFlash *flash, u16 command);
u16 FIELD_FLASH_GetState(FieldFlash *flash);
void FIELD_FLASH_InitTween(FlashTween *tween);
void FIELD_FLASH_ClearTween(FlashTween *tween);
FlashTween *FIELD_FLASH_StartTween(FlashTween *tween, fx32 sizeStart, fx32 sizeEnd, u32 alphaStart, u8 alphaEnd, u32 frames);
int FIELD_FLASH_StepTween(FlashTween *tween);
u32 FIELD_FLASH_GetTweenSize(FlashTween *tween);
void FIELD_FLASH_SetTweenSize(FlashTween *tween, fx32 size);
u8 FIELD_FLASH_GetTweenAlpha(FlashTween *tween);
FlashTween *FIELD_FLASH_SetTweenAlpha(FlashTween *tween, u8 alpha);
void FIELD_FLASH_CmdInit(FieldFlash *flash);
void FIELD_FLASH_CmdExpand(FieldFlash *flash);
void FIELD_FLASH_ShowExpanded(FieldFlash *flash);
void FIELD_FLASH_HideMask(FieldFlash *flash);
/* END mkheaders: generated region */

#endif
