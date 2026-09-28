/*
 * function: func_0215AAB0
 * address:  0x0215AAB0
 * packet:   pkt_ov009_0215AAB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SocBind (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_0215A970  0x0215A970  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 *   g_021A826C  0x021A826C  data
 */

extern char g_02150FEC[];
extern char g_021A826C[];
extern unsigned short func_0215A970(void);

void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc == 0)
        return;
    if (remote_ip == 0x7f000001)
        remote_ip = *(unsigned long *)(g_021A826C + 0x50);
    *(unsigned short *)(soc + 0x1a) = remote_port;
    *(unsigned short *)(soc + 0x18) = *(unsigned short *)(soc + 0x1a);
    *(unsigned long *)(soc + 0x20) = remote_ip;
    *(unsigned long *)(soc + 0x1c) = remote_ip;
    if (local_port != 0)
        *(unsigned short *)(soc + 0xa) = local_port;
    else
        *(unsigned short *)(soc + 0xa) = func_0215A970();
}
