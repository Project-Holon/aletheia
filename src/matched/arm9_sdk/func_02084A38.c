/*
 * function: func_02084A38
 * address:  0x02084A38
 * packet:   pkt_02084A38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_CommonCallback (os_pxi.o)
 *
 * symbols:
 *   OS_Terminate  0x02088234  arm
 *   g_02150FC8    0x02150FC8  data
 */

#include "../include/G_OsPxiBss.h"

typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

extern void OS_Terminate(void);
/* os_pxi.o .bss from 0x02150FC8, addressed from one pool word. */
typedef struct OsPxiBss OsPxiBss;

extern struct OsPxiBss g_02150FC8;

void func_02084A38(int tag, u32 data, BOOL err)
{
    u16 command = (u16)((data & 0x7F00) >> 8);

    if (command == 0x10) {
        g_02150FC8.OSi_IsResetOccurred = 1;
    } else if (command == 0x20) {
        g_02150FC8.OSi_IsTerminateOccurred = 1;
        OS_Terminate();
    } else {
        OS_Terminate();
    }
}
