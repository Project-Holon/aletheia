/*
 * file:     unit_0217A880_p01.c
 * unit:     yes
 * function: func_0217AA20, func_0217AAA0
 * address:  0x0217AA20
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021797D4          0x021797D4  arm  ov009
 *   DWC_Auth_Abort         0x021780A8  arm  ov009
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_JoinThread          0x02085710  arm
 *   g_021ACE5C             0x021ACE5C  data
 *   OS_LockMutex    0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 */
extern void func_021797D4(void *http);
extern void DWC_Auth_Abort(void);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_JoinThread(void *thread);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
void func_0217AA20(void);
int func_0217AAA0(void);
extern char *g_021ACE5C[];


/*
 * sdk:      DWC_Netcheck_Abort (dwc_netcheck.o)
 */
void func_0217AA20(void)
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


/*
 * sdk:      DWC_Netcheck_GetError (dwc_netcheck.o)
 */
int func_0217AAA0(void)
{
    int error;
    OS_LockMutex(g_021ACE5C[1] + 0x11dc);
    error = *(int *)(g_021ACE5C[1] + 0x1000);
    OS_UnlockMutex(g_021ACE5C[1] + 0x11dc);
    return error;
}
