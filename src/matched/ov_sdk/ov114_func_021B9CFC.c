/*
 * function: NHTTPi_SocClose
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
 *   SOC_Close 0x0215F644 arm
 *   OS_Sleep 0x02085A38 arm
 *   SOCLi_TrashSocket 0x0215EBB4 arm
 *   NHTTPi_free 0x021BA850 arm ov114
 */

typedef struct {
    char pad[0xac];
    void *pSslCon;
} Req;

extern int SOC_Close(int socket);
extern void OS_Sleep(unsigned long msec);
extern void SOCLi_TrashSocket(void);
extern void NHTTPi_free(int a);

int NHTTPi_SocClose(int unused, Req *req_p, int socket)
{
    int error;
    int elapsed;

    error = SOC_Close(socket);
    if (error == 0 || error == -26) {
        for (elapsed = 0; (error = SOC_Close(socket)) == -26 && elapsed <= 10000; elapsed += 500) {
            OS_Sleep(500);
            SOCLi_TrashSocket();
        }
    }
    if (error != -26 && req_p != 0 && req_p->pSslCon != 0) {
        NHTTPi_free((int)req_p->pSslCon);
        req_p->pSslCon = 0;
    }
    return error;
}
