/*
 * function: func_021B9CFC
 * address:  0x021B9CFC
 * packet:   pkt_ov114_021B9CFC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SocClose (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 *
 * symbols:
 *   func_0215F644 0x0215F644 arm
 *   func_02085A38 0x02085A38 arm
 *   func_0215EBB4 0x0215EBB4 arm
 *   func_021BA850 0x021BA850 arm ov114
 */

typedef struct {
    char pad[0xac];
    void *pSslCon;
} Req;

extern int func_0215F644(int socket);
extern void func_02085A38(unsigned long msec);
extern void func_0215EBB4(void);
extern void func_021BA850(int a);

int func_021B9CFC(int unused, Req *req_p, int socket)
{
    int error;
    int elapsed;

    error = func_0215F644(socket);
    if (error == 0 || error == -26) {
        for (elapsed = 0; (error = func_0215F644(socket)) == -26 && elapsed <= 10000; elapsed += 500) {
            func_02085A38(500);
            func_0215EBB4();
        }
    }
    if (error != -26 && req_p != 0 && req_p->pSslCon != 0) {
        func_021BA850((int)req_p->pSslCon);
        req_p->pSslCon = 0;
    }
    return error;
}
