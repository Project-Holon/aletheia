/*
 * function: dhcp_discover_server
 * address:  0x0215C2F8
 * packet:   pkt_ov009_0215C2F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dhcp_discover_server (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   CPS_SocUse  0x0215AB10  arm  ov009
 *   CPS_SocDatagramMode  0x0215AA88  arm  ov009
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   dhcp_send_discover  0x0215BD8C  arm  ov009
 *   dhcp_analyze_response  0x0215BF88  arm  ov009
 *   CPS_SocRelease  0x0215AB5C  arm  ov009
 */

extern void CPS_SocUse(void);
extern void CPS_SocDatagramMode(void);
extern void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long dhcp_send_discover(void);
extern int dhcp_analyze_response(unsigned long id, int retry);
extern void CPS_SocRelease(void);

int dhcp_discover_server(void)
{
    int result;
    int retry;

    CPS_SocUse();
    CPS_SocDatagramMode();
    CPS_SocBind(0x44, 0x43, 0xffffffff);
    for (retry = 0; retry < 5; retry++) {
        result = dhcp_analyze_response(dhcp_send_discover(), retry);
        if (result == 1)
            break;
    }
    CPS_SocRelease();
    return result == 1;
}
