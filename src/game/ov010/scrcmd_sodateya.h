#ifndef GAME_OV010_SCRCMD_SODATEYA_H
#define GAME_OV010_SCRCMD_SODATEYA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_sodateya.c, prototypes copied from their definitions. */

struct DaycareEventWork;
typedef struct DaycareEventWork DaycareEventWork;

#include "../types.h"

int SCRCMD_SODATEYA_RunPartyMenuEvent(void *event, u32 *seq, DaycareEventWork *work);
void *SCRCMD_SODATEYA_Create(void *gameSystem, void *fieldMap, u16 *resultVar);
/* END mkheaders: generated region */

#endif
