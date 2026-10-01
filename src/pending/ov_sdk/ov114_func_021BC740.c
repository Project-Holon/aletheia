/*
 * function: func_021BC740
 * address:  0x021BC740
 * packet:   pkt_ov114_021BC740
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (near miss: register allocation and frame spill slots, see notes)
 * blocker:  [sp+0xc] identity: object spills threadInfo_p there (+0x020 str / +0x1A8 ldr)
 *           and keeps endFlag in lr/ip in registers; this source spills volatile endFlag
 *           there and keeps threadInfo_p in sl. Tried `NHTTPThreadInfo *volatile` +
 *           non-volatile endFlag -> 468 B / 367 B diff (worse, endFlag needs to stay in a
 *           register, not be a volatile stack slot). fp/sb roles are swapped (&tmpbuf vs
 *           recvbyte) and the object reuses sb as the constant 1 inside the loop, entering
 *           it 8 B later; the whole inner-loop colouring follows from the spill decision.
 *           Floor 142 B over 24674 decl/qualifier permutations.
 *           DWARF of the defining object (scratch/lt28/sdkobj_021BC740.txt) homes the
 *           variables: totalRecvbyte r8, connectFlag [fb+8], endFlag r14, recvbyte r11,
 *           i r12, tmpbuf [fb+16], res_p r7, req_p r6, mutexInfo_p r5, bgnEndInfo_p r4,
 *           commBuf_p r0, threadInfo_p r0. So the true source has NO tmp_p and a named
 *           commBuf_p; endFlag really is lr and i really is ip. Removing tmp_p/volatile to
 *           match the DWARF changed the allocator's frame (sp+0x208, tmpbuf at sp+8, no
 *           threadInfo spill) -> 456 B / 346 diff; adding commBuf_p alone gave 166 B. The
 *           142 B floor is the closest source approximation but is not the true shape.
 * notes:    121/121 instructions, 484/484 bytes, 142 concrete bytes differ. All 10
 *           relocations resolve; there are no unresolved absolutes, and all 9 bl call sites
 *           are byte-identical to the object. The remainder is register/frame shape only:
 *             - [sp+8] connectFlag is correct in both. [sp+0xc] is the wrong variable: the
 *               object spills threadInfo_p there (+0x020 str, +0x1A8 ldr), here it holds
 *               endFlag (+0x0B0 str, +0x164 ldr) while threadInfo_p stays in sl.
 *             - &tmpbuf[0] is in fp and recvbyte in sb; the object has sb and fp swapped.
 *               The object computes add sb, sp, #0x10 inside the loop at +0x064, here it is
 *               hoisted to +0x04C.
 *             - the object keeps endFlag in lr and i in ip; here i is r2 and endFlag is
 *               reloaded from [sp+0xc] before the +0x0164 test.
 *             - the object's inner loop is entered 2 instructions (8 B) later at +0x0E0
 *               because it sets sb=1 once and copies it (mov r1,sb / mov r2,sb) instead of
 *               needing a dedicated r3, so its loop back-edge targets +0x820 not +0x818 and
 *               the two outer-loop branches target +0x794 not +0x798. The loop bodies are
 *               otherwise the same 32 instructions.
 *             - the object forms the return-1 as a real mov r0, #1 at +0x0168 and reuses
 *               sb=0 for the return-0 at +0x0194; here 1 needs r3 and +0x018C materialises
 *               a mov r0, #1 that the following movlt r0, #0 discards.
 *             - the object reads commBuf via the spill (+0x1A8 ldr, +0x1B8 add #0x100);
 *               here it is add r3, sl, #0x100 at +0x1B8.
 *           tmp_p and the volatile on endFlag are codegen levers only; both are
 *           behaviourally inert. Search: 24674 declaration/qualifier permutations plus a
 *           28-mutation hill climb over spelling; 142 B is the floor reached, all of them
 *           selecting the same allocation.
 *
 * sdk:      NHTTPi_RecvProxyConnectHeader (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF48  0x021BEF48  arm  ov114
 *   func_021BEF50  0x021BEF50  arm  ov114
 *   func_021BEF3C  0x021BEF3C  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   func_021B9F94  0x021B9F94  arm  ov114
 *   func_021BA448  0x021BA448  arm  ov114
 *   func_021BA150  0x021BA150  arm  ov114
 *   g_021CE4A8  0x021CE4A8  data
 */

