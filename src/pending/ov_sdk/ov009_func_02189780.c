/*
 * function: func_02189780
 * address:  0x02189780
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (parked; not EXACT/MATCH)
 *
 * gpiRecvToBuffer: drain the socket into inputBuffer, growing it by 0x4000
 * bytes whenever len+0x4000 exceeds size, until recv stops making progress
 * (rcode < 0), the peer closes (rcode == 0), or 128 KiB have accumulated.
 * The three would-block/in-progress/timeout rcode values are tolerated;
 * anything else raises GP_NETWORK_ERROR.  Publishes buffer/size/len plus
 * *bytesRead and *connClosed.
 *
 * BLOCKER (codegen only, seven instructions, 20 concrete bytes): the GSIDebug
 * raw-dump call's `recvCount++`.  Declaring the counter `volatile` (below) is
 * the lever that gets the size and every relocation right: 524/524 bytes and
 * 17/17 sites resolved (it also lets g_021A4568 and g_021A458C attest, which
 * were previously unresolved).  The residue is that this front end lowers the
 * volatile post-increment as a read-for-the-argument plus a second read for
 * the read-modify-write:
 *
 *   image  ldr r0,[pc] ; ldr r3,[pc] fmt ; ldr r1,[r0,#4] count
 *          str r1,[sp] ; add r2,r1,#1 ; ldr r1,[pc] base ; str sl,[sp,#4]
 *          str r2,[r1,#4]
 *   ours   ldr r0,[pc] ; ldr r1,[r0,#4] count ; ldr r2,[r0,#4] count again
 *          mov r0,#1 ; add r3,r2,#1 ; ldr r2,[pc] base ; str r3,[r2,#4]
 *          stm sp,{r1,sl} ; ldr r3,[pc] fmt
 *
 * The image loads fmt before the counter, spills the old count with `str`
 * before the add, and uses `stm` only for count+id; ours loads the counter
 * twice, stores the increment before the spill, and combines the two vararg
 * spills into one `stm`.  Without `volatile` the body is 520 bytes / 147
 * concrete (the compact order the idiom records) and g_021A4568/g_021A458C do
 * not attest, so the volatile form is strictly closer.  Same argument-
 * scheduling idiom as func_021894D8 (docs/idioms/
 * a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer.md);
 * every non-volatile spelling in that note's list was re-measured here.
 *
 * The static traffic counters live in one struct at 0x021ADFC8: sendCount at
 * +0 (func_021894D8) and recvCount at +4 (here).
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
 *   g_021ADFC8     0x021ADFC8  data ov009 a4
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
extern void func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217EAE0(void *p);
extern void func_02193734(int *connection, int string);
extern char g_021A44C8[];
extern char g_021A453C[];
extern char g_021A4568[];
extern char g_021A458C[];
extern char g_021A45A0[];
typedef struct {
    int sendCount;
    volatile int recvCount;
} GSIDebugCounts;
extern GSIDebugCounts g_021ADFC8;

int func_02189780(int *connection, int sock, GPIBuffer *inputBuffer,
                  int *bytesRead, int *connClosed, char *id)
{
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
            func_0217D254(1, 0, 0x20, g_021A458C, g_021ADFC8.recvCount++, id, buf);
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
