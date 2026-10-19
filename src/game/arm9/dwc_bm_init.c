/*
 * file:     dwc_bm_init.c
 * function: DWC_BM_Init
 * address:  0x020589D0
 * packet:   pkt_020589D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_BM_Init (libdwcbm.TWL.HYB.a dwc_bm_init.o)
 *
 * symbols:
 *   MI_CpuFill8          0x02082BCC arm
 *   OS_IsRunOnTwl        0x02085D3C arm
 *   NCFG_CheckConfigEx   0x0205FB1C arm
 *   NCFG_CheckConfig     0x0205FAC0 arm
 *   DWCi_BACKUPlRead     0x02058770 arm
 *   DWCi_BACKUPlSetWiFi  0x020587E0 arm
 */

#include "../types.h"

#include "../sdk_ncfg.h"

#include "../sdk_math.h"

typedef struct tagDWCMemMap {
    NCFGSlotInfo page[4];
} DWCMemMap;

typedef struct tagMEMINIT {
    DWCMemMap      mm;
    u8             work[256];
    MATHCRC16Table tbl;
} MEMINIT;

#define DWC_INIT_WORK_SIZE 0x1000

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern int  OS_IsRunOnTwl(void);
extern s32  NCFG_CheckConfigEx(void *work);
extern s32  NCFG_CheckConfig(void *work);
extern int  DWCi_BACKUPlRead(void *mem);
extern void DWCi_BACKUPlSetWiFi(u8 *wifi);

int DWC_BM_Init(void *work)
{
    s32 ret;
    MEMINIT *wk;

    MI_CpuFill8(work, 0, DWC_INIT_WORK_SIZE);
    if (OS_IsRunOnTwl())
        ret = NCFG_CheckConfigEx(work);
    else
        ret = NCFG_CheckConfig(work);
    MI_CpuFill8(work, 0, DWC_INIT_WORK_SIZE);
    wk = (MEMINIT *)work;
    if (!DWCi_BACKUPlRead(&wk->mm))
        return -10001;
    DWCi_BACKUPlSetWiFi(wk->mm.page[0].wifi);
    return ret;
}
