/*
 * function: CTVT_COMM_FindPeerName
 * address:  0x021B85D0
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * True when one of three 6-byte records at +0x22 matches the probe string.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int CTVT_COMM_FindPeerName(unsigned char *p, unsigned char *q);

int CTVT_COMM_FindPeerName(unsigned char *p, unsigned char *q)
{
    unsigned char i;

    for (i = 0; i < 3; i++) {
        unsigned char j;
        int ok = 1;

        for (j = 0; j < 6; j++) {
            if (p[i * 6 + j + 0x22] != q[j]) {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            return 1;
        }
    }
    return 0;
}
