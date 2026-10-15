/*
 * file:     gpi.c
 * unit:     yes
 * function: gpiInitialize, gpiDestroy, gpiResetProfile, gpiReset, gpiProcessConnectionManager, gpiProcess
 * address:  0x02186664
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   func_0218FB14  0x0218FB14  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   SocketStartUp  0x0217F25C  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   srand  0x020946C8  arm
 *   gpiDisconnect  0x0218B760  arm  ov009
 *   gpiStatusInfoKeysDestroy  0x0218D840  arm  ov009
 *   func_021846B4  0x021846B4  arm  ov009
 *   gpiStatusInfoKeysInit  0x0218D7F4  arm  ov009
 *   gpiRemoveOperation  0x0218E240  arm  ov009
 *   func_0218FFFC  0x0218FFFC  arm  ov009
 *   current_time                     0x0217F264  arm
 *   gpiAddLocalInfo                  0x0218C5FC  arm
 *   gpiSendFromBuffer                0x0218998C  arm
 *   gpiRecvToBuffer                  0x02189780  arm
 *   gpiSetError                      0x02193710  arm
 *   gpiCallErrorCallback             0x02189D78  arm
 *   gsDebugFormat                    0x0217D254  arm
 *   gsirealloc                       0x0217EAC8  arm
 *   gpiSetErrorString                0x02193734  arm
 *   gpiFindOperationByID             0x0218E290  arm
 *   gpiProcessOperation              0x0218E318  arm
 *   gpiCheckForError                 0x0219329C  arm
 *   gpiProcessRecvBuddyMessage       0x021870B8  arm
 *   gpiValueForKey                   0x02193418  arm
 *   gpiProcessRecvBuddyStatusInfo    0x02187D60  arm
 *   gpiProcessRecvBuddyList          0x02188638  arm
 *   gpiProcessRecvBlockedList        0x02190188  arm
 *   gpiProcessRemoteAuthResponse     0x0218B914  arm
 *   gpiOperationsAreBlocking         0x0218E2DC  arm
 *   msleep                           0x0217F2BC  arm
 *   gpiAppendStringToBuffer          0x0218946C  arm
 *   strstr                           0x02094B20  arm
 *   memcpy                           0x02092344  arm
 *   memmove                          0x02092364  arm
 *   atoi                             0x020964E0  arm
 *   strncmp                          0x020949F4  arm
 *   d_021A412C                       0x021A412C  data
 *   d_021A4130                       0x021A4130  data
 *   d_021A415C                       0x021A415C  data
 *   d_021A4164                       0x021A4164  data
 *   d_021A4170                       0x021A4170  data
 *   d_021A4180                       0x021A4180  data
 *   d_021A4188                       0x021A4188  data
 *   d_021A41B0                       0x021A41B0  data
 *   d_021A41B8                       0x021A41B8  data
 *   d_021A41C0                       0x021A41C0  data
 *   d_021A41C8                       0x021A41C8  data
 *   d_021A41D0                       0x021A41D0  data
 *   d_021A41D8                       0x021A41D8  data
 *   d_021A41E0                       0x021A41E0  data
 *   d_021A41E8                       0x021A41E8  data
 *   d_021A420C                       0x021A420C  data
 *   d_021A4234                       0x021A4234  data
 */
#include "../../matched/arm9_sdk/libc/strncmp/string.h"

typedef struct GPIOperation_s {
    char pad[0x1c];
    int field1c;
    struct GPIOperation_s *field20;
} GPIOperation_s;
typedef unsigned int   u32_02186664;

typedef struct GPIConnection_02186664 {
    unsigned char pad[0x5C8];
    void *f5C8;
} GPIConnection_02186664;

typedef struct GPIProfile_02186664 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
} GPIProfile_02186664;

