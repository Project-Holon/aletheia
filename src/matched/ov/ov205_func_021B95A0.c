/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov205_021B95A0
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_020071F0 0x020071F0 thumb
 */
#include "../include/Obj04611.h"
typedef unsigned short u16;
extern void func_0203064C(unsigned,unsigned,unsigned);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082A7C(unsigned,void *,unsigned);
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Sub020071E4Ctrl;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
int func_021B95A0(void *owner,int unused,void **args)
{
    void *context;
    char *p;
    context=*args;
    func_0203064C(1,84,1<<18);
    p=func_0203159C(owner,76,84);
    func_02082A7C(0,p,76);
    ((struct Obj04611 *)p)->f0=84;
    ((struct Obj04611 *)p)->f2=36;
    ((struct Obj04611 *)p)->f4=func_020120F4(context);
    ((struct Obj04611 *)p)->f8=func_02012944(((struct Obj04611 *)p)->f4);
    if(func_020071F0(func_02012EBC(((struct Obj04611 *)p)->f4))!=0)
        ((struct Obj04611 *)p)->f40=1;
    return 1;
}
