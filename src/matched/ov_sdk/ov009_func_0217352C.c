/*
 * function: DWCi_ServerSynTimeoutExec
 * address:  0x0217352C
 * packet:   pkt_ov009_0217352C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ServerSynTimeoutExec (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02172EAC  0x02172EAC  arm  ov009
 *   DWCi_NodeInfoList_GetCount  0x0217603C  arm  ov009
 *   DWCi_TempNewNodeInfo_IsValid  0x02176554  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   DWCi_SetMatchStatus  0x02175F4C  arm  ov009
 *   func_021720D8  0x021720D8  arm  ov009
 */

extern char *func_02175F3C(void);
typedef unsigned int   u32;
extern int func_02172EAC(u32 bitmap);
extern int DWCi_NodeInfoList_GetCount(void);
extern int DWCi_TempNewNodeInfo_IsValid(void);
extern unsigned long long func_020870D0(void);
extern void DWCi_SetMatchStatus(int status);
extern int func_021720D8(int id);

int DWCi_ServerSynTimeoutExec(void)
{
    if (!func_02172EAC(*(int *)(func_02175F3C() + 0x650)))
        return 0;
    if (DWCi_NodeInfoList_GetCount() > 1 || DWCi_TempNewNodeInfo_IsValid()) {
        unsigned long long t = func_020870D0();
        *(unsigned long long *)(func_02175F3C() + 0x658) = t;
        DWCi_SetMatchStatus(23);
    } else if (!func_021720D8(*(int *)(func_02175F3C() + 0x680))) {
        return 0;
    }
    return 1;
}
