/*
 * function: func_021D82F8
 * address: 0x021D82F8
 * packet: pkt_ov120_021D82F8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D8356.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02045760 0x02045760 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj08085.h"
#include "../include/Obj08086.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern u8 func_02045760(struct Descriptor *p);
extern void BMP_WIN_SetPosY(struct Descriptor *p, u8 v);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D82F8(char *p)
{
    int i;
    char *t;
    if(((struct Obj08085 *)p)->f80) {func_020452E8(((struct Obj08085 *)p)->f80);((struct Obj08085 *)p)->f80=0;}
    for(i=0;i<6;i++) {
        t=p+4*i;
        if(((struct Obj08086 *)t)->f6C) {
            BMP_WIN_SetPosY(((struct Obj08086 *)t)->f6C,func_02045760(((struct Obj08086 *)t)->f6C)+6);
            func_02045374(((struct Obj08086 *)t)->f6C);
        }
    }
    func_02041B6C(6);
    for(i=5;i>0;i--) *(void **)(p+0x6c+4*i)=*(void **)(p+0x68+4*i);
    ((struct Obj08085 *)p)->f6C=0;
}
