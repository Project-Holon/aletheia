/*
 * function: func_021BBAAC
 * address:  0x021BBAAC
 * packet:   pkt_ov114_021BBAAC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_cancelAllRequests (libnhttp.TWL.HYB.a(nhttp_request.o))
 *
 * symbols:
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BEF40 0x021BEF40 arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEFCC 0x021BEFCC arm ov114
 *   func_021BA068 0x021BA068 arm ov114
 *   func_021BAE90 0x021BAE90 arm ov114
 *   func_021BEFD8 0x021BEFD8 arm ov114
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

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

extern ReqInfo *func_021BEF48(void *sysInfo_p);
extern void *func_021BEF40(void *sysInfo_p);
extern void *func_021BEF58(void *sysInfo_p);
extern void func_021BEFCC(void *mutexInfo_p);
extern void func_021BA068(void *mutexInfo_p, Req *req_p, int arg);
extern void func_021BAE90(void *listInfo_p, void *mutexInfo_p);
extern void func_021BEFD8(void *mutexInfo_p);

void func_021BBAAC(void *sysInfo_p)
{
    ReqInfo *reqInfo_p;
    void *listInfo_p;
    void *mutexInfo_p;
    ReqList *reqCurrent_p;

    reqInfo_p = func_021BEF48(sysInfo_p);
    listInfo_p = func_021BEF40(sysInfo_p);
    mutexInfo_p = func_021BEF58(sysInfo_p);
    reqCurrent_p = reqInfo_p->reqCurrent;
    func_021BEFCC(mutexInfo_p);
    if (reqCurrent_p) {
        if (reqCurrent_p->req_p->doCancel == 0) {
            reqCurrent_p->req_p->doCancel = 1;
            func_021BA068(mutexInfo_p, reqCurrent_p->req_p, reqCurrent_p->arg);
        }
    }
    func_021BAE90(listInfo_p, mutexInfo_p);
    func_021BEFD8(mutexInfo_p);
}
