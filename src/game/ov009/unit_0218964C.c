/*
 * file:     unit_0218964C.c
 * unit:     yes
 * function: func_0218964C, func_02189750, func_02189780, func_0218998C, func_02189A7C, func_02189BE4, func_02189D28
 * address:  0x0218964C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ArrayLength                          0x02184200  arm
 *   gsUdpEngineGetPeerOutBufferFreeSpace 0x021818EC  arm
 *   gsUdpEngineSendMessage               0x02181350  arm
 *   gpiAppendStringToBufferLen           0x021893C8  arm
 *   strlen                          0x0209477C  arm
 *   func_0217EC4C  0x0217EC4C  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_0217EAC8  0x0217EAC8  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02092344  0x02092344  arm
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   g_021A44C8     0x021A44C8  data ov009
 *   g_021A453C     0x021A453C  data ov009
 *   g_021A4568     0x021A4568  data ov009
 *   g_021A458C     0x021A458C  data ov009
 *   g_021A45A0     0x021A45A0  data ov009
 *   sendCount      0x021ADFC8  data ov009
 *   _ZZ13func_02189780PiiP9GPIBufferS_S_PcE9recvCount 0x021ADFCC data
 *   func_021894D8  0x021894D8  arm  ov009
 *   func_02092364  0x02092364  arm
 *   func_021818EC  0x021818ec  arm   ov009
 *   func_02181350  0x02181350  arm   ov009
 *   func_02181010  0x02181010  arm   ov009
 *   strchr         0x02094a28  arm
 *   strncmp        0x020949f4  arm
 *   func_02193418  0x02193418  arm   ov009
 *   atoi           0x020964e0  arm
 *   g_021A45B4     0x021a45b4  data
 *   g_021A45BC     0x021a45bc  data
 *   g_021A45C0     0x021a45c0  data
 */
struct GPIPeer_s;
typedef unsigned int   u32;

typedef unsigned short u16;

struct GPIBuffer_0218964C {
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
    struct GPIBuffer_0218964C inputBuffer;      /* +0x1c */
    struct GPIBuffer_0218964C outputBuffer;     /* +0x2c */
    void *messages;                    /* +0x3c */
};

struct GPIConnection {
    char pad0[0x220];
    char mHeader[16];                  /* +0x220 */
};

typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer_02189780;

typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer_0218998C;

typedef struct {
    char *buffer;
    int size;
    unsigned int len;
    unsigned int pos;
} GPIBuffer_02189A7C;

typedef struct {
    char pad[0x220];
    char header[1];
} GPIConnection;

typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer_02189BE4;

