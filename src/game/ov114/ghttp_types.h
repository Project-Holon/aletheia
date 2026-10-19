#ifndef OV114_GHTTP_TYPES_H
#define OV114_GHTTP_TYPES_H
/*
 * GameSpy HTTP (ghttp) types shared by all ov114 files. One definition per
 * type; every file that uses one of these includes this header.
 *
 * GHIConnection is 0x1d4 bytes; its GHIBuffer members are 0x24 bytes each.
 */

#ifndef OV114_BASIC_TYPES
#define OV114_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#endif

typedef enum { GHTTPFalse, GHTTPTrue } GHTTPBool;

struct GHIConnection;
struct GHIEncryptor;

typedef void (*GHTTPProgressCallbackFn)(int request, int state, const char *buffer,
                                      int bufferLen, int bytesReceived,
                                      int totalSize, void *param);

typedef int (*GHTTPCompletedCallbackFn)(int request, int result, char *buffer,
                                      int bufferLen, void *param);

typedef void (*GHTTPPostCallback)(int request, int bytesPosted, int totalBytes,
                                  int objectsPosted, int totalObjects, void *param);

typedef int (*GHIEncryptorFunc)(struct GHIConnection *connection,
                                struct GHIEncryptor *encryptor);

typedef int (*GHIEncryptFunc)(struct GHIConnection *connection, void *encryptor,
                              const char *plainText, int plainTextLen,
                              char *cipherText, int *cipherTextLen);

typedef int (*GHIDecryptFunc)(struct GHIConnection *connection, void *encryptor,
                              char *readPos, int *readLen,
                              char *writePos, int *writeLen);

typedef void (*GHICleanupFunc)(struct GHIConnection *connection, void *encryptor);

/* Receive throttle settings (global at 0x021CE5AC). */
typedef struct GHIThrottle {
    unsigned int timeDelay;             /* 0x00: minimum time between receives */
    int bufferSize;                     /* 0x04: maximum bytes per receive */
} GHIThrottle;

/* Growable byte buffer (0x24 bytes). */
typedef struct GHIBuffer {
    struct GHIConnection *connection;   /* 0x00 */
    char *data;                         /* 0x04 */
    int size;                           /* 0x08 */
    int len;                            /* 0x0c */
    int pos;                            /* 0x10 */
    int sizeIncrement;                  /* 0x14 */
    int fixed;                          /* 0x18 */
    int dontFree;                       /* 0x1c */
    int readOnly;                       /* 0x20 */
} GHIBuffer;

/* One item to post (0x18 bytes). */
typedef struct GHIPostData {
    int type;                           /* 0x00 */
    char *name;                         /* 0x04 */
    union {
        struct {
            char *string;               /* 0x08 */
            int len;                    /* 0x0c */
            int encode;                 /* 0x10 */
            int escapedCount;           /* 0x14: characters needing a %XX escape (guess) */
        } string;
        struct {
            char *filename;             /* 0x08 */
            char *reportFilename;       /* 0x0c */
            char *contentType;          /* 0x10 */
        } fileDisk;
        struct {
            char *buffer;               /* 0x08 */
            int len;                    /* 0x0c */
            char *reportFilename;       /* 0x10 */
            char *contentType;          /* 0x14 */
        } fileMemory;
        struct {
            void *xml;                  /* 0x08 */
        } xml;
    } data;
} GHIPostData;

/* Per-item send state (0x10 bytes). */
typedef struct GHIPostState {
    GHIPostData *data;                  /* 0x00 */
    int pos;                            /* 0x04 */
    union {
        struct {
            void *file;                 /* 0x08 */
            int len;                    /* 0x0c */
        } fileDisk;
    } state;
} GHIPostState;

/* Post description (0x1c bytes). */
typedef struct GHIPost {
    void *data;                         /* 0x00 */
    void *callback;                     /* 0x04 */
    void *param;                        /* 0x08 */
    GHTTPBool hasFiles;                 /* 0x0c */
    GHTTPBool hasSoap;                  /* 0x10 */
    GHTTPBool useDIME;                  /* 0x14 */
    GHTTPBool autoFree;                 /* 0x18 */
} GHIPost;

/* Post progress (0x20 bytes, at GHIConnection 0x168). */
typedef struct GHIPostingState {
    void *states;                       /* 0x00 */
    int index;                          /* 0x04 */
    int bytesPosted;                    /* 0x08 */
    int totalBytes;                     /* 0x0c */
    GHTTPPostCallback callback;         /* 0x10 */
    void *param;                        /* 0x14 */
    int waitPostContinue;               /* 0x18 */
    int completed;                       /* 0x1c */
} GHIPostingState;

