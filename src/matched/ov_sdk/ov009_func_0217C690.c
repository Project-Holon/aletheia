/*
 * function: func_0217C690
 * address:  0x0217C690
 * packet:   pkt_ov009_0217C690
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      get_sockaddrin (gsavailable.o)
 *
 * symbols:
 *   func_0217ED38                  0x0217ED38  arm ov009
 *   func_0215F650                  0x0215F650  arm ov009
 */

struct SOCSockAddrIn { unsigned char len; unsigned char family; unsigned short port; unsigned long addr; };
struct SOCHostEnt { char *name; char **aliases; short addrType; short length; unsigned char **addrList; };
extern unsigned long func_0217ED38(char *name);
extern struct SOCHostEnt *func_0215F650(char *name);
int func_0217C690(char *hostname, int port, struct SOCSockAddrIn *saddr)
{
    struct SOCHostEnt *host;
    saddr->family = 2;
    saddr->port = (unsigned short)((((unsigned short)port >> 8) & 0xff) | (((unsigned short)port << 8) & 0xff00));
    saddr->addr = func_0217ED38(hostname);
    if (saddr->addr == 0xFFFFFFFF) {
        host = func_0215F650(hostname);
        if (host == 0) return 0;
        saddr->addr = *(unsigned long *)host->addrList[0];
    }
    return 1;
}
