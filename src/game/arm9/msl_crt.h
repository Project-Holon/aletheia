#ifndef GAME_ARM9_MSL_CRT_H
#define GAME_ARM9_MSL_CRT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_crt.c, prototypes copied from their definitions. */

#include "../types.h"

void MSL_C_LIB_EmptyStub(int tag, u32 data, BOOL err);
void MSL_C_LIB_TwlCall1(void *ctx);
void MSL_C_LIB_TwlCall3(void *ctx, const void *data, u32 len);
void MSL_C_LIB_TwlCall2(void *ctx, void *digest);
void MSL_C_LIB_TwlCall5(u8 *digest, void *data, u32 dataLen, void *key, u32 keyLen);
void MSL_C_LIB_SetTwlFlag(int x);
u32 MSL_C_LIB_LockRegisterDestructor(u32 arg);
double nan(const char *tagp);
void *MSL_C_LIB_AllocAllFromHeap(u32 size);
void MSL_C_LIB_FreeToHeap(void *ptr);
u32 MSL_C_LIB_PrependResourceSet(void *resSet);
void *MSL_C_LIB_AllocFromHeap(u32 size);
void CRT_Free(void *ptr);
void *MSL_C_LIB_ReallocResource(void *resSet, u32 size);
void *MSL_C_LIB_Calloc(u32 count, u32 elem_size);
int MSL_C_LIB_FlushAllGated(void);
int MSL_C_LIB_FlushAll(void);
int abs(int value);
void MSL_C_LIB_NopBufferHookA(void *a, void *b);
void MSL_C_LIB_NopBufferHookB(void *a, void *b);
/* END mkheaders: generated region */

#endif
