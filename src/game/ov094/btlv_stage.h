#ifndef GAME_OV094_BTLV_STAGE_H
#define GAME_OV094_BTLV_STAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_stage.c, prototypes copied from their definitions. */

#include "../ov094/btlv_stage_shared_types.h"
#include "../types.h"

BtlvStage *BTLV_STAGE_Create(int mode, int group, int variant, u16 heap);
void BTLV_STAGE_Delete(BtlvStage *stage);
void BTLV_STAGE_UpdateLayerAnims(BtlvStage *stage);
void BTLV_STAGE_DrawLayers(BtlvStage *stage);
void BTLV_STAGE_StartTint(BtlvStage *stage, unsigned char startLevel, unsigned char targetLevel, unsigned char interval, unsigned short color);
int BTLV_STAGE_IsTintActive(BtlvStage *stage);
void BTLV_STAGE_SetLayerHidden(BtlvStage *stage, u32 side, u32 hide);
void BTLV_STAGE_ArmLayerEntry(BtlvStage *stage, int side, int anim, int speed, int updates);
int BTLV_STAGE_IsAnyLayerArmed(BtlvStage *stage);
/* END mkheaders: generated region */

#endif
