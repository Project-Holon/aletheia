/*
 * function: DWC_Http_Abort
 * address:  0x021797D4
 * packet:   pkt_ov009_021797D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_Abort (dwc_http.o)
 *
 * symbols:
 *   OS_LockMutex    0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 */

extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);

void DWC_Http_Abort(char *http)
{
    if (*(unsigned char *)(http + 0x1000) != 0xff) {
        return;
    }
    OS_LockMutex(http + 0x1c34);
    *(int *)(http + 0x1c4c) = 1;
    OS_UnlockMutex(http + 0x1c34);
}
