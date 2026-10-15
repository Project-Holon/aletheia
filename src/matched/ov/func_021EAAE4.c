/*
 * function: BOX2_SEQ_SetDirtyBit
 * address:  0x021EAAE4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Set bit i of the 0x174-byte bitmap hung off p.
 *   Unsigned index, or mwccarm emits asr instead of the image's lsr.
 */


void BOX2_SEQ_SetDirtyBit(unsigned char *p, unsigned i)
{
    unsigned char *q = p + 0x174;
    q[i >> 3] |= (unsigned char)(1 << (i & 7));
}
