/*
 * function: func_020853B0
 * address:  0x020853B0
 * packet:   pkt_020853B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_IsThreadAvailable (os_thread.o)
 *
 * symbols:
 *   OSi_IsThreadInitialized  0x02150FDC  data
 */

typedef int BOOL;

extern BOOL OSi_IsThreadInitialized;

BOOL func_020853B0(void)
{
    return OSi_IsThreadInitialized;
}
