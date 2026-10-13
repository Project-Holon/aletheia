/*
 * function: GFL_NET_SYSTEM_ClearChildRecv
 * address:  0x02038570
 * packet:   pkt_02038380
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _pNetSys    0x021469D0  data
 *   GFL_NET_GetMaxConnectNum 0x0203D680  arm
 *   GFL_NET_SYSTEM_IsConnectMember 0x02039160  arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct LinkState *_pNetSys;
extern u32 GFL_NET_GetMaxConnectNum(void);
extern u32 GFL_NET_SYSTEM_IsConnectMember(u16 a);

void GFL_NET_SYSTEM_ClearChildRecv(void)
{
    int i;
    int n = GFL_NET_GetMaxConnectNum();

    for (i = 0; i < n; i++) {
        if (GFL_NET_SYSTEM_IsConnectMember((u16)i) != 0) {
            *(u32 *)((u8 *)((u32 *)((u8 *)_pNetSys) + i) + 0x1b4) += 1;
        }
    }
}
