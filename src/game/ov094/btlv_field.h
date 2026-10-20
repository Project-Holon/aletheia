#ifndef GAME_OV094_BTLV_FIELD_H
#define GAME_OV094_BTLV_FIELD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_field.c, prototypes copied from their definitions. */

#include "../ov094/btlv_field_shared_types.h"
#include "../types.h"

BtlvField *BTLV_FIELD_Create(int unused, int group, u8 variant, u16 heap);
void BTLV_FIELD_Delete(BtlvField *field);
void BTLV_FIELD_UpdateAnims(BtlvField *field);
void BTLV_FIELD_Draw(BtlvField *field);
void BTLV_FIELD_StartTint(BtlvField *field, unsigned char startLevel, unsigned char targetLevel, unsigned char interval, unsigned short color);
int BTLV_FIELD_IsTintActive(BtlvField *field);
void BTLV_FIELD_SetHidden(BtlvField *field, u32 hide);
/* END mkheaders: generated region */

#endif
