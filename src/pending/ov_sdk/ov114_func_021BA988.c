/*
 * function: NHTTPi_CleanupAsync
 * address:  0x021BA988
 * packet:   pkt_ov114_021BA988
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (2 bytes)
 *
 * sdk:      NHTTPi_CleanupAsync (nhttp_bgnend.o)
 *
 * blocker (w5_nm): rewritten from the DWARF; the earlier draft passed a0 to
 * NHTTPi_CheckCurrentThread, but the object passes threadInfo_p (EF50's result)
 * with TRUE, and the socket tail is `NHTTPi_SocClose(NULL, 0); socket = -1`
 * (111 bytes -> 2).  Residue: the object loads bgnEndInfo_p->socket into r2,
 * this compile into r0 (+0x64, +0x68).  Tried: the length result discarded,
 * cast to void, in a comma or dead compare, `< 0` early return, reversed
 * compare, a result local for SocClose, void/K&R prototypes for the length and
 * SocClose, and the callback spelled `(*callback)()`.
 *
 * symbols:
 *   NHTTPi_GetBgnEndInfoP          0x021BEF3C  arm ov114
 *   NHTTPi_GetThreadInfoP          0x021BEF50  arm ov114
 *   NHTTPi_CheckCurrentThread      0x021B9C1C  arm ov114
 *   NHTTPi_cancelAllRequests       0x021BBAAC  arm ov114
 *   NHTTPi_destroyCommThread       0x021B9BD4  arm ov114
 *   NHTTPi_free                    0x021BA850  arm ov114
 *   NHTTPi_exitLockReqList         0x021BEFC8  arm ov114
 *   NHTTPi_GetConnectionListLength 0x021BEC48  arm ov114
 *   NHTTPi_SocClose                0x021B9CFC  arm ov114
 */

struct _NHTTPSysInfo;
struct _NHTTPThreadInfo;
struct _NHTTPReq;
struct _NHTTPBgnEndInfo {
    void *(*alloc)(unsigned long, int);
    void (*free)(void *);
    int isOpened;
    int socket;
    int sslError;
    int error;
    int isThreadEnd;
    unsigned long *commThreadStack;
    int (*forDebugCallback)(void *, unsigned long);
    unsigned long defaultRootCAId;
};
typedef enum { FALSE_, TRUE_ } BOOLE;
extern struct _NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(struct _NHTTPSysInfo *sysInfo_p);
extern struct _NHTTPThreadInfo *NHTTPi_GetThreadInfoP(struct _NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_CheckCurrentThread(struct _NHTTPThreadInfo *threadInfo_p, BOOLE is);
extern void NHTTPi_cancelAllRequests(struct _NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_destroyCommThread(struct _NHTTPThreadInfo *threadInfo_p, struct _NHTTPBgnEndInfo *bgnEndInfo_p);
extern void NHTTPi_free(void *ptr_p);
extern void NHTTPi_exitLockReqList(void);
extern unsigned long NHTTPi_GetConnectionListLength(void);
extern int NHTTPi_SocClose(struct _NHTTPReq *req_p, int socket);

void NHTTPi_CleanupAsync(struct _NHTTPSysInfo *sysInfo_p, void (*callback)(void))
{
    struct _NHTTPBgnEndInfo *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    struct _NHTTPThreadInfo *threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);

    NHTTPi_CheckCurrentThread(threadInfo_p, TRUE_);
    NHTTPi_cancelAllRequests(sysInfo_p);
    NHTTPi_destroyCommThread(threadInfo_p, bgnEndInfo_p);
    NHTTPi_free(bgnEndInfo_p->commThreadStack);
    bgnEndInfo_p->commThreadStack = 0;
    NHTTPi_exitLockReqList();
    bgnEndInfo_p->isOpened = 0;
    if (callback)
        callback();
    NHTTPi_GetConnectionListLength();
    if (bgnEndInfo_p->socket >= 0) {
        NHTTPi_SocClose(0, 0);
        bgnEndInfo_p->socket = -1;
    }
}
