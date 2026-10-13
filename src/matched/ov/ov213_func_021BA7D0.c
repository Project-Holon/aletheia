/*
 * function: func_021BA7D0
 * address: 0x021BA7D0
 * packet: pkt_ov213_021BA7D0
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAC7C 0x021BAC7C thumb ov213
 *   func_021BAC88 0x021BAC88 thumb ov213
 *   PARTICLE_Main 0x02050BE8 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 * arity: 50BE8 has visible p10 input at 021BA7DC despite own void prototype.
 */
#include "../include/Obj04631.h"
typedef unsigned int u32;
typedef struct { u32 x,y,z; } VecFx32;
typedef struct { u32 m[9]; } MtxFx33;
struct Arg { VecFx32 pos,v0c; MtxFx33 m18; };
typedef struct Util Util;
extern void func_021BAC7C(char *p);
extern void func_021BAC88(char *p);
typedef unsigned char  u8;
extern void PARTICLE_Main(void);
extern void MTX_Identity33_(MtxFx33 *p);
extern u32 func_02048A18(u8 *a0, int i);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
void func_021BA7D0(unsigned char *p)
{
    struct Arg arg;
    void *object;
    func_021BAC7C(((struct Obj04631 *)p)->f0);
    if(((struct Obj04631 *)p)->f10) PARTICLE_Main();
    if(p[15]) {
        arg.pos.x=0; arg.pos.y=0; arg.pos.z=0;
        arg.v0c.x=0x1000; arg.v0c.y=0x1000; arg.v0c.z=0x1000;
        MTX_Identity33_(&arg.m18);
        object=(void *)func_02048A18((u8 *)(*(Util * *)&((struct Obj04631 *)p)->f8),((struct Obj04631 *)p)->fC);
        G3D_SYSTEM_DrawObject(object,&arg);
    }
    func_021BAC88(((struct Obj04631 *)p)->f0);
}
