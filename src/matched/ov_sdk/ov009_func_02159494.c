/*
 * function: _tcp_send_finack
 * address:  0x02159494
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call that supplies the second argument 0x11.
 *
 * symbols:
 *   _tcp_send_handshake  0x021593A8  arm
 */

extern void _tcp_send_handshake(char *soc, unsigned char flag);

void _tcp_send_finack(int a)
{
    _tcp_send_handshake((char *)a, 0x11);
}

