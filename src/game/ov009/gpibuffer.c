/*
 * file:     gpibuffer.c
 * unit:     yes
 * function: gpiAppendCharToBuffer, gpiAppendStringToBufferLen, gpiAppendStringToBuffer, gpiAppendIntToBuffer, gpiSendData, gpiSendOrBufferChar, gpiSendOrBufferStringLenToPeer, gpiSendOrBufferString, gpiRecvToBuffer, gpiSendFromBuffer, gpiSendBufferToPeer, gpiReadMessageFromBuffer, gpiClipBufferToPosition
 * address:  0x0218934C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Constant zero: the compiled-out body of a three-argument buffer send
 * helper (connection, peer, character); its caller only tests the result.
 *
 * symbols:
 *   gsirealloc  0x0217EAC8  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   g_021A44C8     0x021A44C8  data
 *   memcpy  0x02092344  arm
 *   strlen  0x0209477C  arm
 *   OS_SPrintf  0x02084F40  arm
 *   g_021A44D8     0x021A44D8  data
 *   send  0x0217EC90  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   gpiSetError  0x02193710  arm  ov009
 *   gpiCallErrorCallback  0x02189D78  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   g_021A44DC     0x021A44DC  data ov009
 *   g_021A4504     0x021A4504  data ov009
 *   g_021A4528     0x021A4528  data ov009
 *   _ZZ11gpiSendDataPiiPciS_S_S0_E9sendCount 0x021ADFC8 data
 *   ArrayLength                          0x02184200  arm
 *   gsUdpEngineGetPeerOutBufferFreeSpace 0x021818EC  arm
 *   gsUdpEngineSendMessage               0x02181350  arm
 *   gpiAppendStringToBufferLen           0x021893C8  arm
 *   strlen                          0x0209477C  arm
 *   recv  0x0217EC4C  arm  ov009
 *   g_021A453C     0x021A453C  data ov009
 *   g_021A4568     0x021A4568  data ov009
 *   g_021A458C     0x021A458C  data ov009
 *   g_021A45A0     0x021A45A0  data ov009
 *   _ZZ14gpiRecvToBufferPiiP9GPIBufferS_S_PcE9recvCount 0x021ADFCC data
 *   memmove  0x02092364  arm
 *   gsUdpEngineGetPeerOutBufferFreeSpace  0x021818ec  arm   ov009
 *   gsUdpEngineSendMessage  0x02181350  arm   ov009
 *   gsUdpEngineGetPeerState  0x02181010  arm   ov009
 *   strchr         0x02094a28  arm
 *   strncmp        0x020949f4  arm
 *   gpiValueForKey  0x02193418  arm   ov009
 *   atoi           0x020964e0  arm
 *   g_021A45B4     0x021a45b4  data
 *   g_021A45BC     0x021a45bc  data
 *   g_021A45C0     0x021a45c0  data
 */
#include "darray.h"
#include "gsdebug.h"
#include "gpibuffer.h"
#include "gpi_types.h"

#include "gsmemory.h"
#include "gpiutility.h"
#include "../arm9/msl_string_mem.h"
#include "../arm9/os_printf.h"
#include "gsplatformsocket.h"
#include "gpicallback.h"
extern int gsUdpEngineGetPeerOutBufferFreeSpace(u32 theIp, u16 thePort);
extern int gsUdpEngineSendMessage(u32 theIp, u16 thePort, char *theHeader,
                                  unsigned char *theMsg, u32 theMsgLen,
                                  int theReliable);
extern int gsUdpEngineGetPeerState(unsigned int ip, unsigned short port, int *state);
int gpiSendOrBufferChar(void **connection, GPIPeer *peer, char c);
int gpiSendOrBufferStringLenToPeer(void **connection, GPIPeer *peer, char *string, int stringLen);
int gpiSendOrBufferString(void **connection, GPIPeer *peer, char *string);
int gpiSendBufferToPeer(GPIConnection **connection, unsigned int ip, unsigned short port, GPIBuffer *outputBuffer, int *closed, int clipSentData);
int gpiReadMessageFromBuffer(void **connection, GPIBuffer *inputBuffer, char **message, int *type, int *plen);
int gpiClipBufferToPosition(void **unused, GPIBuffer *buffer);
extern char g_021A44C8[];
extern char g_021A44D8[];
extern char g_021A44DC[];
extern char g_021A4504[];
extern char g_021A4528[];
extern char g_021A453C[];
extern char g_021A4568[];
extern char g_021A458C[];
extern char g_021A45A0[];
extern char g_021A45B4[];
extern char g_021A45BC[];
extern char g_021A45C0[];



#include "../arm9/msl_string_str.h"
#include "../arm9/msl_strtod.h"
/*
 * gpiAppendCharToBuffer: append one character to a GPIBuffer (0=data,
 * 4=size, 8=len), growing the backing store by 0x4000 bytes when full.
 */
