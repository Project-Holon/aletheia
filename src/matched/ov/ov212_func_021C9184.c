/*
 * function: ZUKAN_ResumeProc210
 * address: 0x021C9184
 * packet: pkt_ov212_021C9184
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 021C91C2.
 * lever: assign the result in each arm after its stores, keeping r4 reusable.
 * symbols:
 *   ZUKAN_FreeIdList 0x021C8F7C thumb ov212
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj04627.h"
#include "../include/Obj10926.h"
#include "../include/Obj25669.h"
typedef unsigned char  u8;
extern void ZUKAN_FreeIdList(u8 *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int ZUKAN_ResumeProc210(char *p)
{
    char *q=*(char * *)&((struct Obj04627 *)p)->f28;
    int result;
    switch(((struct Obj10926 *)q)->fC){
    case 0:
        ZUKAN_FreeIdList((u8 *)p);
        ((struct Obj04627 *)p)->fC=((struct Obj10926 *)q)->f10;
        ((struct Obj04627 *)p)->f10=((struct Obj10926 *)q)->f14;
        ((struct Obj04627 *)p)->f12=1;
        result=3;
        break;
    case 1:
        ((struct Obj04627 *)p)->f12=0;
        result=3;
        break;
    case 2:
    default:
        ((struct Obj25669 *)(*(char * *)&((struct Obj04627 *)p)->f0))->fE=1;
        result=9;
        break;
    }
    func_020307B0(((struct Obj04627 *)p)->f28);
    return result;
}
