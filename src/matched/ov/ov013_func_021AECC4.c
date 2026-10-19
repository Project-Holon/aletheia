/*
 * function: VCT_MAIN_AcceptPendingPeer
 * address:  0x021AECC4
 * packet:   pkt_ov013_021AECC4
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VCT_SESSION_SendPeerReply  0x021B2180  arm  ov013
 *   VCT_MIXER_AddMember  0x021B0614  arm  ov013
 *   gVctWork     0x021B3C80  data  ov013
 */
#include "../include/Obj19303.h"
#include "../include/G_Work.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern struct Work *gVctWork;

extern int VCT_SESSION_SendPeerReply(int a, int b);
extern int VCT_MIXER_AddMember(void *p);

int VCT_MAIN_AcceptPendingPeer(int x)
{
    u8 *p = *(u8 **)(((u8 *)gVctWork) + 0x1A1C);
    int r;

    if (p != 0 && ((struct Obj19303 *)p)->fC == 4) {
        r = 0;
        if (VCT_SESSION_SendPeerReply((int)p, 0) != 0) {
            return r;
        }
        if (VCT_MIXER_AddMember(*(void **)(((u8 *)gVctWork) + 0x1A1C)) != 0) {
            r = 1;
        }
        return r;
    }
    return 0;
}
