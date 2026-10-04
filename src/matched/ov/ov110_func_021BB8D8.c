/*
 * function: func_021BB8D8
 * address: 0x021BB8D8
 * packet: pkt_ov110_021BB8D8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_020499D4 0x020499D4 arm
 *   func_02045374 0x02045374 arm
 *   func_02049238 0x02049238 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj10275.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
extern u8 func_021BF6DC(u8 *);
typedef unsigned int   u32;
struct Cfg;
extern u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02045374(struct Cfg *cfg);
extern void func_02049238(void *);
extern void func_02041B6C(unsigned);
void func_021BB8D8(u8 *p)
{
    void *handle;
    int i;
    handle = func_020490F4(43, 42);
    if (func_021BF6DC(*(u8 * *)&((struct Obj10275 *)p)->f4) == 0) {
        func_020499D4(handle, 27, 1, 0, 0, 0, 0, 42);
        for (i = 0; i < 12; i++) func_02045374(*(void **)(p + 0x60 + i * 4));
    } else {
        func_020499D4(handle, 26, 1, 0, 0, 0, 0, 42);
        func_02045374(((struct Obj10275 *)p)->f90);
        func_02045374(((struct Obj10275 *)p)->f94);
    }
    func_02049238(handle);
    func_02041B6C(1);
}