int gpiAppendCharToBuffer(void **connection, GPIBuffer *buffer, int c)
{
    int len = buffer->len;
    int size = buffer->size;
    char *data;

    data = buffer->buffer;
    if (size == len) {
        size += 0x4000;
        data = gsirealloc(data, size + 1);
        if (data == 0) {
            gpiSetErrorString(connection, g_021A44C8);
            return 1;
        }
    }
    data[len] = c;
    data[len + 1] = 0;
    buffer->buffer = data;
    buffer->len += 1;
    buffer->size = size;
    return 0;
}



/*
 * gpiAppendDataToBuffer: append `n` bytes of `src` to a GPIBuffer
 * (0=data, 4=size, 8=len).  Grows the store by max(0x4000, n) when the
 * free tail is shorter than n, then NUL-terminates.
 */
int gpiAppendStringToBufferLen(void **connection, GPIBuffer *buffer, const char *src, int n)
{
    int buflen;
    int size;
    char *data;

    if (src == 0)
        return 0;
    buflen = buffer->len;
    size = buffer->size;
    data = buffer->buffer;
    if (size - buflen < n) {
        int grow = 0x4000;
        if (n >= grow)
            grow = n;
        size += grow;
        data = gsirealloc(data, size + 1);
        if (data == 0) {
            gpiSetErrorString(connection, g_021A44C8);
            return 1;
        }
    }
    memcpy(data + buflen, src, n);
    data[buflen + n] = 0;
    buffer->size = size;
    buffer->len += n;
    buffer->buffer = data;
    return 0;
}



/*
 * gpiAppendStringToBuffer: append a NUL-terminated string's bytes to a
 * GPIBuffer, its length supplied by strlen.
 */
int gpiAppendStringToBuffer(void **connection, GPIBuffer *buffer, const char *string)
{
    return gpiAppendStringToBufferLen(connection, buffer, string, strlen(string));
}



/*
 * gpiAppendIntToBuffer: format the integer with sprintf("%d") into a small
 * stack buffer, then append that string to the GPIBuffer.
 */
int gpiAppendIntToBuffer(void **connection, GPIBuffer *buffer, int value)
{
    char buf[0x10];

    OS_SPrintf(buf, g_021A44D8, value);
    return gpiAppendStringToBuffer(connection, buffer, buf);
}



/*
 * gpiSendData (static helper of gpiSendFromBuffer): one send() on the socket.
 * On -1/GOAGetLastError outside the three would-block/in-progress/timeout
 * codes, a "PR" peer id returns GP_NETWORK_ERROR immediately, else raise
 * GP_NETWORK on the connection and return GP_NETWORK_ERROR.  On rcode == 0
 * mark the connection closed; otherwise raw-dump the sent bytes through the
 * GSIDebug network logger and account them in the static sendCount.
 *
 * BLOCKER (codegen only, 21 bytes at +0x118..+0x138): the whole function is
 * the right size (364) and every other byte is identical, but the GSIDebug
 * raw-dump call schedules `sendCount++` differently.  The original loads the
 * format pointer into r3 *before* the counter (base r1, fmt r3, count r2,
 * stm sp,{r2,r6}, add r2,#1, str r2,[r1]); this front end instead does the
 * counter first (base r0, base r1, count r3, add, str, stm sp,{r3,sl}) and
 * rematerialises the format address after the increment.  Tried: scalar vs
 * array vs struct-member counter, a named count local, a `register` local,
 * both-fmt-and-count locals, a pointer-to-counter local, an unprototyped
 * callee, and void/int callee returns; all reproduce the same order.  Every
 * other call site in this file (the error path and the rcode==0 branch) is
 * byte-exact.  Not a witness problem: the three literals and both gsiSet
 * underlays all resolve; this is the mwcc argument-scheduling heuristic for
 * a post-increment in a varargs list.  Documented as docs/idioms/
 * a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer.md.
 *
 * Re-verified 2026-09-27 (region ov009 / ARM confirmed): still 364/364 with
 *   the same 21 bytes at +0x118..+0x138; all 13 relocations resolve, so the
 *   only cap is the argument-scheduling quirk.  Not promotable to MATCH (real
 *   bytes differ), so it stays parked.
 *
 * lane U41 (2026-09-30).  Re-measured: still 364/364 with the same 21 bytes at
 * +0118..+0138, 13/13 relocations resolved.  Six more spellings measured, all
 * 21 diffs: `int c = sendCount++;` passed as the argument, the pre-increment
 * split into two statements, `c = ...` in a later statement, `(int)` and
 * `(unsigned)` casts on the post-increment, and the increment moved after the
 * call (that one is 34).  Residue unchanged and named: the argument scheduler
 * picks r3 for the counter and computes `count + 1` into r2 before the vararg
 * store, where the image keeps the counter in r2 and increments it in place
 * after `stm sp, {r2, r6}`.
 *
 * lane T5 (2026-09-30).  Pin sweep (all 9 dsi compilers x 4 flag sets): no
 * configuration moves the 21 bytes at +0118..+0138; 1.1p1 -O4,p at 364/21 is the
 * unique best.  Residue unchanged and already named: the GSIDebug raw-dump call
 * schedules `sendCount++` before the format pointer (see
 * docs/idioms/a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer.md).
 *
 * lane W8 (2026-09-30): re-measured 364/364, 13/13 relocations, 21 concrete.
 *   New spellings tried: `const char *fmt = g_021A4528;` then `fmt` + inline
 *   `sendCount++` (same 21, compactor already sinks the fmt load); sequential
 *   `int count = g_021ADFC8; char *fmt = g_021A4528; ... g_021ADFC8 = count+1;`
 *   which does place the fmt load between the counter load and its store but
 *   resizes to 368/117 (extra callee-saved).  Residue unchanged: mwcc sinks the
 *   format-pointer load below the counter RMW and colours the counter r3.
 *
 * lane W7 (2026-09-30): re-measured 364/364, 13/13 relocations, 21 concrete
 * bytes.  Re-tested the counter as a `cnt` temp with the increment before the
 * call (368/117), after the call (368/119) and passing `g_021ADFC8 + 1` then
 * incrementing (368/71); all are worse and change the size, confirming the
 * image's push-then-writeback order is the mwcc argument scheduler.
 *
 * lane04 (2026-10-01): EXACT. The vendor relocation names
 * `_ZZ11gpiSendData...E9sendCount`, a function-local static. Declaring
 * `static int sendCount;` inside the function closes all 21 bytes (a file-scope
 * static or a block-scope extern does not): the counter's address never
 * escapes, so the varargs scheduler keeps it in r2 and loads fmt first. Its
 * `.bss` relocation resolves through the symbols line naming the compiled
 * local static (mangled with this file's function name). Also restored the
 * DWARF gsDebugFormat prototype (`(int,int,int,char *,int,...)` did not
 * compile).
 */
