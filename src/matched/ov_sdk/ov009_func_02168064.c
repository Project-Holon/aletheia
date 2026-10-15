/*
 * function: DWC_NASLoginAsync
 * address:  0x02168064
 * packet:   pkt_ov009_02168064
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NASLoginAsync (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 *
 * symbols:
 *   OS_Terminate   0x02088234  arm
 *   DWC_Alloc      0x0205A16C  arm
 *   DWCi_SetError  0x02059F54  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   DWC_Auth_Create  0x02177EE8  arm  ov009
 *   gDwcNasCnt     0x021AA830  data
 *   gDwcNasInitialId     0x021A1F74  data
 *   DWC_Free       0x0205A1B0  arm
 */

typedef struct NalCnt {
    unsigned char pad0[0x1C50];
    unsigned char auth[0x1C84 - 0x1C50];
    unsigned char id[0x1C90 - 0x1C84];
    void (*alloc)(void);
    void (*free)(void);
} NalCnt;

extern void OS_Terminate(void);
extern void *DWC_Alloc(int kind, int size);
extern void DWCi_SetError(int kind, int code);
extern void MI_CpuFill8(void *dst, int data, int size);
extern void MI_CpuCopy8(void *src, void *dst, int size);
struct DWCAuthParam;
extern int DWC_Auth_Create(struct DWCAuthParam *param, void *http);
extern void DWC_Free(void);
extern NalCnt *gDwcNasCnt;
extern char gDwcNasInitialId[];

int DWC_NASLoginAsync(void)
{
    if (gDwcNasCnt != 0)
        OS_Terminate();
    gDwcNasCnt = DWC_Alloc(4, 0x1E5C);
    if (gDwcNasCnt == 0) {
        DWCi_SetError(9, -20100);
        return 0;
    }
    MI_CpuFill8(gDwcNasCnt, 0, 0x1E5C);
    MI_CpuCopy8(gDwcNasInitialId, gDwcNasCnt->id, 9);
    gDwcNasCnt->alloc = (void (*)(void))DWC_Alloc;
    gDwcNasCnt->free = DWC_Free;
    DWC_Auth_Create((struct DWCAuthParam *)gDwcNasCnt->auth, gDwcNasCnt);
    return 1;
}
