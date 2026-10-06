/*
 * function: func_021C9098
 * address: 0x021C9098
 * packet: pkt_ov212_021C9098
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: spell the empty-result arm first in the nested if/else;
 * shared failure exit remains after the switch.
 * symbols:
 *   func_021C8F7C 0x021C8F7C thumb ov212
 *   func_021C9288 0x021C9288 thumb ov212
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01587.h"
#include "../include/Obj25660.h"
#include "../include/Obj25661.h"
#include "../include/Obj25662.h"
#include "../include/Obj25663.h"
#include "../include/Obj25664.h"
#include "../include/Obj25665.h"
#include "../include/Obj25666.h"
typedef unsigned short u16;
struct Blk37;
typedef unsigned char  u8;
extern void func_021C8F7C(u8 *p);
extern u16 func_021C9288(struct Blk37 *,u16 **,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int func_021C9098(char *p)
{
    int result;
    switch(((struct Obj25660 *)(*(char * *)&((struct Obj01587 *)p)->f28))->f10){
    case 0:
        if(((struct Obj01587 *)p)->f12==0){
            ((struct Obj25661 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=0;result=9;
        }else{
            func_021C8F7C((u8 *)p);
            ((struct Obj01587 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25662 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
            ((struct Obj01587 *)p)->f12=0;result=3;
        }
        goto done;
    case 1:((struct Obj25663 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=1;result=9;goto done;
    case 2:
        func_021C8F7C((u8 *)p);
        ((struct Obj01587 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25664 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
        result=3;goto done;
    case 3:result=5;((struct Obj01587 *)p)->f24=1;goto done;
    case 4:
        if(((struct Obj01587 *)p)->f12==1){
            func_021C8F7C((u8 *)p);
            ((struct Obj01587 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25665 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
        }
        result=7;goto done;
    default:break;
    }
    ((struct Obj25666 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=0;result=9;
done:
    func_020307B0(((struct Obj01587 *)p)->f28);
    return result;
}
