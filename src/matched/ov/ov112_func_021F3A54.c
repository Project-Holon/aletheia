/*
 * function: func_021F3A54
 * address: 0x021F3A54
 * packet: pkt_ov112_021F3A54
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware read-modify-writes at 0x021F3A64, 0x021F3A6E,
 *   0x021F3A94 (0x04000000, 0x04001000, 0x04000304).
 * symbols:
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   d_021F816C 0x021F816C data a4
 *   d_021F815C 0x021F815C data a4
 *   d_020A1448 0x020A1448 data a4
 */
#include "../include/Obj10296.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_020434CC(void);
extern void func_02043588(void);
typedef unsigned int   u32;
extern void func_0202223C(u32 a, u32 color);
struct Cfg;
extern u32 func_02022224(void *win);
extern void func_020433E0(void *);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(void *);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern char d_021F816C[],d_021F815C[],d_020A1448[];
void func_021F3A54(u8 *p)
{
    func_020434CC();
    func_02043588();
    *(volatile unsigned *)0x04000000 &= 0xffffe0ff;
    *(volatile unsigned *)0x04001000 &= 0xffffe0ff;
    func_0202223C(0,0);
    func_0202223C(1,0);
    func_02022224(0);
    func_02022224((void *)1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_020433E0(d_021F816C);
    func_0203F8F4(((struct Obj10296 *)p)->f0);
    func_02045088(((struct Obj10296 *)p)->f0);
    func_0203FC28(d_021F815C);
    func_0204A48C((const struct Cfg *)d_020A1448,(u32)d_021F816C,((struct Obj10296 *)p)->f0);
    func_020434DC(16,1);
}
