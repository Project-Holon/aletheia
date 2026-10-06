/*
 * function: func_021B9FB4
 * address: 0x021B9FB4
 * packet: pkt_ov110_021B9FB4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021BA058 reads hardware register 0x04000304 before updating it.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_021BBCF0 0x021BBCF0 thumb ov110
 *   func_021BB2CC 0x021BB2CC thumb ov110
 *   func_021BF8BC 0x021BF8BC thumb ov110
 *   func_020403F4 0x020403F4 arm
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj04441.h"
#include "../include/Obj07997.h"
#include "../include/Obj22329.h"
#include "../include/Obj22330.h"
#include "../include/Obj22331.h"
#include "../include/Obj22332.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
struct Descriptor;
struct PrintSys;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021BBCF0(u8 *p);
extern void func_021BB2CC(u8 *p);
extern void func_021BF8BC(u8 *p);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020403F4(u32 i);
extern void func_021B9CBC(u8 *);
void func_021B9FB4(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj04441 *)p)->f0;
    switch (((struct Obj04441 *)p)->f14) {
    case 0:
        func_0202208C(0,0,0,0,5,1,42);
        ++((struct Obj04441 *)p)->f14;
        break;
    case 1:
        if (func_020221A4()) {
            func_020452E8(((struct Obj22329 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f6C);
            func_021BBCF0(((struct Obj22330 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f54);
            func_021BB2CC(((struct Obj22331 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f58);
            func_021BF8BC(((struct Obj22332 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f5C);
            func_0201D83C(((struct Obj07997 *)q)->f80);
            func_0201C6EC(((struct Obj07997 *)q)->f7C);
            func_0201C4C0(((struct Obj07997 *)q)->f7C);
            ((struct Obj07997 *)q)->f7C = 0;
            func_020403F4(0);
            func_020403F4(1);
            func_020403F4(2);
            func_020403F4(3);
            func_020403F4(4);
            func_020403F4(5);
            func_020403F4(6);
            *(volatile u16 *)0x04000304 |= 0x8000;
            func_021B9CBC(p);
        }
        break;
    }
}