typedef struct GPIConnection_021867E8 {
    char pad000[0x110];
    char errorString;              /* 0x110 */
    char pad111[0x1E];
    char f12F;                     /* 0x12F */
    char pad130[0x14];
    char f144;                     /* 0x144 */
    char pad145[0x53];
    int f198;                      /* 0x198 */
    int f19C;                      /* 0x19C */
    int f1A0;                      /* 0x1A0 */
    char pad1A4[0x4C];
    int cmSocket;                  /* 0x1F0 */
    int connectState;              /* 0x1F4 */
    char *buf1F8;                  /* 0x1F8 */
    int size1FC;                   /* 0x1FC */
    int len200;                    /* 0x200 */
    int pos204;                    /* 0x204 */
    char *buf208;                  /* 0x208 */
    int len20C;                    /* 0x20C */
    char *buf210;                  /* 0x210 */
    int size214;                   /* 0x214 */
    int len218;                    /* 0x218 */
    int pos21C;                    /* 0x21C */
    char pad220[0x14];
    int f234;                      /* 0x234 */
    int f238;                      /* 0x238 */
    int f23C;                      /* 0x23C */
    char pad240[0x178];
    char f3B8;                     /* 0x3B8 */
    char pad3B9[0xFF];
    char f4B8;                     /* 0x4B8 */
    char pad4B9[0x103];
    int f5BC;                      /* 0x5BC */
    char pad5C0[0x4];
    void *operationList;           /* 0x5C4 */
    char pad5C8[0x8];
    int f5D0;                      /* 0x5D0 */
    int f5D4;                      /* 0x5D4 */
    int f5D8;                      /* 0x5D8 */
    char pad5DC[0x8];
    char *buf5E4;                  /* 0x5E4 */
    int size5E8;                   /* 0x5E8 */
    int len5EC;                    /* 0x5EC */
    int pos5F0;                    /* 0x5F0 */
    char *buf5F4;                  /* 0x5F4 */
    int size5F8;                   /* 0x5F8 */
    int len5FC;                    /* 0x5FC */
    int pos600;                    /* 0x600 */
    char pad604[0x30];
    int f634;                      /* 0x634 */
} GPIConnection_021867E8;

typedef void *GPConnection;

typedef struct GPIProfile_021867E8 GPIProfile_021867E8;

typedef unsigned char u8;

typedef unsigned long u32_02186A0C;

typedef struct GPIBuffer {
    char *buffer;
    unsigned long length;
} GPIBuffer;

typedef struct GPIConnection {
    u8 pad0[0x1F0];
    int sock;
    int lastResult;
    char *recvBuf;
    int recvLen;
    int f200;
    int f204;
    char *sendBuf;
    int sendCap;
    char *localBuf;
    int f214;
    int f218;
    u8 pad21C[0x634 - 0x21C];
    int lastSend;
} GPIConnection;

extern void *gsimalloc(int size);
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32_02186664 n);
extern int   func_0218FB14(void **pp);
extern void  gsifree(void *p);
extern void  SocketStartUp(void);
extern unsigned int current_time(void);
extern void  srand(void);
extern void gpiDisconnect(void **connection, int tellServer);
extern void gpiStatusInfoKeysDestroy(void **connection);
extern void func_021846B4(void *table);
extern int gpiStatusInfoKeysInit(GPConnection *connection);
extern void gpiRemoveOperation(void **connection, GPIOperation_s *operation);
extern int func_0218FFFC(GPConnection *connection, int (*func)(GPConnection *, GPIProfile_021867E8 *, void *), void *data);
extern int gpiAddLocalInfo(void **connection, GPIBuffer *buffer);
extern int gpiSendFromBuffer(void **connection, int sock, GPIBuffer *outputBuffer,
                             int *connClosed, int clipSentData, char *id);
extern int gpiRecvToBuffer(void **connection, int sock, GPIBuffer *inputBuffer,
                           int *bytesRead, int *connClosed, char *id);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern void gpiCallErrorCallback(void **connection, int result, int fatal);
