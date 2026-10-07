/*
 * file:     unit_0215F428_p03.c
 * unit:     yes
 * function: func_0215F590, func_0215F5B4
 * address:  0x0215F590
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SOCL_WriteTo   0x0215e024 arm
 */
struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

extern int SOCL_WriteTo(int s, void *buffer, int buffer_len,
                        unsigned short remote_port, unsigned long remote_ip,
                        int flags);
int SOC_Recv(int s, void *buf, int len, int flags);
int SOC_SendTo(int s, void * buf, int len, int flags, void * sockTo);


int SOC_Recv(int s, void *buf, int len, int flags)
{
    return SOCL_WriteTo(s, buf, len, 0, 0, flags);
}


int SOC_SendTo(int s, void * buf, int len, int flags, void * sockTo)
{
    struct SOCSockAddrIn * addr = (struct SOCSockAddrIn *)sockTo;
    unsigned short port;
    unsigned long ip;

    if (sockTo != 0) {
        port = addr->port;
        ip = addr->addr;
        port = (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00));
        ip = ((ip >> 24) & 0xff) | ((ip >> 8) & 0xff00) | ((ip << 8) & 0xff0000)
           | ((ip << 24) & 0xff000000);
    } else {
        port = 0;
        ip = 0;
    }
    return SOCL_WriteTo(s, buf, len, port, ip, flags);
}
