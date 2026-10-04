/*
 * function: func_021D4310
 * address: 0x021D4310
 * packet: pkt_ov115_021D4310
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4240 0x021D4240 thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4644 0x021D4644 thumb ov115
 *   func_021D4BB4 0x021D4BB4 thumb ov115
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 */
#include "../include/Obj08038.h"
#include "../include/Obj22586.h"
#include "../include/Obj22587.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D4240(u8 *);
extern void func_021D5F7C(u8 *p);
extern void func_021D5CCC(u8 *p, u32 n);
extern void func_021D426C(u8 *, u32);
extern int func_021D4644(u8 *);
extern void func_021D4BB4(u8 *p);
extern void func_021D4AB0(int a);
void func_021D4310(u8 *p)
{
    if (func_021D4240(p)) {
        func_021D5F7C((u8 *)(((struct Obj08038 *)p)->f38));
        if (((struct Obj22586 *)(*(u8 * *)&((struct Obj08038 *)p)->f40))->f4 == 0)
            func_021D5CCC((u8 *)(((struct Obj08038 *)p)->f38), 0x23);
        if (((struct Obj22587 *)(*(u8 * *)&((struct Obj08038 *)p)->f40))->f10 != 0)
            func_021D426C(p, (u32)func_021D4BB4);
        else
            func_021D426C(p, (u32)func_021D4AB0);
    } else {
        func_021D4644(p);
    }
}
