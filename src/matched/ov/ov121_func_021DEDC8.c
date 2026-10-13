/*
 * function: func_021DEDC8
 * address: 0x021DEDC8
 * packet: pkt_ov121_021DEDC8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Follower 021DEE14 is filed separately and verified.
 * symbols:
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 */
#include "../include/Obj22918.h"
extern int GFL_NET_Exit(int);
extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
extern void func_021DEEA4(u32 *p, void *f);
extern void func_021DE618(void);
void func_021DEDC8(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        if (GFL_NET_Exit(0)) *state = 1;
        else *state = 2;
        break;
    case 1:
        if (GFL_NET_GetRunState() == 0) {
            ((struct Obj22918 *)p)->f5C = 0;
            *state = 2;
        }
        break;
    case 2:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}
