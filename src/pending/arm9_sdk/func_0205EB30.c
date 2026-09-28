/*
 * function: func_0205EB30
 * address:  0x0205EB30
 * packet:   pkt_0205EB30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    prologue, key xors, db64 call and table copy match; the cycle-walk loop does not. The image keeps two registers for the same u8 index (ctable_inv[lr] and ctable_inv[r2] both reloaded, 0xff store through the old lr address); every spelling tried (512 brute-forced variants, permuter seed 12202) CSEs them into one. Needs the index-aliasing shape.
 *
 * sdk:      decodeSSID (libdwcac.TWL.HYB.a(shop_usb.o))
 *
 * symbols:
 *   db64                             0x0205ee98 arm
 *   SHMASKkey0                       0x020a80b0 data
 *   g_020A1688                       0x020A1688 data
 *   g_020A80B0                       0x020A80B0 data
 */

typedef struct CTable {
    unsigned char b[24];
} CTable;

extern const CTable g_020A1688;
extern char *g_020A80B0[4];
extern int db64(char *src, unsigned char *dest, unsigned long srcsize, unsigned long destsize);

void func_0205EB30(char *ssid, unsigned char *buf)
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
        srcnum = (unsigned char)i;
        destnum = srcnum;
        src = buf[i];
        while (ctable_inv.b[srcnum] != 0xff) {
            destnum = ctable_inv.b[destnum];
            dest = buf[destnum];
            ctable_inv.b[srcnum] = 0xff;
            buf[destnum] = src;
            src = dest;
            srcnum = destnum;
        }
    }
    for (i = 0; i < 24; i++) {
        buf[i] = buf[i] ^ g_020A80B0[0][i];
    }
}
