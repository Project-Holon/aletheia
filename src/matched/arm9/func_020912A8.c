/*
 * function: MSL_C_LIB_LockRegisterDestructor
 * address:  0x020912A8
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  label - the only branch in the whole image to MSL_CONSOLE_IO_RegisterDestructor is the
 *           `bl` at +0x90 inside this very function.  `label` needs a site from
 *           outside 020912A8..02091374 and there is none, and MSL_CONSOLE_IO_RegisterDestructor is
 *           itself parked at MATCH in src/pending/MSL_CONSOLE_IO_RegisterDestructor.c, so the
 *           `matched` class has no manifest entry to cite either.  Filing the
 *           callee is the fix, but it lives in pkt_0209D728, which is not one
 *           of this lane's packets (write-set rule 9).
 *
 * harness output:
 *   MATCH  compiled 204 = original 204, 7 of 8 sites resolved
 *     +0010 OS_TryLockMutex [label x20]   +0070 OS_LockMutex [label x25]
 *     +0090 MSL_CONSOLE_IO_RegisterDestructor [UNRESOLVED - no witness outside this range]
 *     +00B0 func_02086078 [label x25]
 *     +00BC gMslMutexTable [literal x15]    +00C0 gMslRefToken [literal x60]
 *     +00C4 g_02153B8C [literal x15]    +00C8 g_02153BB0 [literal x15]
 *   every concrete byte right, no wildcard byte is inside a branch opcode.
 *
 * symbols:
 *   OS_LockMutex    0x02086028  arm
 *   OS_TryLockMutex    0x020860D0  arm
 *   func_02086078    0x02086078  arm
 *   MSL_CONSOLE_IO_RegisterDestructor    0x0209D728  arm
 *   gMslRefToken       0x02150FEC  data
 *   g_02153B8C       0x02153B8C  data
 *   g_02153BB0       0x02153BB0  data
 *   gMslMutexTable       0x02153BD4  data
 */

typedef unsigned int u32;

extern void OS_LockMutex(void *a0);
extern int OS_TryLockMutex(void *a0);
extern void func_02086078(void *a0);
extern int MSL_CONSOLE_IO_RegisterDestructor(int a);

extern u32 gMslRefToken[];
extern u32 g_02153B8C;
extern u32 g_02153BB0;
extern u32 gMslMutexTable;

u32 MSL_C_LIB_LockRegisterDestructor(u32 a0)
{
    u32 r;

    if (OS_TryLockMutex(&gMslMutexTable) == 0) {
        g_02153B8C = *(u32 *)(gMslRefToken[1] + 0x6C);
        g_02153BB0 = 1;
    } else if (g_02153B8C == *(u32 *)(gMslRefToken[1] + 0x6C)) {
        g_02153BB0 = g_02153BB0 + 1;
    } else {
        OS_LockMutex(&gMslMutexTable);
        g_02153B8C = *(u32 *)(gMslRefToken[1] + 0x6C);
        g_02153BB0 = 1;
    }
    r = MSL_CONSOLE_IO_RegisterDestructor(a0);
    if (--g_02153BB0 == 0) {
        func_02086078(&gMslMutexTable);
    }
    return r;
}
