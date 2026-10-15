/*
 * function: CPS_SocGetLength
 * address:  0x0215B504
 * packet:   pkt_ov009_0215B504
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SocGetLength (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   _tcp_send_ack  0x02159404  arm  ov009
 *   CPSi_SslGetLength  0x02162C28  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 */

extern char g_02150FEC[];
extern void _tcp_send_ack(void *soc, int flush);
struct CPSSoc;
extern long CPSi_SslGetLength(struct CPSSoc *soc);

long CPS_SocGetLength(void)
{
    long count;
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 4)
            _tcp_send_ack(soc, 1);
        if (*(unsigned char *)(soc + 9) != 0)
            return CPSi_SslGetLength((struct CPSSoc *)soc);
        count = *(long *)(soc + 0x50);
        if (count != 0)
            return count;
        if (*(unsigned char *)(soc + 8) == 4)
            return count;
        if (*(unsigned char *)(soc + 8) == 10 || *(unsigned char *)(soc + 8) == 11)
            return count;
        return -1;
    }
    return 0;
}
