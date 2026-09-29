/*
 * function: NHTTPi_CreateRequest
 * address:  0x021BB3CC
 * packet:   pkt_ov114_021BB3CC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      NHTTPi_CreateRequest (libnhttp.TWL.HYB.a nhttp_request.o)
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
 *
 * blocker:  codegen -- full URL/host parser reconstructed; 575/1172 concrete
 *           bytes differ, compiled 1260 vs 1256. Register allocation now
 *           matches (declen r4, urllen/i r5, prefix_p r6, req_p r7) by
 *           declaring declen/urllen/i/out before prefix_p and req_p last.
 *           Remaining: the two decode loops. The object's first loop is
 *           rotated (body at 0x554, incr 0x5a8, latch 0x5ac with the bound
 *           test and the prefix_p[i] load) -- a plain while/for emits it
 *           condition-first (749 differ); a `for(;;){ if(i>=declen)break; }`
 *           is closest (575). The object's second loop is not rotated.
 *           Left untouched: exact loop spelling and the +0044-byte extent.
 */

typedef unsigned char u8;
typedef unsigned long u32;

struct _NHTTPBgnEndInfo;

typedef char *(*NHTTPBufFullFn)(char **, unsigned long *, unsigned long,
                                void *(*)(unsigned long, int),
                                void (*)(void *), void *);
typedef void (*NHTTPFreeBufFn)(char *, void (*)(void *), void *);

struct _NHTTPReqSub {
    u8 pad00[0x1c];
    u32 len;                    /* 0x1c */
    u8 pad20[8];
    char *buf;                  /* 0x28 */
    NHTTPBufFullFn bufFull;     /* 0x2c */
    NHTTPFreeBufFn freeBuf;     /* 0x30 */
    u8 pad34[0x404];
    void *param;                /* 0x438 */
};

struct _NHTTPReq {
    u8 pad00[8];
    int isHttps;                /* 0x08 */
    int field_0x0c;             /* 0x0c */
    int field_0x10;             /* 0x10 */
    int hostend;                /* 0x14 */
    int pathstart;              /* 0x18 */
    int method;                 /* 0x1c */
    u32 port;                   /* 0x20 */
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

extern void *NHTTPi_alloc(unsigned long size, int align);
extern void NHTTPi_SetError(struct _NHTTPBgnEndInfo *bgnEndInfo_p, int error);
extern void NHTTPi_memclr(void *p_p, int size);
extern int NHTTPi_strnlen(char *p_p, int size);
extern void NHTTPi_memcpy(void *dst_p, void *src_p, int size);
extern int NHTTPi_strnicmp(char *p1_p, char *p2_p, int size);
extern int NHTTPi_strToHex(char *p_p, int len);
extern int NHTTPi_strtonum(char *p_p, int size);
extern void NHTTPi_free(void *ptr_p);

extern char str_http_scheme[8];
extern char str_https_scheme[9];
extern char NHTTPi_strMultipartBound[21];

struct _NHTTPReq *NHTTPi_CreateRequest(
    struct _NHTTPBgnEndInfo *bgnEndInfo_p, char *url_p, int method,
    char *buf_p, unsigned long len, void *param_p,
    NHTTPBufFullFn bufFull, NHTTPFreeBufFn freeBuf)
{
    int declen;
    int urllen;
    int i;
    int out;
    char *prefix_p;
    struct _NHTTPReq *req_p;
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
    for (;;) {
        if (i >= declen)
            break;
        c = prefix_p[i];
        if (c == '/')
            break;
        if (deccount == 2) {
            deccount = 1;
        } else if (deccount == 1) {
            c = (char)NHTTPi_strToHex(prefix_p + i - 1, 2);
            deccount = deccount - 1;
            if (deccount < 0) {
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

    out = 0;
    deccount = 0;
    flag = 0;
    for (i = 0; i < declen; i++) {
        if (deccount == 2) {
            deccount = 1;
        } else if (deccount == 1) {
            c = (char)NHTTPi_strToHex(prefix_p + i - 1, 2);
            if (c == '/')
                flag = 1;
            deccount = deccount - 1;
            req_p->decodedUrl[prelen + out - 1] = c;
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

    i = 0;
    if (out > 0) {
        for (i = 0; i < out; i++) {
            c = req_p->decodedUrl[prelen + i];
            if (c == '/' || c == ':') {
                req_p->hostend = i + prelen;
                break;
            }
        }
    }
    if (i == out) {
        req_p->hostend = i + prelen;
        req_p->pathstart = i + prelen;
    } else {
        c = req_p->decodedUrl[prelen + i];
        if (c == '/') {
            req_p->pathstart = req_p->hostend;
        } else if (c == ':') {
            for (; i < out; i++) {
                c = req_p->decodedUrl[prelen + i];
                if (c == '/') {
                    req_p->pathstart = i + prelen;
                    break;
                }
            }
            if (i == out) {
                req_p->pathstart = i + prelen;
            } else {
                port = NHTTPi_strtonum(req_p->decodedUrl + req_p->hostend + 1,
                                       req_p->pathstart - req_p->hostend - 1);
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

    suflen = req_p->isHttps ? 8 : 7;
    urllen = req_p->hostend - suflen;
    req_p->hostname = NHTTPi_alloc(urllen + 1, 4);
    if (req_p->hostname == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        goto cleanup;
    }
    NHTTPi_memclr(req_p->hostname, urllen + 1);
    NHTTPi_memcpy(req_p->hostname, req_p->decodedUrl + suflen, urllen);

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
