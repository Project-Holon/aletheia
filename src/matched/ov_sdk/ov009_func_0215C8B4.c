/*
 * function: func_0215C8B4
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
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_0215AA88  0x0215AA88  arm  ov009
 *   func_0215AAB0  0x0215AAB0  arm  ov009
 *   func_0215C538  0x0215C538  arm  ov009
 *   func_0215AB5C  0x0215AB5C  arm  ov009
 */

extern void func_0215AB10(void);
extern void func_0215AA88(void);
extern void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long func_0215C538(unsigned char *name, unsigned long type, unsigned short id, unsigned char *rname, unsigned long rname_max);
extern void func_0215AB5C(void);

unsigned long func_0215C8B4(unsigned char *name, unsigned long dnsip, unsigned short id)
{
    unsigned long ip;

    if (dnsip == 0)
        return 0xffffffff;
    func_0215AB10();
    func_0215AA88();
    func_0215AAB0(0, 0x35, dnsip);
    ip = func_0215C538(name, 1, id, 0, 0);
    func_0215AB5C();
    return ip;
}
