/*
 * function: DWC_Netcheck_GetError
 * address:  0x0217AAA0
 * packet:   pkt_ov009_0217AAA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Netcheck_GetError (dwc_netcheck.o)
 *
 * symbols:
 *   OS_LockMutex    0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   g_021ACE5C      0x021ACE5C  data
 */

extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern char *g_021ACE5C[];

int DWC_Netcheck_GetError(void)
{
    int error;
    OS_LockMutex(g_021ACE5C[1] + 0x11dc);
    error = *(int *)(g_021ACE5C[1] + 0x1000);
    OS_UnlockMutex(g_021ACE5C[1] + 0x11dc);
    return error;
}
