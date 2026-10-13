/*
 * function: ghiDoSend
 * address:  0x021C0684
 * packet:   pkt_ov114_021C0684
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoSend (libdwcgsghttp.TWL.HYB.a ghttpcommon.o)
 *
 * symbols:
 *   ghiEncryptorSslSendFunc  0x021c1c78  arm  ov114
 *   send           0x0217ec90  arm  ov009
 *   GOAGetLastError 0x0217ed54 arm  ov009
 */

typedef struct GHIConnection {
    unsigned char pad0[0x10];
    int f10;
    unsigned char pad1[0x40 - 0x14];
    int f40;
    unsigned char pad2[0x50 - 0x44];
    int f50;
    int f54;
    unsigned char pad3[0x124 - 0x58];
    int f124;
    unsigned char pad4[0x170 - 0x128];
    int f170;
    unsigned char pad5[0x180 - 0x174];
    int f180;
    unsigned char pad6[0x194 - 0x184];
    int f194;
    int f198;
    unsigned char pad7[0x1a4 - 0x19c];
    int f1a4;
    unsigned char pad8[0x1ac - 0x1a8];
    int f1ac;
} GHIConnection;

extern int ghiEncryptorSslSendFunc(void *a0, void *a1, char *a2, int a3, int *a4);
extern int send(int, char *, int, int);
extern int GOAGetLastError(int);

int ghiDoSend(GHIConnection *connection, char *buffer, int len)
{
    int rcode;
    int bytesSent;
    int error;

    if (buffer == 0 || len == 0)
        return 0;
    if (connection->f198 != 0 && connection->f1a4 == 1 && connection->f1ac == 1) {
        bytesSent = 0;
        if (ghiEncryptorSslSendFunc(connection, &connection->f194, buffer, len, &bytesSent) == 1) {
            rcode = bytesSent;
            if (rcode == -1)
                return -2;
        } else {
            connection->f124 = 1;
            connection->f40 = 5;
            connection->f54 = 0;
            return -1;
        }
    } else {
        rcode = send(connection->f50, buffer, len, 0);
        if (rcode == -1) {
            error = GOAGetLastError(connection->f50);
            if (error == -6 || error == -26 || error == -76)
                return 0;
            connection->f54 = error;
            connection->f124 = 1;
            connection->f40 = 5;
            return -1;
        }
    }
    if (connection->f10 == 6 && connection->f180 == 0)
        connection->f170 += rcode;
    return rcode;
}
