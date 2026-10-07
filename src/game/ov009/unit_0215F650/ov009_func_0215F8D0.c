/*
 * function: FreeFunc_SOCL
 * address:  0x0215f8d0
 * packet:   pkt_ov009_0215F8D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FreeFunc_SOCL (soc.o)
 *
 * symbols:
 *   g_021AA4BC   0x021aa4bc data
 */

#include "../../../matched/include/G_SOCLAlloc.h"

typedef struct {
    unsigned long w00;
    void (*free_)(int, void *, unsigned long);
    unsigned long w08;
    void *(*alloc_)(int, unsigned long);
} SOCLAlloc;

extern struct SOCLAlloc g_021AA4BC;

static void FreeFunc_SOCL(void *ptr)
{
    unsigned long *m;

    if (ptr == 0)
        return;
    m = (unsigned long *)((char *)ptr - 4);
    g_021AA4BC.free_(0, m, *m);
}
