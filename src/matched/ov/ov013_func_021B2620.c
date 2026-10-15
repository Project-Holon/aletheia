/*
 * function: VCT_SESSION_BroadcastPacket
 * address:  0x021B2620
 * packet:   pkt_ov013_021B2620
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctSession  0x021B60D8  data  ov013  a4
 *   gVctGroup  0x021B4BD0  data  ov013  a4
 *   VCT_SESSION_FillAnnounceFields  0x021B25FC  arm  ov013
 *   DWC_SendReliable  0x02176E90  arm  ov009
 */

#include "../include/G_Stat.h"

typedef unsigned char u8;

typedef struct Ctx {
    u8 b0;
} Ctx;

typedef struct Stat Stat;

extern Ctx gVctSession;
extern struct Stat gVctGroup;
extern void VCT_SESSION_FillAnnounceFields(u8 *a, u8 *b);
extern int DWC_SendReliable(int i, u8 *p, int n);

int VCT_SESSION_BroadcastPacket(int *o, u8 *p)
{
    int cnt;
    u8 i;

    cnt = 0;
    VCT_SESSION_FillAnnounceFields((u8 *)o, p);
    for (i = 0; i < 0x20; i++) {
        unsigned int m = (i != 0) ? (1 << i) : 1;
        if ((gVctGroup.mask & m) != 0 && i != gVctSession.b0) {
            p[9] = i;
            if (DWC_SendReliable(i, p, 0x10) != 0)
                cnt++;
        }
    }
    if (p[10] == 1)
        o[2] = gVctGroup.mask;
    else if (p[10] == 0)
        o[2] = 0;
    return cnt == 0 ? -4 : 0;
}
