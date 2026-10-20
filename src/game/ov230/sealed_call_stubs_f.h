#ifndef GAME_OV230_SEALED_CALL_STUBS_F_H
#define GAME_OV230_SEALED_CALL_STUBS_F_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sealed_call_stubs_f.c, prototypes copied from their definitions. */

#include "../types.h"

u32 OV230_CallSealedBody16(void (*caller)(void), void (*target)(void), u32 arg);
u32 OV230_CallSealedBody17(void (*caller)(void), void (*target)(void), u32 arg);
void LOADER_ENTRY_DecryptCallStubs2(void);
/* END mkheaders: generated region */

#endif
