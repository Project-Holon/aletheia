/*
 * function: LIVEBATTLEMATCH_IRC_DeliveryEnd
 * address: 0x0217E414
 * packet: pkt_ov176_0217E414
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DELIVERY_IRC_Main 0x02157E78 thumb ov010
 *   DELIVERY_IRC_Delete 0x02157E8C thumb ov010
 *   GFL_NET_IsIdle 0x0203D210 arm
 */
#include "../include/Obj04563.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void DELIVERY_IRC_Main(u8 *p);
extern int DELIVERY_IRC_Delete(void *a0);
extern u32 GFL_NET_IsIdle(void);
int LIVEBATTLEMATCH_IRC_DeliveryEnd(char *p)
{
    if (((struct Obj04563 *)p)->f1018)
        DELIVERY_IRC_Main(((struct Obj04563 *)p)->f1018);
    switch (((struct Obj04563 *)p)->f0) {
    case 0:
        if (((struct Obj04563 *)p)->f1018) {
            DELIVERY_IRC_Delete((void *)(((struct Obj04563 *)p)->f1018));
            ((struct Obj04563 *)p)->f1018 = 0;
        }
        (((struct Obj04563 *)p)->f0)++;
        break;
    case 1:
        if (GFL_NET_IsIdle())
            return 1;
        break;
    }
    return 0;
}
