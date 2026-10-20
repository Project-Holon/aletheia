#ifndef GAME_ARM9_APP_ENV_H
#define GAME_ARM9_APP_ENV_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of app_env.c, prototypes copied from their definitions. */

#include "../types.h"

u32 APP_ENV_IsRunOnTwl(void);
int APP_ENV_HasParentalControlBits(void);
BOOL APP_ENV_IsWirelessAvailable(void);
u32 APP_ENV_IsEulaAgreed(void);
void APP_ENV_GetOwnerColorAndBirthMonth(u8 *outBirthMonth, u8 *outBirthDay);
/* END mkheaders: generated region */

#endif
