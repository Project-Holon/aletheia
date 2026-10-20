#ifndef OV009_DWC_HTTP_TYPES_H
#define OV009_DWC_HTTP_TYPES_H
/*
 * Shared DWC HTTP types for ov009 (dwc_http, dwc_auth and the other
 * callers of DWC_Http_Create). One definition per object; offsets checked
 * against every view the parts had.
 */

/* Parameter block handed to DWC_Http_Create (gDwcHttpParamArg and its sibling
 * gDwcHttpParamArg). Field offsets: url 0x00, action 0x04, len_recvbuf 0x08,
 * alloc 0x0c, free 0x10, ignoreca 0x14, timeout 0x18. */
#include "../sdk_dwc.h"
#include "../sdk_os.h"
#include "../ov009/cps_ssl_types.h"

/* One DWC HTTP connection object. */
typedef struct DWCHttp {
    unsigned char stack[0x1000];        /* 0x0000 */
    unsigned char initflag;             /* 0x1000 */
    DWCHttpParam param;                 /* 0x1004 */
    int error;                          /* 0x1020 */
    char url[256];                      /* 0x1024 */
    char *hostname;                     /* 0x1124 */
    char *filepath;                     /* 0x1128 */
    unsigned long hostip;               /* 0x112c */
    int ssl_enabled;                    /* 0x1130 */
    unsigned short port;                /* 0x1134 */
    CPSSoc soc;                         /* 0x1138 */
    CPSSslConnection con;               /* 0x11d8 */
    unsigned char *lowrecvbuf;          /* 0x1a08 */
    unsigned char *lowsendbuf;          /* 0x1a0c */
    unsigned long lowentropydata[8];    /* 0x1a10 */
    int num_postitem;                   /* 0x1a30 */
    DWCHttpBuffer req;                  /* 0x1a34 */
    DWCHttpBuffer rep;                  /* 0x1a44 */
    OSMutex content_len_mutex;          /* 0x1a54 */
    int content_len;                    /* 0x1a6c */
    int receivedbody_len;               /* 0x1a70 */
    DWCHttpLabelValue labelvalue[32];   /* 0x1a74 */
    OSThread thread;                    /* 0x1b74 */
    OSMutex mutex;                      /* 0x1c34 */
    int abort;                          /* 0x1c4c */
} DWCHttp;

#endif
