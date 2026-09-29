/*
 * function: func_021D6C78
 * address:  0x021D6C78
 * packet:   pkt_ov016_021D6C78
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ITRlIntr (libdwcutil.TWL.HYB.a interrupt.o)
 *
 * symbols:
 *   OS_SetIrqMask  0x0208493C  arm
 *   OS_EnableIrqMask 0x02084968  arm
 *   OS_GetIrqFunction 0x02084818  arm
 *   OS_SetIrqFunction 0x02084774  arm
 *   OS_ResetRequestIrqMask 0x020849C8  arm
 *   OS_EnableInterrupts 0x02087974  arm
 *   func_021D6D1C  0x021D6D1C  arm  ov016
 *   g_021DE6A0     0x021DE6A0  data
 */

typedef struct ItrState {
    void (*func)(void);
    unsigned long mask;
} ItrState;

extern unsigned long OS_SetIrqMask(unsigned long intr);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
extern void (*OS_GetIrqFunction(unsigned long intrBit))(void);
extern void OS_SetIrqFunction(unsigned long intrBit, void (*function)(void));
extern unsigned long OS_ResetRequestIrqMask(unsigned long intr);
extern unsigned long OS_EnableInterrupts(void);
extern void func_021D6D1C(void);
extern ItrState g_021DE6A0;

void func_021D6C78(void)
{
    volatile unsigned short *ime;
    unsigned short old;
    g_021DE6A0.mask = *(volatile unsigned long *)0x04000210;
    OS_SetIrqMask(0x40018);
    OS_EnableIrqMask(1);
    g_021DE6A0.func = OS_GetIrqFunction(1);
    OS_SetIrqFunction(1, func_021D6D1C);
    OS_ResetRequestIrqMask(1);
    ime = (volatile unsigned short *)0x04000208;
    old = *ime;
    *ime = 1;
    OS_EnableInterrupts();
}
