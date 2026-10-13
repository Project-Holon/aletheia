/*
 * function: DWC_RAPUTIL_RunUtility
 * address:  0x021B6100
 * packet:   pkt_ov016_021B6100
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   DWC_StartUtility  0x021C0970  arm
 *   sDwcRaputilFileName  0x021DAAA0  data  a1
 */
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int x);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int OS_IsRunOnTwl(void);
extern int DWC_StartUtility(void *work, int language, int param);
extern char sDwcRaputilFileName[];

void DWC_RAPUTIL_RunUtility(int heap)
{
    int e;
    void *p;

    e = OS_DisableInterrupts();
    p = func_02030734(heap, 0x40000, 1, sDwcRaputilFileName, 0x3d);
    if (OS_IsRunOnTwl() == 0)
        DWC_StartUtility(p, 1, 0);
    func_020307B0(p);
    OS_RestoreInterrupts(e);
    *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = 1;
}
