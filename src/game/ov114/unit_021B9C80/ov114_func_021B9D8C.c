/*
 * function: func_021B9D8C
 * address:  0x021B9D8C
 * packet:   pkt_ov114_021B9D8C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SocConnect (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 *
 * symbols:
 *   func_021B9E3C 0x021B9E3C arm ov114
 *   func_0215F480 0x0215F480 arm
 */

typedef struct {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned long addr;
} SOCSockAddrIn;

typedef struct {
    int doCancel;
    char pad[4];
    int isSSL;
    int hasSSLCon;
} Req;

extern int func_021B9E3C(void *bgnEndInfo_p, void *mutexInfo_p, Req *req_p, int socket);
extern int func_0215F480(int s, void *sockAddr);

int func_021B9D8C(void *bgnEndInfo_p, void *mutexInfo_p, Req *req_p, int socket, unsigned long hostaddr, int port)
{
    SOCSockAddrIn scadr;
    int error;

    scadr.len = 8;
    scadr.family = 2;
    scadr.port = (unsigned short)(((((unsigned short)port) >> 8) & 0xff) | (((unsigned short)port) << 8 & 0xff00));
    scadr.addr = hostaddr;
    if (req_p->isSSL != 0 && req_p->hasSSLCon == 0) {
        error = func_021B9E3C(bgnEndInfo_p, mutexInfo_p, req_p, socket);
        if (error < 0) {
            return error;
        }
    }
    error = func_0215F480(socket, &scadr);
    if (error < 0) {
        if (req_p->doCancel != 0) {
            return -1002;
        }
        return -1001;
    }
    return 0;
}
