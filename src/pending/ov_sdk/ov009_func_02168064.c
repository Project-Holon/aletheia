/*
 * function: func_02168064
 * address:  0x02168064
 * packet:   pkt_ov009_02168064
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (2 B differ at +0x90/+0x94: object ldr r1,[r4]; add r0,r1,#0xc50 for the auth pointer, compiler emits ldr r0 and add r0,r0)
 *
 * sdk:      DWC_NASLoginAsync (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 *
 * symbols:
 *   OS_Terminate   0x02088234  arm
 *   DWC_Alloc      0x0205A16C  arm
 *   DWCi_SetError  0x02059F54  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02177EE8  0x02177EE8  arm  ov009
 *   g_021AA830     0x021AA830  data
 *   g_021A1F74     0x021A1F74  data
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
extern void func_02177EE8(void *auth);
extern void DWC_Free(void);
extern NalCnt *g_021AA830;
extern char g_021A1F74[];

int func_02168064(void)
{
    if (g_021AA830 != 0)
        OS_Terminate();
    g_021AA830 = DWC_Alloc(4, 0x1E5C);
    if (g_021AA830 == 0) {
        DWCi_SetError(9, -20100);
        return 0;
    }
    MI_CpuFill8(g_021AA830, 0, 0x1E5C);
    MI_CpuCopy8(g_021A1F74, g_021AA830->id, 9);
    g_021AA830->alloc = (void (*)(void))DWC_Alloc;
    g_021AA830->free = DWC_Free;
    func_02177EE8(g_021AA830->auth);
    return 1;
}
