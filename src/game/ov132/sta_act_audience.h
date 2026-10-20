#ifndef GAME_OV132_STA_ACT_AUDIENCE_H
#define GAME_OV132_STA_ACT_AUDIENCE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_act_audience.c, prototypes copied from their definitions. */

#include "../types.h"

char *STA_ACT_AUDIENCE_Create(unsigned heap, void *scene, unsigned input);
void STA_ACT_AUDIENCE_Delete(u8 *p);
void STA_ACT_AUDIENCE_Update(char *p);
void STA_ACT_AUDIENCE_Noop(char *audience);
void STA_ACT_AUDIENCE_Noop2(void *p);
void STA_ACT_AUDIENCE_SetupRecords(char *p, char *input);
void STA_ACT_AUDIENCE_Noop3(void *audience);
void STA_ACT_AUDIENCE_UpdateRecords(char *p);
void STA_ACT_AUDIENCE_UpdateRecord(char *p,u8 *rec);
void STA_ACT_AUDIENCE_DrawRecord(char *p,u8 *rec,unsigned type);
void STA_ACT_AUDIENCE_ApplyChoices(char *p);
void STA_ACT_AUDIENCE_RandomizeRecords(char *p);
void STA_ACT_AUDIENCE_SetSlotValue(char *p, int player, int value);
void STA_ACT_AUDIENCE_SetHighlight(char *p, u8 actor);
void STA_ACT_AUDIENCE_SetBgScroll(void *unused, int scroll);
/* END mkheaders: generated region */

#endif
