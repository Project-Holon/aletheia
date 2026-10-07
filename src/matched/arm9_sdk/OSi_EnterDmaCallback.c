/*
 * function: OSi_EnterDmaCallback
 * address:  0x020848A4
 * packet:   pkt_020848A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT* (listing extent runs on into OSi_EnterNDmaCallback at 0x020848EC)
 *
 * TwlSDK libos os interrupt.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   g_02150F38                     0x02150F38  data
 *   OS_EnableIrqMask               0x02084968  arm
 */

#include "../include/G_OSIrqCallbackInfo.h"

typedef unsigned long u32;
typedef int BOOL;
typedef u32 OSIrqMask;
typedef void (*OSIrqFunction)(void);

typedef struct OSIrqCallbackInfo OSIrqCallbackInfo;

extern struct OSIrqCallbackInfo g_02150F38[];   /* OSi_IrqCallbackInfo */
extern OSIrqFunction g_02FE0020[];       /* OS_IRQTable (DTCM) */
#define OSi_IrqCallbackInfo g_02150F38
#define OS_IRQTable g_02FE0020

extern OSIrqMask OS_EnableIrqMask(OSIrqMask intr);

void OSi_EnterDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg)
{
    OSIrqMask imask = (OSIrqMask)(1 << (dmaNo + 8));

    OSi_IrqCallbackInfo[dmaNo].func = callback;
    OSi_IrqCallbackInfo[dmaNo].arg = arg;
    OSi_IrqCallbackInfo[dmaNo].enable = OS_EnableIrqMask(imask) & imask;
}
