/*
 * function: GDS_RAP_GetDownloadEntries
 * address: 0x021D7374
 * packet: pkt_ov125_021D7374
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_SOCKET_GetReply 0x021D85E8 arm ov125
 */
#include "../include/Obj23004.h"
extern char *GDS_SOCKET_GetReply(void);
typedef struct { int count; char entries[1]; } List;
int GDS_RAP_GetDownloadEntries(char *a, void **out, int max)
{
    int p;
    char *base;
    int n;
    int i;
    p = (int)(GDS_SOCKET_GetReply() + 4);
    n = ((struct Obj23004 *)p)->f0;
    if (n > max) n = max;
    base = (char *)(p + 4);
    for (i = 0; i < n; i++) out[i] = base + i * 572 + 12;
    for (; i < max; i++) out[i] = 0;
    return n;
}
