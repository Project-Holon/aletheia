/*
 * function: VCT_MAIN_DisconnectPeers
 * address:  0x021AF2AC
 * packet:   pkt_ov013_021AF2AC
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gVctWork     0x021B3C80  data  ov013
 *   VCT_SESSION_RemovePeer  0x021B2254  arm  ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;

typedef struct Work Work;

extern struct Work *gVctWork;
extern int VCT_SESSION_RemovePeer(int a);

int VCT_MAIN_DisconnectPeers(int n)
{
    int i;

    if (gVctWork == 0 || gVctWork->f19A8 != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == n) {
            continue;
        }
        if (gVctWork->a[i] != 1) {
            continue;
        }
        if (VCT_SESSION_RemovePeer((u8)i)) {
            return 0;
        }
        gVctWork->a[i] = 0;
    }
    return 1;
}
