/*
 * function: func_021DB3E8
 * address: 0x021DB3E8
 * packet: pkt_ov121_021DB3E8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040DA8 0x02040DA8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021D9A40 0x021D9A40 thumb ov121
 */
#include "../include/Obj01058.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
struct Obj;
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021D9A40(u8 *p);
void func_021DB3E8(char *p)
{
    int i;
    func_02040DA8(2,1,0);
    func_02040DA8(1,1,0);
    for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+0xaf4+i*4));
    func_0204B3B4(((struct Obj01058 *)p)->fAF0);
    func_0204B3B4(((struct Obj01058 *)p)->fAEC);
    func_0204A8D4((u32)(((struct Obj01058 *)p)->fAFC));
    func_0204AFD8((u32)(((struct Obj01058 *)p)->fB00));
    func_0204ADA4((u32)(((struct Obj01058 *)p)->fB04));
    func_021D9A40(((struct Obj01058 *)p)->fAB4);
    ((struct Obj01058 *)p)->fAB4=0;
    func_0204ADA4((u32)(((struct Obj01058 *)p)->fBA8));
    for(i=0;i<8;i++) func_020452E8(*(void **)(p+0xb08+i*4));
}
