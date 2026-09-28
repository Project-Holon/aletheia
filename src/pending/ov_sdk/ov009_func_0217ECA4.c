/*
 * function: sendto
 * address:  0x0217ECA4
 * packet:   pkt_ov009_0217ECA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * codegen: 8 bytes differ, pure register allocation swap (source pointer r5
 * vs dest r6); every other instruction is byte-identical. Not fixed by
 * declaration order, const, or a named dest pointer.
 *
 * sdk:      sendto (gsplatformsocket)
 *
 * symbols:
 *   SOC_SendTo       0x0215f5b4 arm
 *   CheckRcode       0x0217eb00 arm
 */

struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned char addr[4];
} __attribute__((packed));

extern int SOC_SendTo(int s, void * buf, int len, int flags, void * sockTo);
extern int CheckRcode(int rcode, int errCode);

int sendto(int sock, char * buf, int len, int flags, const struct SOCSockAddr * addr, int tolen)
{
    struct SOCSockAddr remoteAddr;
    int rcode;

    remoteAddr = *addr;
    remoteAddr.len = tolen;
    rcode = SOC_SendTo(sock, buf, len, flags, &remoteAddr);
    return CheckRcode(rcode, -1);
}
