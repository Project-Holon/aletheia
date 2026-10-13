/*
 * function: NHTTPi_SocSSLConnect
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
 *   NHTTPi_alloc 0x021BA820 arm ov114
 *   NHTTPi_memclr 0x021BA13C arm ov114
 *   func_0215FC80 0x0215FC80 arm
 *   NHTTPi_SetSSLseed 0x021B9C80 arm ov114
 *   NHTTPi_CpsAuthCallbackForDebug 0x021B9C78 arm ov114
 *   NHTTPi_CpsAuthCallback 0x021B9C6C arm ov114
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

extern int NHTTPi_alloc(int a, int b);
extern void NHTTPi_memclr(int a, int b);
extern int func_0215FC80(int s, SslCon *con);
extern void NHTTPi_SetSSLseed(void);
extern int NHTTPi_CpsAuthCallbackForDebug(void);
extern int NHTTPi_CpsAuthCallback(int result);

int NHTTPi_SocSSLConnect(int unused0, int unused1, Req *req_p, int socket)
{
    SslCon *pSslCon;

    pSslCon = req_p->pSslCon;
    if (pSslCon == 0) {
        pSslCon = (SslCon *)NHTTPi_alloc(0x830, 4);
        req_p->pSslCon = pSslCon;
        NHTTPi_memclr((int)pSslCon, 0x830);
    }
    pSslCon->a814 = req_p->aC0;
    pSslCon->a818 = req_p->aC4;
    pSslCon->a800 = req_p->a28;
    if (req_p->aD8) {
        pSslCon->cb810 = (void *)NHTTPi_CpsAuthCallbackForDebug;
    } else {
        pSslCon->cb810 = (void *)NHTTPi_CpsAuthCallback;
    }
    if (func_0215FC80(socket, pSslCon) < 0) {
        return -1001;
    }
    NHTTPi_SetSSLseed();
    return 0;
}
