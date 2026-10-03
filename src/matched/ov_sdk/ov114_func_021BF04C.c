/*
 * function: func_021BF04C
 * address:  0x021BF04C
 * packet:   pkt_ov114_021BF04C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_CreateConnection (libnhttp.TWL.HYB.a(d_nhttp_private.o))
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BA820 0x021BA820 arm ov114
 *   func_021BA874 0x021BA874 arm ov114
 *   func_021BA13C 0x021BA13C arm ov114
 *   func_021BB3CC 0x021BB3CC arm ov114
 *   func_021BA850 0x021BA850 arm ov114
 *   func_021BEB88 0x021BEB88 arm ov114
 *   func_021BEF60 0x021BEF60 arm ov114
 */

typedef unsigned long u32;

typedef struct {
    char pad[0x2c];
    void *res_p;
} Req;

typedef struct {
    u32 status;
    u32 nhttpError;
    int sslError;
    int running;
    Req *req_p;
    void *res_p;
    int reqId;
    int (*connectionCallback)(void *, int, void *);
    void *next_p;
    u32 postData0;
    u32 postData1;
    u32 virtualContentLength;
    void *reqCallback;
    unsigned short padding[6];
    unsigned short tmpBuf[16384];
    u32 tmpBufOffset;
    u32 tmpBufRest;
    int ref;
} Connection;

typedef unsigned char  u8;
extern u8 *func_021BEF08(void);
extern void *func_021BEF3C(void);
extern void *func_021BEF58(void *sysInfo);
extern void *func_021BA820(u32 size, int a);
extern void func_021BA874(u8 *p, int v);
extern void func_021BA13C(void *p, u32 size);
extern Req *func_021BB3CC(void *bgnEnd, char *url_p, int method, char *buf_p, u32 len,
                          void *param_p, void *bufFull, void *freeBuf);
extern void func_021BA850(void *p);
extern void func_021BEB88(void *mutexInfo, void *conn);
extern void func_021BEF60(void *conn, u32 len);

void *func_021BF04C(char *url_p, int method, char *buf_p, u32 len,
                    int (*callback)(void *, int, void *), void *userParam_p)
{
    Connection *connection_p;
    void *sysInfo_p;
    void *bgnEndInfo_p;
    void *mutexInfo_p;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    mutexInfo_p = func_021BEF58(sysInfo_p);
    connection_p = func_021BA820(0x804c, 0x20);
    if (connection_p == 0) {
        func_021BA874(bgnEndInfo_p, 1);
        return 0;
    }
    func_021BA13C(connection_p, 0x804c);
    connection_p->req_p = func_021BB3CC(bgnEndInfo_p, url_p, method, buf_p, len, userParam_p, 0, 0);
    if (connection_p->req_p == 0) {
        func_021BA850(connection_p);
        return 0;
    }
    connection_p->res_p = connection_p->req_p->res_p;
    connection_p->status = 0;
    connection_p->connectionCallback = callback;
    connection_p->postData0 = 0;
    connection_p->postData1 = 0;
    connection_p->reqId = -1;
    func_021BEB88(mutexInfo_p, connection_p);
    connection_p->nhttpError = 0xf;
    connection_p->sslError = 0;
    connection_p->running = 1;
    func_021BEF60(connection_p, 0);
    connection_p->reqCallback = 0;
    connection_p->tmpBufOffset = 0;
    connection_p->tmpBufRest = 0;
    func_021BA13C(connection_p->tmpBuf, 0x8000);
    connection_p->ref = 1;
    return connection_p;
}
