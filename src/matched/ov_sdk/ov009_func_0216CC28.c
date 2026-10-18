/*
 * function: DWCi_MatchInit
 * address:  0x0216CC28
 * packet:   pkt_0216CC28
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_MatchInit (dwc_match.o): seed the match parameter block returned by
 * func_02175F3C(), every field through a fresh getter call.  The +0x5f0/+0x5f4
 * pair is the one place a local reuses one getter result.
 *
 * symbols:
 *   DWCi_SetMatchCnt  0x02175F1C  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_SetMatchStatus  0x02175F4C  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWCi_NodeInfoList_Clear  0x0217601C  arm  ov009
 *   DWCi_TempNewNodeInfo_Clear  0x0217653C  arm  ov009
 *   DWCi_ClearGameMatchKeys  0x02173B18  arm  ov009
 *   DWCi_ResetMatchParam  0x0216F388  arm  ov009
 */

extern void  DWCi_SetMatchCnt(int a0);
extern int func_02175F3C(void);
extern void  DWCi_SetMatchStatus(int a0);
extern void  MI_CpuFill8(void *p, int v, int n);
extern void  DWCi_NodeInfoList_Clear(void);
extern void  DWCi_TempNewNodeInfo_Clear(void);
extern void  DWCi_ClearGameMatchKeys(void);
extern int   DWCi_ResetMatchParam(int a0);

int DWCi_MatchInit(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    char *q;

    DWCi_SetMatchCnt(a0);
    *(int *)(func_02175F3C() + 0x0) = a1;
    *(int *)(func_02175F3C() + 4) = a2;
    *(int *)(func_02175F3C() + 8) = a3;
    *(int *)(func_02175F3C() + 0x10) = 0;
    *(int *)(func_02175F3C() + 0x5d8) = 0;
    *(unsigned short *)(func_02175F3C() + 0x5d4) = 0;
    *(int *)(func_02175F3C() + 0x5e0) = 0;
    DWCi_SetMatchStatus(0);
    *(char *)(func_02175F3C() + 0x19) = 0;
    *(int *)(func_02175F3C() + 0x678) = 0;
    *(int *)(func_02175F3C() + 0x684) = a4;
    *(int *)(func_02175F3C() + 0x688) = a5;
    *(int *)(func_02175F3C() + 0x68c) = a6;
    *(int *)(func_02175F3C() + 0x690) = a7;
    MI_CpuFill8((void *)(func_02175F3C() + 0x694), 0, 0x40);
    *(int *)(func_02175F3C() + 0x6d4) = 0;
    *(int *)(func_02175F3C() + 0x770) = 0;
    *(int *)(func_02175F3C() + 0x774) = 0;
    *(int *)(func_02175F3C() + 0x780) = 0;
    *(int *)(func_02175F3C() + 0x784) = 0;
    *(int *)(func_02175F3C() + 0x788) = 0;
    *(int *)(func_02175F3C() + 0x78c) = 0;
    *(int *)(func_02175F3C() + 0x790) = 0;
    *(char *)(func_02175F3C() + 0x794) = 0;
    *(int *)(func_02175F3C() + 0x798) = 0;
    *(char *)(func_02175F3C() + 0x15) = 0;
    *(char *)(func_02175F3C() + 0x16) = 0;
    q = (char *)func_02175F3C();
    *(int *)(q + 0x5f0) = 0;
    *(int *)(q + 0x5f4) = 0;
    *(int *)(func_02175F3C() + 0x7c8) = 0;
    *(int *)(func_02175F3C() + 0x7d4) = 1;
    *(char *)(func_02175F3C() + 0x7b5) = 0;
    *(char *)(func_02175F3C() + 0x7b6) = 0;
    *(int *)(func_02175F3C() + 0x7b0) = 0;
    DWCi_NodeInfoList_Clear();
    DWCi_TempNewNodeInfo_Clear();
    DWCi_ClearGameMatchKeys();
    return DWCi_ResetMatchParam(0);
}
