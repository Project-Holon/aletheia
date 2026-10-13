/*
 * function: func_021B67BC
 * address: 0x021B67BC
 * packet: pkt_ov172_021B67BC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_021B680C 0x021B680C arm ov172
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02504.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int OS_IsRunOnTwl(void);
extern int func_021B680C(void);
extern void GFL_NET_FreeAligned(void *);
extern u32 func_020307B0(void *p);
void func_021B67BC(char *p)
{
    u8 i;
    if (((struct Obj02504 *)p)->f10 != 0) return;
    if ((OS_IsRunOnTwl() == 1 ? func_021B680C() : 0) != 0) return;
    if (((struct Obj02504 *)p)->fC == 1) {
        for (i = 0; i < ((struct Obj02504 *)p)->f8; i++)
            GFL_NET_FreeAligned((void *)(*(u32 **)(p + 4))[i]);
    }
    func_020307B0(((struct Obj02504 *)p)->f4);
    ((struct Obj02504 *)p)->f8 = 0;
    *(u32 *)&((struct Obj02504 *)p)->f4 = 0;
}
