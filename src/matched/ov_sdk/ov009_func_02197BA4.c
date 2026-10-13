/*
 * function: gti2SendPong
 * address:  0x02197BA4
 * packet:   pkt_ov009_02197BA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gti2ConnectionSendData       0x02195750  arm
*/

extern int gti2ConnectionSendData(void *connection, unsigned char *message, int len);

int gti2SendPong(void *connection, unsigned char *message, int len)
{
    message[2] = 0x67;
    return gti2ConnectionSendData(connection, message, len);
}