int gpiSendData(int *connection, int sock, char *buffer, int bufferLen,
                  int *closed, int *sent, char *id)
{
    static int sendCount;
    int rcode = send(sock, buffer, bufferLen, 0);

    if (rcode == -1) {
        rcode = GOAGetLastError(sock);
        if (rcode != -6 && rcode != -26 && rcode != -76) {
            if (id[0] == 'P' && id[1] == 'R')
                return 3;
            gpiSetError((void **)connection, 5, g_021A44DC);
            gpiCallErrorCallback((void **)connection, 3, 0);
            return 3;
        }
        *sent = 0;
        *closed = 0;
    } else if (rcode == 0) {
        gsDebugFormat(1, 0, 0x10, g_021A4504, id);
        *sent = 0;
        *closed = 1;
    } else {
        char *buf = gsimalloc(rcode + 1);

        memcpy(buf, buffer, rcode);
        buf[rcode] = 0;
        gsDebugFormat(1, 0, 0x20, g_021A4528, sendCount++, id, buf);
        gsifree(buf);
        *sent = rcode;
        *closed = 0;
    }
    return 0;
}

int gpiSendOrBufferChar(void **connection, GPIPeer *peer, char c)
{
    return 0;
}



int gpiSendOrBufferStringLenToPeer(void **connection, GPIPeer *peer,
                                   char *string, int stringLen)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
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
                                                (string + total), remaining);
        if (result != 0)
            return result;
    }
    return 0;
}



int gpiSendOrBufferString(void **connection, GPIPeer *peer,
                          char *string)
{
    return gpiSendOrBufferStringLenToPeer(connection, peer, string,
                                          strlen(string));
}




/*
 * sdk:      gpiRecvToBuffer (GameSpy gp, C++ object stamped 4.0.0.1025)
 *
 * gpiRecvToBuffer: drain the socket into inputBuffer, growing it by 0x4000
 * bytes whenever len+0x4000 exceeds size, until recv stops making progress,
 * the peer closes, or 128 KiB have accumulated. Publishes buffer/size/len
 * plus *bytesRead and *connClosed.
 *
 * 2026-10-01 (w3 lane28): closed. recvCount is a function-local static
 * (lever 3, as sibling gpiSendData). The vendor reloc is
 * gpiSendData's sendCount + 4: both counters sit in this object's .bss with
 * sendCount first, so the load is `[anchor, #4]`. No volatile needed.
 */
