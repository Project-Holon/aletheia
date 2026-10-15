#ifndef OV009_GSUDP_TYPES_H
#define OV009_GSUDP_TYPES_H
/*
 * Shared GameSpy UDP engine types for ov009 gsudpengine. One definition per
 * object, offsets checked against every view the parts had.
 */

typedef unsigned char u8;

typedef struct { char c[16]; } GSUdpHdr;

typedef struct GSUdpRemotePeer {
    unsigned int mAddr;                   /* 0x00 */
    unsigned short mPort;                 /* 0x04 */
    void *mConnection;                    /* 0x08 */
} GSUdpRemotePeer;

typedef struct GSUdpMsgHandler {
    unsigned char mInitialMsg[16];        /* 0x00 */
    unsigned char mHeader[16];            /* 0x10 */
    void *mPendingConnections;            /* 0x20 */
    void (*mClosed)(unsigned int, unsigned short, int, void *);  /* 0x24 */
    void (*mReceived)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *);  /* 0x28 */
    void (*mConnected)(unsigned int, unsigned short, int, int, void *);  /* 0x2c */
    void (*mPingReply)(unsigned int, unsigned short, unsigned int, void *);  /* 0x30 */
    void (*mNetworkError)(int, void *);   /* 0x34 */
    void *mUserData;                      /* 0x38 */
} GSUdpMsgHandler;

typedef struct GSUdpEngineObject {
    void *mSocket;                        /* 0x00 */
    void *mRemotePeers;                   /* 0x04 */
    void *mMsgHandlers;                   /* 0x08 */
    int mInitialized;                     /* 0x0c */
    void (*mAppConnected)(unsigned int, unsigned short, int, int, void *);  /* 0x10 */
    void (*mAppClosed)(unsigned int, unsigned short, int, void *);  /* 0x14 */
    void (*mAppPingReply)(unsigned int, unsigned short, unsigned int, void *);  /* 0x18 */
    void (*mAppRecvData)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *);  /* 0x1c */
    void (*mAppConnAttempt)(unsigned int, unsigned short, int, unsigned char *, unsigned int, void *);  /* 0x20 */
    void (*mAppNetworkError)(int, void *);  /* 0x24 */
    int (*mAppUnknownMessage)(unsigned int, unsigned short, unsigned char *, unsigned int, void *);  /* 0x28 */
    void *mAppUserData;                   /* 0x2c */
    int mAppPendingConnections;           /* 0x30 */
    unsigned int mLocalAddr;              /* 0x34 */
    unsigned short mLocalPort;            /* 0x38 */
} GSUdpEngineObject;

typedef struct GT2ConnectionCallbacks {
    void (*connected)(void *, int, unsigned char *, int);
    void (*received)(void *, unsigned char *, int, int);
    void (*closed)(void *, int);
    void (*ping)(void *, int);
} GT2ConnectionCallbacks;

/* shared callees, named by address */
extern GSUdpEngineObject *gsUdpEngineContext(void);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void ArrayFree(void *array);
extern int ArrayLength(void *array);
extern void *func_02184208(void *array, int n);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void ArrayAppend(void *array, void *newElem);
extern char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);

extern char g_021A3B9C[];

#endif
