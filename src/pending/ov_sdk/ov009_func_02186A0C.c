/*
 * function: gpiProcessConnectionManager
 * address:  0x02186A0C
 * packet:   pkt_ov009_02186A0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: codegen + compiler. The vendor object carries the Metrowerks
 *   ARM 4.0.0.1025 stamp, which no tool/mwccarm build in this collection
 *   reproduces, so this can never reach EXACT here. Body is transcribed
 *   from the disassembly (connection send/recv, command dispatch by
 *   strncmp prefix, blocking retry), parked for coverage.
 *
 * sdk:      gpiProcessConnectionManager (libdwcgsgp.TWL.HYB.a gpi.o)
 *
 * symbols:
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

typedef unsigned char u8;
typedef unsigned long u32;

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

extern unsigned int current_time(void);
extern int gpiAddLocalInfo(void **connection, GPIBuffer *buffer);
extern int gpiSendFromBuffer(void **connection, int sock, GPIBuffer *outputBuffer,
                             int *connClosed, int clipSentData, char *id);
extern int gpiRecvToBuffer(void **connection, int sock, GPIBuffer *inputBuffer,
                           int *bytesRead, int *connClosed, char *id);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern void gpiCallErrorCallback(void **connection, int result, int fatal);
extern void gsDebugFormat(int cat, int type, int level, char *token);
extern void *gsirealloc(void *ptr, unsigned long size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern int gpiFindOperationByID(void **connection, void **operation, int id);
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
extern void *memcpy(void *dst, void *src, unsigned long n);
extern void *memmove(void *dst, void *src, unsigned long n);
extern int atoi(char *s);
extern int strncmp(char *a, char *b, unsigned long n);

extern char d_021A412C[], d_021A4130[], d_021A415C[], d_021A4164[];
extern char d_021A4170[], d_021A4180[], d_021A4188[], d_021A41B0[];
extern char d_021A41B8[], d_021A41C0[], d_021A41C8[], d_021A41D0[];
extern char d_021A41D8[], d_021A41E0[], d_021A41E8[], d_021A420C[];
extern char d_021A4234[];

int gpiProcessConnectionManager(void **connection)
{
    GPIConnection *ic;
    u32 now;
    int connClosed;
    int result;
    int bytesRead;
    int len;
    void *operation;
    int id;
    char *str;
    char *next;
    char *value;

    ic = (GPIConnection *)*connection;
    now = current_time();

retry:
    gpiAddLocalInfo(connection, (GPIBuffer *)&ic->localBuf);
    if (ic->f218 > 0)
        ic->lastSend = now;
    result = gpiSendFromBuffer(connection, ic->sock, (GPIBuffer *)&ic->localBuf,
                               &connClosed, 1, d_021A412C);
    if (result)
        return result;
    result = gpiRecvToBuffer(connection, ic->sock, (GPIBuffer *)&ic->recvBuf,
                             &bytesRead, &connClosed, d_021A412C);
    if (result == 0)
        goto process;
    if (result != 3)
        return result;
    gpiSetError(connection, 5, d_021A4130);
    gpiCallErrorCallback(connection, 3, 1);
    return 3;

process:
    str = strstr(ic->recvBuf, d_021A415C);
    if (str) {
dispatch:
        ic->lastSend = now;
        *str = 0;
        gsDebugFormat(1, 0, 0x20, d_021A4164);
        len = (int)(str - ic->recvBuf);
        if (len > ic->sendCap) {
            int grow;
            grow = len < 0x4000 ? 0x4000 : len;
            ic->sendCap = ic->sendCap + grow;
            next = (char *)gsirealloc(ic->sendBuf, ic->sendCap + 1);
            if (next == 0) {
                gpiSetErrorString(connection, d_021A4170);
                return 1;
            }
            ic->sendBuf = next;
        }
        memcpy(ic->sendBuf, ic->recvBuf, len + 1);
        ic->f200 = ic->f200 - ((str + 7) - ic->recvBuf);
        memmove(ic->recvBuf, str + 7, ic->f200 + 1);
        str = ic->sendBuf;
        next = strstr(str, d_021A4180);
        if (next) {
            id = atoi(next + 4);
            if (gpiFindOperationByID(connection, &operation, id)) {
                result = gpiProcessOperation(connection, operation, str);
                if (result)
                    return result;
            } else {
                gsDebugFormat(1, 0, 1, d_021A4188);
            }
        } else {
            if (gpiCheckForError(connection, str, 1))
                return 4;
            if (strncmp(str, d_021A41B0, 4) == 0) {
                result = gpiProcessRecvBuddyMessage(connection, str);
                if (result)
                    return result;
            } else if (strncmp(str, d_021A41B8, 4) == 0) {
                /* no-op */
            } else if (strncmp(str, d_021A41C0, 4) == 0) {
                value = (char *)((u8 *)&ic->f214 + 0x400);
                gpiValueForKey(str, d_021A41C0, value, 0x19);
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
        next = strstr(ic->recvBuf, d_021A415C);
        str = next;
        if (str)
            goto dispatch;
    }

    if (connClosed != 0 && ic->lastResult != 5) {
        gpiSetError(connection, 7, d_021A420C);
        gpiCallErrorCallback(connection, 3, 1);
        return 0;
    }
    if (gpiOperationsAreBlocking(connection)) {
        msleep(10);
        goto retry;
    }
    if ((int)(now - ic->lastSend) > 120000) {
        gpiAppendStringToBuffer(connection, (GPIBuffer *)&ic->localBuf, d_021A4234);
        ic->lastSend = now;
    }
    return 0;
}
