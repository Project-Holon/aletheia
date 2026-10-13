/*
 * function: NHTTPi_resolveHostname
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
 *   SOC_InetAtoN 0x0215FAD0 arm
 *   SOC_GetHostByName 0x0215F650 arm
 *   NHTTPi_memcpy 0x021BA100 arm ov114
 */

typedef struct {
    char pad[0xa];
    short h_length;
    char **h_addr_list;
} SOCHostEnt;

typedef struct {
    unsigned long addr;
} SOCInAddr;

extern int SOC_InetAtoN(char *cp, SOCInAddr *inp);
extern SOCHostEnt *SOC_GetHostByName(char *name);
extern void NHTTPi_memcpy(void *dst_p, void *src_p, int size);

unsigned long NHTTPi_resolveHostname(int unused, char *hostname_p)
{
    SOCHostEnt *hostEnt;
    unsigned long addr = 0;
    SOCInAddr inAddr;

    if (SOC_InetAtoN(hostname_p, &inAddr)) {
        addr = inAddr.addr;
    } else {
        hostEnt = SOC_GetHostByName(hostname_p);
        if (hostEnt && hostEnt->h_length > 0) {
            NHTTPi_memcpy(&addr, *hostEnt->h_addr_list, 4);
        }
    }
    return addr;
}
