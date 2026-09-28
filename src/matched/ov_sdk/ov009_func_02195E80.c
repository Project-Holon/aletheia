/*
 * function: gti2UShortFromBuffer
 * address:  0x02195E80
 * packet:   pkt_ov009_02195E80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2UShortFromBuffer (gt2message.o)
 *
 * Reads a big-endian 16-bit value. The `& 0xff00` is what keeps the byte
 * in a separate register and preserves the original's `and` + `lsl #16`
 * truncation pair; a plain `(b0 << 8) | b1` folds to a different sequence.
 */

static unsigned short gti2UShortFromBuffer(unsigned char * buffer, int pos)
{
    unsigned short s;
    s = (unsigned short)((buffer[pos] << 8) & 0xff00);
    s |= buffer[pos + 1];
    return s;
}
