#ifndef GAME_OV114_NHTTP_LIST_H
#define GAME_OV114_NHTTP_LIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_list.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"

void NHTTPi_InitListInfo(NHTTPListInfo *listInfo_p);
int NHTTPi_setReqQueue(NHTTPListInfo *listInfo_p, NHTTPReq *req_p);
NHTTPi_REQLIST *NHTTPi_findReqQueue(NHTTPListInfo *listInfo_p, int id);
int NHTTPi_freeReqQueue(NHTTPListInfo *listInfo_p, NHTTPMutexInfo *mutexInfo_p, int id);
void NHTTPi_allFreeReqQueue(NHTTPListInfo *listInfo_p, NHTTPMutexInfo *mutexInfo_p);
NHTTPi_REQLIST *NHTTPi_popReqQueue(NHTTPListInfo *listInfo_p);
/* END mkheaders: generated region */

#endif
