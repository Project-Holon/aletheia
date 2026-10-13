/*
 * function: NHTTPi_CleanupAsync
 * address:  0x021BA988
 * packet:   pkt_ov114_021BA988
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_CleanupAsync (nhttp_bgnend.o)
 *
 * Closed by giving the socket its own home: the object loads
 * bgnEndInfo_p->socket into r2 because that value is the third ARGUMENT of
 * NHTTPi_SocClose (= NHTTPi_SocClose, see the sibling NHTTPi_ThreadReqEnd at
 * 0x021BD270), so it stays live to the call.  Declaring the callee with the
 * (mutexInfo_p, req_p, socket) signature and passing the field through makes
 * the load land in r2 and the compare follow it: 140 bytes, EXACT, no other
 * byte moved.  The earlier two-argument spelling loaded it into r0 as a plain
 * scratch and was 2 bytes out.
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
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov114_func_021BA988.c \
 *       --func NHTTPi_CleanupAsync --addr 0x021BA988 --region ov114 --arm --cc 1.1p1 --lang c99 --diff
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
extern int NHTTPi_SocClose(void *mutexInfo_p, struct _NHTTPReq *req_p, int socket);

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
        NHTTPi_SocClose(0, 0, bgnEndInfo_p->socket);
        bgnEndInfo_p->socket = -1;
    }
}
