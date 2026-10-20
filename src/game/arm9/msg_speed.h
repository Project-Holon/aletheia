#ifndef GAME_ARM9_MSG_SPEED_H
#define GAME_ARM9_MSG_SPEED_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msg_speed.c, prototypes copied from their definitions. */

struct SaveControl;

#include "../types.h"

void MSG_SPEED_SetSaveControl(struct SaveControl *save);
signed char MSG_SPEED_GetWait(void);
signed char MSG_SPEED_GetSlowerWait(void);
signed char MSG_SPEED_GetFasterWait(void);
signed char MSG_SPEED_GetWaitForSpeed(u32 speed);
/* END mkheaders: generated region */

#endif
