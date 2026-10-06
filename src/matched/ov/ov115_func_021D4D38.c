/*
 * function: func_021D4D38
 * address: 0x021D4D38
 * packet: pkt_ov115_021D4D38
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware reads/writes 021D4D66, 021D4D70, 021D4D74.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_021D4FA4 0x021D4FA4 thumb ov115
 *   func_021D5214 0x021D5214 thumb ov115
 *   func_021D57D0 0x021D57D0 thumb ov115
 *   func_021D5598 0x021D5598 thumb ov115
 *   func_021D4E58 0x021D4E58 thumb ov115
 *   func_021D50BC 0x021D50BC thumb ov115
 *   func_021D532C 0x021D532C thumb ov115
 *   d_021D6614 0x021D6614 data a1
 *   d_021D65E4 0x021D65E4 data a4
 *   d_021D65D4 0x021D65D4 data a4
 */
#include "../include/Obj00198.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 d_021D6614[];
extern u32 d_021D65E4[];
extern u32 d_021D65D4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204363C(u32);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16);
struct DispConfig;
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_021D4FA4(void *,u32);
extern void func_021D5214(void *,u32);
extern void func_021D57D0(u8 *p);
extern void func_021D5598(u8 *p);
extern void func_021D4E58(u32 unused, unsigned long base);
extern void func_021D50BC(void *,u32);
extern void func_021D532C(char *p);
u8 *func_021D4D38(u16 heap, u32 mode, int a2) {
    u8 *p;
    p=func_02030734(heap,0x14bc,1,(const char *)d_021D6614,146);
    ((struct Obj00198 *)p)->fC=heap;
    ((struct Obj00198 *)p)->f8=mode;
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050=0;
    func_0204363C(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj00198 *)p)->fC);
    func_020433E0((const struct DispVram *)d_021D65E4);
    func_0203FC28((struct DispConfig *)d_021D65D4);
    switch (((struct Obj00198 *)p)->f8) {
    case 1:
        func_021D4FA4(p,0);
        func_021D5214(p,4);
        func_021D57D0(p);
        func_021D5598(p);
        break;
    case 0:
        func_021D4E58((u32)p,0);
        func_021D50BC(p,4);
        func_021D532C((char *)p);
        break;
    }
    func_020435F4(31);
    func_02043534(31);
    return p;
}
