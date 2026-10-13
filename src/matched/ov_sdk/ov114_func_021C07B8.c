/*
 * function: ghiTrySendThenBuffer
 * address:  0x021C07B8
 * packet:   pkt_ov114_021C07B8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiTrySendThenBuffer (libdwcgsghttp.TWL.HYB.a(ghttpcommon.o))
 *
 * symbols:
 *   ghiEncryptDataToBuffer  0x021BFDEC arm ov114
 *   ghiSendBufferedData     0x021C011C arm ov114
 *   ghiResetBuffer          0x021C00FC arm ov114
 *   ghiDoSend               0x021C0684 arm ov114
 *   ghiAppendDataToBuffer   0x021BFCEC arm ov114
 *
 * The -2 exit must be the else of a two-guard if/else whose then-arm is the
 * -1 guard, with the `rcode == len` test as a separate if after it: that
 * places the shared `return 2` block between the return 0 and the len test
 * and keeps the -1 guard a real bne instead of a predicated return
 * (docs/idioms/a-bare-constant-return-guard-is-predicated-unless-its-exit-is-shared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov114_func_021C07B8.c \
 *     --func ghiTrySendThenBuffer --addr 0x021C07B8 --region ov114 --arm --cc 1.1p1 --lang c99
 *   (--cc 1.2 is byte-identical)
 */

typedef struct {
    char pad0[4];
    char *data;
    int size;
    int length;
    int pos;
    char pad1[12];
    int fixed;
    char pad2[4];
} GHIBuffer;

typedef struct GHIConnection {
    char pad0[0x58];
    GHIBuffer sendBuffer;
    char pad1[0x118];
    int encrypt;
    char pad2[8];
    int encryptState;
    int encryptSent;
} GHIConnection;

extern int ghiEncryptDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
extern int ghiSendBufferedData(GHIConnection *connection);
extern void ghiResetBuffer(GHIBuffer *buffer);
extern int ghiDoSend(GHIConnection *connection, char *buffer, int len);
extern int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);

int ghiTrySendThenBuffer(GHIConnection *connection, char *buffer, int len)
{
    int rcode = 0;
    if (connection->encrypt != 0 && connection->encryptState == 1 && connection->encryptSent == 1)
    {
        if (ghiEncryptDataToBuffer(&connection->sendBuffer, buffer, len) == 0)
            return 0;
        if (ghiSendBufferedData(connection) == 0)
            return 0;
        if (connection->sendBuffer.pos < connection->sendBuffer.length)
            return 2;
        ghiResetBuffer(&connection->sendBuffer);
        return 1;
    }
    if (connection->sendBuffer.pos >= connection->sendBuffer.length)
    {
        rcode = ghiDoSend(connection, buffer, len);
        if (rcode != -2) {
            if (rcode == -1)
                return 0;
        } else {
            return 2;
        }
        if (rcode == len)
            return 1;
    }
    if (ghiAppendDataToBuffer(&connection->sendBuffer, buffer + rcode, len - rcode) == 0)
        return 0;
    return 2;
}
