/* Work area of the Game Sync download module (gsync_download.c). One instance, 0xD4 bytes. */
#ifndef GSYNC_DOWNLOAD_TYPES_H
#define GSYNC_DOWNLOAD_TYPES_H

#include "../ov114/dwci_nd_types.h"

typedef struct GsyncDownloadWork {
    DWCNdFileInfo fileInfo;     /* 0x00, filled by DWC_NdGetFileListAsync (one entry) */
    int requestDone;            /* 0xB0, set by the nd callback, cleared before each request */
    unsigned int callbackResult;/* 0xB4, error code the nd callback reported (0 = ok) */
    void *fileBuffer;           /* 0xB8, receives the downloaded file */
    int fileBufferSize;         /* 0xBC, size asked for by the caller (buffer holds 0x40 more) */
    unsigned int unused_C0;     /* 0xC0, never accessed */
    int cleanupStarted;         /* 0xC4, nd cleanup was requested */
    int errorFlag;              /* 0xC8, fatal callback error or failed cancel */
    int timeoutFrames;          /* 0xCC, frames since the request started, 0 = no request */
    int timedOut;               /* 0xD0, request exceeded 3600 frames */
} GsyncDownloadWork;

#endif
