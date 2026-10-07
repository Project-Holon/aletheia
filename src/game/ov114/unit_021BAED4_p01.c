/*
 * file:     unit_021BAED4_p01.c
 * unit:     yes
 * function: func_021BAED4, func_021BAF2C, func_021BAFA0, func_021BB0BC
 * address:  0x021BAED4
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
 *   func_021BAED4 0x021BAED4 arm ov114
 *   func_021BAF2C 0x021BAF2C arm ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

struct _NHTTPi_HDRBUFLIST {
    struct _NHTTPi_HDRBUFLIST *next_p;   /* 0x00 */
    char block[512];                     /* 0x04 */
};

struct _NHTTPRes {
    int headerLen;                            /* 0x00 */
    int bodyLen;                              /* 0x04 */
    int totalBodyLen;                         /* 0x08 */
    int contentLength;                        /* 0x0c */
    int isSuccess;                            /* 0x10 */
    int isHeaderParse;                        /* 0x14 */
    int httpStatus;                           /* 0x18 */
    unsigned long recvBufLen;                 /* 0x1c */
    char *allHeader_p;                        /* 0x20 */
    char *foundHeader_p;                      /* 0x24 */
    char *recvBuf_p;                          /* 0x28 */
    void *bufFull;                            /* 0x2c */
    void *freeBuf;                            /* 0x30 */
    struct _NHTTPi_HDRBUFLIST *hdrBufBlock_p; /* 0x34 */
    char hdrBufFirst[1024];                   /* 0x38 */
    void *param_p;                            /* 0x438 */
};

typedef struct {
    char pad[0x34];
    void *hdrBufBlock_p;
} Res;

extern void func_021BAED4(Res *res_p, int pos, void *hdrbuf_pp, int *blockpos_p);
extern char func_021BAF2C(Res *res_p, void *hdrbuf_pp, int *blockpos_p);
int func_021BAFA0(Res *res_p, int pos, int limit, int *colon_pos_p, int *return_code_size_p);
int NHTTPi_skipSpaceHdrRecvBuf(struct _NHTTPRes *res_p, int pos, int limit);


static void setupGetcharFromHdrRecvBuf(struct _NHTTPRes *res_p, int pos,
        struct _NHTTPi_HDRBUFLIST **hdrbuf_pp, int *blockpos_p)
{
    struct _NHTTPi_HDRBUFLIST *a_hdrbuf_p;
    int blockidx;

    if (pos < 0x400) {
        *hdrbuf_pp = 0;
        *blockpos_p = pos;
        return;
    }
    blockidx = (pos - 0x400) >> 9;
    a_hdrbuf_p = res_p->hdrBufBlock_p;
    while (blockidx-- != 0) {
        a_hdrbuf_p = a_hdrbuf_p->next_p;
    }
    *hdrbuf_pp = a_hdrbuf_p;
    *blockpos_p = (pos - 0x400) & 0x1ff;
}


static char getcharFromHdrRecvBuf(const struct _NHTTPRes *res_p,
        struct _NHTTPi_HDRBUFLIST **hdrbuf_pp, int *blockpos_p)
{
    if (*hdrbuf_pp == 0) {
        if (*blockpos_p < 0x400)
            return res_p->hdrBufFirst[(*blockpos_p)++];
        *blockpos_p = 0;
        *hdrbuf_pp = res_p->hdrBufBlock_p;
    } else {
        if (*blockpos_p == 0x200) {
            *blockpos_p = 0;
            *hdrbuf_pp = (*hdrbuf_pp)->next_p;
        }
    }
    return (*hdrbuf_pp)->block[(*blockpos_p)++];
}


int func_021BAFA0(Res *res_p, int pos, int limit, int *colon_pos_p, int *return_code_size_p)
{
    void *hdrbuf_p;
    int blockpos;
    int findCR;
    int return_pos;
    char c;

    if (colon_pos_p) {
        *colon_pos_p = -1;
    }
    if (pos < limit) {
        return_pos = -1;
        findCR = 0;
        func_021BAED4(res_p, pos, &hdrbuf_p, &blockpos);
        for (; pos < limit; pos++) {
            c = func_021BAF2C(res_p, &hdrbuf_p, &blockpos);
            if (c == ':') {
                if (colon_pos_p && *colon_pos_p < 0) {
                    *colon_pos_p = pos;
                }
            }
            if (findCR) {
                if (c == '\n') {
                    return_pos = 0;
                    if (pos != limit - 1) {
                        return_pos = pos + 1;
                    }
                    if (return_code_size_p) {
                        *return_code_size_p = 2;
                    }
                }
                return return_pos;
            }
            if (c == '\r') {
                return_pos = 0;
                if (pos != limit - 1) {
                    return_pos = pos + 1;
                }
                findCR = 1;
                if (return_code_size_p) {
                    *return_code_size_p = findCR;
                }
            }
            if (c == '\n') {
                if (pos == limit - 1) {
                    return_pos = 0;
                } else {
                    return_pos = pos + 1;
                }
                if (return_code_size_p) {
                    *return_code_size_p = 1;
                }
                return return_pos;
            }
        }
    }
    return -1;
}


int NHTTPi_skipSpaceHdrRecvBuf(struct _NHTTPRes *res_p, int pos, int limit)
{
    struct _NHTTPi_HDRBUFLIST *hdrbuf_p;
    int blockpos;

    if (pos < limit) {
        setupGetcharFromHdrRecvBuf(res_p, pos, &hdrbuf_p, &blockpos);
        while (pos < limit) {
            if (getcharFromHdrRecvBuf(res_p, &hdrbuf_p, &blockpos) != ' ')
                return pos;
            pos++;
        }
    }
    return -1;
}
