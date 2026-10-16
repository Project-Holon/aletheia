/*
 * function: gpiDisconnect
 * address:  0x0218B760
 * packet:   pkt_ov009_0218B760
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiDisconnect (gpiconnect.o)
 *
 * symbols:
 *   gpiAppendStringToBuffer  0x0218946C  arm   ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm   ov009
 *   gpiSendFromBuffer  0x0218998C  arm   ov009
 *   shutdown  0x0217EB9C  arm   ov009
 *   closesocket  0x0217EB2C  arm   ov009
 *   gsUdpEngineIsInitialized  0x02180E48  arm   ov009
 *   gsUdpEngineRemoveMsgHandler  0x02181748  arm   ov009
 *   func_02181828  0x02181828  arm   ov009
 *   func_02181874  0x02181874  arm   ov009
 *   func_02181530  0x02181530  arm   ov009
 *   gsifree  0x0217EAE0  arm   ov009
 *   gpiRemoveOperation  0x0218E240  arm   ov009
 *   func_0218EEC0  0x0218EEC0  arm   ov009
 *   func_0218FFFC  0x0218FFFC  arm   ov009
 *   gpiDisconnectCleanupProfile  0x0218B618  arm   ov009
 *   g_021A4A80     0x021A4A80  data
 *   g_021A495C     0x021A495C  data
 *   g_021A4A94     0x021A4A94  data
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPIPeer_s {
    char pad0[0x4c];
    struct GPIPeer_s *pnext;
} GPIPeer;

typedef struct GPIConnection {
    char pad0[0x198];
    int sessKey;
    int userid;
    int profileid;
    char pad1a4[0x1f0 - 0x1a4];
    int cmSocket;
    int connectState;
    GPIBuffer socketBuffer;
    char *inputBuffer;
    int inputBufferSize;
    GPIBuffer outputBuffer;
    char mHeader[16];
    char pad230[0x5c4 - 0x230];
    void *operationList;
    char pad5c8[0x5d8 - 0x5c8];
    GPIPeer *peerList;
    char pad5dc[0x5e4 - 0x5dc];
    GPIBuffer updateproBuffer;
    GPIBuffer updateuiBuffer;
} GPIConnection;

extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern int gpiSendFromBuffer(void **connection, int sock, GPIBuffer *outputBuffer, int *connClosed, int clipSentData, char *id);
extern int shutdown(int sock, int how);
extern int closesocket(int sock);
extern int gsUdpEngineIsInitialized(void);
extern int gsUdpEngineRemoveMsgHandler(char *theHeader);
extern int func_02181828(void);
extern int func_02181874(void);
extern int func_02181530(void);
extern void gsifree(void *ptr);
struct GPIOperation;
extern void gpiRemoveOperation(void **connection, struct GPIOperation *operation);
extern void func_0218EEC0(void **connection, GPIPeer *peer);
extern int func_0218FFFC(void **connection, int (*func)(void **, void *, void *), void *data);
extern int gpiDisconnectCleanupProfile(void **connection, void *profile);
extern char g_021A4A80[];
extern char g_021A495C[];
extern char g_021A4A94[];

void gpiDisconnect(void **connection, int tellServer)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIPeer *peer;
    GPIPeer *delPeer;
    int connClosed;

    if (iconnection->connectState == 4)
        return;

    if (iconnection->connectState != 0) {
        if (tellServer && iconnection->connectState == 3) {
            gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4A80);
            gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->sessKey);
            gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), g_021A495C);
        }
        gpiSendFromBuffer(connection, iconnection->cmSocket, &iconnection->outputBuffer, &connClosed, 1, g_021A4A94);
        if (iconnection->cmSocket != -1) {
            shutdown(iconnection->cmSocket, 2);
            closesocket(iconnection->cmSocket);
            iconnection->cmSocket = -1;
        }
        iconnection->connectState = 4;
        iconnection->userid = 0;
        iconnection->profileid = 0;
    }

    if (gsUdpEngineIsInitialized()) {
        gsUdpEngineRemoveMsgHandler(iconnection->mHeader);
        if (func_02181828() && func_02181874())
            func_02181530();
    }

    gsifree(iconnection->socketBuffer.buffer);
    iconnection->socketBuffer.buffer = 0;
    gsifree(iconnection->inputBuffer);
    iconnection->inputBuffer = 0;
    gsifree(iconnection->outputBuffer.buffer);
    iconnection->outputBuffer.buffer = 0;
    gsifree(iconnection->updateproBuffer.buffer);
    iconnection->updateproBuffer.buffer = 0;
    gsifree(iconnection->updateuiBuffer.buffer);
    iconnection->updateuiBuffer.buffer = 0;

    while (iconnection->operationList)
        gpiRemoveOperation(connection, iconnection->operationList);
    iconnection->operationList = 0;

    for (peer = iconnection->peerList; peer; ) {
        delPeer = peer;
        peer = peer->pnext;
        func_0218EEC0(connection, delPeer);
    }
    iconnection->peerList = 0;

    while (!func_0218FFFC(connection, (int (*)(void **, void *, void *))gpiDisconnectCleanupProfile, 0)) {
    }
}
