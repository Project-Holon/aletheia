#ifndef GAME_OV009_DWC_HTTP_H
#define GAME_OV009_DWC_HTTP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_http.c, prototypes copied from their definitions. */

struct DWCHttpParseResult;
typedef struct DWCHttpParseResult DWCHttpParseResult;

#include "../ov009/dwc_http_types.h"
#include "../sdk_dwc.h"
#include "../types.h"
#include "../ov009/cps_ssl_types.h"

int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param);
int DWC_Http_FinishHeader(char *http);
void DWC_Http_StartThread(char *http, unsigned long prio);
void DWC_Http_Abort(char *http);
u32 DWCi_Http_Resolve(const char *p);
int DWCi_Http_CheckHeaderReceived(char *http);
void DWCi_Http_Thread(void *arg);
void DWC_Http_Destroy(char *http);
int DWCi_Http_WriteBasicHeader(char *http);
int DWC_Http_Add_HeaderItem(char *http, char *label, char *data);
int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len);
int DWC_Http_Add_Body(char *http, char *data);
int DWCi_Http_CPSCallback(int result, CPSSslConnection *con, int level);
int DWCi_Http_SetHostinfo(DWCHttp *http, char *url);
int DWCi_Http_AddResult(DWCHttp *http, DWCHttpParseResult *result, char *label, char *value);
int DWC_Http_ParseResult(DWCHttp *http, int noparsebody);
char *DWC_Http_GetResult(char *http, char *label);
int DWC_Http_GetBase64DecodedResult(char *http, char *label, char *buffer, unsigned long buffer_len);
int DWC_Http_GetRawResult(char *http, char *label, char *buffer, int buffer_len);
/* END mkheaders: generated region */

#endif
