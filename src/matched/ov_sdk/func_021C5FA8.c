/*
 * function: func_021C5FA8
 * address:  0x021C5FA8
 * packet:   pkt_021C5FA8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C5FA8   0x021C5FA8  arm
 *
 * Bail out when a0 is at or past the count in the shared record's +0x51 byte,
 * then splice two 10-bit palette fields into the +4 halfword of the a1-th
 * sprite entry (fields at +0x10/table +0x42 and +0x24/table +0x48).
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_021C5FA8(int a0, int a1)
{
    u8 *g = (u8 *)0x021DE5D8;
    u8 *p = *(u8 **)(g + 4);
    int i;
    int mask = -0x400;
    u16 *d;

    if (a0 >= p[0x51])
        return;

    i = a0 * 0x2a;

    d = *(u16 **)(p + a1 * 4 + 0x10);
    d[2] = (d[2] & mask) | *(u16 *)(p + (*(u8 *)(*(int *)p + i + 0x28) << 1) + 0x42);

    p = *(u8 **)(g + 4);
    d = *(u16 **)(p + a1 * 4 + 0x24);
    d[2] = (d[2] & mask) | *(u16 *)(p + (*(u16 *)(*(int *)p + i + 0x26) << 1) + 0x48);
}
