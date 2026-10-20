#ifndef GAME_OV114_NHTTP_OS_NTR_H
#define GAME_OV114_NHTTP_OS_NTR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_os_ntr.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"

int NHTTPi_createCommThread(NHTTPThreadInfo *threadInfo_p, unsigned long priority, unsigned long *stack_p);
void NHTTPi_destroyCommThread(NHTTPThreadInfo *threadInfo_p, NHTTPBgnEndInfo *bgnEndInfo_p);
void NHTTPi_idleCommThread(NHTTPThreadInfo *threadInfo_p);
void NHTTPi_kickCommThread(NHTTPThreadInfo *threadInfo_p);
void NHTTPi_CheckCurrentThread(NHTTPThreadInfo *threadInfo_p, int isCommThread);
void NHTTPi_CommThreadProc(void *arg);
/* END mkheaders: generated region */

#endif
