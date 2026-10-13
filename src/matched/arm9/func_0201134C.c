/*
 * function: VM_GetU32
 * address:  0x0201134C
 * packet:   pkt_0201134C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: read a big-endian u32 from the cursor at +0x14 of
 * the object and advance the cursor by four.  The four bytes are assembled
 * MSB-first: buf[3]<<24 | buf[2]<<16 | buf[1]<<8 | buf[0].
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Cursor {
    u8 pad_00[0x14];
    u8 *buf;
};

u32 VM_GetU32(struct Cursor *p)
{
    u8 *b = p->buf;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 v;

    b0 = b[0];
    p1 = b + 1;
    p2 = p1 + 1;
    p->buf = p1;
    b1 = b[1];
    p3 = p2 + 1;
    p->buf = p2;
    b2 = p1[1];
    p->buf = p3;
    b3 = p2[1];
    p->buf = p3 + 1;

    v = 0;
    v += b3;
    v <<= 8;
    v += b2;
    v <<= 8;
    v += b1;
    v <<= 8;
    v += b0;
    return v;
}
