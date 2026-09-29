/*
 * function: func_021DFF78
 * address:  0x021DFF78
 * packet:   pkt_ov175_021DFF78
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      sciReportSetPlayerConnectionId (libdwcgssc.TWL.HYB.a(scireport.o))
 *
 * NEAR MISS (4 B differ): register allocation only; the object uses r0 for the buffer pointer and r3 for the offset add, the compiler here picks ip for the pointer.
 *
 * symbols:
 *   func_021E05AC  0x021E05AC  arm  ov175
 */

struct SCIReport {
    char pad[0x124];
    unsigned char *buffer;
};

extern unsigned char *func_021E05AC(unsigned char *cursor, unsigned char *guid);

int func_021DFF78(struct SCIReport *report, unsigned int index, unsigned char *connectionId)
{
    unsigned int off = index * 20 + 0x44;

    func_021E05AC(report->buffer + off, connectionId);
    return 0;
}
