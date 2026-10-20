#ifndef GAME_OV175_SAKEREQUESTREAD_H
#define GAME_OV175_SAKEREQUESTREAD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sakerequestread.c, prototypes copied from their definitions. */

#include "../ov175/sake_types.h"

int sakeiValidateRequestFieldNames(char **fieldNames, int numFields);
void sakeiFillSoapRequestFieldNames(SAKERequestInternal *request, char **fieldNames, int numFields);
void sakeiFillSoapRequestRecordIds(SAKERequestInternal *request, int *recordIds, int numRecordIds);
void sakeiFillSoapRequestOwnerIds(SAKERequestInternal *request, int *ownerIds, int numOwnerIds);
int sakeiReadOutputRecords(SAKERequestInternal *request, SAKEField ***outputRecordsPtr, int *numRecords, int numFields, char **fieldNames);
void sakeiFreeOutputRecord(int numFields, SAKEField *record);
void sakeiFreeOutputRecords(int numFields, int numRecords, SAKEField **records);
int sakeiSearchForRecordsValidateInput(SAKERequestInternal *request);
int sakeiSearchForRecordsFillSoapRequest(SAKERequestInternal *request);
int sakeiSearchForRecordsProcessSoapResponse(SAKERequestInternal *request);
void sakeiSearchForRecordsFreeData(SAKERequestInternal *request);
int sakeiGetMyRecordsValidateInput(SAKERequestInternal *request);
int sakeiGetMyRecordsFillSoapRequest(SAKERequestInternal *request);
int sakeiGetMyRecordsProcessSoapResponse(SAKERequestInternal *request);
void sakeiGetMyRecordsFreeData(SAKERequestInternal *request);
int sakeiStartGetMyRecordsRequest(SAKERequestInternal *request);
int sakeiGetSpecificRecordsValidateInput(SAKERequestInternal *request);
int sakeiGetSpecificRecordsFillSoapRequest(SAKERequestInternal *request);
int sakeiGetSpecificRecordsProcessSoapResponse(SAKERequestInternal *request);
void sakeiGetSpecificRecordsFreeData(SAKERequestInternal *request);
int sakeiStartGetSpecificRecordsRequest(SAKERequestInternal *request);
int sakeiGetRandomRecordValidateInput(SAKERequestInternal *request);
int sakeiGetRandomRecordFillSoapRequest(SAKERequestInternal *request);
int sakeiGetRandomRecordProcessSoapResponse(SAKERequestInternal *request);
void sakeiGetRandomRecordFreeData(SAKERequestInternal *request);
/* END mkheaders: generated region */

#endif
