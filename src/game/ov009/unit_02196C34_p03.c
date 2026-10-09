/*
 * file:     unit_02196C34_p03.c
 * unit:     yes
 * function: gti2ReceiveMessages, gti2StoreOutgoingReliableMessageInfo
 * address:  0x0219725C
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
 *   CanReceiveOnSocket               0x0217ef50 arm
 *   recvfrom                         0x0217ec60 arm
 *   GOAGetLastError                  0x0217ed54 arm
 *   gti2HandleConnectionReset        0x021970bc arm
 *   gti2HandleHostUnreachable        0x021971bc arm
 *   gti2SocketError                  0x021985e4 arm
 *   gti2HandleMessage                0x02196dc4 arm
 *   current_time  0x0217F264 arm
 *   ArrayLength   0x02184200 arm
 *   ArrayAppend   0x02184234 arm
 */
#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
struct GTI2Connection;
struct GTI2OutgoingBufferMessage;
struct DArrayImplementation;
struct GTI2Socket {
    int fd;                    /* +0x00 */
};

struct SOCSockAddrIn {
    unsigned char  len;
    unsigned char  family;
    unsigned short port;
    unsigned long  addr;
};

struct GTI2OutgoingBufferMessage {
    unsigned int offset;
    int len;
    unsigned short SN;
    unsigned short pad;
    unsigned int sendTime;
};

struct GTI2Connection {
    char pad00[0x58];
    unsigned int field_58;
    char pad5c[4];
    struct DArrayImplementation *outgoingBuffers;
};

extern int CanReceiveOnSocket(int sock);
extern int recvfrom(int sock, char *buf, int len, int flags,
                    struct SOCSockAddrIn *addr, int *fromlen);
extern int GOAGetLastError(int sock);
extern int gti2HandleConnectionReset(struct GTI2Socket *socket,
                                     unsigned int ip, unsigned short port);
extern int gti2HandleHostUnreachable(struct GTI2Socket *socket,
                                     unsigned int ip, unsigned short port,
                                     int send);
extern void gti2SocketError(struct GTI2Socket *socket);
extern int gti2HandleMessage(struct GTI2Socket *socket,
                             unsigned char *message, int len,
                             unsigned int ip, unsigned short port);
extern unsigned int current_time(void);
extern int ArrayLength(struct DArrayImplementation *array);
extern void ArrayAppend(struct DArrayImplementation *array, void *newElem);
int gti2ReceiveMessages(struct GTI2Socket *socket);


int gti2ReceiveMessages(struct GTI2Socket *socket)
{
    char buffer[1500];
    struct SOCSockAddrIn address;
    int addressLen;
    int rcode;

    if (CanReceiveOnSocket(socket->fd) != 0) {
        do {
            addressLen = 8;
            rcode = recvfrom(socket->fd, buffer, 1500, 0, &address,
                             &addressLen);
            if (rcode == -1) {
                int err = GOAGetLastError(socket->fd);
                if (err == -15) {
                    if (gti2HandleConnectionReset(socket, address.addr,
                                                  SWAP16(address.port)) != 0)
                        continue;
                    return 0;
                } else if (err == -23) {
                    if (gti2HandleHostUnreachable(socket, address.addr,
                                                  SWAP16(address.port), 0) != 0)
                        continue;
                    return 0;
                } else {
                    if (err == -35)
                        continue;
                    gti2SocketError(socket);
                    return 0;
                }
            } else {
                if (gti2HandleMessage(socket, (unsigned char *)buffer, rcode,
                                      address.addr, SWAP16(address.port)) == 0)
                    return 0;
            }
        } while (CanReceiveOnSocket(socket->fd) != 0);
    }
    return 1;
}


static int gti2StoreOutgoingReliableMessageInfo(struct GTI2Connection *connection,
                                                unsigned short SN, int len)
{
    struct GTI2OutgoingBufferMessage messageInfo = { 0 };
    int num;
    int result = 0;

    messageInfo.offset = connection->field_58;
    messageInfo.len = len;
    messageInfo.SN = SN;
    messageInfo.sendTime = current_time();
    num = ArrayLength(connection->outgoingBuffers);
    ArrayAppend(connection->outgoingBuffers, &messageInfo);
    if (ArrayLength(connection->outgoingBuffers) == (num + 1))
        result = 1;
    return result;
}
