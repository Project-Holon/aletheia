/*
 * unit: yes
 * function: func_021C6170, func_021C61CC
 * address: 0x021C6170
 * packet: pkt_ov136_021C6170
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021C5FDC 0x021C5FDC thumb ov136
 */
#include "../include/Obj06528.h"
#include "../include/Obj23555.h"
#include "../include/Obj23556.h"
#include "../include/Obj23557.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021C5FDC(u8 *, void *, int, u32, int, int, u32, u16, int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
void func_021C6170(u8 *p)
{
    void *obj;
    func_02043B5C(func_02045770(((struct Obj23555 *)(*(u8 * *)&((struct Obj06528 *)p)->f8))->fAC), 0);
    func_021C5FDC(*(u8 * *)&((struct Obj06528 *)p)->f8, ((struct Obj23556 *)(*(u8 * *)&((struct Obj06528 *)p)->f8))->f1D0, 26, 0, 52, 0, ((struct Obj06528 *)p)->f18, 0x440, 2);
    obj = ((struct Obj23557 *)(*(u8 * *)&((struct Obj06528 *)p)->f8))->fAC;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
}
void func_021C61CC(u8 *a0)
{
}
