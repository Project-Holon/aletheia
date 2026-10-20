#ifndef GAME_OV114_NHTTP_CONTROL_H
#define GAME_OV114_NHTTP_CONTROL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_control.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"
#include "../ov114/nhttp_types.h"
#include "../types.h"

int addHdrList(NHTTPi_DATALIST **head_pp, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p);
char incAscii(u8 c);
int checkTagPost(NHTTPReq *req_p, char *value_p, unsigned long length);
NHTTPi_DATALIST *NHTTPi_getHdrFromList(NHTTPi_DATALIST **head_pp);
int NHTTPi_AddRequestHeaderField(NHTTPReq *req_p, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p);
int NHTTPi_AddRequestPostDataAscii(NHTTPReq *req_p, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p);
/* END mkheaders: generated region */

#endif
