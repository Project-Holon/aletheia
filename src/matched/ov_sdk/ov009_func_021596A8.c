/*
 * function: find_specific_socket
 * address:  0x021596A8
 * packet:   pkt_ov009_021596A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      find_specific_socket (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   find_socket  0x02159244  arm  ov009
 *   dt_syn_LISTEN  0x021595C0  arm  ov009
 *   _tcp_send_rst  0x021594A4  arm  ov009
 */

extern char *find_socket(unsigned char *iphdr, unsigned char *tcphdr);
struct _CPSSoc;
extern void dt_syn_LISTEN(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
extern void _tcp_send_rst(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);

unsigned long find_specific_socket(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
    char *soc = find_socket(iphdr, tcphdr);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 1) {
            dt_syn_LISTEN(iphdr, tcphdr, (struct _CPSSoc *)soc);
        } else if (*(unsigned char *)(soc + 8) == 3) {
            *(long *)(soc + 0x34) = *(long *)(soc + 0x34) - 1;
            dt_syn_LISTEN(iphdr, tcphdr, (struct _CPSSoc *)soc);
        } else {
            _tcp_send_rst(iphdr, tcphdr, len);
        }
        return 1;
    }
    return 0;
}
