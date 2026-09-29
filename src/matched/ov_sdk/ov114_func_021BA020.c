/*
 * function: func_021BA020
 * address:  0x021BA020
 * packet:   pkt_ov114_021BA020
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SocSend (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 *
 * symbols:
 *   func_021BA014 0x021BA014 arm ov114
 */

typedef struct {
    int doCancel;
} Req;

extern int func_021BA014(int socket, char *buf_p, int len, int flags);

int func_021BA020(Req *req_p, int socket, char *buf_p, int len, int flags)
{
    int error;

    error = func_021BA014(socket, buf_p, len, flags);
    if (error < 0) {
        if (req_p->doCancel != 0) {
            return -1002;
        }
        if (error == -56) {
            return 0;
        }
        return -1001;
    }
    return error;
}
