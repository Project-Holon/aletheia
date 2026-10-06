/*
 * function: func_021596A8
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
 *   func_02159244  0x02159244  arm  ov009
 *   func_021595C0  0x021595C0  arm  ov009
 *   func_021594A4  0x021594A4  arm  ov009
 */

extern char *func_02159244(unsigned char *iphdr, unsigned char *tcphdr);
struct _CPSSoc;
extern void func_021595C0(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
extern void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);

unsigned long func_021596A8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
    char *soc = func_02159244(iphdr, tcphdr);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 1) {
            func_021595C0(iphdr, tcphdr, (struct _CPSSoc *)soc);
        } else if (*(unsigned char *)(soc + 8) == 3) {
            *(long *)(soc + 0x34) = *(long *)(soc + 0x34) - 1;
            func_021595C0(iphdr, tcphdr, (struct _CPSSoc *)soc);
        } else {
            func_021594A4(iphdr, tcphdr, len);
        }
        return 1;
    }
    return 0;
}
