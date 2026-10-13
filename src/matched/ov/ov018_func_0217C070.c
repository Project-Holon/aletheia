/*
 * function: INTRUDE_FIELD_IsStartRequested
 * address: 0x0217C070
 * packet: pkt_ov018_0217C070
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: byte bitfield at +0x93f emits the original shift pair.
 * symbols:
 *   INTRUDE_COMM_IsRequestFromSelf 0x02176258 thumb ov011
 */
typedef unsigned char u8;
typedef struct { u8 bit:1; u8 rest:7; } Bits;
extern int INTRUDE_COMM_IsRequestFromSelf(u8 *);
int INTRUDE_FIELD_IsStartRequested(u8 *p)
{
    if (((Bits *)(p + 0x93f))->bit == 1 || INTRUDE_COMM_IsRequestFromSelf(p) == 1)
        return 1;
    return 0;
}
