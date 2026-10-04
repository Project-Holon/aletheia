/*
 * function: func_021D5D94
 * address: 0x021D5D94
 * packet: pkt_ov123_021D5D94
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: display register 04001000 read/write at 021D5DCA/021D5DD0.
 * symbols:
 *   ov067_id 0x00000043 data
 *   func_02030734 0x02030734 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_021D5F4C 0x021D5F4C thumb ov123
 *   func_021D614C 0x021D614C thumb ov123
 *   func_021D6CD8 0x021D6CD8 thumb ov123
 *   func_021D6D5C 0x021D6D5C thumb ov123
 *   func_021D60F8 0x021D60F8 thumb ov123
 *   d_021DAB68 0x021DAB68 data a1
 *   d_021DAA9C 0x021DAA9C data a4
 *   d_020A1464 0x020A1464 data a4
 *   d_021DAA78 0x021DAA78 data a4
 */
#include "../include/Obj04498.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern const char d_021DAB68[];
extern char ov067_id[];
extern const u32 d_021DAA9C[], d_020A1464[], d_021DAA78[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int func_02034AC4(int);
extern void func_02043534(u32);
extern void func_020435F4(u32);
struct Bank;
extern void func_0204363C(u32 swap);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16 heapId);
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_020433E0(const void *);
extern void func_0203FC28(const void *);
extern void func_021D5F4C(u8 *);
extern void func_021D614C(u8 *);
extern void func_021D6CD8(u8 *);
extern void func_021D6D5C(u8 *);
extern void func_021D60F8(void *,u8 *);
extern void *func_020056A0(void *,void *,int);
u8 *func_021D5D94(u32 heap)
{
    u8 *p;
    p=func_02030734(heap,0x4568,1,d_021DAB68,0xfe);
    ((struct Obj04498 *)p)->f43C4=heap;
    func_02034AC4((int)ov067_id);
    func_02043534(0); func_020435F4(0); func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj04498 *)p)->f43C4);
    func_0204A48C((const struct Cfg *)d_020A1464,(u32)d_021DAA9C,((struct Obj04498 *)p)->f43C4);
    ((struct Obj04498 *)p)->fC=func_0204B100(40,0,((struct Obj04498 *)p)->f43C4);
    func_020433E0(d_021DAA9C); func_0203FC28(d_021DAA78);
    func_021D5F4C(p); func_021D614C(p); func_021D6CD8(p); func_021D6D5C(p);
    ((struct Obj04498 *)p)->f10=func_020056A0(func_021D60F8,p,0);
    ((struct Obj04498 *)p)->f455C=200;
    func_020435F4(31); func_02043534(27);
    return p;
}
