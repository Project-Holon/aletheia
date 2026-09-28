/*
 * function: SOCL_GetHostID
 * address:  0x0215ef48
 * packet:   pkt_ov009_0215EF48
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_GetHostID (socl_resolve.o)
 *
 * symbols:
 *   CPSMyIp            0x021a82bc data
 *   SOCLiDhcpState     0x021aa448 data
 *   SOCLiRequestedIP   0x021aa444 data
 *   OS_GetProcMode     0x020879ec arm
 *   OS_Sleep           0x02085a38 arm
 */

extern unsigned long CPSMyIp;
extern unsigned long SOCLiDhcpState;
extern unsigned long SOCLiRequestedIP;
extern int OS_GetProcMode(void);
extern void OS_Sleep(unsigned long msec);

unsigned long SOCL_GetHostID(void)
{
    if (CPSMyIp == 0) {
        if ((SOCLiDhcpState & 3) == 1 && OS_GetProcMode() != 0x12)
            OS_Sleep(10);
    } else {
        if (SOCLiRequestedIP == 0)
            SOCLiRequestedIP = CPSMyIp;
    }
    return CPSMyIp;
}
