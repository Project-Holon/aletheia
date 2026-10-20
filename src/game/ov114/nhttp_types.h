#ifndef OV114_NHTTP_TYPES_H
#define OV114_NHTTP_TYPES_H
/*
 * Shared NHTTP types for ov114. One definition per type; every part that
 * uses one of these includes this header.
 */

#include "../types.h"
#include "../sdk_os.h"

/* Opaque SDK objects. */

typedef struct _NHTTPSslCon NHTTPSslCon;
typedef struct _NHTTPReq NHTTPReq;
typedef struct _NHTTPRes NHTTPRes;
typedef struct _NHTTPConnection NHTTPConnection;
typedef struct _NHTTPi_REQLIST NHTTPi_REQLIST;
typedef struct _NHTTPi_HDRBUFLIST NHTTPi_HDRBUFLIST;

typedef char *(*NHTTPBufFullFn)(char **, unsigned long *, unsigned long,
                                void *(*)(unsigned long, int),
                                void (*)(void *), void *);
typedef void (*NHTTPFreeBufFn)(char *, void (*)(void *), void *);

/* Post data and header list node (size 0x18); the list is circular and
 * doubly linked, the list pointer is the first node and its prev is the
 * node added last. */
typedef struct _NHTTPi_DATALIST {
    struct _NHTTPi_DATALIST *prev;      /* 0x00 */
    struct _NHTTPi_DATALIST *next;      /* 0x04 */
    char *name;                         /* 0x08 */
    char *data;                         /* 0x0c */
    unsigned long len;                  /* 0x10 */
    u32 isBinary;                       /* 0x14 */
} NHTTPi_DATALIST;

/* Extra header buffer block chained from NHTTPRes (size 0x204). */
struct _NHTTPi_HDRBUFLIST {
    struct _NHTTPi_HDRBUFLIST *next_p;
    char block[512];
};

/* SSL connection object handed to the socket library (size 0x830). */
struct _NHTTPSslCon {
    u8 pad_0[0x800];
    char *hostname_p;                   /* 0x800 */
    u8 pad_804[0xc];
    void *authCallback;                 /* 0x810 */
    void *rootCA_p;                     /* 0x814 */
    int rootCALen;                      /* 0x818 */
    u8 pad_81c[0x14];
};

/* One request (size 0x254). */
struct _NHTTPReq {
    int doCancel;                       /* 0x00 */
    int isStarted;                      /* 0x04 */
    int isSSL;                          /* 0x08 */
    int isProxy;                        /* 0x0c */
    int isRawData;                      /* 0x10 */
    int hostLen;                        /* 0x14 */
    int hostDescLen;                    /* 0x18 */
    int method;                         /* 0x1c */
    int port;                           /* 0x20 */
    char *URL_p;                        /* 0x24 */
    char *hostname_p;                   /* 0x28 */
    NHTTPRes *res_p;                    /* 0x2c */
    NHTTPi_DATALIST *hdrlist_p;         /* 0x30 */
    NHTTPi_DATALIST *datalist_p;        /* 0x34 */
    char multipartBound[0x14];          /* 0x38: "--" and the boundary */
    char basicAuth[0x5c];               /* 0x4c */
    int basicAuthLen;                   /* 0xa8 */
    NHTTPSslCon *sslCon_p;              /* 0xac */
    int sslHandshakeState;              /* 0xb0 */
    int sslRecvLen;                     /* 0xb4 */
    int sslSendLen;                     /* 0xb8 */
    int sslLastError;                   /* 0xbc */
    void *rootCA_p;                     /* 0xc0 */
    int rootCALen;                      /* 0xc4 */
    int rootCAIndex;                    /* 0xc8 */
    void *clientCert_p;                 /* 0xcc */
    int verifyOption;                   /* 0xd0 */
    int postEncoding;                   /* 0xd4 */
    int isIgnoreAuth;                   /* 0xd8: selects the debug auth callback */
    int rootCAChainLen;                   /* 0xdc */
    u8 pad_e0[4];
    char proxyAddr[256];                /* 0xe4 */
    int proxyPort;                      /* 0x1e4 */
    char proxyAuth[0x5c];               /* 0x1e8 */
    int proxyAuthLen;                   /* 0x244 */
    int postDataState;                  /* 0x248 */
    char *rawPostData_p;                /* 0x24c */
    unsigned long rawPostDataLen;       /* 0x250 */
};

/* One response (size 0x43c). */
struct _NHTTPRes {
    volatile int headerLen;             /* 0x00 */
    unsigned long bodyLen;              /* 0x04 */
    int totalBodyLen;                   /* 0x08 */
    volatile u32 contentLength;         /* 0x0c */
    int isSuccess;                      /* 0x10 */
    int isHeaderParse;                  /* 0x14 */
    int httpStatus;                     /* 0x18 */
    unsigned long recvBufLen;           /* 0x1c */
    char *allHeader_p;                  /* 0x20 */
    char *foundHeader_p;                /* 0x24 */
    char *recvBuf_p;                    /* 0x28 */
    NHTTPBufFullFn bufFull;             /* 0x2c */
    NHTTPFreeBufFn freeBuf;             /* 0x30 */
    NHTTPi_HDRBUFLIST *hdrBufBlock_p;   /* 0x34 */
    char hdrBufFirst[1024];             /* 0x38 */
    void *param_p;                      /* 0x438 */
};

