/*
 * function: OEKAKI_StoreLastPoints
 * address:  0x02185DA8
 * packet:   pkt_ov023_02185DA8
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

struct e6 {
    unsigned char b[4];
    unsigned char c : 3;
    unsigned char n : 3;
    unsigned char d : 2;
    unsigned char pad;
};

struct o4 {
    unsigned char x;
    unsigned char y;
    unsigned short n;
};

void OEKAKI_StoreLastPoints(struct e6 *e, struct o4 *o)
{
    int i;

    for (i = 0; i < 5; i++) {
        o[i].n = e[i].n;
        if (e[i].n != 0) {
            o[i].x = *((unsigned char *)&e[i] + e[i].n - 1);
            o[i].y = *((unsigned char *)&e[i] + e[i].n + 1);
        }
    }
}
