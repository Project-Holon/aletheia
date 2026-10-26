#ifndef GAME_OV194_PROF_WORD_H
#define GAME_OV194_PROF_WORD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of prof_word.c, prototypes copied from their definitions. */

struct ProfWordResources;
typedef struct ProfWordResources Resources;

#include "../types.h"

Resources *PROF_WORD_Create(unsigned short heap);
void PROF_WORD_Delete(Resources *p);
int PROF_WORD_FindMatch(const Resources *cache,const void *input,u16 heap);
int PROF_WORD_CompareChunks(const u16 *a, u32 b, u32 c, const u16 *d, u32 n);
int PROF_WORD_MatchWord(const u16 *a,const u16 *b);
int PROF_WORD_CheckDigitCount(void *src, int n, int unused);
/* END mkheaders: generated region */

#endif
