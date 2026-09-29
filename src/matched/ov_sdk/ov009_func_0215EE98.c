/*
 * function: func_0215EE98
 * address:  0x0215EE98
 * packet:   pkt_ov009_0215EE98
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_InetAtoH (libsoc.TWL.HYB.a(socl_resolve.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0215C910  0x0215C910  arm  ov009
 *   func_0208799C  0x0208799C  arm
 *   g_021A82DC     0x021A82DC  data
 */

extern unsigned long g_021A82DC[2];
extern unsigned long func_02087988(void);
extern unsigned long func_0215C910(char *name);
extern unsigned long func_0208799C(unsigned long state);

unsigned long func_0215EE98(char *hostname)
{
    unsigned long hostip;
    unsigned long enable;
    unsigned long dns0;
    unsigned long dns1;

    enable = func_02087988();
    dns0 = g_021A82DC[0];
    dns1 = g_021A82DC[1];
    g_021A82DC[0] = 0;
    g_021A82DC[1] = 0;
    hostip = func_0215C910(hostname);
    g_021A82DC[0] = dns0;
    g_021A82DC[1] = dns1;
    func_0208799C(enable);
    return hostip;
}
