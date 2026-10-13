/*
 * function: func_021DF1C4
 * address: 0x021DF1C4
 * packet: pkt_ov137_021DF1C4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E1584 0x021E1584 thumb ov137
 *   func_021E0A44 0x021E0A44 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj02209.h"
#include "../include/Obj23756.h"
typedef unsigned char u8;
extern void func_021E1584(char *p, int flag);
extern u8 *func_021E0A44(void *);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void func_020061E4(u32 a);
int func_021DF1C4(u8 *p)
{
    func_021E1584((char *)p, 0);
    *(u8 * *)&((struct Obj02209 *)p)->f28 = func_021E0A44(p);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        if (((struct Obj23756 *)(*(u8 * *)&((struct Obj02209 *)p)->f28))->fC == GFL_NET_SYSTEM_GetCurrentAid())
            ((struct Obj02209 *)p)->f0 = 29;
        else
            ((struct Obj02209 *)p)->f0 = 30;
    } else {
        ((struct Obj02209 *)p)->f0 = 31;
    }
    func_020061E4(1833);
    return 1;
}
