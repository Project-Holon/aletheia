/*
 * function: DWC_RAP_FreeRecvBuffers
 * address:  0x02156C60
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resets the two slots and marks the flag at +0x7a6.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 *   DWC_RAP_FreeRecvBuffer  0x02156BD8  thumb  ov009
 */

#include "../include/G__anon_Work.h"

extern struct _anon_Work *g_021A8264;
typedef unsigned int   u32;
extern void DWC_RAP_FreeRecvBuffer(u32 i);

void DWC_RAP_FreeRecvBuffers(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        DWC_RAP_FreeRecvBuffer(i);
    }

    *(unsigned char *)(((char *)g_021A8264) + 0x7a6) = 1;
}

