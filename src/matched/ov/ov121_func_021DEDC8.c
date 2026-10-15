/*
 * function: MYSTERY_NET_EndDownload
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
 *   MYSTERY_NET_SetHandler 0x021DEEA4 thumb ov121
 *   MYSTERY_NET_NoopHandler 0x021DE618 thumb ov121
 */
#include "../include/Obj22918.h"
extern int GFL_NET_Exit(int);
extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
extern void MYSTERY_NET_SetHandler(u32 *p, void *f);
extern void MYSTERY_NET_NoopHandler(void);
void MYSTERY_NET_EndDownload(void *a, int *state, char *p)
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
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_NoopHandler);
        break;
    }
}
