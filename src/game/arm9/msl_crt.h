#ifndef GAME_ARM9_MSL_CRT_H
#define GAME_ARM9_MSL_CRT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_crt.c, prototypes copied from their definitions. */

#include "../types.h"

void MSL_C_LIB_EmptyStub(void);
void MSL_C_LIB_TwlCall1(u32 ctx);
void MSL_C_LIB_TwlCall3(u32 ctx, u32 data, u32 len);
void MSL_C_LIB_TwlCall2(u32 ctx, u32 digest);
void MSL_C_LIB_TwlCall5(u32 digest, u32 data, u32 dataLen, u32 key, u32 keyLen);
void MSL_C_LIB_SetTwlFlag(int x);
u32 MSL_C_LIB_LockRegisterDestructor(u32 arg);
double nan(const char *tagp);
void *MSL_C_LIB_AllocAllFromHeap(u32 heap);
void MSL_C_LIB_FreeToHeap(u32 heap);
u32 MSL_C_LIB_PrependResourceSet(void *resSet);
void *MSL_C_LIB_AllocFromHeap(u32 heap);
void CRT_Free(u32 heap);
void *MSL_C_LIB_ReallocResource(u32 resSet, u32 heap);
void *MSL_C_LIB_Calloc(u32 count, u32 elem_size);
int MSL_C_LIB_FlushAllGated(void);
int MSL_C_LIB_FlushAll(void);
int abs(int value);
void MSL_C_LIB_NopBufferHookA(int a, void *b);
void MSL_C_LIB_NopBufferHookB(int a, void *b);
/* END mkheaders: generated region */

#endif
