/*
 * file:     unit_021BB3C0.c
 * unit:     yes
 * function: func_021BB3C0, func_021BB3CC, func_021BB8B4, func_021BB8F0, func_021BB934, func_021BB97C, func_021BBA14, func_021BBAAC
 * address:  0x021BB3C0
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
 *   NHTTPi_alloc             0x021ba820 arm
 *   NHTTPi_SetError          0x021ba874 arm
 *   NHTTPi_memclr            0x021ba13c arm
 *   NHTTPi_strnlen           0x021ba124 arm
 *   NHTTPi_memcpy            0x021ba100 arm
 *   NHTTPi_strnicmp          0x021ba150 arm
 *   NHTTPi_strToHex          0x021ba35c arm
 *   NHTTPi_strtonum          0x021ba620 arm
 *   NHTTPi_free              0x021ba850 arm
 *   str_http_scheme          0x021ce400 data a1
 *   str_https_scheme         0x021ce408 data a1
 *   NHTTPi_strMultipartBound 0x021cdfc8 data a1
 *   func_021BA850  0x021BA850  arm  ov114
 *   func_021BEBE0  0x021BEBE0  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   NHTTPi_GetBgnEndInfoP     0x021bef3c arm
 *   NHTTPi_GetThreadInfoP     0x021bef50 arm
 *   NHTTPi_GetMutexInfoP      0x021bef58 arm
 *   NHTTPi_lockReqList        0x021befcc arm
 *   NHTTPi_GetListInfoP       0x021bef40 arm
 *   NHTTPi_setReqQueue        0x021bacfc arm
 *   NHTTPi_kickCommThread     0x021b9c08 arm
 *   NHTTPi_unlockReqList      0x021befd8 arm
 *   NHTTPi_GetReqInfoP      0x021bef48 arm
 *   NHTTPi_SocCancel        0x021ba068 arm
 *   NHTTPi_freeReqQueue     0x021bade0 arm
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BEF40 0x021BEF40 arm ov114
 *   func_021BEFCC 0x021BEFCC arm ov114
 *   func_021BA068 0x021BA068 arm ov114
 *   func_021BAE90 0x021BAE90 arm ov114
 *   func_021BEFD8 0x021BEFD8 arm ov114
 */
struct _NHTTPBgnEndInfo;
struct List;
struct _NHTTPSysInfo;
struct _NHTTPMutexInfo;
struct _NHTTPListInfo;
struct _NHTTPThreadInfo;
struct _NHTTPReq;
typedef unsigned char u8;

typedef unsigned int u32_021BB3C0;

typedef unsigned long u32_021BB3CC;

typedef char *(*NHTTPBufFullFn)(char **, unsigned long *, unsigned long,
                                void *(*)(unsigned long, int),
                                void (*)(void *), void *);

typedef void (*NHTTPFreeBufFn)(char *, void (*)(void *), void *);

struct _NHTTPReqSub {
    u8 pad00[0x1c];
    u32_021BB3CC len;                    /* 0x1c */
    u8 pad20[8];
    char *buf;                  /* 0x28 */
    NHTTPBufFullFn bufFull;     /* 0x2c */
    NHTTPFreeBufFn freeBuf;     /* 0x30 */
    u8 pad34[0x404];
    void *param;                /* 0x438 */
};

struct _NHTTPReq_021BB3CC {
    u8 pad00[8];
    int isHttps;                /* 0x08 */
    int field_0x0c;             /* 0x0c */
    int field_0x10;             /* 0x10 */
    int hostend;                /* 0x14 */
    int pathstart;              /* 0x18 */
    int method;                 /* 0x1c */
    u32_021BB3CC port;                   /* 0x20 */
    char *decodedUrl;           /* 0x24 */
    char *hostname;             /* 0x28 */
    struct _NHTTPReqSub *sub;   /* 0x2c */
    int field_0x30;
    int field_0x34;
    u8 multipartBound[0xac - 0x38];
    int field_0xac;
    int field_0xb0;
    int field_0xb4;
    int field_0xb8;
    int field_0xbc;
    int field_0xc0;
    int field_0xc4;
    u8 pad_c8[4];
    int field_0xcc;
    int field_0xd0;
    u8 pad_d4[4];
    int field_0xd8;
    u8 pad_dc[0x248 - 0xdc];
    int field_0x248;
};

