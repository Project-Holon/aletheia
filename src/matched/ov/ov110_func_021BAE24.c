/*
 * function: func_021BAE24
 * address: 0x021BAE24
 * packet: pkt_ov110_021BAE24
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * symbols:
 *   func_021BC704 0x021BC704 thumb ov110
 *   func_021BF71C 0x021BF71C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 */
#include "../include/Obj02459.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BC704(u8 *p, u32 flag);
extern u16 func_021BF71C(u8 *);
extern void func_021BCF7C(u8 *p, int n, int v);
void func_021BAE24(u8 *p, u8 *a1, void *a2) {
    if(**(u32 * *)&((struct Obj02459 *)p)->f78==1) {
        func_021BC704(*(u8 * *)&((struct Obj02459 *)p)->f54,0);
        func_021BCF7C(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)func_021BF71C(*(u8 * *)&((struct Obj02459 *)p)->f18),0);
    } else if(p[0x74]==1) {
        func_021BC704(*(u8 * *)&((struct Obj02459 *)p)->f54,0);
        func_021BCF7C(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)func_021BF71C(*(u8 * *)&((struct Obj02459 *)p)->f18),1);
    } else {
        func_021BC704(*(u8 * *)&((struct Obj02459 *)p)->f54,1);
        func_021BCF7C(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)func_021BF71C(*(u8 * *)&((struct Obj02459 *)p)->f18),0);
    }
}
