/*
 * function: MYSTERY_NET_DeleteBeacon
 * address: 0x021DE7BC
 * packet: pkt_ov121_021DE7BC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DELIVERY_BEACON_Delete 0x02157938 thumb ov010
 *   GFL_NET_IsIdle 0x0203D210 arm
 *   MYSTERY_NET_SetHandler 0x021DEEA4 thumb ov121
 *   MYSTERY_NET_NoopHandler 0x021DE618 thumb ov121
 */
#include "../include/Obj22916.h"
extern int DELIVERY_BEACON_Delete(void *a0);
extern unsigned GFL_NET_IsIdle(void);
typedef unsigned int   u32;
extern void MYSTERY_NET_SetHandler(u32 *p, void *f);
extern void MYSTERY_NET_NoopHandler(void);
void MYSTERY_NET_DeleteBeacon(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        DELIVERY_BEACON_Delete((void *)(((struct Obj22916 *)p)->f798));
        *state = 1;
        break;
    case 1:
        if (GFL_NET_IsIdle()) *state = 2;
        break;
    case 2:
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_NoopHandler);
        break;
    }
}
