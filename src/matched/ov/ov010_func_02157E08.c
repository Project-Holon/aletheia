/*
 * function: DELIVERY_IRC_StartNet
 * address: 0x02157E08
 * packet: pkt_ov010_02157E08
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   d_02172868 0x02172868 data a1
 *   d_02172808 0x02172808 data a1
 */
#include "../include/Obj18744.h"
typedef unsigned char u8;
extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
struct Req;
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern u8 d_02172868[];
extern u8 d_02172808[];
int DELIVERY_IRC_StartNet(void *p)
{
    if (GFL_NET_GetRunState() != 0)
        return 0;
    d_02172868[7] = ((struct Obj18744 *)p)->f0;
    GFL_NET_StartSession((struct Req *)d_02172808, 0, (u32)p);
    return 1;
}
