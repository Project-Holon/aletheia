/*
 * function: func_021B9E3C
 * address:  0x021B9E3C
 * packet:   pkt_ov114_021B9E3C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SocSSLConnect (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 *
 * symbols:
 *   func_021BA820 0x021BA820 arm ov114
 *   func_021BA13C 0x021BA13C arm ov114
 *   func_0215FC80 0x0215FC80 arm
 *   func_021B9C80 0x021B9C80 arm ov114
 *   func_021B9C78 0x021B9C78 arm ov114
 *   func_021B9C6C 0x021B9C6C arm ov114
 */

typedef struct {
    char pad[0x800];
    int a800;
    char pad1[0xc];
    void *cb810;
    int a814;
    int a818;
    char pad2[0x830 - 0x81c];
} SslCon;

typedef struct {
    char pad0[0x28];
    int a28;
    char pad1[0xac - 0x2c];
    SslCon *pSslCon;
    char pad2[0xc0 - 0xb0];
    int aC0;
    int aC4;
    char pad3[0xd8 - 0xc8];
    int aD8;
} Req;

extern int func_021BA820(int a, int b);
extern void func_021BA13C(int a, int b);
extern int func_0215FC80(int s, SslCon *con);
extern void func_021B9C80(void);
extern int func_021B9C78(void);
extern int func_021B9C6C(int result);

int func_021B9E3C(int unused0, int unused1, Req *req_p, int socket)
{
    SslCon *pSslCon;

    pSslCon = req_p->pSslCon;
    if (pSslCon == 0) {
        pSslCon = (SslCon *)func_021BA820(0x830, 4);
        req_p->pSslCon = pSslCon;
        func_021BA13C((int)pSslCon, 0x830);
    }
    pSslCon->a814 = req_p->aC0;
    pSslCon->a818 = req_p->aC4;
    pSslCon->a800 = req_p->a28;
    if (req_p->aD8) {
        pSslCon->cb810 = (void *)func_021B9C78;
    } else {
        pSslCon->cb810 = (void *)func_021B9C6C;
    }
    if (func_0215FC80(socket, pSslCon) < 0) {
        return -1001;
    }
    func_021B9C80();
    return 0;
}
