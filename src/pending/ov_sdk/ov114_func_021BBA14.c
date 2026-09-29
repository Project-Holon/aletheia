/*
 * function: NHTTPi_CancelRequestAsync
 * address:  0x021BBA14
 * packet:   pkt_ov114_021BBA14
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      NHTTPi_CancelRequestAsync (libnhttp.TWL.HYB.a nhttp_request.o)
 *
 * symbols:
 *   NHTTPi_GetReqInfoP      0x021bef48 arm
 *   NHTTPi_GetMutexInfoP    0x021bef58 arm
 *   NHTTPi_lockReqList      0x021befcc arm
 *   NHTTPi_SocCancel        0x021ba068 arm
 *   NHTTPi_GetListInfoP     0x021bef40 arm
 *   NHTTPi_freeReqQueue     0x021bade0 arm
 *   NHTTPi_unlockReqList    0x021befd8 arm
 *
 * blocker:  register allocation -- rc lands in r6 where the original keeps
 *           it in r4, and the original re-materialises reqCurrent->field_0x0c
 *           once more (the predicated condition load is not reused for the
 *           store); 148/152 bytes.
 *
 * w8_nm:    locals declared in reverse DWARF order (rc first) put rc, mutexInfo_p
 *           and reqCurrent_p in r4, r5, r6 as in the object (75 B -> 66 B,
 *           the rest is the one-instruction shift). Left: the object reloads
 *           reqCurrent_p->field_0x0c for the store after the predicated test.
 *           Not fixed by nested ifs (two or three levels), rc = 1 before the
 *           store, `!*p`, an unsigned or volatile-cast deref, or a listInfo_p
 *           local for the free call.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPSysInfo;
struct _NHTTPMutexInfo;
struct _NHTTPListInfo;
struct _NHTTPReq;

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

extern struct _NHTTPReqInfo *NHTTPi_GetReqInfoP(struct _NHTTPSysInfo *);
extern struct _NHTTPMutexInfo *NHTTPi_GetMutexInfoP(struct _NHTTPSysInfo *);
extern struct _NHTTPListInfo *NHTTPi_GetListInfoP(struct _NHTTPSysInfo *);
extern void NHTTPi_lockReqList(struct _NHTTPMutexInfo *);
extern void NHTTPi_SocCancel(struct _NHTTPMutexInfo *, int, int);
extern int NHTTPi_freeReqQueue(struct _NHTTPListInfo *, struct _NHTTPMutexInfo *, int);
extern void NHTTPi_unlockReqList(struct _NHTTPMutexInfo *);

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
        *reqCurrent_p->field_0x0c = 1;
        NHTTPi_SocCancel(mutexInfo_p, (int)reqCurrent_p->field_0x0c, reqCurrent_p->field_0x10);
        rc = 1;
    }
    if (rc == 0)
        rc = NHTTPi_freeReqQueue(NHTTPi_GetListInfoP(sysInfo_p), mutexInfo_p, id);
    NHTTPi_unlockReqList(mutexInfo_p);
    return rc;
}
