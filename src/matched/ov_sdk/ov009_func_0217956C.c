/*
 * function: DWC_Http_Create
 * address:  0x0217956C
 * packet:   pkt_ov009_0217956C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_Create (libdwcauth.TWL.HYB.a dwc_http.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0217A0D4  0x0217A0D4  arm  ov009
 *   DWCi_Http_SetHostinfo  0x0217A1FC  arm  ov009
 *   DWCi_Http_WriteBasicHeader  0x02179DA0  arm  ov009
 */

typedef struct DWCHttpBuffer {
    char *buffer;
    char *write_index;
    char *buffer_tail;
    unsigned long length;
} DWCHttpBuffer;

typedef struct DWCHttpParam {
    char *url;
    int action;
    unsigned long len_recvbuf;
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    int ignoreca;
    int timeout;
} DWCHttpParam;

typedef struct DWCHttp {
    unsigned char stack[0x1000];
    unsigned char initflag;
    DWCHttpParam param;
    int error;
    char pad1024[0x9e4];
    unsigned char *lowrecvbuf;
    unsigned char *lowsendbuf;
    unsigned long lowentropydata[8];
    int num_postitem;
    DWCHttpBuffer req;
    DWCHttpBuffer rep;
    char content_len_mutex[0x18];
    int content_len;
    int receivedbody_len;
    char pad1a74[0x1dc];
} DWCHttp;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int func_0217A0D4(DWCHttp *http, DWCHttpBuffer *buf, unsigned long size);
extern int DWCi_Http_SetHostinfo(DWCHttp *http, char *url);
extern int DWCi_Http_WriteBasicHeader(char *http);

int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param)
{
    void *(*alloc)(unsigned long, long) = param->alloc;

    MI_CpuFill8(http, 0, sizeof(DWCHttp));
    http->content_len = -1;
    http->receivedbody_len = -1;
    http->param = *param;

    http->lowrecvbuf = alloc(0, 0xb68);
    if (http->lowrecvbuf == 0) {
        http->error = 1;
        return 1;
    }
    http->lowsendbuf = alloc(0, 0x5ea);
    if (http->lowsendbuf == 0) {
        http->error = 1;
        return 1;
    }
    if (!func_0217A0D4(http, &http->rep, http->param.len_recvbuf)) {
        http->error = 1;
        return 1;
    }
    if (!DWCi_Http_SetHostinfo(http, param->url)) {
        http->error = 1;
        return 1;
    }
    http->error = DWCi_Http_WriteBasicHeader((char *)http);
    if (http->error == 0)
        http->initflag = 0xff;
    return http->error;
}
