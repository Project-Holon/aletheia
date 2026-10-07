/*
 * function: func_0217B7E8
 * address:  0x0217B7E8
 * packet:   pkt_ov009_0217B7E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Netcheck_SetError (dwc_netcheck.o)
 *
 * symbols:
 *   OS_LockMutex    0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   g_021ACE5C      0x021ACE5C  data
 */

#include "../../../matched/include/G_G.h"

typedef struct {
    char pad0[0x11dc];
    int mutex;
} NC;
typedef struct {
    void *http;
    NC *nc;
} G;
extern struct G g_021ACE5C;
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);

void func_0217B7E8(int error)
{
    OS_LockMutex((char *)((NC *)g_021ACE5C.nc) + 0x11dc);
    *(int *)((char *)((NC *)g_021ACE5C.nc) + 0x1000) = error;
    OS_UnlockMutex((char *)((NC *)g_021ACE5C.nc) + 0x11dc);
}
