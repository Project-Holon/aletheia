/*
 * function: sciReportSetPlayerTeamIndex
 * address:  0x021DFFA0
 * packet:   pkt_ov175_021DFFA0
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciReportSetPlayerTeamIndex (libdwcgssc.TWL.HYB.a(scireport.o))
 *
 * notes:    the offset is built in steps (header size, the roster row, the
 *           16-byte connection id); the one-expression form swaps ip and r3.
 *
 * symbols:
 *   sciSerializeInt32  0x021E054C  arm  ov175
 */

struct SCIReport {
    char pad[0x124];
    unsigned char *buffer;
};

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *sciSerializeInt32(u8 *dst, u32 v);

int sciReportSetPlayerTeamIndex(struct SCIReport *report, unsigned int index, unsigned int team)
{
    unsigned int off;

    off = 0x44;
    off += index * 20;
    off += 16;
    sciSerializeInt32(report->buffer + off, team);
    return 0;
}
