/*
 * function: func_0205BC78
 * address:  0x0205BC78
 * packet:   pkt_0205BC78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_AC_Process (dwc_ac.o)
 *
 * symbols:
 *   CheckEULA             0x0205C600  arm
 *   CheckWirelessPowerON  0x0205C670  arm
 *   CheckDuplicate        0x0205C55C  arm
 *   Free_Disused          0x0205C528  arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef unsigned long long u64;
typedef int BOOL;

extern u8 DWCi_AC_GetPhase(void);
extern BOOL CheckEULA(void);
extern BOOL CheckWirelessPowerON(void);
extern u8 DWCi_AC_Start(void);
extern void DWCi_AC_SetError(int error);
extern u32 OS_DisableInterrupts(void);
extern u8 DWCi_AC_SearchAP(void);
extern void DWCi_AC_SetPhase(u8 phase);
extern u32 OS_RestoreInterrupts(u32 state);
extern u8 DWCi_AC_ConnectAP(void);
extern u8 DWCi_AC_ConnectRetryAP(void);
extern u8 DWCi_AC_ConnectTest(void);
extern u8 DWCi_AC_Error(void);
extern BOOL CheckDuplicate(void);
extern void Free_Disused(void);

int func_0205BC78(void)
{
    int ret;
    u32 irq;
    u8 phase = DWCi_AC_GetPhase();

    if (phase == 1) {
        if (CheckEULA()) {
            if (CheckWirelessPowerON()) {
                phase = DWCi_AC_Start();
            } else {
                DWCi_AC_SetError(8);
                phase = DWCi_AC_Error();
            }
        } else {
            DWCi_AC_SetError(7);
            phase = DWCi_AC_Error();
        }
    } else if (phase < 7) {
        irq = OS_DisableInterrupts();
        phase = DWCi_AC_SearchAP();
        DWCi_AC_SetPhase(phase);
        OS_RestoreInterrupts(irq);
    } else if (phase < 9) {
        phase = DWCi_AC_ConnectAP();
    } else if (phase < 0xa) {
        phase = DWCi_AC_ConnectRetryAP();
    } else if (phase < 0x10) {
        phase = DWCi_AC_ConnectTest();
    } else if (phase == 0x11) {
        phase = DWCi_AC_Error();
    }
    DWCi_AC_SetPhase(phase);
    if (phase == 0x10) {
        ret = CheckDuplicate();
        Free_Disused();
        return ret;
    }
    if (phase == 0x12) {
        Free_Disused();
        return -1;
    }
    return 0;
}
