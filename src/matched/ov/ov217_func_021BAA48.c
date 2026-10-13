/*
 * function: func_021BAA48
 * address: 0x021BAA48
 * packet: pkt_ov217_021BAA48
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA3D8 0x021BA3D8 thumb ov217
 *   func_021BA3D0 0x021BA3D0 thumb ov217
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   d_021C2EFC 0x021C2EFC data a4
 * B294's returned r0 is stored and passed to B3DC in the original.
 */
#include "../include/Obj01785.h"
typedef unsigned short u16;
struct Vec {short x,y,z;unsigned char a,b;};
struct Entry {struct Vec vec;unsigned first,second,third,fourth;u16 arg,pad;};
struct Obj;
extern const struct Entry d_021C2EFC;
extern unsigned func_021BA3D8(void *,unsigned);
extern unsigned func_021BA3D0(void *,unsigned);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
void func_021BAA48(char *p)
{
    struct Vec vec;
    unsigned first,second,third,fourth;
    vec.x=d_021C2EFC.vec.x;vec.y=d_021C2EFC.vec.y;vec.z=d_021C2EFC.vec.z;
    vec.a=d_021C2EFC.vec.a;vec.b=d_021C2EFC.vec.b;
    first=func_021BA3D8(p,d_021C2EFC.first);
    second=func_021BA3D0(p,d_021C2EFC.second);
    third=func_021BA3D0(p,d_021C2EFC.third);
    fourth=func_021BA3D0(p,d_021C2EFC.fourth);
    *(unsigned *)&((struct Obj01785 *)p)->f7C=(unsigned)CLACT_CreateActor((void *)first,second,third,fourth,&vec,d_021C2EFC.arg,((struct Obj01785 *)p)->f4);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01785 *)p)->f7C,0);
}
