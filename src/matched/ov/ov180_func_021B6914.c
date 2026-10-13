/*
 * function: func_021B6914
 * address:  0x021B6914
 * packet:   pkt_021B6914
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B6984  0x021B6984  thumb  ov180
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   MCSS_Exit  0x02014BA8  thumb
 */
#include "../include/Obj04569.h"

extern void func_021B6984(char *p);
typedef unsigned char  u8;
typedef unsigned int   u32;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void MCSS_Exit(u8 *a0);

void func_021B6914(int *p)
{
    func_021B6984((char *)p);
    G3D_CAMERA_Delete((void *)(((struct Obj04569 *)p)->f20));
    MCSS_Exit((u8 *)(((struct Obj04569 *)p)->f18));
}
