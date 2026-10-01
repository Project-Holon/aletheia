/*
 * function: func_02189780
 * address:  0x02189780
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 *
 * symbols:
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
 */

typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

extern int func_0217EC4C(int sock, char *buffer, int len, int flags);
extern int func_0217ED54(int sock);
extern char *func_0217EAC8(char *p, int size);
extern char *func_0217EAB0(int size);
extern void func_02092344(void *dst, const void *src, int n);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void func_0217EAE0(void *p);
extern void func_02193734(int *connection, int string);
extern char g_021A44C8[];
extern char g_021A453C[];
extern char g_021A4568[];
extern char g_021A458C[];
extern char g_021A45A0[];

static int sendCount = 0;

int func_02189780(int *connection, int sock, GPIBuffer *inputBuffer,
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
