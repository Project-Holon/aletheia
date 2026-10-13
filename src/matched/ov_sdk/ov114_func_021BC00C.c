/*
 * function: NHTTPi_SkipLineBuf
 * address:  0x021BC00C
 * packet:   pkt_ov114_021BC00C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SkipLineBuf (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_SocRecv 0x021B9F94 arm ov114
 */

typedef unsigned int   u32;
extern int NHTTPi_SocRecv(int a, u32 *b, int c, int d, int e, int f);

int NHTTPi_SkipLineBuf(void *mutexInfo_p, void *req_p, int socket)
{
    char buf[2];
    int p;
    int recvbyte;
    int rc;

    rc = 0;
    p = 0;
    buf[0] = 0;
    buf[1] = 0;
    while (!(buf[p & 1] == '\r' && buf[(p - 1) & 1] == '\n')) {
        recvbyte = NHTTPi_SocRecv((int)mutexInfo_p, req_p, socket, (int)(&buf[p & 1]), 1, 0);
        if (recvbyte <= 0) {
            return recvbyte;
        }
        rc += recvbyte;
        p++;
    }
    return rc;
}
