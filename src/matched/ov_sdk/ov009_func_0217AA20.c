/*
 * function: DWC_Netcheck_Abort
 * address:  0x0217AA20
 * packet:   pkt_ov009_0217AA20
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Netcheck_Abort (dwc_netcheck.o)
 *
 * symbols:
 *   func_021797D4          0x021797D4  arm  ov009
 *   DWC_Auth_Abort         0x021780A8  arm  ov009
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_JoinThread          0x02085710  arm
 *   g_021ACE5C             0x021ACE5C  data
 */

extern void func_021797D4(void *http);
extern void DWC_Auth_Abort(void);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_JoinThread(void *thread);
extern char *g_021ACE5C[];

void DWC_Netcheck_Abort(void)
{
    if (g_021ACE5C[1] == 0) {
        return;
    }
    if (g_021ACE5C[0] != 0) {
        func_021797D4(g_021ACE5C[0]);
    }
    DWC_Auth_Abort();
    if (*(int *)(g_021ACE5C[1] + 0x1188) != 0 &&
        !OS_IsThreadTerminated(g_021ACE5C[1] + 0x111c)) {
        OS_JoinThread(g_021ACE5C[1] + 0x111c);
    }
    *(int *)(g_021ACE5C[1] + 0x1004) = -7;
}
