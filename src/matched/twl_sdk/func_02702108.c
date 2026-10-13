/*
 * function: CAMERA_StartCaptureCore
 * address:  0x02702108
 * packet:   twl_wifi
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_04004202         0x04004202  data twl a2
 */

typedef unsigned short u16;
#define reg_04004202 (*(volatile u16 *)0x04004202)
extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);

void CAMERA_StartCaptureCore(void) {
    unsigned int irq = OS_DisableInterrupts();
    reg_04004202 |= 0x8000;
    OS_RestoreInterrupts(irq);
}
