/*
 * function: NHTTPi_SendRequestAsync
 * address:  0x021BB97C
 * packet:   pkt_ov114_021BB97C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SendRequestAsync (libnhttp.TWL.HYB.a nhttp_request.o)
 *
 * symbols:
 *   NHTTPi_GetBgnEndInfoP     0x021bef3c arm
 *   NHTTPi_GetThreadInfoP     0x021bef50 arm
 *   NHTTPi_GetMutexInfoP      0x021bef58 arm
 *   NHTTPi_SetError           0x021ba874 arm
 *   NHTTPi_lockReqList        0x021befcc arm
 *   NHTTPi_GetListInfoP       0x021bef40 arm
 *   NHTTPi_setReqQueue        0x021bacfc arm
 *   NHTTPi_kickCommThread     0x021b9c08 arm
 *   NHTTPi_unlockReqList      0x021befd8 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPSysInfo;
struct _NHTTPMutexInfo;
struct _NHTTPListInfo;
struct _NHTTPBgnEndInfo;
struct _NHTTPThreadInfo;

struct _NHTTPReq {
    u32 field_0x00;
    int field_0x04;
};

extern struct _NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(struct _NHTTPSysInfo *);
extern struct _NHTTPThreadInfo *NHTTPi_GetThreadInfoP(struct _NHTTPSysInfo *);
extern struct _NHTTPMutexInfo *NHTTPi_GetMutexInfoP(struct _NHTTPSysInfo *);
extern struct _NHTTPListInfo *NHTTPi_GetListInfoP(struct _NHTTPSysInfo *);
extern void NHTTPi_SetError(struct _NHTTPBgnEndInfo *, int);
extern void NHTTPi_lockReqList(struct _NHTTPMutexInfo *);
extern int NHTTPi_setReqQueue(struct _NHTTPListInfo *, struct _NHTTPReq *);
extern void NHTTPi_kickCommThread(struct _NHTTPThreadInfo *);
extern void NHTTPi_unlockReqList(struct _NHTTPMutexInfo *);

int NHTTPi_SendRequestAsync(struct _NHTTPSysInfo *sysInfo_p, struct _NHTTPReq *req_p)
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
