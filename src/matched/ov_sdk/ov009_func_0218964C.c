/*
 * function: gpiSendOrBufferStringLenToPeer
 * address:  0x0218964C
 * packet:   pkt_ov009_0218964C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendOrBufferStringLenToPeer (gpibuffer.o)
 *
 * symbols:
 *   ArrayLength                          0x02184200  arm
 *   gsUdpEngineGetPeerOutBufferFreeSpace 0x021818EC  arm
 *   gsUdpEngineSendMessage               0x02181350  arm
 *   gpiAppendStringToBufferLen           0x021893C8  arm
 */

typedef unsigned int   u32;
typedef unsigned short u16;

struct GPIBuffer {
    char *buffer;  /* +0x00 */
    int   size;    /* +0x04 */
    int   len;     /* +0x08 */
    int   pos;     /* +0x0c */
};

struct GPIPeer_s {
    int  state;                        /* +0x00 */
    int  initiated;                    /* +0x04 */
    u32  ip;                           /* +0x08 */
    u16  port;                         /* +0x0c */
    u16  pad0e;                        /* +0x0e */
    int  profile;                      /* +0x10 */
    long timeout;                      /* +0x14 */
    int  nackCount;                    /* +0x18 */
    struct GPIBuffer inputBuffer;      /* +0x1c */
    struct GPIBuffer outputBuffer;     /* +0x2c */
    void *messages;                    /* +0x3c */
};

struct GPIConnection {
    char pad0[0x220];
    char mHeader[16];                  /* +0x220 */
};

extern int ArrayLength(void *array);
extern unsigned int gsUdpEngineGetPeerOutBufferFreeSpace(u32 theIp, u16 thePort);
extern int gsUdpEngineSendMessage(u32 theIp, u16 thePort, char *theHeader,
                                  unsigned char *theMsg, u32 theMsgLen,
                                  int theReliable);
extern int gpiAppendStringToBufferLen(void **connection,
                                      struct GPIBuffer *outputBuffer,
                                      char *string, int stringLen);

int gpiSendOrBufferStringLenToPeer(void **connection, struct GPIPeer_s *peer,
                                   char *string, int stringLen)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    unsigned int total = 0;
    unsigned int remaining;

    if (stringLen == 0)
        return 0;
    remaining = stringLen;
    if (peer->outputBuffer.len - peer->outputBuffer.pos == 0 &&
        ArrayLength(peer->messages) == 0) {
        unsigned int freeSpace =
            gsUdpEngineGetPeerOutBufferFreeSpace(peer->ip, peer->port);
        if (stringLen <= (int)freeSpace - 0x17) {
            gsUdpEngineSendMessage(peer->ip, peer->port, iconnection->mHeader,
                                   (unsigned char *)string, stringLen, 1);
            total = stringLen;
            remaining = 0;
        } else {
            freeSpace =
                gsUdpEngineGetPeerOutBufferFreeSpace(peer->ip, peer->port);
            if (freeSpace > 0x17) {
                total = freeSpace - 0x17;
                gsUdpEngineSendMessage(peer->ip, peer->port,
                                       iconnection->mHeader,
                                       (unsigned char *)string, total, 1);
                remaining = stringLen - total;
            }
        }
    }
    if (remaining != 0) {
        int result = gpiAppendStringToBufferLen(connection, &peer->outputBuffer,
                                                string + total, remaining);
        if (result != 0)
            return result;
    }
    return 0;
}
