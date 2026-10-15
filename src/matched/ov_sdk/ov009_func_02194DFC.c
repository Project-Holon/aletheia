/*
 * function: gti2BufferWriteUShort
 * address:  0x02194DFC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Appends a 16-bit big-endian value to the byte buffer at *p, advancing the
 * length word at +8 for each half.
 *
 * symbols:
 *

 */

void gti2BufferWriteUShort(int *p, int v)
{
    ((unsigned char *)p[0])[p[2]++] = v >> 8;
    ((unsigned char *)p[0])[p[2]++] = v;
}