typedef struct {
    char pad[0x18];
    int httpStatus;
    char pad1c[0x2c - 0x1c];
} NHTTPRes;

typedef struct {
    char pad[0x2c];
    NHTTPRes *res_p;
} NHTTPReq;

typedef struct {
    char pad[0xc];
    NHTTPReq *req_p;
} NHTTPReqList;

typedef struct {
    NHTTPReqList *reqCurrent;
} NHTTPReqInfo;

typedef struct {
    char pad[0xc];
    int socket;
} NHTTPBgnEndInfo;

typedef struct {
    char pad0[0x100];
    char commBuf[1];
} NHTTPThreadInfo;

extern void *func_021BEF08(void);
extern NHTTPReqInfo *func_021BEF48();
extern NHTTPThreadInfo *func_021BEF50(void *sysInfo_p);
extern NHTTPBgnEndInfo *func_021BEF3C(void *sysInfo_p);
extern void *func_021BEF58(void *sysInfo_p);
extern int func_021B9F94(void *mutexInfo_p, NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
extern int func_021BA448(char *p_p, int len);
extern int func_021BA150(char *p1_p, char *p2_p, int size);
extern char g_021CE4A8[];

static int func_021BC740(void)
{
    NHTTPBgnEndInfo *bgnEndInfo_p;
    void *mutexInfo_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    int totalRecvbyte;
    char *tmp_p;
    char tmpbuf[512];
    int recvbyte;
    NHTTPThreadInfo *threadInfo_p;
    int connectFlag;
    volatile int endFlag;
    void *sysInfo_p;
    NHTTPReqInfo *reqInfo_p;
    int i;

    sysInfo_p = func_021BEF08();
    reqInfo_p = func_021BEF48();
    threadInfo_p = func_021BEF50(sysInfo_p);
    bgnEndInfo_p = func_021BEF3C(sysInfo_p);
    mutexInfo_p = func_021BEF58(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    tmp_p = tmpbuf;
    connectFlag = 0;
    totalRecvbyte = 0;
    while (1) {
        recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket, tmp_p + totalRecvbyte,
                                 512 - totalRecvbyte, 0);
        totalRecvbyte += recvbyte;
        res_p->httpStatus = func_021BA448(&tmpbuf[9], 3);
        if (func_021BA150(tmp_p, g_021CE4A8, 5) == 0 && tmpbuf[8] == ' ' && res_p->httpStatus == 200)
            connectFlag = 1;
        endFlag = 0;
        for (i = 0; i < totalRecvbyte; i++) {
            if (i > 1 && tmpbuf[i] == '\r' && tmpbuf[i - 1] == '\r') {
                endFlag = 1;
                break;
            }
            if (i > 1 && tmpbuf[i] == '\n' && tmpbuf[i - 1] == '\n') {
                endFlag = 1;
                break;
            }
            if (i > 3 && tmpbuf[i - 3] == '\r' && tmpbuf[i - 2] == '\n' && tmpbuf[i - 1] == '\r' &&
                tmpbuf[i] == '\n')
                endFlag = 1;
        }
        if (endFlag)
            return connectFlag != 0;
        if (recvbyte < 0)
            return 0;
        if (totalRecvbyte >= 512) {
            recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket, threadInfo_p->commBuf, 1, 0);
            if (recvbyte < 0)
                return 0;
            if (recvbyte != 0)
                return 0;
        }
    }
}
