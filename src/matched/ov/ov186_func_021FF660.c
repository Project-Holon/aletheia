/*
 * function: BR_NET_GetDownloadEntries
 * address:  0x021FF660
 * packet:   pkt_021FF660
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GDS_RAP_GetDownloadEntries  0x021D7374  thumb  ov125
 */
#include "../include/Obj24856.h"

extern int GDS_RAP_GetDownloadEntries(char *a, void **out, int max);

int BR_NET_GetDownloadEntries(char *p, int a1, int a2, int *out)
{
    int v = ((struct Obj24856 *)p)->f5BC;

    if (v != 0)
        *out = GDS_RAP_GetDownloadEntries((char *)p, (void **)a1, a2);
    return v;
}
