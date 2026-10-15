/*
 * function: decodeSSID
 * address:  0x0205EB30
 * packet:   pkt_0205EB30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      decodeSSID (shop_usb.o)
 *
 * symbols:
 *   db64 0x0205EE98 arm
 *   g_020A1688 0x020A1688 data
 *   g_020A80B0 0x020A80B0 data
 */

typedef struct CTable {
    unsigned char b[24];
} CTable;

extern const CTable g_020A1688;
extern char *g_020A80B0[4];
extern int db64(char *src, unsigned char *dest, unsigned long srcsize, unsigned long destsize);

void decodeSSID(char *ssid, unsigned char *buf)
{
    int i;
    CTable ctable_inv;
    unsigned char destnum;
    unsigned char dest;
    unsigned char srcnum;
    unsigned char src;

    ctable_inv = g_020A1688;
    db64(ssid, buf, 32, 24);
    for (i = 0; i < 24; i++) {
        buf[i] = buf[i] ^ g_020A80B0[2][i];
    }
    for (i = 0; i < 24; i++) {
        destnum = (unsigned char)i;
        srcnum = (unsigned char)i;
        src = buf[i];
        while (ctable_inv.b[srcnum] != 0xff) {
            dest = buf[ctable_inv.b[srcnum]];
            buf[ctable_inv.b[destnum]] = src;
            destnum = ctable_inv.b[srcnum];
            ctable_inv.b[srcnum] = 0xff;
            srcnum = destnum;
            src = dest;
        }
    }
    for (i = 0; i < 24; i++) {
        buf[i] = buf[i] ^ g_020A80B0[0][i];
    }
}
