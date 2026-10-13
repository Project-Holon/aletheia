#ifndef OV114_DWC_GHTTP_TYPES_H
#define OV114_DWC_GHTTP_TYPES_H
/* DWC wrapper over the ghttp client: request parameter list shared by dwc_ghttp and dwc_encsession. */

#ifndef OV114_BASIC_TYPES
#define OV114_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#endif

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
