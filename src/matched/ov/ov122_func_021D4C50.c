/*
 * function: func_021D4C50
 * address: 0x021D4C50
 * packet: pkt_ov122_021D4C50
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02158630 0x02158630 thumb ov010
 *   func_021D4BF4 0x021D4BF4 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 */
#include "../include/Obj05359.h"
#include "../include/Obj22931.h"
struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
extern int func_02158630(int a);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_021D4BF4(char *p);
extern void func_021D4244(void *p, u32 a, int a2);
int func_021D4C50(int value, char *p)
{
    void *obj;
    obj = (void *)func_02012138(((struct Obj05359 *)p)->f354);
    ((struct Obj05359 *)p)->f35C = value;
    switch (value) {
    case 0:
    case 3:
        ((struct Obj22931 *)(*(char * *)&((struct Obj05359 *)p)->f344))->f28 = func_02158630((int)obj);
        ((struct Obj05359 *)p)->f8 = 0;
        func_020061E4(0x73b);
        func_021D4244(p, (u32)func_021D4BF4, 0x3c4);
        break;
    case 1:
    case 4:
        ((struct Obj05359 *)p)->f8 = 1;
        func_020061E4(0x73b);
        func_021D4244(p, (u32)func_021D4BF4, 0x3cd);
        break;
    case 2:
        func_020061E4(0x73c);
        ((struct Obj05359 *)p)->f8 = 2;
        func_021D4244(p, (u32)func_021D4BF4, 0x3d3);
        break;
    }
    return 1;
}
