/*
 * function: func_02162DD8
 * address:  0x02162DD8
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021619CC  0x021619CC  arm  ov009
 *   CPSi_TcpWrite2Raw  0x0215B198  arm  ov009
 *
 * Flush a queued request when the object reached through +0xc is in state 8:
 * a 7-byte header is laid down on the stack, func_021619CC fills the rest of
 * the buffer and returns its length, and that buffer (plus the length) is
 * handed to CPSi_TcpWrite2Raw along with the two zero flags and this object.  The
 * state byte is cleared either way.
 */

typedef unsigned char u8;

void func_02162DD8(void *p)
{
    u8 *q;
    u8 buf[0x1c];

    q = *(u8 **)((u8 *)p + 0xc);
    if (q[0x455] == 8) {
        buf[0] = 0x15;
        buf[1] = 3;
        buf[2] = 0;
        buf[3] = 0;
        buf[4] = 2;
        buf[5] = 1;
        buf[6] = 0;
        CPSi_TcpWrite2Raw(buf, func_021619CC(q, buf), 0, 0, p);
    }
    q[0x455] = 0;
}
