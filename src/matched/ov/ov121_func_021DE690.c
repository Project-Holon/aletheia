/*
 * function: MYSTERY_NET_StopSession
 * address: 0x021DE690
 * packet: pkt_ov121_021DE690
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_DWC_Delete 0x020103E4 thumb
 *   GFL_NET_Exit 0x0203CEAC arm
 *   MYSTERY_NET_FlagExit 0x021DEED0 thumb ov121
 *   MYSTERY_NET_SetHandler 0x021DEEA4 thumb ov121
 *   MYSTERY_NET_NoopHandler 0x021DE618 thumb ov121
 */
#include "../include/Obj08100.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WIH_DWC_Delete(u8 *p);
extern int GFL_NET_Exit(int);
extern void MYSTERY_NET_FlagExit(char *p);
extern void MYSTERY_NET_NoopHandler(void);
extern void MYSTERY_NET_SetHandler(u32 *p, void *f);
void MYSTERY_NET_StopSession(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        WIH_DWC_Delete(((struct Obj08100 *)p)->f10);
        *(int *)&((struct Obj08100 *)p)->f10 = 0;
        *state = 1;
        break;
    case 1:
        if (GFL_NET_Exit((int)MYSTERY_NET_FlagExit)) *state = 2;
        else *state = 3;
        break;
    case 2:
        if (((struct Obj08100 *)p)->f5C) {
            ((struct Obj08100 *)p)->f5C = 0;
            *state = 3;
        }
        break;
    case 3:
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_NoopHandler);
        break;
    }
}
