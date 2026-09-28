/*
 * function: OS_SetIrqFunction
 * address:  0x02084774
 * packet:   pkt_02084774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os interrupt.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   g_02150F38                     0x02150F38  data
 *   g_02FE0020                     0x02FE0020  data
 */

typedef unsigned long u32;
typedef int BOOL;
typedef u32 OSIrqMask;
typedef void (*OSIrqFunction)(void);

typedef struct OSIrqCallbackInfo {
    void (*func)(void *);
    u32 enable;
    void *arg;
} OSIrqCallbackInfo;

extern OSIrqCallbackInfo g_02150F38[];   /* OSi_IrqCallbackInfo */
extern OSIrqFunction g_02FE0020[];       /* OS_IRQTable (DTCM) */
#define OSi_IrqCallbackInfo g_02150F38
#define OS_IRQTable g_02FE0020

extern OSIrqMask OS_EnableIrqMask(OSIrqMask intr);

void OS_SetIrqFunction(OSIrqMask intrBit, OSIrqFunction function)
{
    int i;
    OSIrqCallbackInfo *info;

    for (i = 0; i < 32; i++) {
        if (intrBit & 1) {
            info = 0;

            if (8 <= i && i <= 11) {
                info = &OSi_IrqCallbackInfo[i - 8];
            } else if (0x1C <= i && i <= 0x1F) {
                info = &OSi_IrqCallbackInfo[i - 0x18];
            } else if (3 <= i && i <= 6) {
                info = &OSi_IrqCallbackInfo[i - 3 + 8];
            } else {
                OS_IRQTable[i] = function;
            }

            if (info) {
                info->func = (void (*)(void *))function;
                info->arg = 0;
                info->enable = 1;
            }
        }
        intrBit >>= 1;
    }
}
