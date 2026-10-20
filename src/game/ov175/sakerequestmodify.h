#ifndef GAME_OV175_SAKEREQUESTMODIFY_H
#define GAME_OV175_SAKEREQUESTMODIFY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sakerequestmodify.c, prototypes copied from their definitions. */

#include "../ov175/sake_types.h"

int sakeiValidateRequestFields(SAKEField *fields, int numFields);
void sakeiFillSoapRequestFieldValues(SAKERequestInternal *request, SAKEField *fields, int numFields);
int sakeiCreateRecordValidateInput(SAKERequestInternal *request);
int sakeiCreateRecordFillSoapRequest(SAKERequestInternal *request);
int sakeiCreateRecordProcessSoapResponse(SAKERequestInternal *request);
int sakeiStartCreateRecordRequest(SAKERequestInternal *request);
int sakeiUpdateRecordValidateInput(SAKERequestInternal *request);
int sakeiUpdateRecordFillSoapRequest(SAKERequestInternal *request);
int sakeiStartUpdateRecordRequest(SAKERequestInternal *request);
int sakeiDeleteRecordValidateInput(SAKERequestInternal *request);
int sakeiDeleteRecordFillSoapRequest(SAKERequestInternal *request);
/* END mkheaders: generated region */

#endif
