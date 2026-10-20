#ifndef GAME_OV114_NHTTP_BGNEND_H
#define GAME_OV114_NHTTP_BGNEND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_bgnend.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"
#include "../types.h"

void NHTTPi_InitBgnEndInfo(NHTTPBgnEndInfo *info_p);
void *NHTTPi_alloc(unsigned long size, int align);
void NHTTPi_free(void *ptr_p);
void NHTTPi_SetError(NHTTPBgnEndInfo *bgnEndInfo_p, int error);
void NHTTPi_SetSSLError(NHTTPBgnEndInfo *bgnEndInfo_p, int sslError);
u32 NHTTPi_GetSSLError(NHTTPBgnEndInfo *bgnEndInfo_p);
int NHTTPi_Startup(NHTTPSysInfo *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio);
void NHTTPi_CleanupAsync(NHTTPSysInfo *sysInfo_p, void (*callback)(void));
u32 NHTTPi_GetError(NHTTPBgnEndInfo *bgnEndInfo_p);
/* END mkheaders: generated region */

#endif
