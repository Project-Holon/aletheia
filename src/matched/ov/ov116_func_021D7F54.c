/*
 * function: func_021D7F54
 * address: 0x021D7F54
 * packet: pkt_ov116_021D7F54
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj03252.h"
typedef unsigned char u8;
typedef short s16;
extern void func_0207E3D0(void *,int,int);
extern void func_0207E468(void *,int,int);
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
void func_021D7F54(void *unused,u8 *p) {
    if(((struct Obj03252 *)p)->f4!=0) {
        p[0x96b]^=1;
        if((p[0x96b]&1)==0) {
            func_0207E3D0(p+0x1f0+(((struct Obj03252 *)p)->f968<<5),40,14);
            func_0207E468(p+0x1f0+(((struct Obj03252 *)p)->f968<<5),40,14);
            (((struct Obj03252 *)p)->f968)++;
            if(((struct Obj03252 *)p)->f968>=60) ((struct Obj03252 *)p)->f968=0;
            func_02040618(p[0x96c],2,7);
        }
    }
}
