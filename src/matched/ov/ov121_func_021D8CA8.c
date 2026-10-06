/*
 * function: func_021D8CA8
 * address: 0x021D8CA8
 * packet: pkt_ov121_021D8CA8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware access at 021D8CB2
 * symbols:
 *   func_021D6D7C 0x021D6D7C thumb ov121
 *   func_021D6D38 0x021D6D38 thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj08088.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void *func_021D6D7C(u8 *p);
extern void func_021D6D38(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02082BCC(void *,int,int);
void func_021D8CA8(u8 *p)
{
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    if(func_021D6D7C(p+280)) func_021D6D38(p+280);
    func_02040588(2,0);
    func_0204B3B4(((struct Obj08088 *)p)->f4);
    func_0204ADA4((u32)(((struct Obj08088 *)p)->fC));
    func_0204A8D4((u32)(((struct Obj08088 *)p)->f10));
    func_0204AFD8((u32)(((struct Obj08088 *)p)->f14));
    func_02082BCC(p,0,300);
}
