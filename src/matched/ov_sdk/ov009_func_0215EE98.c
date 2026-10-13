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
 *   OS_DisableInterrupts  0x02087988  arm
 *   CPS_Resolve  0x0215C910  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021A82DC     0x021A82DC  data
 */

extern unsigned long g_021A82DC[2];
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long CPS_Resolve(char *name);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

unsigned long func_0215EE98(char *hostname)
{
    unsigned long hostip;
    unsigned long enable;
    unsigned long dns0;
    unsigned long dns1;

    enable = OS_DisableInterrupts();
    dns0 = g_021A82DC[0];
    dns1 = g_021A82DC[1];
    g_021A82DC[0] = 0;
    g_021A82DC[1] = 0;
    hostip = CPS_Resolve(hostname);
    g_021A82DC[0] = dns0;
    g_021A82DC[1] = dns1;
    OS_RestoreInterrupts(enable);
    return hostip;
}
