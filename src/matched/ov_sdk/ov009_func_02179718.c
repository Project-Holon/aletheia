/*
 * function: DWC_Http_StartThread
 * address:  0x02179718
 * packet:   pkt_ov009_02179718
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_StartThread (dwc_http.o)
 *
 * symbols:
 *   OS_InitMutex           0x02086004  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_CreateThread        0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   gDwcHttpFlag             0x021ACE58  data
 *   DWCi_Http_Thread          0x021799E8  arm  ov009
 */

extern int gDwcHttpFlag;
extern void OS_InitMutex(void *mutex);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long size, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void DWCi_Http_Thread(void *arg);

void DWC_Http_StartThread(char *http, unsigned long prio)
{
    *(int *)(http + 0x1c4c) = 0;
    OS_InitMutex(http + 0x1c34);
    OS_InitMutex(http + 0x1a54);
    if (*(int *)(http + 0x1018) == 1) {
        gDwcHttpFlag = 1;
    } else {
        gDwcHttpFlag = 0;
    }
    if (*(int *)(http + 0x1be0) != 0 && !OS_IsThreadTerminated(http + 0x1b74)) {
        return;
    }
    OS_CreateThread(http + 0x1b74, DWCi_Http_Thread, http, http + 0x1000, 0x1000, prio);
    OS_WakeupThreadDirect(http + 0x1b74);
}
