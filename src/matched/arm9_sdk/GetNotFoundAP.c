/*
 * function: GetNotFoundAP
 * address:  0x0205D1C4
 * packet:   pkt_0205D1C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef struct {
    u8 pad00[0xb];
    u8 findAP : 4;
    u8 ipCollision : 4;
} ACHOLD;

int GetNotFoundAP(ACHOLD *hd)
{
    if (hd->findAP == 0) {
        return -50099;
    }
    return -51099;
}