typedef unsigned int u32_021BB8B4;

typedef struct List {
    struct List *next;
} List;

typedef unsigned int u32_021BB934;

typedef unsigned int u32_021BB97C;

struct _NHTTPReq_021BB97C {
    u32_021BB97C field_0x00;
    int field_0x04;
};

typedef unsigned int u32_021BBA14;

struct _NHTTPi_REQLIST {
    void *field_0x00;
    void *field_0x04;
    int field_0x08;
    int *field_0x0c;
    int field_0x10;
};

struct _NHTTPReqInfo {
    struct _NHTTPi_REQLIST *field_0x00;
};

typedef struct {
    int doCancel;
} Req;

typedef struct {
    char pad[0xc];
    Req *volatile req_p;
    int arg;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef unsigned int   u32_021BBAAC;

extern void *NHTTPi_alloc(unsigned long size, int align);
extern void NHTTPi_SetError(struct _NHTTPBgnEndInfo *bgnEndInfo_p, int error);
extern void NHTTPi_memclr(void *p_p, int size);
extern int NHTTPi_strnlen(char *p_p, int size);
extern void NHTTPi_memcpy(void *dst_p, void *src_p, int size);
extern int NHTTPi_strnicmp(char *p1_p, char *p2_p, int size);
extern int NHTTPi_strToHex(char *p_p, int len);
extern int NHTTPi_strtonum(char *p_p, int size);
extern void NHTTPi_free(void *ptr_p);
void *func_021BEF58(int p);
u8 *func_021BEBE0(int, int);
void func_021BA850(int a);
extern struct _NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(struct _NHTTPSysInfo *);
extern struct _NHTTPThreadInfo *NHTTPi_GetThreadInfoP(struct _NHTTPSysInfo *);
extern struct _NHTTPMutexInfo *NHTTPi_GetMutexInfoP(struct _NHTTPSysInfo *);
extern struct _NHTTPListInfo *NHTTPi_GetListInfoP(struct _NHTTPSysInfo *);
extern void NHTTPi_lockReqList(struct _NHTTPMutexInfo *);
extern int NHTTPi_setReqQueue(struct _NHTTPListInfo *, struct _NHTTPReq_021BB97C *);
extern void NHTTPi_kickCommThread(struct _NHTTPThreadInfo *);
extern void NHTTPi_unlockReqList(struct _NHTTPMutexInfo *);
extern struct _NHTTPReqInfo *NHTTPi_GetReqInfoP(struct _NHTTPSysInfo *);
extern void NHTTPi_SocCancel(struct _NHTTPMutexInfo *, int, int);
extern int NHTTPi_freeReqQueue(struct _NHTTPListInfo *, struct _NHTTPMutexInfo *, int);
extern void *func_021BEF48(int p);
extern void *func_021BEF40(int p);
extern void func_021BEFCC(void);
extern void func_021BA068(int a, int b, int c);
extern void func_021BAE90(u32_021BBAAC **p, int v);
extern void func_021BEFD8(void *mutexInfo_p);
void func_021BB3C0(u8 *p);
struct _NHTTPReq_021BB3CC *NHTTPi_CreateRequest( struct _NHTTPBgnEndInfo *bgnEndInfo_p, char *url_p, int method, char *buf_p, unsigned long len, void *param_p, NHTTPBufFullFn bufFull, NHTTPFreeBufFn freeBuf);
void func_021BB8B4(int a, u8 *b);
void func_021BB8F0(List *list_p);
int func_021BB934(int a, u8 *b);
int NHTTPi_SendRequestAsync(struct _NHTTPSysInfo *sysInfo_p, struct _NHTTPReq_021BB97C *req_p);
int NHTTPi_CancelRequestAsync(struct _NHTTPSysInfo *sysInfo_p, int id);
void func_021BBAAC(void *sysInfo_p);
extern char str_http_scheme[8];
extern char str_https_scheme[9];
extern char NHTTPi_strMultipartBound[21];

/*
 * Clears the leading word.
 */
void func_021BB3C0(u8 *p)
{
    *(u32_021BB3C0 *)(p + 0) = 0;
}


struct _NHTTPReq_021BB3CC *NHTTPi_CreateRequest(
    struct _NHTTPBgnEndInfo *bgnEndInfo_p, char *url_p, int method,
    char *buf_p, unsigned long len, void *param_p,
    NHTTPBufFullFn bufFull, NHTTPFreeBufFn freeBuf)
{
    int declen;
    int urllen;
    int i;
    int out;
    char *prefix_p;
    char *host_p;
    struct _NHTTPReq_021BB3CC *req_p;
    int prelen;
    int nhostenc;
    int deccount;
    int flag;
    int decode_urllen;
    int port;
    int suflen;
    char c;
    char a_url[512];

    req_p = 0;
    if (method != 0 && method != 1 && method != 2) {
        NHTTPi_SetError(bgnEndInfo_p, 0xb);
        goto cleanup;
    }

    req_p = NHTTPi_alloc(0x258, 4);
    if (req_p == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        goto cleanup;
    }
    NHTTPi_memclr(req_p, 0x258);

    req_p->sub = NHTTPi_alloc(0x43c, 4);
    if (req_p->sub == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        goto cleanup;
    }
    NHTTPi_memclr(req_p->sub, 0x43c);

    req_p->sub->buf = buf_p;
    req_p->sub->len = len;
    req_p->sub->bufFull = bufFull;
    req_p->sub->freeBuf = freeBuf;

    urllen = NHTTPi_strnlen(url_p, 511);
    if (urllen <= 7) {
        NHTTPi_SetError(bgnEndInfo_p, 4);
        goto cleanup;
    }

    NHTTPi_memclr(a_url, 0x200);
    NHTTPi_memcpy(a_url, url_p, urllen);

    prelen = 7;
    req_p->port = 80;
    if (NHTTPi_strnicmp(a_url, str_http_scheme, prelen) != 0) {
        prelen = 8;
        if (NHTTPi_strnicmp(a_url, str_https_scheme, prelen) != 0) {
            NHTTPi_SetError(bgnEndInfo_p, 4);
            goto cleanup;
        }
        req_p->isHttps = 1;
        req_p->port = 443;
    }

    declen = urllen - prelen;
    prefix_p = a_url + prelen;
    if (declen <= 0) {
        NHTTPi_SetError(bgnEndInfo_p, 4);
        goto cleanup;
    }

    i = 0;
    nhostenc = 0;
    deccount = 0;
    flag = 2;
    while (i < declen && (c = prefix_p[i]) != '/') {
        if (deccount == 2) {
            deccount = deccount - 1;
        } else if (deccount == 1) {
            c = (char)NHTTPi_strToHex(prefix_p + (i - 1), flag);
            deccount = deccount - 1;
            if (c < 0) {
                NHTTPi_SetError(bgnEndInfo_p, 4);
                goto cleanup;
            }
            if (c == '/') {
                nhostenc = nhostenc - 1;
                break;
            }
        } else {
            if (c == '%') {
                deccount = 2;
                nhostenc = nhostenc + 1;
            }
        }
        i = i + 1;
    }
    if (deccount != 0) {
        NHTTPi_SetError(bgnEndInfo_p, 4);
        goto cleanup;
    }

    decode_urllen = prelen + declen - (nhostenc << 1);
    req_p->decodedUrl = NHTTPi_alloc(decode_urllen + 1, 4);
    if (req_p->decodedUrl == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        goto cleanup;
    }
    NHTTPi_memclr(req_p->decodedUrl, decode_urllen + 1);
    NHTTPi_memcpy(req_p->decodedUrl, a_url, prelen);

    i = 0;
    out = 0;
    deccount = 0;
    flag = 0;
    for (; i < declen; i++) {
        if (deccount == 2) {
            deccount = deccount - 1;
        } else if (deccount == 1) {
            c = (char)NHTTPi_strToHex(prefix_p + (i - 1), 2);
            deccount = deccount - 1;
            req_p->decodedUrl[prelen + out - 1] = c;
            if (c == '/')
                flag = 1;
        } else {
            c = prefix_p[i];
            if (c == '/')
                flag = 1;
            if (flag == 0 && c == '%') {
                deccount = 2;
            } else {
                req_p->decodedUrl[prelen + out] = c;
            }
            out = out + 1;
        }
    }
    req_p->decodedUrl[prelen + out] = 0;

    host_p = req_p->decodedUrl + prelen;
    for (i = 0; i < out; i++) {
        c = host_p[i];
        if (c == '/' || c == ':') {
            req_p->hostend = i + prelen;
            break;
        }
    }
    if (i == out) {
        req_p->hostend = i + prelen;
        req_p->pathstart = i + prelen;
    } else {
        c = host_p[i];
        if (c == '/') {
            req_p->pathstart = req_p->hostend;
        } else if (c == ':') {
            for (; i < out; i++) {
                c = host_p[i];
                if (c == '/') {
                    req_p->pathstart = i + prelen;
                    break;
                }
            }
            if (i == out) {
                req_p->pathstart = i + prelen;
            } else {
                suflen = req_p->hostend + 1;
                port = NHTTPi_strtonum(req_p->decodedUrl + suflen, req_p->pathstart - suflen);
                if (port < 0) {
                    port = req_p->port;
                } else if (port > 0xffff) {
                    NHTTPi_SetError(bgnEndInfo_p, 4);
                    goto cleanup;
                }
                req_p->port = (unsigned short)port;
            }
        }
    }

    urllen = req_p->hostend - (req_p->isHttps ? 8 : 7);
    req_p->hostname = NHTTPi_alloc(urllen + 1, 4);
    if (req_p->hostname == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        goto cleanup;
    }
    NHTTPi_memclr(req_p->hostname, urllen + 1);
    NHTTPi_memcpy(req_p->hostname, req_p->decodedUrl + (req_p->isHttps ? 8 : 7), urllen);

    NHTTPi_memcpy(req_p->multipartBound, NHTTPi_strMultipartBound, 0x14);
    req_p->method = method;
    req_p->field_0xac = 0;
    req_p->field_0xb0 = 0;
    req_p->field_0xb4 = 0;
    req_p->field_0xb8 = 0;
    req_p->field_0xbc = 0;
    req_p->field_0xc0 = 0;
    req_p->field_0xc4 = 0;
    req_p->field_0xcc = 0;
    req_p->field_0xd0 = 0;
    req_p->field_0xd8 = 0;
    req_p->sub->param = param_p;
    req_p->field_0x0c = 0;
    req_p->field_0x248 = 0;
    return req_p;

cleanup:
    if (req_p != 0) {
        if (req_p->decodedUrl != 0)
            NHTTPi_free(req_p->decodedUrl);
        if (req_p->hostname != 0)
            NHTTPi_free(req_p->hostname);
        if (req_p->sub != 0)
            NHTTPi_free(req_p->sub);
        NHTTPi_free(req_p);
    }
    return 0;
}


/*
 * Unlinks the record from the module's list, releases its handle and then tears the record down.
 */
void func_021BB8B4(int a, u8 *b)
{
    void *p = func_021BEF58(a);
    u8 *r = func_021BEBE0((int)p, (int)b);

    if (r != 0)
        *(u32_021BB8B4 *)(r + 0x14) = 0;
    func_021BA850(*(u32_021BB8B4 *)(b + 0x2c));
    func_021BB934((int)p, b);
}


/*
 * sdk:      deleteStrList (libnhttp.TWL.HYB.a(nhttp_request.o))
 */
void func_021BB8F0(List *list_p)
{
    List *p;

    if (list_p) {
        do {
            p = list_p->next;
            if (list_p != p) {
                List *n = p->next;
                func_021BA850((int)p);
                list_p->next = n;
            } else {
                func_021BA850((int)list_p);
                list_p = 0;
            }
        } while (list_p);
    }
}


int func_021BB934(int a, u8 *b)
{
    u8 *p = func_021BEBE0(a, (int)b);

    if (p != 0)
        *(u32_021BB934 *)(p + 0x10) = 0;
    func_021BB8F0((struct List *)(*(u32_021BB934 *)(b + 0x30)));
    func_021BB8F0((struct List *)(*(u32_021BB934 *)(b + 0x34)));
    func_021BA850(*(u32_021BB934 *)(b + 0x24));
    func_021BA850(*(u32_021BB934 *)(b + 0x28));
    func_021BA850((u32_021BB934)b);
    return 1;
}


int NHTTPi_SendRequestAsync(struct _NHTTPSysInfo *sysInfo_p, struct _NHTTPReq_021BB97C *req_p)
{
    struct _NHTTPBgnEndInfo *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    struct _NHTTPThreadInfo *threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    struct _NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    int id;

    if (req_p->field_0x04 != 0) {
        NHTTPi_SetError(bgnEndInfo_p, 0xb);
        return -1;
    }
    NHTTPi_lockReqList(mutexInfo_p);
    id = NHTTPi_setReqQueue(NHTTPi_GetListInfoP(sysInfo_p), req_p);
    if (id >= 0) {
        req_p->field_0x04 = 1;
        NHTTPi_kickCommThread(threadInfo_p);
    } else {
        NHTTPi_SetError(bgnEndInfo_p, 1);
    }
    NHTTPi_unlockReqList(mutexInfo_p);
    return id;
}


int NHTTPi_CancelRequestAsync(struct _NHTTPSysInfo *sysInfo_p, int id)
{
    int rc = 0;
    struct _NHTTPReqInfo *reqInfo_p;
    struct _NHTTPMutexInfo *mutexInfo_p;
    struct _NHTTPi_REQLIST *reqCurrent_p;

    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    reqCurrent_p = reqInfo_p->field_0x00;
    NHTTPi_lockReqList(mutexInfo_p);
        if (reqCurrent_p != 0 && reqCurrent_p->field_0x08 == id && *reqCurrent_p->field_0x0c == 0) {
        *(int *)(*(int *volatile *)&reqCurrent_p->field_0x0c) = 1;
        NHTTPi_SocCancel(mutexInfo_p, (int)reqCurrent_p->field_0x0c, reqCurrent_p->field_0x10);
        rc = 1;
    }
    if (rc == 0)
        rc = NHTTPi_freeReqQueue(NHTTPi_GetListInfoP(sysInfo_p), mutexInfo_p, id);
    NHTTPi_unlockReqList(mutexInfo_p);
    return rc;
}


/*
 * sdk:      NHTTPi_cancelAllRequests (libnhttp.TWL.HYB.a(nhttp_request.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void func_021BBAAC(void *sysInfo_p)
{
    ReqInfo *reqInfo_p;
    void *listInfo_p;
    void *mutexInfo_p;
    ReqList *reqCurrent_p;

    reqInfo_p = func_021BEF48((int)sysInfo_p);
    listInfo_p = func_021BEF40((int)sysInfo_p);
    mutexInfo_p = func_021BEF58((int)sysInfo_p);
    reqCurrent_p = reqInfo_p->reqCurrent;
    func_021BEFCC();
    if (reqCurrent_p) {
        if (reqCurrent_p->req_p->doCancel == 0) {
            reqCurrent_p->req_p->doCancel = 1;
            func_021BA068((int)mutexInfo_p, (int)reqCurrent_p->req_p, reqCurrent_p->arg);
        }
    }
    func_021BAE90(listInfo_p, (int)mutexInfo_p);
    func_021BEFD8(mutexInfo_p);
}
