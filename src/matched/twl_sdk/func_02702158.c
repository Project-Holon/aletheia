/*
 * function: CAMERA_SetTrimmingCore
 * address:  0x02702158
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

void CAMERA_SetTrimmingCore(unsigned int enable) {
    unsigned int irq = OS_DisableInterrupts();
    u16 v = reg_04004202;
    reg_04004202 = enable ? (v | 0x4000) : (v & ~0x4000);
    OS_RestoreInterrupts(irq);
}
