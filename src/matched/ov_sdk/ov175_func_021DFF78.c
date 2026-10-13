/*
 * function: sciReportSetPlayerConnectionId
 * address:  0x021DFF78
 * packet:   pkt_ov175_021DFF78
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciReportSetPlayerConnectionId (libdwcgssc.TWL.HYB.a(scireport.o))
 *
 * notes:    the offset is built in steps (header size, then the roster row);
 *           the one-expression form swaps the buffer and offset registers.
 *
 * symbols:
 *   sciSerializeGUID  0x021E05AC  arm  ov175
 */

struct SCIReport {
    char pad[0x124];
    unsigned char *buffer;
};

extern unsigned char *sciSerializeGUID(unsigned char *cursor, unsigned char *guid);

int sciReportSetPlayerConnectionId(struct SCIReport *report, unsigned int index, unsigned char *connectionId)
{
    unsigned int off;

    off = 0x44;
    off += index * 20;
    sciSerializeGUID(report->buffer + off, connectionId);
    return 0;
}
