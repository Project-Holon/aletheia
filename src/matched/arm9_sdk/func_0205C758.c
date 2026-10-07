/*
 * function: func_0205C758
 * address:  0x0205C758
 * packet:   pkt_0205C758
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ConnectInetAsync (dwc_connectinet.o)
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   DWC_AC_Create 0x0205B98C arm
 *   DWCi_SetError 0x02059F54 arm
 *   DWC_Alloc 0x0205A16C arm
 *   DWC_Free 0x0205A1B0 arm
 *   g_02146AD4 0x02146AD4 data
 */

#include "../include/G_INETBSS.h"

typedef struct {
    int ac_state;
    unsigned short state;
    unsigned short online;
    unsigned short dmaNo;
    unsigned short powerMode;
    long rwin;
    unsigned char wontExecuteEULACheck;
    unsigned char wontExecuteWDS;
    int processWDSstate;
} DWCstInetControl;

/* dwc_connectinet.o .bss: stateOld (DWC_GetInetStatus static) then stpInetCntl */
typedef struct {
    int stateOld;
    DWCstInetControl *stpInetCntl;
} INETBSS;

extern struct INETBSS g_02146AD4;

typedef struct {
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    unsigned char dmaNo;
    unsigned char powerMode;
    unsigned char option[2];
    long rwin;
    unsigned char wontExecuteEULACheck;
} DWCACConfig;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWC_AC_Create(DWCACConfig *config);
extern void DWCi_SetError(int error, int errorCode);
extern void *DWC_Alloc(unsigned long name, long size);
extern void DWC_Free(unsigned long name, void *ptr, long size);

void func_0205C758(void)
{
    DWCACConfig inp;

    if (g_02146AD4.stpInetCntl != 0) {
        if (((DWCstInetControl *)g_02146AD4.stpInetCntl)->state != 1) {
            return;
        }
        MI_CpuFill8(&inp, 0, sizeof(inp));
        inp.dmaNo = ((DWCstInetControl *)g_02146AD4.stpInetCntl)->dmaNo;
        inp.powerMode = ((DWCstInetControl *)g_02146AD4.stpInetCntl)->powerMode;
        inp.rwin = ((DWCstInetControl *)g_02146AD4.stpInetCntl)->rwin;
        inp.alloc = DWC_Alloc;
        inp.free = DWC_Free;
        inp.wontExecuteEULACheck = ((DWCstInetControl *)g_02146AD4.stpInetCntl)->wontExecuteEULACheck;
        ((DWCstInetControl *)g_02146AD4.stpInetCntl)->state = 2;
        if (!DWC_AC_Create(&inp)) {
            DWCi_SetError(9, -50199);
        }
    } else {
        DWCi_SetError(9, -50199);
    }
}
