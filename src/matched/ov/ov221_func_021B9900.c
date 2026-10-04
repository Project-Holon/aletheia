/*
 * function: func_021B9900
 * address: 0x021B9900
 * packet: pkt_ov221_021B9900
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj08452.h"
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef unsigned int   u32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern void func_020409B4(unsigned);
void func_021B9900(unsigned char *p)
{
    void *h=func_020490F4(0xCA,((struct Obj08452 *)p)->f0);
    func_02049B68((void *)((unsigned)h),1,0,0,0x1E0,((struct Obj08452 *)p)->f0);
    func_02049658((void *)((unsigned)h),4,1,0,0,0,((struct Obj08452 *)p)->f0);
    func_020498F4((void *)((unsigned)h),6,1,0,0,0,((struct Obj08452 *)p)->f0);
    func_02049238(h);
    func_020409B4(1);
}
