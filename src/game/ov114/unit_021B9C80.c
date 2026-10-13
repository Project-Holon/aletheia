/*
 * file:     unit_021B9C80.c
 * unit:     yes
 * function: func_021B9C80, func_021B9CA4, func_021B9CE4, func_021B9CFC, func_021B9D8C, func_021B9E3C, func_021B9ECC, func_021B9F94
 * address:  0x021B9C80
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021CF964  0x021CF964  data
 *   SOC_Close 0x0215F644 arm
 *   func_02085A38 0x02085A38 arm
 *   func_0215EBB4 0x0215EBB4 arm
 *   func_021BA850 0x021BA850 arm ov114
 *   func_0215F480 0x0215F480 arm
 *   func_021BA820 0x021BA820 arm ov114
 *   func_021BA13C 0x021BA13C arm ov114
 *   func_0215FC80 0x0215FC80 arm
 *   func_021B9C78 0x021B9C78 arm ov114
 *   func_021B9C6C 0x021B9C6C arm ov114
 *   func_0215F4DC 0x0215F4DC arm
 *   func_021BA100 0x021BA100 arm ov114
 *   func_021BEBE0  0x021BEBE0  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    char pad[0xac];
    void *pSslCon;
} Req_021B9C80;

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
} Req_021B9D8C;

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

typedef struct {
    char pad[0x40];
    char buf[0x8000];
    int pos;
    int size;
} Con;

extern void func_02088168(u32 *buffer);
extern void func_02162248(void *, int);
extern int func_0215F4DC(int, int *, int, int);
extern void func_0215F428(int, int, int);
extern int SOC_Close(int socket);
extern void func_02085A38(unsigned long msec);
extern void func_0215EBB4(void);
extern void func_021BA850(int a);
extern int func_0215F480(int s, void *sockAddr);
extern int func_021BA820(int a, int b);
extern void func_021BA13C(int a, int b);
extern int func_0215FC80(int s, SslCon *con);
extern int func_021B9C78(void);
extern int func_021B9C6C(int result);
extern void func_021BA100(void *dst_p, void *src_p, int size);
u8 *func_021BEBE0(int, int);
void func_021B9C80(void);
int func_021B9CA4(int a);
void func_021B9CE4(void);
int func_021B9CFC(int unused, Req_021B9C80 *req_p, int socket);
int func_021B9D8C(void *bgnEndInfo_p, void *mutexInfo_p, Req_021B9D8C *req_p, int socket, unsigned long hostaddr, int port);
int func_021B9E3C(int unused0, int unused1, Req *req_p, int socket);
int func_021B9ECC(Con *connection_p, int socket, char *buf_p, int len, int flags);
int func_021B9F94(int a, u32 *b, int c, int d, int e, int f);
extern u8 g_021CF964[];




void func_021B9C80(void)
{
    func_02088168((u32 *)g_021CF964);
    func_02162248(g_021CF964, 0x20);
}




int func_021B9CA4(int a)
{
    int v = 0;
    if (a == -1) {
        v = -1;
    } else {
        int n = 4;
        int tmp;
        if (func_0215F4DC(a, &tmp, 1, n) != n - 10)
            v = n - 5;
    }
    return v;
}




void func_021B9CE4(void)
{
    func_0215F428(2, 1, 0);
}




int func_021B9CFC(int unused, Req_021B9C80 *req_p, int socket)
{
    int error;
    int elapsed;

    error = SOC_Close(socket);
    if (error == 0 || error == -26) {
        for (elapsed = 0; (error = SOC_Close(socket)) == -26 && elapsed <= 10000; elapsed += 500) {
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



/*
 * sdk:      NHTTPi_SocConnect (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 */
int func_021B9D8C(void *bgnEndInfo_p, void *mutexInfo_p, Req_021B9D8C *req_p, int socket, unsigned long hostaddr, int port)
{
    SOCSockAddrIn scadr;
    int error;

    scadr.len = 8;
    scadr.family = 2;
    scadr.port = (unsigned short)(((((unsigned short)port) >> 8) & 0xff) | (((unsigned short)port) << 8 & 0xff00));
    scadr.addr = hostaddr;
    if (req_p->isSSL != 0 && req_p->hasSSLCon == 0) {
        error = func_021B9E3C((int)bgnEndInfo_p, (int)mutexInfo_p, (Req *)req_p, socket);
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




/*
 * sdk:      NHTTPi_SocRecv_sub (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 */
int func_021B9ECC(Con *connection_p, int socket, char *buf_p, int len, int flags)
{
    char *tmpBuf_p;
    int ret;
    int rec;
    unsigned long size;

    tmpBuf_p = connection_p->buf;
    ret = 0;
    if (len > 0) {
        if (connection_p->size == 0) {
            rec = func_0215F4DC(socket, (int *)tmpBuf_p, 0x8000, flags);
            if (rec <= 0) {
                return rec;
            }
            connection_p->size = rec;
            connection_p->pos = 0;
        }
        size = connection_p->size;
        if (size != 0) {
            if ((unsigned long)len <= size) {
                size = len;
            }
            func_021BA100(buf_p, tmpBuf_p + connection_p->pos, size);
            connection_p->size -= size;
            if (connection_p->size != 0) {
                connection_p->pos += size;
            } else {
                func_021BA13C((int)tmpBuf_p, 0x8000);
                connection_p->pos = 0;
            }
            ret = size;
        }
    }
    return ret;
}



int func_021B9F94(int a, u32 *b, int c, int d, int e, int f)
{
    void *p = func_021BEBE0(a, (int)b);
    int r;

    if (p != 0) {
        r = func_021B9ECC((Con *)p, c, (char *)d, e, f);
    } else {
        return -1001;
    }
    if (r >= 0)
        return r;
    if (*b != 0)
        return -1002;
    if (r == -56)
        return 0;
    return -1001;
}