int gpiRecvToBuffer(void **connection, int sock, GPIBuffer *inputBuffer,
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
            buffer = gsirealloc(buffer, size + 1);
            if (buffer == 0) {
                gpiSetErrorString(connection, g_021A44C8);
                return 1;
            }
            inputBuffer->buffer = buffer;
            inputBuffer->size = size;
        }

        rcode = recv(sock, &buffer[len], size - len, 0);

        if (rcode == -1) {
            int error = GOAGetLastError(sock);
            if (error != -6 && error != -26 && error != -76) {
                gpiSetErrorString(connection, g_021A453C);
                return 3;
            }
        } else if (rcode == 0) {
            closed = 1;
            gsDebugFormat(1, 0, 0x10, g_021A4568, id);
        } else {
            char *buf = gsimalloc(rcode + 1);

            memcpy(buf, &buffer[len], rcode);
            buf[rcode] = 0;
            gsDebugFormat(1, 0, 0x20, g_021A458C, recvCount++, id, buf);
            gsifree(buf);
            len += rcode;
            total += rcode;
        }

        buffer[len] = 0;
    } while ((rcode >= 0) && !closed && (total < 0x20000));

    if (total != 0) {
        gsDebugFormat(1, 0, 0x20, g_021A45A0, id, total);
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
 * socket through gpiSendData (gpiSendData), looping until nothing more is
 * sent or the buffer is drained.  With clipSentData the sent prefix is
 * memmoved out and len shrinks; otherwise pos advances.  Publishes the new
 * len/pos and, when connClosed is non-NULL, the closed flag.
 *
 * GPIBuffer here is DWC's field order {buffer, size, len, pos}: gpiAppendCharToBuffer
 * treats +4 as size and +8 as len, while this routine reads len at +8 and
 * pos at +0xc.
 */
int gpiSendFromBuffer(void **connection, int sock, GPIBuffer *outputBuffer,
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
        result = gpiSendData((int *)connection, sock, &buffer[pos + total], remaining, &closed, &sent, id);
        if (result != 0)
            return result;
        if (sent) {
            total += sent;
            remaining -= sent;
        }
    } while (sent && remaining);

    if (clipSentData) {
        if (total > 0) {
            memmove(buffer, &buffer[total], remaining + 1);
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
int gpiSendBufferToPeer(GPIConnection **connection, unsigned int ip, unsigned short port,
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

    freeSpace = gsUdpEngineGetPeerOutBufferFreeSpace(ip, port) - 23;
    if ((int)remaining <= (int)freeSpace) {
        gsUdpEngineSendMessage(ip, port, iconnection->mHeader, buffer + pos, remaining, 1);
        total = remaining;
        remaining = 0;
    } else {
        do {
            sendAmount = gsUdpEngineGetPeerOutBufferFreeSpace(ip, port) - 23;
            if (sendAmount <= 23)
                break;
            if (gsUdpEngineSendMessage(ip, port, iconnection->mHeader, &buffer[pos + total], sendAmount, 1) == 8)
                break;
            total += sendAmount;
            remaining -= sendAmount;
        } while (remaining != 0);
    }

    if (clipSentData) {
        if (total != 0) {
            memmove(buffer, buffer + total, remaining + 1);
            len -= total;
        }
    } else {
        pos += total;
    }
    outputBuffer->len = len;
    outputBuffer->pos = pos;
    gsUdpEngineGetPeerState(ip, port, &aPeerState);
    if (aPeerState == 3)
        *closed = 1;
    else
        *closed = 0;
    return 0;
}



/*
 * sdk:      gpiReadMessageFromBuffer (libdwcgsgp.TWL.HYB.a gpibuffer.o)
 */
int gpiReadMessageFromBuffer(void **connection, GPIBuffer *inputBuffer, char **message, int *type, int *plen)
{
    char intValue[16];
    int len;
    char *str;

    *message = 0;
    if (inputBuffer->len < 5)
        return 0;
    str = (char *)strchr(inputBuffer->buffer, '\n');
    if (str != 0) {
        if (strncmp((str - 5), g_021A45B4, 5) != 0)
            return 3;
        *str = 0;
        if (!gpiValueForKey(inputBuffer->buffer, g_021A45BC, intValue, 16))
            return 3;
        *type = atoi(intValue);
        if (!gpiValueForKey(inputBuffer->buffer, g_021A45C0, intValue, 16))
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
int gpiClipBufferToPosition(void **unused, GPIBuffer *buffer)
{
    if (buffer == 0 || buffer->buffer == 0 || buffer->pos == 0)
        return 0;
    buffer->len -= buffer->pos;
    if (buffer->len != 0)
        memmove(buffer->buffer, buffer->buffer + buffer->pos, buffer->len);
    buffer->buffer[buffer->len] = 0;
    buffer->pos = 0;
    return 0;
}