typedef struct GPIBuffer_02189D28 {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer_02189D28;

extern int ArrayLength(void *array);
extern unsigned int gsUdpEngineGetPeerOutBufferFreeSpace(u32 theIp, u16 thePort);
extern int gsUdpEngineSendMessage(u32 theIp, u16 thePort, char *theHeader,
                                  unsigned char *theMsg, u32 theMsgLen,
                                  int theReliable);
extern int gpiAppendStringToBufferLen(void **connection,
                                      struct GPIBuffer_0218964C *outputBuffer,
                                      char *string, int stringLen);
extern int strlen(char *s);
extern int func_0217EC4C(int sock, char *buffer, int len, int flags);
extern int func_0217ED54(int sock);
extern char *func_0217EAC8(char *p, int size);
extern char *func_0217EAB0(int size);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217EAE0(void *p);
extern void func_02193734(int *connection, int string);
extern int func_021894D8(int *connection, int sock, char *buffer, int bufferLen,
                         int *closed, int *sent, char *id);
extern void *func_02092364(void *dest, const void *src, unsigned int n);
extern int func_021818EC(unsigned int ip, unsigned short port);
extern int func_02181350(unsigned int ip, unsigned short port, char *header, unsigned char *msg, unsigned int len, int reliable);
extern int func_02181010(unsigned int ip, unsigned short port, int *state);
extern char *strchr(const char *, int);
extern int strncmp(const char *, const char *, unsigned int);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
extern int atoi(const char *);
int gpiSendOrBufferStringLenToPeer(void **connection, struct GPIPeer_s *peer, char *string, int stringLen);
int gpiSendOrBufferString(void **connection, struct GPIPeer_s *peer, char *string);
int func_02189780(int *connection, int sock, GPIBuffer_02189780 *inputBuffer, int *bytesRead, int *connClosed, char *id);
int func_0218998C(int *connection, int sock, GPIBuffer_0218998C *outputBuffer, int *connClosed, int clipSentData, char *id);
int func_02189A7C(GPIConnection **connection, unsigned int ip, unsigned short port, GPIBuffer_02189A7C *outputBuffer, int *closed, int clipSentData);
int func_02189BE4(int unused, GPIBuffer_02189BE4 *inputBuffer, char **message, int *type, int *plen);
int func_02189D28(void **unused, GPIBuffer_02189D28 *buffer);
extern char g_021A44C8[];
extern char g_021A453C[];
extern char g_021A4568[];
extern char g_021A458C[];
extern char g_021A45A0[];
extern char g_021A45B4[];
extern char g_021A45BC[];
extern char g_021A45C0[];


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


int gpiSendOrBufferString(void **connection, struct GPIPeer_s *peer,
                          char *string)
{
    return gpiSendOrBufferStringLenToPeer(connection, peer, string,
                                          strlen(string));
}


static int sendCount = 0;


/*
 * sdk:      gpiRecvToBuffer (GameSpy gp, C++ object stamped 4.0.0.1025)
 *
 * gpiRecvToBuffer: drain the socket into inputBuffer, growing it by 0x4000
 * bytes whenever len+0x4000 exceeds size, until recv stops making progress,
 * the peer closes, or 128 KiB have accumulated. Publishes buffer/size/len
 * plus *bytesRead and *connClosed.
 *
 * 2026-10-01 (w3 lane28): closed. recvCount is a function-local static
 * (lever 3, as sibling func_021894D8). The vendor reloc is
 * gpiSendData's sendCount + 4: both counters sit in this object's .bss with
 * sendCount first, so the load is `[anchor, #4]`. The file-scope
 * `static int sendCount = 0;` models that preceding static (a tentative def
 * lands after recvCount instead). No volatile needed.
 */
int func_02189780(int *connection, int sock, GPIBuffer_02189780 *inputBuffer,
                  int *bytesRead, int *connClosed, char *id)
{
    static int recvCount;
    char *buffer;
    int len;
    int size;
    int rcode;
    int total;
    int closed;

    buffer = inputBuffer->buffer;
    len = inputBuffer->len;
    size = inputBuffer->size;
    total = 0;
    closed = 0;

    do {
        if ((len + 0x4000) > size) {
            size = len + 0x4000;
            buffer = func_0217EAC8(buffer, size + 1);
            if (buffer == 0) {
                func_02193734(connection, (int)g_021A44C8);
                return 1;
            }
            inputBuffer->buffer = buffer;
            inputBuffer->size = size;
        }

        rcode = func_0217EC4C(sock, &buffer[len], size - len, 0);

        if (rcode == -1) {
            int error = func_0217ED54(sock);
            if (error != -6 && error != -26 && error != -76) {
                func_02193734(connection, (int)g_021A453C);
                return 3;
            }
        } else if (rcode == 0) {
            closed = 1;
            func_0217D254(1, 0, 0x10, g_021A4568, id);
        } else {
            char *buf = func_0217EAB0(rcode + 1);

            func_02092344(buf, &buffer[len], rcode);
            buf[rcode] = 0;
            func_0217D254(1, 0, 0x20, g_021A458C, recvCount++, id, buf);
            func_0217EAE0(buf);
            len += rcode;
            total += rcode;
        }

        buffer[len] = 0;
    } while ((rcode >= 0) && !closed && (total < 0x20000));

    if (total != 0) {
        func_0217D254(1, 0, 0x20, g_021A45A0, id, total);
    }

    inputBuffer->buffer = buffer;
    inputBuffer->len = len;
    inputBuffer->size = size;
    *bytesRead = total;
    *connClosed = closed;
    return 0;
}


/*
 * gpiSendFromBuffer: push outputBuffer's pending bytes [pos, len) at the
 * socket through gpiSendData (func_021894D8), looping until nothing more is
 * sent or the buffer is drained.  With clipSentData the sent prefix is
 * memmoved out and len shrinks; otherwise pos advances.  Publishes the new
 * len/pos and, when connClosed is non-NULL, the closed flag.
 *
 * GPIBuffer here is DWC's field order {buffer, size, len, pos}: func_0218934C
 * treats +4 as size and +8 as len, while this routine reads len at +8 and
 * pos at +0xc.
 */
int func_0218998C(int *connection, int sock, GPIBuffer_0218998C *outputBuffer,
                  int *connClosed, int clipSentData, char *id)
{
    int closed;
    int sent;
    int total;
    int remaining;
    char *buffer;
    int pos;
    int len;
    int result;

    buffer = outputBuffer->buffer;
    len = outputBuffer->len;
    pos = outputBuffer->pos;
    remaining = len - pos;
    total = 0;

    if (remaining == 0)
        return 0;

    do {
        result = func_021894D8(connection, sock, &buffer[pos + total], remaining, &closed, &sent, id);
        if (result != 0)
            return result;
        if (sent) {
            total += sent;
            remaining -= sent;
        }
    } while (sent && remaining);

    if (clipSentData) {
        if (total > 0) {
            func_02092364(buffer, &buffer[total], remaining + 1);
            len -= total;
        }
    } else {
        pos += total;
    }

    outputBuffer->len = len;
    outputBuffer->pos = pos;
    if (connClosed != 0)
        *connClosed = closed;
    return 0;
}


/*
 * sdk:      gpiSendBufferToPeer (libdwcgsgp.TWL.HYB.a gpibuffer.o)
 */
int func_02189A7C(GPIConnection **connection, unsigned int ip, unsigned short port,
                  GPIBuffer_02189A7C *outputBuffer, int *closed, int clipSentData)
{
    GPIConnection *iconnection;
    unsigned int remaining;
    unsigned char *buffer;
    unsigned int pos;
    unsigned int len;
    unsigned int total;
    int aPeerState;
    unsigned int freeSpace;
    unsigned int sendAmount;

    len = outputBuffer->len;
    iconnection = *connection;
    pos = outputBuffer->pos;
    buffer = (unsigned char *)outputBuffer->buffer;
    remaining = len - pos;
    total = 0;
    if (remaining == 0)
        return 0;

    freeSpace = func_021818EC(ip, port) - 23;
    if ((int)remaining <= (int)freeSpace) {
        func_02181350(ip, port, iconnection->header, buffer + pos, remaining, 1);
        total = remaining;
        remaining = 0;
    } else {
        do {
            sendAmount = func_021818EC(ip, port) - 23;
            if (sendAmount <= 23)
                break;
            if (func_02181350(ip, port, iconnection->header, &buffer[pos + total], sendAmount, 1) == 8)
                break;
            total += sendAmount;
            remaining -= sendAmount;
        } while (remaining != 0);
    }

    if (clipSentData) {
        if (total != 0) {
            func_02092364(buffer, buffer + total, remaining + 1);
            len -= total;
        }
    } else {
        pos += total;
    }
    outputBuffer->len = len;
    outputBuffer->pos = pos;
    func_02181010(ip, port, &aPeerState);
    if (aPeerState == 3)
        *closed = 1;
    else
        *closed = 0;
    return 0;
}


/*
 * sdk:      gpiReadMessageFromBuffer (libdwcgsgp.TWL.HYB.a gpibuffer.o)
 */
int func_02189BE4(int unused, GPIBuffer_02189BE4 *inputBuffer, char **message, int *type, int *plen)
{
    char intValue[16];
    int len;
    char *str;

    *message = 0;
    if (inputBuffer->len < 5)
        return 0;
    str = strchr(inputBuffer->buffer, '\n');
    if (str != 0) {
        if (strncmp(str - 5, g_021A45B4, 5) != 0)
            return 3;
        *str = 0;
        if (!func_02193418(inputBuffer->buffer, g_021A45BC, intValue, 16))
            return 3;
        *type = atoi(intValue);
        if (!func_02193418(inputBuffer->buffer, g_021A45C0, intValue, 16))
            return 3;
        len = atoi(intValue);
        if (inputBuffer->len > len + 1 + (str - inputBuffer->buffer)) {
            if (str[len + 1] != 0)
                return 3;
            *message = str + 1;
            *plen = len;
            inputBuffer->pos = len + 1 + (str - inputBuffer->buffer) + 1;
        } else {
            *str = '\n';
        }
    }
    return 0;
}


/*
 * sdk:      gpiClipBufferToPosition (gpibuffer.o)
 */
int func_02189D28(void **unused, GPIBuffer_02189D28 *buffer)
{
    if (buffer == 0 || buffer->buffer == 0 || buffer->pos == 0)
        return 0;
    buffer->len -= buffer->pos;
    if (buffer->len != 0)
        func_02092364(buffer->buffer, buffer->buffer + buffer->pos, buffer->len);
    buffer->buffer[buffer->len] = 0;
    buffer->pos = 0;
    return 0;
}
