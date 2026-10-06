/*
 * function: func_021D5C60
 * address: 0x021D5C60
 * packet: pkt_ov120_021D5C60
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword registers written at 0x021D5C78 and 0x021D5C7E.
 * prototype: 0203064C r2 explicitly loaded despite two-arg definition;
 * 0203159C r0 allocation result used despite void matched definition.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D5E88 0x021D5E88 thumb ov120
 *   func_021D7724 0x021D7724 thumb ov120
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203A574 0x0203A574 arm
 *   d_021D88EC 0x021D88EC data a4
 *   func_0200F7E8 0x0200F7E8 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D588C 0x021D588C thumb ov120
 */
#include "../include/Obj01401.h"
#include "../include/Obj06435.h"
#include "../include/Obj22836.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203064C(u32, u32, u32);
extern u8 *func_0203159C(void *, u32, u32);
extern void func_02082BCC(void *, int, u32);
extern u8 *func_021D5E88(u32, void *);
struct Big;
struct BigObj;
extern char *func_021D7724(u32 heap, u32 n);
extern void func_0202223C(u32, u32);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_0203CD98(void);
extern void func_0203A574(u32, u32, u32, u32);
extern const u32 d_021D88EC[];
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_02005D90(u32, u32);
extern void func_0203D34C(u32, u32);
extern void func_0200F7E8(u32 value);
extern void func_021D4244(int, int, int);
extern void func_021D588C(u8 *);
int func_021D5C60(void *a, int unused, u8 *q)
{
    u8 *p;
    int zero = 0;
    func_0203064C(1, 0x1f, 0x38000);
    *(volatile u16 *)0x04000050 = zero;
    *(volatile u16 *)0x04001050 = zero;
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    p = func_0203159C(a, 0x1b8, 0x1f);
    func_02082BCC(p, 0, 0x1b8);
    ((struct Obj01401 *)p)->fC = 0x1f;
    *(u8 * *)&((struct Obj01401 *)p)->f48 = q;
    ((struct Obj01401 *)p)->f3C = func_021D5E88(((struct Obj01401 *)p)->fC, ((struct Obj06435 *)q)->f0);
    ((struct Obj01401 *)p)->f40 = func_021D7724(((struct Obj01401 *)p)->fC, 0x28);
    ((struct Obj01401 *)p)->f2C = ((struct Obj06435 *)q)->f0;
    ((struct Obj01401 *)p)->f30 = func_02012EBC(((struct Obj06435 *)q)->f0);
    ((struct Obj01401 *)p)->f44 = func_0201283C(((struct Obj06435 *)q)->f0);
    ((struct Obj22836 *)(*(u8 * *)&((struct Obj01401 *)p)->f48))->f1B0 = 1;
    ((struct Obj01401 *)p)->f15C = zero;
    ((struct Obj01401 *)p)->f160 = 2;
    ((struct Obj01401 *)p)->f164 = 6;
    ((struct Obj01401 *)p)->f14C = func_02008530((const struct Sub0200852CObj *)func_02012944(((struct Obj06435 *)q)->f0));
    if (func_0203CD98())
        func_0203A574(0x2200, (u32)d_021D88EC, 3, (u32)p);
    func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj01401 *)p)->fC);
    func_02005D90(0x486, 0xffff);
    func_0203D34C(1, ((struct Obj01401 *)p)->fC);
    func_0200F7E8(1);
    func_021D4244((int)p, (int)func_021D588C, 0x96a);
    return 1;
}
