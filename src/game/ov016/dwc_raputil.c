/*
 * file:     dwc_raputil.c
 * unit:     yes
 * function: DWC_RAPUTIL_RunUtility, DWC_RAPUTIL_Init, DWC_RAPUTIL_Main, DWC_RAPUTIL_ResetSystem, DWC_RAPUTIL_Exit
 * address:  0x021B6100
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_ResetSystem                 0x02087BCC  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   DWC_StartUtility  0x021C0970  arm
 *   sDwcRaputilFileName  0x021DAAA0  data  a1
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   NET_DEVICE_TABLE_Select 0x0200F17C thumb
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   ov107_id 0x0000006B data a1
 *   NET_DEVICE_TABLE_Reset 0x0200F234 thumb
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   WIH_DWC_ResetFilterState 0x020107CC thumb
 */
#include "../types.h"

#include "../sdk_os.h"

#include "../arm9/os_system.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/os_emulator.h"
#include "dwcutil_main.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/net_device_table.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/os_reset.h"
#include "../arm9/wih_dwc.h"
void DWC_RAPUTIL_RunUtility(int heapId);
int DWC_RAPUTIL_Init(void);
int DWC_RAPUTIL_Main(void);
int DWC_RAPUTIL_ResetSystem(void);
int DWC_RAPUTIL_Exit(void);
extern char sDwcRaputilFileName[];
/* Overlay id 107: the symbol is absolute (its address is the id), hence the (int) casts. */
extern char ov107_id[];

#define REG_IME (*(volatile unsigned short *)0x04000208)

void DWC_RAPUTIL_RunUtility(int heapId)
{
    int savedIrq;
    void *utilWork;

    savedIrq = OS_DisableInterrupts();
    utilWork = GFL_HEAP_Alloc(heapId, 0x40000, 1, sDwcRaputilFileName, 0x3d);
    if (OS_IsRunOnTwl() == 0)
        DWC_StartUtility(utilWork, 1, 0);
    GFL_HEAP_Free(utilWork);
    OS_RestoreInterrupts(savedIrq);
    REG_IME;
    REG_IME = 1;
}

int DWC_RAPUTIL_Init(void) { GFL_HEAP_CreateChildHeap(1, 15, 0x40100); NET_DEVICE_TABLE_Select(1); GF_OVERLAY_Load((int)ov107_id); return 1; }

int DWC_RAPUTIL_Main(void)
{
    DWC_RAPUTIL_RunUtility(0xf);
    return 1;
}

int DWC_RAPUTIL_ResetSystem(void)
{
    OS_ResetSystem(0);
    return 1;
}

int DWC_RAPUTIL_Exit(void) { NET_DEVICE_TABLE_Reset(1); GF_OVERLAY_Unload((int)ov107_id); GFL_HEAP_DeleteChecked(15); WIH_DWC_ResetFilterState(); return 1; }
