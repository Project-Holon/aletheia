/*
 * function: MYSTERY_NET_DeleteIrc
 * address: 0x021DE8D0
 * packet: pkt_ov121_021DE8D0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DELIVERY_IRC_Delete 0x02157E8C thumb ov010
 *   GFL_NET_IsIdle 0x0203D210 arm
 *   MYSTERY_NET_SetHandler 0x021DEEA4 thumb ov121
 *   MYSTERY_NET_NoopHandler 0x021DE618 thumb ov121
 */
#include "../include/Obj22917.h"
extern int DELIVERY_IRC_Delete(void *a0);
extern unsigned GFL_NET_IsIdle(void);
typedef unsigned int   u32;
extern void MYSTERY_NET_SetHandler(u32 *p, void *f);
extern void MYSTERY_NET_NoopHandler(void);
void MYSTERY_NET_DeleteIrc(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        DELIVERY_IRC_Delete((void *)(((struct Obj22917 *)p)->f79C));
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
