/*
 * function: ghiDoReceive
 * address:  0x021C04D4
 * packet:   pkt_ov114_021C04D4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoReceive (ghttpcommon.o)
 *
 * symbols:
 *   func_0217F264                    0x0217f264 arm  ov009
 *   ghiEncryptorSslReceiveFunc                    0x021c1c80 arm  ov114
 *   func_0217EC4C                    0x0217ec4c arm  ov009
 *   func_0217ED54                    0x0217ed54 arm  ov009
 *   func_0217D254                    0x0217d254 arm  ov009
 *   gGhttpThrottle                       0x021ce5ac data
 *   sGhttpReceivedBytes                       0x021ce60c data
 */

#include "../include/G_GHIThrottle.h"

typedef struct GHIThrottle GHIThrottle;

typedef struct GHIConnection {
    char pad0[0x40];
    int result;                 /* +0x040 */
    char pad44[0x50 - 0x44];
    int socket;                 /* +0x050 */
    int socketError;            /* +0x054 */
    char pad58[0x124 - 0x58];
    int completed;              /* +0x124 */
    char pad128[0x158 - 0x128];
    int connectionClosed;       /* +0x158 */
    int throttle;               /* +0x15c */
    unsigned int lastThrottleRecv; /* +0x160 */
    char pad164[0x194 - 0x164];
    char encryptor[4];          /* +0x194 */
    int engine;                 /* +0x198 */
    char pad19c[0x1a4 - 0x19c];
    int sessionEstablished;     /* +0x1a4 */
    char pad1a8[0x1ac - 0x1a8];
    int encryptOnSend;          /* +0x1ac */
} GHIConnection;

extern unsigned int func_0217F264(void);
extern int ghiEncryptorSslReceiveFunc(void *connection, void *encryptor, char *buffer, int *bufferLen);
extern int func_0217EC4C(int sock, char *buf, int len, int flags);
extern int func_0217ED54(int sock);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern struct GHIThrottle gGhttpThrottle;
extern char sGhttpReceivedBytes[];

int ghiDoReceive(GHIConnection *connection, char *buffer, int *bufferLen)
{
    int rcode;
    int socketError;
    int len;

    len = *bufferLen - 1;

    if (connection->throttle) {
        unsigned int now = func_0217F264();
        if (now < connection->lastThrottleRecv + gGhttpThrottle.timeDelay)
            return 1;
        connection->lastThrottleRecv = now;
        if (len >= gGhttpThrottle.bufferSize)
            len = gGhttpThrottle.bufferSize;
    }

    if (connection->engine != 0 && connection->sessionEstablished == 1 &&
        connection->encryptOnSend == 1) {
        int result;
        int recvLength = len;
        result = ghiEncryptorSslReceiveFunc(connection, connection->encryptor, buffer, &recvLength);
        if (result == 1) {
            if (recvLength == -1)
                return 1;
            rcode = recvLength;
        } else {
            connection->completed = 1;
            connection->result = 5;
            connection->socketError = 0;
            connection->connectionClosed = 1;
            return 3;
        }
    } else {
        rcode = func_0217EC4C(connection->socket, buffer, len, 0);
        if (rcode == -1) {
            socketError = func_0217ED54(connection->socket);
            if (socketError == -56) {
                connection->connectionClosed = 1;
                return 2;
            }
            if (socketError == -6 || socketError == -26 || socketError == -76)
                return 1;
            connection->socketError = socketError;
            connection->completed = 1;
            connection->result = 5;
            connection->connectionClosed = 1;
            return 3;
        }
    }

    if (rcode == 0) {
        connection->connectionClosed = 1;
        return 2;
    }

    buffer[rcode] = 0;
    *bufferLen = rcode;
    func_0217D254(8, 0, 0x20, sGhttpReceivedBytes, rcode);
    return 0;
}
