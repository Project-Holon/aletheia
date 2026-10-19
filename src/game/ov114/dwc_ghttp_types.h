#ifndef OV114_DWC_GHTTP_TYPES_H
#define OV114_DWC_GHTTP_TYPES_H
/* DWC wrapper over the ghttp client: request parameter list shared by dwc_ghttp and dwc_encsession. */

#include "../types.h"

typedef void (*DWCGHTTPProgressCallback)(int state, const char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param);

typedef void (*DWCGHTTPCompletedCallback)(char *buffer, int bufferLen, int result, void *param);

typedef struct DWCGHTTPParam {
    void *param;
    DWCGHTTPCompletedCallback completedCallback;
    DWCGHTTPProgressCallback progressCallback;
    void (*postCallback)(int, int, int, int, void *);
    int bufferClear;
} DWCGHTTPParam;

typedef struct DWCGHTTPParamEntry {
    DWCGHTTPParam param;
    char *buffer;
    int request;
    struct DWCGHTTPParamEntry *next;
} DWCGHTTPParamEntry;

typedef struct DWCGHTTPParamList {
    int initCount;
    DWCGHTTPParamEntry *head;
} DWCGHTTPParamList;

extern DWCGHTTPParamList gDwcGhttpParamList;

#endif
