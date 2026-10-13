/*
 * function: resolve_sub
 * address:  0x0215C8B4
 * packet:   pkt_ov009_0215C8B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      resolve_sub (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   CPS_SocUse  0x0215AB10  arm  ov009
 *   CPS_SocDatagramMode  0x0215AA88  arm  ov009
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   resolve_common  0x0215C538  arm  ov009
 *   CPS_SocRelease  0x0215AB5C  arm  ov009
 */

extern void CPS_SocUse(void);
extern void CPS_SocDatagramMode(void);
extern void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long resolve_common(unsigned char *name, unsigned long type, unsigned short id, unsigned char *rname, unsigned long rname_max);
extern void CPS_SocRelease(void);

unsigned long resolve_sub(unsigned char *name, unsigned long dnsip, unsigned short id)
{
    unsigned long ip;

    if (dnsip == 0)
        return 0xffffffff;
    CPS_SocUse();
    CPS_SocDatagramMode();
    CPS_SocBind(0, 0x35, dnsip);
    ip = resolve_common(name, 1, id, 0, 0);
    CPS_SocRelease();
    return ip;
}
