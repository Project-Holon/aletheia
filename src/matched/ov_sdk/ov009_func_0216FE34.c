/*
 * function: DWCi_DoNatNegotiationAsync
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
 *   gt2AddressToString  0x02198620  arm  ov009
 *   ServerBrowserSendNatNegotiateCookieToServerA  0x0219EF60  arm  ov009
 *   DWCi_HandleSBError  0x02173D9C  arm  ov009
 *   gt2GetSocketSOCKET  0x02195E60  arm  ov009
 *   NNBeginNegotiationWithSocket  0x02199DFC  arm  ov009
 *   DWCi_NNProgressCallback  0x02174FE4  arm  ov009
 *   func_02174FE8  0x02174FE8  arm  ov009
 */

struct nninfo_s {
    unsigned char clientindex;
    unsigned char pad1;
    unsigned short port;
    int ip;
    int cookie;
};

extern int func_02175F3C(void);
extern char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);
struct ServerBrowser;
extern int ServerBrowserSendNatNegotiateCookieToServerA(struct ServerBrowser *sb, char *ip, unsigned short port, int cookie);
extern int DWCi_HandleSBError(int sbError);
extern int gt2GetSocketSOCKET(const int *p);
extern int NNBeginNegotiationWithSocket(int sock, int cookie, int clientindex, void *progress, void *completed, void *userdata);
extern void DWCi_NNProgressCallback(void);
extern void func_02174FE8(void);

int DWCi_DoNatNegotiationAsync(struct nninfo_s *nnInfo)
{
    int i;
    int nnError;
    int sbError;

    if (nnInfo->clientindex == 0) {
        sbError = ServerBrowserSendNatNegotiateCookieToServerA((struct ServerBrowser *)(*(int *)(func_02175F3C() + 0x5e0)), gt2AddressToString(nnInfo->ip, 0, 0), nnInfo->port, nnInfo->cookie);
        if (DWCi_HandleSBError(sbError))
            return 2;
    }
    for (i = 0; i < 1; i++) {
        nnError = NNBeginNegotiationWithSocket(gt2GetSocketSOCKET((const int *)(**(int **)(func_02175F3C() + 4))), nnInfo->cookie, nnInfo->clientindex, DWCi_NNProgressCallback, func_02174FE8, nnInfo);
        if (nnError == 0)
            return nnError;
        if (nnError != 3)
            return nnError;
    }
    return nnError;
}
