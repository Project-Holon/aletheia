/*
 * function: OSi_GetUnusedThreadId
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
 *   gOsThreadBss  0x02150FD0  data  a4
 */

#include "../include/G_OsThreadBss.h"

extern struct OsThreadBss gOsThreadBss;

int OSi_GetUnusedThreadId(void)
{
    return ++((int *)&gOsThreadBss)[6];
}
