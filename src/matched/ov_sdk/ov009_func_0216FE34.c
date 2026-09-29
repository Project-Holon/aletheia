/*
 * function: func_0216FE34
 * address:  0x0216FE34
 * packet:   pkt_ov009_0216FE34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_DoNatNegotiationAsync (dwc_match.o)
 *
 * notes:    closed (w5_nm): the progress-callback pointer 0x02174FE4 (bx lr leaf,
 *           DWCi_NNProgressCallback) now has a seed, a catalog row and a stub
 *           (src/matched/ov_sdk/ov009_func_02174FE4.c), so it attests as sdk.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02198620  0x02198620  arm  ov009
 *   func_0219EF60  0x0219EF60  arm  ov009
 *   func_02173D9C  0x02173D9C  arm  ov009
 *   func_02195E60  0x02195E60  arm  ov009
 *   func_02199DFC  0x02199DFC  arm  ov009
 *   func_02174FE4  0x02174FE4  arm  ov009
 *   func_02174FE8  0x02174FE8  arm  ov009
 */

struct nninfo_s {
    unsigned char clientindex;
    unsigned char pad1;
    unsigned short port;
    int ip;
    int cookie;
};

extern char *func_02175F3C(void);
extern char *func_02198620(int ip, int a, int b);
extern int func_0219EF60(int sb, char *addr, int port, int cookie);
extern int func_02173D9C(int sbError);
extern int func_02195E60(int gt2sock);
extern int func_02199DFC(int sock, int cookie, int clientindex, void *progress, void *completed, void *userdata);
extern void func_02174FE4(void);
extern void func_02174FE8(void);

int func_0216FE34(struct nninfo_s *nnInfo)
{
    int i;
    int nnError;
    int sbError;

    if (nnInfo->clientindex == 0) {
        sbError = func_0219EF60(*(int *)(func_02175F3C() + 0x5e0), func_02198620(nnInfo->ip, 0, 0), nnInfo->port, nnInfo->cookie);
        if (func_02173D9C(sbError))
            return 2;
    }
    for (i = 0; i < 1; i++) {
        nnError = func_02199DFC(func_02195E60(**(int **)(func_02175F3C() + 4)), nnInfo->cookie, nnInfo->clientindex, func_02174FE4, func_02174FE8, nnInfo);
        if (nnError == 0)
            return nnError;
        if (nnError != 3)
            return nnError;
    }
    return nnError;
}
