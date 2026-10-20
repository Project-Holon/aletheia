#ifndef GAME_OV009_GSPLATFORMTHREAD_H
#define GAME_OV009_GSPLATFORMTHREAD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsplatformthread.c, prototypes copied from their definitions. */

unsigned int gsiInterlockedIncrement(unsigned int *value);
unsigned int gsiInterlockedDecrement(unsigned int *value);
void gsiInitializeCriticalSection(void *criticalSection);
void gsiEnterCriticalSection(void *criticalSection);
void gsiLeaveCriticalSection(void *criticalSection);
void gsiDeleteCriticalSection(void *criticalSection);
long long gsiStringToInt64(const char *string);
/* END mkheaders: generated region */

#endif
