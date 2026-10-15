/*
 * function: SOCL_InetAtoH
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
 *   gCpsDnsIp     0x021A82DC  data
 */

extern unsigned long gCpsDnsIp[2];
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long CPS_Resolve(char *name);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

unsigned long SOCL_InetAtoH(char *hostname)
{
    unsigned long hostip;
    unsigned long enable;
    unsigned long dns0;
    unsigned long dns1;

    enable = OS_DisableInterrupts();
    dns0 = gCpsDnsIp[0];
    dns1 = gCpsDnsIp[1];
    gCpsDnsIp[0] = 0;
    gCpsDnsIp[1] = 0;
    hostip = CPS_Resolve(hostname);
    gCpsDnsIp[0] = dns0;
    gCpsDnsIp[1] = dns1;
    OS_RestoreInterrupts(enable);
    return hostip;
}
