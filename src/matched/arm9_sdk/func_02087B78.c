/*
 * function: OS_InitReset
 * address:  0x02087B78
 * packet:   pkt_02087B78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitReset (os_reset.o)
 *
 * symbols:
 *   PXI_Init                 0x02088498  arm
 *   PXI_IsCallbackReady      0x020885EC  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   OSi_CommonCallback       0x02084A38  arm
 *   OSi_IsInitReset          0x02151368  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

extern void PXI_Init(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int, u32, BOOL));
extern void OSi_CommonCallback(int tag, u32 data, BOOL err);
extern u16 OSi_IsInitReset;

void OS_InitReset(void)
{
    if (OSi_IsInitReset) {
        return;
    }
    OSi_IsInitReset = 1;

    PXI_Init();
    while (!PXI_IsCallbackReady(12, 1)) {
    }
    PXI_SetFifoRecvCallback(12, OSi_CommonCallback);
}
