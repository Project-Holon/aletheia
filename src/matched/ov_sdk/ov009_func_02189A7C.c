/*
 * function: func_02189A7C
 * address:  0x02189A7C
 * packet:   pkt_ov009_02189A7C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendBufferToPeer (libdwcgsgp.TWL.HYB.a gpibuffer.o)
 *
 * symbols:
 *   func_021818EC  0x021818ec  arm   ov009
 *   func_02181350  0x02181350  arm   ov009
 *   func_02092364  0x02092364  arm
 *   func_02181010  0x02181010  arm   ov009
 */

typedef struct {
    char *buffer;
    int size;
    unsigned int len;
    unsigned int pos;
} GPIBuffer;
typedef struct {
    char pad[0x220];
    char header[1];
} GPIConnection;
extern int func_021818EC(unsigned int ip, unsigned short port);
extern int func_02181350(unsigned int ip, unsigned short port, char *header, unsigned char *msg, unsigned int len, int reliable);
extern void *func_02092364(void *dest, const void *src, unsigned int n);
extern int func_02181010(unsigned int ip, unsigned short port, int *state);

int func_02189A7C(GPIConnection **connection, unsigned int ip, unsigned short port,
                  GPIBuffer *outputBuffer, int *closed, int clipSentData)
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
