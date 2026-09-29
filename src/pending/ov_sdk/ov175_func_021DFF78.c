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
 * w4_nm tried: enum SCResult return, DWARF local rosterDataOffset, 5 call spellings,
 * and a sweep of constant splits (0x44 = A + B), init and call forms: 4 bytes remain
 * (buffer in ip instead of r0).
 *
 * w6_nm tried: `&buffer[off]` with char/unsigned char buffers, `= 0` init then
 * assignment, sizeof-based offsets, a const [16] GUID parameter, casts: 4 B remain.
 *
 * w7_nm tried: mBuffer as a one-member struct (`&r->mBuffer.mData[off]`), a
 *           buffer local and a Buf* local, a cursor local, `0x44 + 20 * idx`,
 *           a comma return: 4 B remain (a NULL check adds 35 B).
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
