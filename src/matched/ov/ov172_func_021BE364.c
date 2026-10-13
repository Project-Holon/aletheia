/*
 * function: func_021BE364
 * address: 0x021BE364
 * packet: pkt_ov172_021BE364
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   func_0203630C 0x0203630C arm
 *   func_021BD1AC 0x021BD1AC thumb ov172
 *   d_021C724C 0x021C724C data a4
 */
#include "../include/Obj03856.h"
#include "../include/Obj24143.h"
#include "../include/Obj24145.h"
#include "../include/Obj24146.h"
#include "../include/Obj24147.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *GAME_DATA_Create(u16 heap);
extern unsigned int func_0203630C(void);
extern void func_021BD1AC(char *self);
extern u8 d_021C724C[];
int func_021BE364(struct Obj0203159C *obj,int unused,u8 *arg)
{
    u8 *p;
    if (arg && ((struct Obj24143 *)arg)->f4==3) func_0203064C(1,109,0xd0000);
    else func_0203064C(1,109,0xe8000);
    p=func_0203159C(obj,0x1fc,109);
    ((struct Obj03856 *)p)->f0=109;
    if (arg==0) {
        *(u8 * *)&((struct Obj03856 *)p)->f1F8=func_02030734(1,16,1,(const char *)d_021C724C,1357);
        **(u32 * *)&((struct Obj03856 *)p)->f1F8=(u32)GAME_DATA_Create(1);
        ((struct Obj24145 *)(*(u8 * *)&((struct Obj03856 *)p)->f1F8))->f4=0;
        if (func_0203630C() & 0x100) ((struct Obj24146 *)(*(u8 * *)&((struct Obj03856 *)p)->f1F8))->f4=1;
        if (func_0203630C() & 0x400) ((struct Obj24147 *)(*(u8 * *)&((struct Obj03856 *)p)->f1F8))->f4=2;
    } else *(u8 * *)&((struct Obj03856 *)p)->f1F8=arg;
    ((struct Obj03856 *)p)->f14=0;
    func_021BD1AC((char *)p);
    return 1;
}
