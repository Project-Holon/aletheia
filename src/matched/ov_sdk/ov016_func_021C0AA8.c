/*
 * function: func_021C0AA8
 * address:  0x021C0AA8
 * packet:   pkt_ov016_021C0AA8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      initGame (libdwcutil.TWL.HYB.a main.o)
 *
 * symbols:
 *   GX_DispOff  0x0207D42C  arm
 *   OS_IsTickAvailable  0x02087058  arm
 *   OS_Terminate   0x02088234  arm
 *   OS_IsAlarmAvailable  0x02087244  arm
 *   GX_VBlankIntr  0x0207D3E4  arm
 *   FX_Init  0x0207D148  arm
 *   FS_Init  0x0207AD04  arm
 *   TP_Init  0x0208A924  arm
 *   RTC_Init  0x02088788  arm
 *   DWCi_ClearVram  0x021D7274  arm  ov016
 *   DWCi_HEAPlInit  0x021D6360  arm  ov016
 *   DWCi_ITRlIntr  0x021D6C78  arm  ov016
 *   DWCi_TSKlInit  0x021D7484  arm  ov016
 *   DWCi_ARClInit  0x021D486C  arm  ov016
 *   DWCi_IPTlInit  0x021D64B8  arm  ov016
 *   DWCi_EFFlInit  0x021D551C  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWC_BM_Init  0x020589D0  arm
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gDwcutilMainWork     0x021DE56C  data
 */

#include "../include/G_UtilState.h"

typedef struct UtilState UtilState;

extern void GX_DispOff(void);
extern int OS_IsTickAvailable(void);
extern void OS_Terminate(void);
extern int OS_IsAlarmAvailable(void);
extern long GX_VBlankIntr(int enable);
extern void FX_Init(void);
extern void FS_Init(unsigned long default_dma_no);
extern void TP_Init(void);
extern void RTC_Init(void);
extern void DWCi_ClearVram(void);
extern void DWCi_HEAPlInit(void *address);
extern void DWCi_ITRlIntr(void);
extern void DWCi_TSKlInit(void);
extern void DWCi_ARClInit(void);
extern void DWCi_IPTlInit(void);
extern void DWCi_EFFlInit(void);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern int DWC_BM_Init(void *work);
extern void DWCi_HEAPlFree_(void **mem);
extern struct UtilState gDwcutilMainWork;

void func_021C0AA8(void)
{
    void *work;
    int zero;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short old = *ime;
    *ime = 0;
    GX_DispOff();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    if (!OS_IsTickAvailable())
        OS_Terminate();
    if (!OS_IsAlarmAvailable())
        OS_Terminate();
    zero = 0;
    GX_VBlankIntr(zero);
    FX_Init();
    FS_Init(zero - 1);
    TP_Init();
    RTC_Init();
    GX_DispOff();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    DWCi_ClearVram();
    DWCi_HEAPlInit(gDwcutilMainWork.work);
    DWCi_ITRlIntr();
    DWCi_TSKlInit();
    DWCi_ARClInit();
    DWCi_IPTlInit();
    DWCi_EFFlInit();
    work = DWCi_HEAPlAllocEx(0x1000, 0x20);
    DWC_BM_Init(work);
    DWCi_HEAPlFree_(&work);
}
