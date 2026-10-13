/*
 * function: func_021D824C
 * address: 0x021D824C
 * packet: pkt_ov120_021D824C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D82A6.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02045760 0x02045760 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj08083.h"
#include "../include/Obj08084.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern u8 func_02045760(struct Descriptor *p);
extern void BMP_WIN_SetPosY(struct Descriptor *p, u8 v);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D824C(char *p)
{
    int i;
    char *t;
    if(((struct Obj08083 *)p)->f6C) {func_020452E8(((struct Obj08083 *)p)->f6C);((struct Obj08083 *)p)->f6C=0;}
    for(i=1;i<6;i++) {
        t=p+4*i;
        if(((struct Obj08084 *)t)->f6C) {
            BMP_WIN_SetPosY(((struct Obj08084 *)t)->f6C,func_02045760(((struct Obj08084 *)t)->f6C)-6);
            BMP_WIN_MakeScreen(((struct Obj08084 *)t)->f6C);
        }
    }
    func_02041B6C(6);
    for(i=0;i<5;i++) *(void **)(p+0x6c+4*i)=*(void **)(p+0x70+4*i);
    ((struct Obj08083 *)p)->f80=0;
}