extern void gsDebugFormat(int cat, int type, int level, char *token, ...);
extern void *gsirealloc(void *ptr, unsigned long size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern int gpiFindOperationByID(void **connection, GPIOperation_s **operation, int id);
extern int gpiProcessOperation(void **connection, void *operation, char *input);
extern int gpiCheckForError(void **connection, char *input, int callErrorCallback);
extern int gpiProcessRecvBuddyMessage(void **connection, char *input);
extern int gpiValueForKey(char *command, char *key, char *value, int len);
extern int gpiProcessRecvBuddyStatusInfo(void **connection, char *input);
extern int gpiProcessRecvBuddyList(void **connection, char *input);
extern int gpiProcessRecvBlockedList(void **connection, char *input);
extern int gpiProcessRemoteAuthResponse(void **connection, char *input);
extern int gpiOperationsAreBlocking(void **connection);
extern void msleep(int ms);
extern int gpiAppendStringToBuffer(void **connection, GPIBuffer *outputBuffer, char *buffer);
extern char *strstr(char *s, char *t);
extern void *memmove(void *dst, void *src, unsigned long n);
extern int atoi(char *s);
/*
 * gpiInitialize (gpi_engine?): allocate the 0x638-byte GP connection block, * clear it, seed the state words, hand its address to func_0218FB14, clear * nine 8-byte pairs, run the two sub-initialisers, then publish the block * through *out. p lives on the stack because &p is taken.
 */
int gpiInitialize(void **out, int a1, int a2, int a3);
/*
 * sdk: gpiDestroy (gpi.o)
 */
void gpiDestroy(void **connection);
/*
 * sdk: gpiResetProfile (gpi.o) * * The object keeps profile in r1 (a leading unused parameter takes r0).
 */
int gpiResetProfile(int unused, GPIProfile_02186664 *profile);
int gpiReset(GPConnection *connection);
int gpiProcessConnectionManager(void **connection);
extern char d_021A412C[], d_021A4130[], d_021A415C[], d_021A4164[];
extern char d_021A4170[], d_021A4180[], d_021A4188[], d_021A41B0[];
extern char d_021A41B8[], d_021A41C0[], d_021A41C8[], d_021A41D0[];
extern char d_021A41D8[], d_021A41E0[], d_021A41E8[], d_021A420C[];
extern char d_021A4234[];
extern int gpiCheckConnect(void **connection);
extern int gpiProcessPeers(void **connection);
extern int gpiProcessSearches(void **connection);
extern int gpiFailedOpCallback(void **connection, GPIOperation_s *operation);
extern void gpiRemoveOperation(void **connection, GPIOperation_s *operation);
extern int gpiProcessCallbacks(void **connection, int blockingOperationID);
extern void gpiDisconnect(void **connection, int tellServer);
extern int gpiReset(void **connection);




/*
 * gpiInitialize (gpi_engine?): allocate the 0x638-byte GP connection block,
 * clear it, seed the state words, hand its address to func_0218FB14, clear
 * nine 8-byte pairs, run the two sub-initialisers, then publish the block
 * through *out.  p lives on the stack because &p is taken.
 */
int gpiInitialize(void **out, int a1, int a2, int a3)
{
    char *p;
    int i;

    *out = 0;
    p = gsimalloc(0x638);
    if (p == 0)
        return 1;
    MSL_C_LIB_MemsetPtr(p, 0, 0x638);
    p[0] = 0;
    *(int *)(p + 0x5b8) = 0;
    *(int *)(p + 0x100) = 1;
    *(int *)(p + 0x104) = 0;
    *(int *)(p + 0x108) = 0;
    *(int *)(p + 0x10c) = 0;
    *(int *)(p + 0x60c) = a1;
    *(int *)(p + 0x610) = a2;
    *(int *)(p + 0x1a4) = a3;

    if (func_0218FB14((void **)&p) == 0) {
        gsifree(p);
        return 1;
    }

    *(int *)(p + 0x5c0) = 0;
    for (i = 0; i < 9; i++) {
        *(int *)(p + i * 8 + 0x1a8) = 0;
        *(int *)(p + i * 8 + 0x1ac) = 0;
    }

    i = gpiReset((void **)&p);
    if (i != 0) {
        gpiDestroy((void **)&p);
        return i;
    }

    SocketStartUp();
    current_time();
    srand();
    *out = p;
    return 0;
}




/*
 * sdk:      gpiDestroy (gpi.o)
 */
void gpiDestroy(void **connection)
{
    GPIConnection_02186664 *iconnection = (GPIConnection_02186664 *)*connection;

    gpiDisconnect(connection, 1);
    gpiStatusInfoKeysDestroy(connection);
    func_021846B4(iconnection->f5C8);
    gsifree(iconnection);
    *connection = 0;
}




/*
 * sdk:      gpiResetProfile (gpi.o)
 *
 * The object keeps profile in r1 (a leading unused parameter takes r0).
 */
int gpiResetProfile(int unused, GPIProfile_02186664 *profile)
{
    profile->f8 = 0;
    profile->fC = 0;
    profile->f14 = 0;
    profile->f18 = 0;
    profile->f1C = 0;
    profile->f20 = 0;
    profile->f28 = 0;
    return 1;
}



/*
 * sdk:      gpiReset (libdwcgsgp.TWL.HYB.a gpi.o)
 */
int gpiReset(GPConnection *connection)
{
    GPIConnection_021867E8 *iconnection = (GPIConnection_021867E8 *)*connection;
    int result;

    iconnection->errorString = '\0';
    iconnection->f12F = '\0';
    iconnection->f144 = '\0';
    iconnection->cmSocket = -1;
    iconnection->connectState = 0;
    iconnection->len200 = 0;
    iconnection->pos204 = 0;
    iconnection->size1FC = 0;
    gsifree(iconnection->buf1F8);
    iconnection->buf1F8 = 0;
    iconnection->buf1F8 = 0;
    iconnection->len20C = 0;
    gsifree(iconnection->buf208);
    iconnection->buf208 = 0;
    iconnection->buf208 = 0;
    iconnection->len218 = 0;
    iconnection->pos21C = 0;
    iconnection->size214 = 0;
    gsifree(iconnection->buf210);
    iconnection->buf210 = 0;
    iconnection->buf210 = 0;
    iconnection->len5EC = 0;
    iconnection->pos5F0 = 0;
    iconnection->size5E8 = 0;
    gsifree(iconnection->buf5E4);
    iconnection->buf5E4 = 0;
    iconnection->buf5E4 = 0;
    iconnection->len5FC = 0;
    iconnection->pos600 = 0;
    iconnection->size5F8 = 0;
    gsifree(iconnection->buf5F4);
    iconnection->buf5F4 = 0;
    iconnection->buf5F4 = 0;

    gpiStatusInfoKeysDestroy(connection);
    result = gpiStatusInfoKeysInit((GPConnection *)&iconnection);
    if (result != 0)
    {
        gpiDestroy((GPConnection *)&iconnection);
        return result;
    }

    iconnection->f234 = 2;
    while (iconnection->operationList != 0)
        gpiRemoveOperation(connection, (GPIOperation_s *)iconnection->operationList);
    iconnection->operationList = 0;
    iconnection->f5D0 = 0;
    iconnection->f5D4 = 0;
    func_0218FFFC(connection, (int (*)(GPConnection *, GPIProfile_021867E8 *, void *))gpiResetProfile, 0);
    iconnection->f19C = 0;
    iconnection->f1A0 = 0;
    iconnection->f198 = 0;
    iconnection->f238 = 0;
    iconnection->f5BC = 0;
    iconnection->f5D8 = 0;
    iconnection->f23C = -1;
    iconnection->f3B8 = '\0';
    iconnection->f4B8 = '\0';
    iconnection->f634 = 0;
    return 0;
}


int gpiProcessConnectionManager(void **connection)
{
    GPIConnection *ic;
    u32_02186A0C now;
    GPIOperation_s *operation;
    int len;
    int connClosed;
    int result;
    int id;
    char *str;
    char *next;
    char *tempPtr;
    int loop;

    connClosed = 0;
    ic = (GPIConnection *)*connection;
    now = current_time();

    do {
        gpiAddLocalInfo(connection, (GPIBuffer *)&ic->localBuf);
        if (ic->f218 > 0)
            ic->lastSend = now;
        result = gpiSendFromBuffer(connection, ic->sock, (GPIBuffer *)&ic->localBuf,
                                   &connClosed, 1, d_021A412C);
        if (result)
            return result;
        result = gpiRecvToBuffer(connection, ic->sock, (GPIBuffer *)&ic->recvBuf,
                                 &len, &connClosed, d_021A412C);
        if (result) {
            if (result != 3)
                return result;
            gpiSetError(connection, 5, d_021A4130);
            result = 3;
            gpiCallErrorCallback(connection, result, 1);
            return result;
        }

        while ((str = strstr(ic->recvBuf, d_021A415C)) != 0) {
            ic->lastSend = now;
            *str = 0;
            gsDebugFormat(1, 0, 0x20, d_021A4164, ic->recvBuf);
            len = (int)(str - ic->recvBuf);
            if (len > ic->sendCap) {
                ic->sendCap = ic->sendCap + (len < 0x4000 ? 0x4000 : len);
                tempPtr = (char *)gsirealloc(ic->sendBuf, ic->sendCap + 1);
                if (tempPtr == 0) {
                    gpiSetErrorString(connection, d_021A4170);
                    return 1;
                }
                ic->sendBuf = tempPtr;
            }
            memcpy(ic->sendBuf, ic->recvBuf, len + 1);
            ic->f200 = ic->f200 - ((str + 7) - ic->recvBuf);
            memmove(ic->recvBuf, str + 7, ic->f200 + 1);
            str = ic->sendBuf;
            next = strstr(str, d_021A4180);
            if (next) {
                id = atoi(next + 4);
                if (!gpiFindOperationByID(connection, &operation, id)) {
                    gsDebugFormat(1, 0, 1, d_021A4188, id);
                } else {
                    result = gpiProcessOperation(connection, operation, ic->sendBuf);
                    if (result)
                        return result;
                }
            } else {
                if (gpiCheckForError(connection, str, 1))
                    return 4;
                str = ic->sendBuf;
                if (strncmp(str, d_021A41B0, 4) == 0) {
                    result = gpiProcessRecvBuddyMessage(connection, str);
                    if (result)
                        return result;
                } else if (strncmp(str, d_021A41B8, 4) == 0) {
                } else if (strncmp(str, d_021A41C0, 4) == 0) {
                    gpiValueForKey(str, d_021A41C0, (char *)&ic->f214 + 0x400, 0x19);
                } else if (strncmp(str, d_021A41C8, 5) == 0) {
                    result = gpiProcessRecvBuddyStatusInfo(connection, str);
                    if (result)
                        return result;
                } else if (strncmp(str, d_021A41D0, 5) == 0) {
                    result = gpiProcessRecvBuddyList(connection, str);
                    if (result)
                        return result;
                } else if (strncmp(str, d_021A41D8, 5) == 0) {
                    result = gpiProcessRecvBlockedList(connection, str);
                    if (result)
                        return result;
                } else if (strncmp(str, d_021A41E0, 5) == 0) {
                    result = gpiProcessRemoteAuthResponse(connection, str);
                    if (result)
                        return result;
                } else {
                    gsDebugFormat(1, 0, 1, d_021A41E8);
                }
            }
        }

        if (connClosed != 0 && ic->lastResult != 5) {
            gpiSetError(connection, 7, d_021A420C);
            gpiCallErrorCallback(connection, 3, 1);
            return 0;
        }
        loop = gpiOperationsAreBlocking(connection);
        if (loop)
            msleep(10);
    } while (loop);

    if ((now - ic->lastSend) > 120000) {
        gpiAppendStringToBuffer(connection, (GPIBuffer *)&ic->localBuf, d_021A4234);
        ic->lastSend = now;
    }
    return 0;
}

int gpiProcess(void **connection, int blockingOperationID)
{
    GPIConnection *iconnection;
    GPIOperation_s *operation;
    int result;
    int loop;
    int __result__;

    iconnection = (GPIConnection *)*connection;
    result = 0;

    if (iconnection->lastResult == 1) {
        do {
            result = gpiCheckConnect(connection);
            if (result == 0 && blockingOperationID != 0
                && iconnection->lastResult == 1)
                loop = 1;
            else
                loop = 0;
            if (loop)
                msleep(10);
        } while (loop);

        if (result != 0) {
            if (gpiFindOperationByID(connection, &operation, 1))
                operation->field1c = 4;
        }
    }

    if (iconnection->lastResult == 3
        || iconnection->lastResult == 2
        || iconnection->lastResult == 5) {
        if (result == 0)
            result = gpiProcessConnectionManager(connection);
        if (result == 0)
            result = gpiProcessPeers(connection);
    }
    if (result == 0)
        result = gpiProcessSearches(connection);

    operation = *(GPIOperation_s **)((char *)iconnection + 0x5c4);
    while (operation != 0) {
        if (operation->field1c == 0) {
            operation = operation->field20;
        } else {
            GPIOperation_s *op;
            gpiFailedOpCallback(connection, operation);
            op = operation;
            operation = op->field20;
            gpiRemoveOperation(connection, op);
        }
    }

    __result__ = gpiProcessCallbacks(connection, blockingOperationID);
    if (__result__ != 0)
        return __result__;
    if (*(int *)((char *)iconnection + 0x5bc) != 0) {
        gpiDisconnect(connection, 0);
        gpiReset(connection);
    }
    return result;
}
