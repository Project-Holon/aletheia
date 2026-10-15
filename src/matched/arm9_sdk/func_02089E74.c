/*
 * function: InitPXI
 * address:  0x02089E74
 * packet:   pkt_02089E74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      InitPXI (snd_command.o)
 *
 * symbols:
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   IsCommandAvailable       0x02089F48  arm
 *   PXI_IsCallbackReady      0x020885EC  arm
 *   OS_SpinWaitSysCycles     0x02087A04  arm
 *   PxiFifoCallback          0x02089E50  arm
 */

typedef unsigned long u32;
typedef int BOOL;
typedef void (*PXIFifoCallback)(int tag, u32 data, BOOL err);

extern void PXI_SetFifoRecvCallback(int fifotag, PXIFifoCallback callback);
extern BOOL IsCommandAvailable(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern void PxiFifoCallback(int tag, u32 data, BOOL err);

void InitPXI(void)
{
    PXI_SetFifoRecvCallback(7, PxiFifoCallback);

    if (IsCommandAvailable()) {
        if (!PXI_IsCallbackReady(7, 1)) {
            do {
                OS_SpinWaitSysCycles(0x32);
            } while (!PXI_IsCallbackReady(7, 1));
        }
    }
}