/* TWL SSL engine handle (0x08 bytes). */
typedef struct GsTwlSslInterface {
    void *con;                          /* 0x00 */
    int connected;                      /* 0x04 */
} GsTwlSslInterface;

/* SSL/encryption layer state (0x34 bytes, at GHIConnection 0x194). */
typedef struct GHIEncryptor {
    GsTwlSslInterface *mInterface;      /* 0x00 */
    int engine;                         /* 0x04 */
    int interfaceCreated;               /* 0x08  set once the SSL interface exists */
    int initialized;                    /* 0x0c */
    int sessionEstablished;             /* 0x10 */
    int encryptOnBuffer;                /* 0x14 */
    int encryptOnSend;                  /* 0x18 */
    int handshaking;                    /* 0x1c */
    GHIEncryptorFunc initFunc;          /* 0x20 */
    GHICleanupFunc cleanupFunc;         /* 0x24 */
    GHIEncryptorFunc startFunc;         /* 0x28 */
    GHIEncryptFunc encryptFunc;         /* 0x2c */
    GHIDecryptFunc decryptFunc;         /* 0x30 */
} GHIEncryptor;

/* One HTTP request (0x1d4 bytes). */
typedef struct GHIConnection {
    int inUse;                          /* 0x000 */
    int request;                        /* 0x004 */
    int uniqueID;                       /* 0x008 */
    int type;                           /* 0x00c */
    int state;                          /* 0x010 */
    char *URL;                          /* 0x014 */
    char *serverAddress;                /* 0x018 */
    u32 serverIP;                       /* 0x01c */
    u16 serverPort;                     /* 0x020 */
    char *requestPath;                  /* 0x024 */
    int protocol;                       /* 0x028 */
    char *sendHeaders;                  /* 0x02c */
    void *saveFile;                     /* 0x030 */
    char *saveFileName;                 /* 0x034 */
    int blocking;                       /* 0x038 */
    int persistConnection;              /* 0x03c */
    int result;                         /* 0x040 */
    GHTTPProgressCallbackFn progressCallback;   /* 0x044 */
    GHTTPCompletedCallbackFn completedCallback; /* 0x048 */
    void *callbackParam;                /* 0x04c */
    int socket;                         /* 0x050 */
    int socketError;                    /* 0x054 */
    GHIBuffer sendBuffer;               /* 0x058 */
    GHIBuffer encodeBuffer;             /* 0x07c */
    GHIBuffer recvBuffer;               /* 0x0a0 */
    GHIBuffer decodeBuffer;             /* 0x0c4 */
    GHIBuffer getFileBuffer;            /* 0x0e8 */
    int userBufferSupplied;             /* 0x10c */
    int statusMajorVersion;             /* 0x110 */
    int statusMinorVersion;             /* 0x114 */
    int statusCode;                     /* 0x118 */
    int statusStringIndex;              /* 0x11c */
    int headerStringIndex;              /* 0x120 */
    int completed;                      /* 0x124 */
    int fileBytesReceived;              /* 0x128 */
    int totalSize;                      /* 0x12c */
    char *redirectURL;                  /* 0x130 */
    int redirectCount;                  /* 0x134 */
    int chunkedTransfer;                /* 0x138 */
    char chunkHeader[12];               /* 0x13c */
    int chunkHeaderLen;                 /* 0x148 */
    int chunkBytesLeft;                 /* 0x14c */
    int chunkReadingState;              /* 0x150 */
    int processing;                     /* 0x154 */
    int connectionClosed;               /* 0x158 */
    int throttle;                       /* 0x15c */
    u32 lastThrottleRecv;               /* 0x160 */
    GHIPost *post;                      /* 0x164 */
    GHIPostingState postingState;       /* 0x168 */
    u32 maxRecvTime;                    /* 0x188 */
    char *proxyOverrideServer;          /* 0x18c */
    u16 proxyOverridePort;              /* 0x190 */
    GHIEncryptor encryptor;             /* 0x194 */
    int handleStatus;                   /* 0x1c8 */
    void *handle;                       /* 0x1cc */
    u32 receiveFileIdleTime;            /* 0x1d0 */
} GHIConnection;

#endif