/* Request queue node (size 0x14). */
struct _NHTTPi_REQLIST {
    NHTTPi_REQLIST *next;               /* 0x00 */
    NHTTPi_REQLIST *prev;               /* 0x04 */
    int id;                             /* 0x08 */
    NHTTPReq *req_p;                    /* 0x0c */
    int socket;                         /* 0x10 */
};

/* Request queue head (size 0x8): ring of NHTTPi_REQLIST plus the next id. */
typedef struct _NHTTPListInfo {
    NHTTPi_REQLIST *head;               /* 0x00 */
    volatile int nextId;                /* 0x04 */
} NHTTPListInfo;

/* Current request holder. */
typedef struct _NHTTPReqInfo {
    NHTTPi_REQLIST *reqCurrent;
} NHTTPReqInfo;

/* Socket state (size 0x28). */
typedef struct _NHTTPBgnEndInfo {
    void *(*alloc)(unsigned long, int); /* 0x00 */
    void (*free)(void *);               /* 0x04 */
    int isOpened;                       /* 0x08 */
    int socket;                         /* 0x0c */
    int sslError;                       /* 0x10 */
    int error;                          /* 0x14 */
    int isThreadEnd;                    /* 0x18 */
    unsigned long *commThreadStack;     /* 0x1c */
    int (*forDebugCallback)(void *, unsigned long); /* 0x20 */
    unsigned long defaultRootCAId;      /* 0x24 */
} NHTTPBgnEndInfo;

/* Communication thread: message queue, its three slots, the OS thread
 * and the transfer buffer (size 0x4100). */
typedef struct _NHTTPThreadInfo {
    u8 msgQueue[0x20];                  /* 0x00 */
    void *msgArray[3];                  /* 0x20 */
    OSThread commThread;                /* 0x2c */
    int isCreateCommThreadMessageQueue; /* 0xec */
    u8 pad_f0[0x10];
    char commBuf[0x4000];               /* 0x100 */
} NHTTPThreadInfo;

/* Communication thread state (size 0x340). */
typedef struct _NHTTPThreadData {
    int id;                             /* 0x000 */
    char preHostname[256];              /* 0x004 */
    char tmpBodyBuf[512];               /* 0x104 */
    char tmpHeaderBuf[14];              /* 0x304 */
    unsigned short padding;             /* 0x312 */
    u32 hostaddr;                       /* 0x314 */
    u32 preHostaddr;                    /* 0x318 */
    int port;                           /* 0x31c */
    int prePort;                        /* 0x320 */
    int sendBufwp;                      /* 0x324 */
    int recvBufwp;                      /* 0x328 */
    int contentLength;                  /* 0x32c */
    int result;                         /* 0x330 */
    int restartConnect;                 /* 0x334 */
    int isKeepAlive;                    /* 0x338 */
    int isChunked;                      /* 0x33c */
} NHTTPThreadData;

/* Connection object (size 0x804c). */
struct _NHTTPConnection {
    int status;                         /* 0x00 */
    int nhttpError;                     /* 0x04 */
    int sslError;                       /* 0x08 */
    int running;                        /* 0x0c */
    NHTTPReq *req_p;                    /* 0x10 */
    NHTTPRes *res_p;                    /* 0x14 */
    int reqId;                          /* 0x18 */
    int (*connectionCallback)(NHTTPConnection *, int, void *); /* 0x1c */
    NHTTPConnection *next_p;            /* 0x20 */
    char *postDataBuf;                  /* 0x24 */
    unsigned long postDataLen;          /* 0x28 */
    unsigned long virtualContentLength; /* 0x2c */
    void *reqCallback;                  /* 0x30 */
    u8 pad_34[0xc];
    unsigned short tmpBuf[0x4000];      /* 0x40 */
    unsigned long tmpBufOffset;         /* 0x8040 */
    unsigned long tmpBufRest;           /* 0x8044 */
    int ref;                            /* 0x8048 */
};
/* Argument blocks handed to the connection callback. */
typedef struct _NHTTPPostSendArg {
    char *label;
    void *value;
    unsigned long length;
    int offset;
} NHTTPPostSendArg;

typedef struct _NHTTPBodyBufArg {
    void *buf;
    unsigned long length;
    unsigned long offset;
} NHTTPBodyBufArg;

/* Lock state for the request list (size 0x1c). */
typedef struct _NHTTPMutexInfo {
    int mutex[6];                       /* 0x00 */
    int isInitialized;                  /* 0x18 */
} NHTTPMutexInfo;

/* The system info singleton at gNHTTPSystemInfo (size 0x4150). */
typedef struct _NHTTPSysInfo {
    NHTTPBgnEndInfo bgnEndInfo;         /* 0x00 */
    NHTTPListInfo listInfo;             /* 0x28 */
    NHTTPReqInfo reqInfo;               /* 0x30 */
    NHTTPMutexInfo mutexInfo;           /* 0x34 */
    NHTTPThreadInfo threadInfo;         /* 0x50 */
} NHTTPSysInfo;

/* Module globals at gNHTTPModuleGlobals: connection list head, the system info
 * pointer, and an initialised flag that overlaps the first word of the
 * static resource block that follows. */
typedef struct _NHTTPModuleGlobals {
    NHTTPConnection *connListHead;
    NHTTPSysInfo *sysInfo_p;
    int isInitialized;
} NHTTPModuleGlobals;

#endif
