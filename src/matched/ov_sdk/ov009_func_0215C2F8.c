/*
 * function: func_0215C2F8
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
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_0215AA88  0x0215AA88  arm  ov009
 *   func_0215AAB0  0x0215AAB0  arm  ov009
 *   func_0215BD8C  0x0215BD8C  arm  ov009
 *   func_0215BF88  0x0215BF88  arm  ov009
 *   func_0215AB5C  0x0215AB5C  arm  ov009
 */

extern void func_0215AB10(void);
extern void func_0215AA88(void);
extern void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long func_0215BD8C(void);
extern int func_0215BF88(unsigned long id, int retry);
extern void func_0215AB5C(void);

int func_0215C2F8(void)
{
    int result;
    int retry;

    func_0215AB10();
    func_0215AA88();
    func_0215AAB0(0x44, 0x43, 0xffffffff);
    for (retry = 0; retry < 5; retry++) {
        result = func_0215BF88(func_0215BD8C(), retry);
        if (result == 1)
            break;
    }
    func_0215AB5C();
    return result == 1;
}
