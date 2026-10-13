/*
 * function: func_021BF9FC
 * address: 0x021BF9FC
 * packet: pkt_ov204_021BF9FC
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing two bytes are zero alignment padding; separate component stores preserve ascending order.
 * symbols:
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 */
#include "../include/Obj06675.h"

struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void func_0207ADC4(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
struct Arg;
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

void func_021BF9FC(char *p)
{
    struct Transform { int pos[3]; int scale[3]; int matrix[9]; } t;
    G3D_CAMERA_Reset(((struct Obj06675 *)p)->fC);
    if (((struct Obj06675 *)p)->f14 != 0 && ((struct Obj06675 *)p)->f18 != 0)
    {
        t.pos[0] = 0;
        t.pos[1] = 0;
        t.pos[2] = 0;
        t.scale[0] = 4096;
        t.scale[1] = 4096;
        t.scale[2] = 4096;
        func_0207ADC4(t.matrix);
        G3D_SYSTEM_DrawObject((void *)func_02048A18(((struct Obj06675 *)p)->f8, ((struct Obj06675 *)p)->f10), (struct Arg *)(&t));
    }
}
