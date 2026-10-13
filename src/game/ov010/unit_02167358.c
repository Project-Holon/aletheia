/*
 * file:     unit_02167358.c
 * function: func_02167358
 * address:  0x02167358
 * packet:   pkt_02167358
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02171F5D  0x02171F5D  data  a1
 *
 * Questionnaire table accessor: answer width in bits (first of the four-leaf run 0x02167358..0x021673A8):
 * returns byte 1 of the 4-byte record for id, 0 when id > 0x1d.  The record
 * table starts at 0x02171F5C; the pool word names the field address itself.
 * Unlabelled in the listing (no lr-saving prologue, callers all in arm9).
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 d_02171F5D[];
u8 func_02167358(u32 questionId)
{
    if (questionId > 0x1d)
        return 0;
    return d_02171F5D[questionId * 4];
}
