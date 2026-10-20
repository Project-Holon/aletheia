#ifndef GAME_OV230_SEALED_BODY_H
#define GAME_OV230_SEALED_BODY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sealed_body.c, prototypes copied from their definitions. */

#include "../types.h"

u8 *OV230_OpenSealedBody(u32 seed, u32 body, u32 end);
u32 OV230_SealBody(u32 seed, u32 body, u32 end);
u32 OV230_CallDispatcher(void);
void LOADER_ENTRY_DecryptCallDispatch(void);
/* END mkheaders: generated region */

#endif
