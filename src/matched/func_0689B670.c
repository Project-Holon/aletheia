/*
 * function: func_0689B670
 * address:  0x0689B670
 * packet:   pkt_0689B670
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the low seven bits of the byte at +0x92 and sets its top bit,
 * unless the top bit is already set.  The byte is a union of the whole
 * byte and a { lo:7, hi:1 } split, which is why the guard reads as the
 * lsls/lsrs bitfield pair and the two writes stay two stores.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad[0x92];
    union {
        u8 raw;
        struct {
            u8 lo : 7;
            u8 hi : 1;
        } b;
    } f;
};

void func_0689B670(struct S *s)
{
    if (s->f.b.hi)
        return;
    s->f.b.lo = 0;
    s->f.b.hi = 1;
}
