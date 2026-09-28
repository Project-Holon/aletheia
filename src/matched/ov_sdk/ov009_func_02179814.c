/*
 * function: DWCi_Http_Yield
 * address:  0x02179814
 * packet:   pkt_ov009_02179814
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_Yield (dwc_http.o)
 *
 * symbols:
 *   OS_GetLowEntropyData   0x02088168  arm
 *   CPS_SslAddRandomSeed   0x02162248  arm
 *   OS_LockMutex           0x02086028  arm
 *   OS_UnlockMutex         0x02086078  arm
 *   OS_Sleep               0x02085a38  arm
 */

extern void OS_GetLowEntropyData(unsigned long *buffer);
extern void CPS_SslAddRandomSeed(void *random_seed, unsigned long len);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern void OS_Sleep(unsigned long msec);

static int DWCi_Http_Yield(char *http)
{
    if (*(int *)(http + 0x1130) == 1) {
        OS_GetLowEntropyData((unsigned long *)(http + 0x1a10));
        CPS_SslAddRandomSeed(http + 0x1a10, 0x20);
    }
    OS_LockMutex(http + 0x1c34);
    if (*(int *)(http + 0x1c4c) == 1) {
        OS_UnlockMutex(http + 0x1c34);
        return 0;
    }
    OS_UnlockMutex(http + 0x1c34);
    OS_Sleep(10);
    return 1;
}
