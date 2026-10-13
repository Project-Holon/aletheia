/*
 * function: func_021DE7BC
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
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 */
#include "../include/Obj22916.h"
extern int DELIVERY_BEACON_Delete(void *a0);
extern unsigned GFL_NET_IsIdle(void);
typedef unsigned int   u32;
extern void func_021DEEA4(u32 *p, void *f);
extern void func_021DE618(void);
void func_021DE7BC(void *a, int *state, char *p)
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
        func_021DEEA4(a, func_021DE618);
        break;
    }
}
