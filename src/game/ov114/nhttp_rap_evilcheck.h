#ifndef GAME_OV114_NHTTP_RAP_EVILCHECK_H
#define GAME_OV114_NHTTP_RAP_EVILCHECK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_rap_evilcheck.c, prototypes copied from their definitions. */

struct MyStatus;

#include "../types.h"
#include "../ov114/nhttp_rap_types.h"

u8 *NHTTP_RAP_EvilCheckAllocArray(int elemSize, int count, int heapId);
void NHTTP_RAP_EvilCheckFreeArray(void *buf);
void NHTTP_RAP_EvilCheckSetElement(u8 *base_p, const void *src_p, u32 elemSize, int index);
void *NHTTP_RAP_EvilCheckCryptoAlloc(unsigned long size);
void NHTTP_RAP_EvilCheckCryptoFree(void *block);
void NHTTP_RAP_InitTrainerInfo(NHTTPRapTrainerInfo *info_p, const struct MyStatus *mystatus_p);
void NHTTPi_InitMutex(int *mutex_p);
void NHTTPi_LockMutexThunk(int *mutex_p);
/* END mkheaders: generated region */

#endif
