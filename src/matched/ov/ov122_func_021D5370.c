/*
 * function: func_021D5370
 * address: 0x021D5370
 * packet: pkt_ov122_021D5370
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 021D53BA reads hardware DISPCNT, 021D53C0 writes the update.
 * ABI: 0203159C leaves the allocator result in r0 (020315BC/15C0); caller uses it.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_021D5368 0x021D5368 thumb ov122
 *   func_021D424C 0x021D424C thumb ov122
 *   func_021D48D8 0x021D48D8 thumb ov122
 *   func_0203101C 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021D4A64 0x021D4A64 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 *   func_0203D798 0x0203D798 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_021D5278 0x021D5278 thumb ov122
 *   func_02178118 0x02178118 thumb ov014
 *   func_020355D8 0x020355D8 arm
 *   data_021D58B0 0x021D58B0 data a4
 *   data_021D5770 0x021D5770 data a4
 *   data_021D5740 0x021D5740 data a4
 */
#include "../include/Obj00073.h"
#include "../include/Obj13967.h"
#include "../include/Obj22934.h"
#include "../include/Obj22935.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v[4]; } Display;
extern u32 data_021D58B0[], data_021D5740[];
extern const Display data_021D5770;
extern void func_0203064C(u32, u32, u32);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, u32);
extern void func_0204363C(u32);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
struct Cfg;
struct DispConfig;
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
struct R;
struct Tcbl;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_021D5368(void);
extern void *func_020056A0(u32, void *, u32);
extern void func_021D424C(void *);
extern void func_021D48D8(char *);
extern void *func_0201EC74(u32, u32, u32);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021D4A64(char *);
extern void func_021D4244(void *p, u32 a, int a2);
extern void *func_0203D798(void);
extern void func_0203D34C(u32, u32);
extern int func_0203CD98(void);
extern void func_021D5278(void *, const char *, int, int);
extern void func_02178118(u32, u32);
extern void func_020355D8(u8);
int func_021D5370(void *owner, void *unused, char *args)
{
    char *p;
    Display display;
    func_0203064C(1, 31, 0x18000);
    p = func_0203159C(owner, 0x3a8, 31);
    func_02082BCC(p, 0, 0x3a8);
    ((struct Obj00073 *)p)->fC = 31;
    ((struct Obj00073 *)p)->f350 = ((struct Obj13967 *)args)->f4;
    ((struct Obj00073 *)p)->f354 = ((struct Obj13967 *)args)->f0;
    func_0204363C(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj00073 *)p)->fC);
    func_02045088(((struct Obj00073 *)p)->fC);
    func_0201DD60();
    func_020433E0((const struct DispVram *)data_021D58B0);
    display = data_021D5770;
    func_0203FC28((struct DispConfig *)(&display));
    func_02043534(0);
    func_020435F4(0);
    func_0204A48C((const struct Cfg *)data_021D5740, (u32)data_021D58B0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f30C = func_0204B100(40, 0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f310 = func_020056A0((u32)func_021D5368, p, 0);
    func_021D424C(p);
    func_021D48D8(p);
    ((struct Obj00073 *)p)->f48 = func_0201EC74(11, 200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f31C = func_0203101C(((struct Obj00073 *)p)->fC, ((struct Obj00073 *)p)->fC, 1, 0);
    ((struct Obj00073 *)p)->f320 = func_0201C440((void *)(((struct Obj00073 *)p)->fC));
    ((struct Obj00073 *)p)->f340 = func_02027F60(5, 13, *(u32 *)&((struct Obj00073 *)p)->f4C, ((struct Obj00073 *)p)->f320, ((struct Obj00073 *)p)->fC);
    func_0207D63C((void *)0x04001050, 4, 1, 15, 4);
    func_0202208C((void *)4, 1, 1, 0, 6, 1, ((struct Obj00073 *)p)->fC);
    func_020435F4(31);
    func_021D4244(p, (u32)func_021D4A64, 0x6cb);
    *(char * *)&((struct Obj00073 *)p)->f344 = args;
    func_0203D798();
    ((struct Obj22934 *)(*(char * *)&((struct Obj00073 *)p)->f344))->f10 = 1;
    ((struct Obj22935 *)(*(char * *)&((struct Obj00073 *)p)->f344))->fC = ((struct Obj00073 *)p)->f350;
    func_0203D34C(0, ((struct Obj00073 *)p)->fC);
    if (func_0203CD98()) func_02178118((u32)func_021D5278, (u32)p);
    func_020355D8(1);
    return 1;
}
