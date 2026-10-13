/*
 * function: GFL_NET_SYSTEM_CheckAllChildRecv
 * address:  0x02038524
 * packet:   pkt_02038380
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _pNetSys    0x021469D0  data
 *   GFL_NET_SYSTEM_IsConnectMember 0x02039160  arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct LinkState *_pNetSys;
extern u32 GFL_NET_SYSTEM_IsConnectMember(u16 a);

int GFL_NET_SYSTEM_CheckAllChildRecv(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (GFL_NET_SYSTEM_IsConnectMember((u16)i) != 0 && *(int *)(((u8 *)_pNetSys) + 0x1b4 + i * 4) > 0) {
            return 0;
        }
    }
    return 1;
}
