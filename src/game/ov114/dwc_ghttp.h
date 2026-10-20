#ifndef GAME_OV114_DWC_GHTTP_H
#define GAME_OV114_DWC_GHTTP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_ghttp.c, prototypes copied from their definitions. */

#include "../ov114/dwc_ghttp_types.h"
#include "../ov114/dwc_ghttp_types.h"
#include "../ov114/ghttp_types.h"
#include "../types.h"

int DWC_GHTTPSetRootCAList(char *url);
int DWC_GHTTPCleanupRootCAList(char *url);
int DWC_InitGHTTP(void *theParam);
int DWC_ShutdownGHTTP(void);
int DWC_ProcessGHTTP(void);
int GHTTPCompletedCallback(int request, int result, char *buffer, int bufferLen, void *param);
void GHTTPProgressCallback(int request, int state, const char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param);
int DWC_GetGHTTPDataEx(char *url, int bufferLen, int bufferClear, DWCGHTTPProgressCallback progressCallback, DWCGHTTPCompletedCallback completedCallback, void *param);
int DWCi_GHTTPGetEx(char *url, int bufferLen, int bufferClear, GHIPost **post, DWCGHTTPProgressCallback progressCallback, DWCGHTTPCompletedCallback completedCallback, void *param);
void DWC_CancelGHTTPRequest(int request);
int DWCi_HandleGHTTPError(int result);
DWCGHTTPParamEntry *DWCi_AppendDWCGHTTPParam(DWCGHTTPParam *param);
void DWCi_RemoveDWCGHTTPParamEntry(DWCGHTTPParamEntry *entry);
DWCGHTTPParamEntry *DWCi_FindDWCGHTTPParamEntryByReq(u32 request);
void DWCi_RemoveAllDWCGHTTPParamEntry(void);
/* END mkheaders: generated region */

#endif
