/*
 * file:     interrupt.c
 * unit:     yes
 * function: DWCi_ITRlIntr, DWCi_ITRlEnd, intrVBlank
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
 *   gInterruptWork     0x021DE6A0  data
 *   DWCi_TSKlAct  0x021D75D0  arm  ov016
 *   sInterruptTable     0x02FE0000  data
 */
#include "../../matched/include/G_ItrState.h"
#include "../sdk_ioreg.h"

typedef struct ItrState ItrState;

typedef unsigned int OSIrqMask;
#include "../arm9/os_interrupt.h"
extern void OS_SetIrqFunction(unsigned long intrBit, void (*function)(void));
typedef unsigned int OSIntrMode;
#include "../arm9/os_system.h"
#include "task.h"
void DWCi_ITRlIntr(void);
void DWCi_ITRlEnd(void);
extern struct ItrState gInterruptWork;
extern int sInterruptTable;

extern void (*OS_GetIrqFunction(unsigned long intrBit))(void);

static void intrVBlank(void);


void DWCi_ITRlIntr(void)
{
    volatile unsigned short *ime;
    unsigned short old;
    gInterruptWork.mask = *(volatile unsigned long *)REG_IE_ADDR;
    OS_SetIrqMask(0x40018);
    OS_EnableIrqMask(1);
    gInterruptWork.func = OS_GetIrqFunction(1);
    OS_SetIrqFunction(1, intrVBlank);
    OS_ResetRequestIrqMask(1);
    ime = (volatile unsigned short *)REG_IME_ADDR;
    old = *ime;
    *ime = 1;
    OS_EnableInterrupts();
}


/*
 * sdk:      DWCi_ITRlEnd (libdwcutil.TWL.HYB.a interrupt.o)
 */
void DWCi_ITRlEnd(void)
{
    volatile unsigned short *ime = (volatile unsigned short *)REG_IME_ADDR;
    unsigned short old = *ime;
    *ime = 0;
    OS_SetIrqMask(gInterruptWork.mask);
    OS_SetIrqFunction(1, gInterruptWork.func);
}


/*
 * sdk:      intrVBlank (libdwcutil.TWL.HYB.a interrupt.o)
 */
static void intrVBlank(void)
{
    DWCi_TSKlAct(1);
    *(volatile unsigned int *)((uptr)&sInterruptTable + 0x3FF8) |= 1;
}
