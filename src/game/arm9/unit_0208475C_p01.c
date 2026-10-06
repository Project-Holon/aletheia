/*
 * file:     unit_0208475C_p01.c
 * unit:     yes
 * function: func_0208475C, func_02084774, OS_GetIrqFunction, OSi_EnterDmaCallback
 * address:  0x0208475C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02FE00A0  0x02FE00A0  data  a4
 *   g_02150F38                     0x02150F38  data
 *   g_02FE0020                     0x02FE0020  data
 *   OS_EnableIrqMask               0x02084968  arm
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

void func_0208475C(void);
extern int g_02FE00A0[2];




/*
 * note:     os_interrupt.o OS_InitIrqTable (zeroes OSi_IrqThreadQueue).
 */
void func_0208475C(void)
{
    g_02FE00A0[1] = 0;
    g_02FE00A0[0] = 0;
}




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


extern OSIrqCallbackInfo g_02150F38[];   /* OSi_IrqCallbackInfo */
extern OSIrqFunction g_02FE0020[];       /* OS_IRQTable (DTCM) */
#define OSi_IrqCallbackInfo g_02150F38
#define OS_IRQTable g_02FE0020

extern OSIrqMask OS_EnableIrqMask(OSIrqMask intr);

OSIrqFunction OS_GetIrqFunction(OSIrqMask intrBit)
{
    int i;
    OSIrqFunction *funcPtr = &OS_IRQTable[0];

    for (i = 0; i < 32; i++) {
        if (intrBit & 1) {
            if (8 <= i && i <= 11) {
                return (OSIrqFunction)OSi_IrqCallbackInfo[i - 8].func;
            } else if (3 <= i && i <= 6) {
                return (OSIrqFunction)OSi_IrqCallbackInfo[i - 3 + 8].func;
            }
            return *funcPtr;
        }
        intrBit >>= 1;
        funcPtr++;
    }
    return 0;
}


extern OSIrqCallbackInfo g_02150F38[];   /* OSi_IrqCallbackInfo */
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
