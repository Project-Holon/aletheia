/*
 * function: AllocFunc_SOCL
 * address:  0x0215f8a4
 * packet:   pkt_ov009_0215F8A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      AllocFunc_SOCL (soc.o)
 *
 * symbols:
 *   g_021AA4BC   0x021aa4bc data
 */

#include "../include/G_SOCLAlloc.h"

typedef struct {
    unsigned long w00;
    void *(*free_)(int, void *, unsigned long);
    unsigned long w08;
    void *(*alloc_)(int, unsigned long);
} SOCLAlloc;

extern struct SOCLAlloc g_021AA4BC;

static void *AllocFunc_SOCL(unsigned long size)
{
    unsigned long *m;
    unsigned long msize = size + 4;

    m = (unsigned long *)g_021AA4BC.alloc_(0, msize);
    if (m != 0)
        *m++ = msize;
    return m;
}
