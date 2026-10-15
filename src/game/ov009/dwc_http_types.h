#ifndef OV009_DWC_HTTP_TYPES_H
#define OV009_DWC_HTTP_TYPES_H
/*
 * Shared DWC HTTP types for ov009 (dwc_http, dwc_auth and the other
 * callers of DWC_Http_Create). One definition per object; offsets checked
 * against every view the parts had.
 */

/* Parameter block handed to DWC_Http_Create (g_021A2358 and its sibling
 * gDwcHttpParamArg). Field offsets: url 0x00, action 0x04, len_recvbuf 0x08,
 * alloc 0x0c, free 0x10, ignoreca 0x14, timeout 0x18. */
typedef struct DWCHttpParam {
    char *url;
    int action;
    unsigned long len_recvbuf;
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    int ignoreca;
    int timeout;
} DWCHttpParam;

#endif
