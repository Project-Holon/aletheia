/*
 * function: BufferAddByte
 * address:  0x0219FD40
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a byte through the pointer in *p, then advances the pointer and the counter.
 */

void BufferAddByte(unsigned char **p, unsigned char v, int *n)
{
    **p = v;
    (*n)++;
    (*p)++;
}
