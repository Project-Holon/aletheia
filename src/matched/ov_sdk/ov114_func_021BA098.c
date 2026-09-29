/*
 * function: func_021BA098
 * address:  0x021BA098
 * packet:   pkt_ov114_021BA098
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_resolveHostname (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 *
 * symbols:
 *   func_0215FAD0 0x0215FAD0 arm
 *   func_0215F650 0x0215F650 arm
 *   func_021BA100 0x021BA100 arm ov114
 */

typedef struct {
    char pad[0xa];
    short h_length;
    char **h_addr_list;
} SOCHostEnt;

typedef struct {
    unsigned long addr;
} SOCInAddr;

extern int func_0215FAD0(char *cp, SOCInAddr *inp);
extern SOCHostEnt *func_0215F650(char *name);
extern void func_021BA100(void *dst_p, void *src_p, int size);

unsigned long func_021BA098(int unused, char *hostname_p)
{
    SOCHostEnt *hostEnt;
    unsigned long addr = 0;
    SOCInAddr inAddr;

    if (func_0215FAD0(hostname_p, &inAddr)) {
        addr = inAddr.addr;
    } else {
        hostEnt = func_0215F650(hostname_p);
        if (hostEnt && hostEnt->h_length > 0) {
            func_021BA100(&addr, *hostEnt->h_addr_list, 4);
        }
    }
    return addr;
}
