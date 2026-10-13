/*
 * function: gti2IncomingBufferMessageCompare
 * address:  0x02196658
 * packet:   pkt_ov009_02196658
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gti2SNDiff                   0x02195EB4  arm
*/

struct GTI2IncomingBufferMessage {
    int start;
    int len;
    int type;
    unsigned short serialNumber;
};

extern short gti2SNDiff(unsigned short a, unsigned short b);

int gti2IncomingBufferMessageCompare(void *elem1, void *elem2)
{
    return gti2SNDiff(((struct GTI2IncomingBufferMessage *)elem1)->serialNumber, ((struct GTI2IncomingBufferMessage *)elem2)->serialNumber);
}
