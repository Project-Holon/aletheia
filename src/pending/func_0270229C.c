/*
 * function: func_0270229C
 * address:  0x0270229C
 * packet:   twl_wifi
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * NOT EXACT - 17 bytes differ. Two issues:
 *  1. Conditional LDM (poplt/popgt/ldmltfd/ldmgtfd) is not supported in CW asm void blocks.
 *  2. The barrel-shifted `orr r1, r2, r1, lsr #16` pattern for the count-1
 *     field insertion cannot be forced from C; the compiler generates an
 *     explicit `and r2, r2, #0xf` instead.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_02004200         0x02004200  data twl a2
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 enable);
extern u16 data_02004200;

void func_0270229C(s32 count)
{
    u32 ie;
    if (count < 1 || count > 16) {
        return;
    }
    ie = OS_DisableInterrupts();
    data_02004200 = (data_02004200 & ~0xf) | (count - 1);
    OS_RestoreInterrupts(ie);
}
