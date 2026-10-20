/*
 * file:     os_systemwork.c
 * unit:     yes
 * function: OS_GetBootType, OS_GetBootInfo, OSi_IsCodecTwlMode
 * address:  0x02087B04
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
 *   OS_GetBootInfo    0x02087B14  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   g_02151360     0x02151360  data
 */
#include "../types.h"

#include "../sdk_os.h"

/* os_systemwork.o .bss from 0x02151360, addressed from one pool word: the
   function's statics retval and initialized. */
typedef struct OsSystemWorkBss {
    BOOL retval;
    BOOL initialized;
} OsSystemWorkBss;

#include "os_emulator.h"
u16 OS_GetBootType(void);
void *OS_GetBootInfo(void);
BOOL OSi_IsCodecTwlMode(void);
extern char SDK_AUTOLOAD_DTCM_START[];
extern OsSystemWorkBss g_02151360;

u16 OS_GetBootType(void)
{
    return *(u16 *)OS_GetBootInfo();
}

void *OS_GetBootInfo(void)
{
    return (void *)0x02FFFC40;
}

/*
 * sdk:      OSi_IsCodecTwlMode (os_systemwork.o)
 */
BOOL OSi_IsCodecTwlMode(void)
{
    if (!g_02151360.initialized) {
        g_02151360.retval = (OS_IsRunOnTwl() == 1 && (*(u8 *)0x02FFE1BF & 1) == 1) ? 1 : 0;
    }
    g_02151360.initialized = 1;
    return g_02151360.retval;
}
