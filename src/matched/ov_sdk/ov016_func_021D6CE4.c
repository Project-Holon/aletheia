/*
 * function: func_021D6CE4
 * address:  0x021D6CE4
 * packet:   pkt_ov016_021D6CE4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ITRlEnd (libdwcutil.TWL.HYB.a interrupt.o)
 *
 * symbols:
 *   OS_SetIrqMask  0x0208493C  arm
 *   OS_SetIrqFunction 0x02084774  arm
 *   g_021DE6A0     0x021DE6A0  data
 */

#include "../include/G_ItrState.h"

typedef struct ItrState ItrState;

extern unsigned long OS_SetIrqMask(unsigned long intr);
extern void OS_SetIrqFunction(unsigned long intrBit, void (*function)(void));
extern struct ItrState g_021DE6A0;

void func_021D6CE4(void)
{
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short old = *ime;
    *ime = 0;
    OS_SetIrqMask(g_021DE6A0.mask);
    OS_SetIrqFunction(1, g_021DE6A0.func);
}
