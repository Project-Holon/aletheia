/*
 * function: func_0218998C
 * address:  0x0218998C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiSendFromBuffer: push outputBuffer's pending bytes [pos, len) at the
 * socket through gpiSendData (func_021894D8), looping until nothing more is
 * sent or the buffer is drained.  With clipSentData the sent prefix is
 * memmoved out and len shrinks; otherwise pos advances.  Publishes the new
 * len/pos and, when connClosed is non-NULL, the closed flag.
 *
 * GPIBuffer here is DWC's field order {buffer, size, len, pos}: func_0218934C
 * treats +4 as size and +8 as len, while this routine reads len at +8 and
 * pos at +0xc.
 *
 * symbols:
 *   func_021894D8  0x021894D8  arm  ov009
 *   func_02092364  0x02092364  arm
 */

typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

extern int func_021894D8(int *connection, int sock, char *buffer, int bufferLen,
                         int *closed, int *sent, char *id);
extern void *func_02092364(void *dest, const void *src, unsigned int n);

int func_0218998C(int *connection, int sock, GPIBuffer *outputBuffer,
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
