/*
 * file:     os_pxi.c
 * unit:     yes
 * function: OS_IsResetOccurred, OSi_CommonCallback, OSi_SendToPxi
 * address:  0x02084A28
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
 *   g_02150FC8    0x02150FC8  data
 *   OS_Terminate  0x02088234  arm
 *   PXI_SendWordByFifo  0x02088610  arm
 */
#include "../types.h"

/* os_pxi.o .bss from 0x02150FC8, addressed from one pool word. */
typedef struct OsPxiBss {
    u16 OSi_IsResetOccurred;
    u16 OSi_IsTerminateOccurred;
} OsPxiBss;

#include "../sdk_os.h"

#include "os_terminate_processor.h"
#include "pxi_fifo.h"
BOOL OS_IsResetOccurred(void);
void OSi_CommonCallback(int tag, u32 data, BOOL err);
void OSi_SendToPxi(u16 data);
extern OsPxiBss g_02150FC8;
extern char SDK_AUTOLOAD_DTCM_START[];

/*
 * sdk:      OS_IsResetOccurred (os_pxi.o)
 */
BOOL OS_IsResetOccurred(void)
{
    return g_02150FC8.OSi_IsResetOccurred;
}

/*
 * sdk:      OSi_CommonCallback (os_pxi.o)
 */
void OSi_CommonCallback(int tag, u32 data, BOOL err)
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

void OSi_SendToPxi(u16 data)
{
    u32 pxiSendData = (u32)data << 8;

    while (PXI_SendWordByFifo(12, pxiSendData, 0) != 0) {
    }
}
