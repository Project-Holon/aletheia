/*
 * function: func_02084FB4
 * address:  0x02084FB4
 * packet:   pkt_02084FB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_thread.o OSi_GetUnusedThreadId.
 *
 * symbols:
 *   g_02150FD0  0x02150FD0  data  a4
 */

#include "../include/G_OsThreadBss.h"

extern struct OsThreadBss g_02150FD0;

int func_02084FB4(void)
{
    return ++((int *)&g_02150FD0)[6];
}
