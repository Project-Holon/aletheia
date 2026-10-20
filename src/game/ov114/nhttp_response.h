#ifndef GAME_OV114_NHTTP_RESPONSE_H
#define GAME_OV114_NHTTP_RESPONSE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_response.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"
#include "../ov114/nhttp_types.h"

void NHTTPi_DestroyResponse(NHTTPMutexInfo *mutexInfo_p, NHTTPRes *res_p);
int NHTTPi_getHeaderValue(const NHTTPRes *res_p, char *label_p, int *pos_p);
int NHTTP_GetResponseHeaderField(NHTTPRes *res_p, char *label_p, char **value_pp);
int NHTTPi_GetResponseHeaderAll(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPRes *res_p, char **value_pp);
void NHTTPi_InitThreadInfo(NHTTPThreadInfo *threadInfo_p);
/* END mkheaders: generated region */

#endif
