/*
 * function: VCT_MAIN_ConnectPeers
 * address:  0x021AF238
 * packet:   pkt_ov013_021AF238
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gVctWork     0x021B3C80  data  ov013
 *   VCT_SESSION_AddPeer  0x021B21A4  arm  ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Work Work;

extern struct Work *gVctWork;
extern int VCT_SESSION_AddPeer(u8 i);

int VCT_MAIN_ConnectPeers(u32 mask, int n)
{
    int i;

    if (gVctWork == 0 || gVctWork->f19A8 != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == n) {
            continue;
        }
        if (!(mask & (1 << i))) {
            continue;
        }
        if (gVctWork->a[i] == 1) {
            continue;
        }
        if (VCT_SESSION_AddPeer(i)) {
            return 0;
        }
        gVctWork->a[i] = 1;
    }
    return 1;
}
