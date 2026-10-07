/*
 * file:     unit_021D6C78.c
 * unit:     yes
 * function: func_021D6C78, func_021D6CE4, func_021D6D1C
 * address:  0x021D6C78
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_SetIrqMask  0x0208493C  arm
 *   OS_EnableIrqMask 0x02084968  arm
 *   OS_GetIrqFunction 0x02084818  arm
 *   OS_SetIrqFunction 0x02084774  arm
 *   OS_ResetRequestIrqMask 0x020849C8  arm
 *   OS_EnableInterrupts 0x02087974  arm
 *   g_021DE6A0     0x021DE6A0  data
 *   func_021D75D0  0x021D75D0  arm  ov016
 *   g_02FE0000     0x02FE0000  data
 */
#include "../../matched/include/G_ItrState.h"

typedef struct ItrState ItrState;

extern unsigned long OS_SetIrqMask(unsigned long intr);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
extern void OS_SetIrqFunction(unsigned long intrBit, void (*function)(void));
extern unsigned long OS_ResetRequestIrqMask(unsigned long intr);
extern unsigned long OS_EnableInterrupts(void);
extern void func_021D75D0(int kind);
void func_021D6C78(void);
void func_021D6CE4(void);
void func_021D6D1C(void);
extern struct ItrState g_021DE6A0;
extern int g_02FE0000;

extern void (*OS_GetIrqFunction(unsigned long intrBit))(void);


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


/*
 * sdk:      DWCi_ITRlEnd (libdwcutil.TWL.HYB.a interrupt.o)
 */
void func_021D6CE4(void)
{
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short old = *ime;
    *ime = 0;
    OS_SetIrqMask(g_021DE6A0.mask);
    OS_SetIrqFunction(1, g_021DE6A0.func);
}


/*
 * sdk:      intrVBlank (libdwcutil.TWL.HYB.a interrupt.o)
 */
void func_021D6D1C(void)
{
    func_021D75D0(1);
    *(volatile unsigned int *)((unsigned int)&g_02FE0000 + 0x3FF8) |= 1;
}
