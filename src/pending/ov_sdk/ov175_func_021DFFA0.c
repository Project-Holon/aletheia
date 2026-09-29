/*
 * function: func_021DFFA0
 * address:  0x021DFFA0
 * packet:   pkt_ov175_021DFFA0
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      sciReportSetPlayerTeamIndex (libdwcgssc.TWL.HYB.a(scireport.o))
 *
 * NEAR MISS (4 B differ): register allocation only; the object holds the offset in ip and the buffer pointer in r3, the compiler here swaps them.
 *
 * w4_nm tried: the same sweep as sciReportSetPlayerConnectionId (0x54 = A + B,
 * enum return, init/call forms): 4 bytes remain (ip/r3 roles).
 *
 * symbols:
 *   func_021E054C  0x021E054C  arm  ov175
 */

struct SCIReport {
    char pad[0x124];
    unsigned char *buffer;
};

extern unsigned char *func_021E054C(unsigned char *cursor, int value);

int func_021DFFA0(struct SCIReport *report, unsigned int index, unsigned int team)
{
    unsigned int off = index * 20 + 0x54;

    func_021E054C(report->buffer + off, team);
    return 0;
}
