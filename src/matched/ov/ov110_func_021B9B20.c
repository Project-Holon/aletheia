/*
 * function: func_021B9B20
 * address: 0x021B9B20
 * packet: pkt_ov110_021B9B20
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049238 0x02049238 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021BCA30 0x021BCA30 thumb ov110
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj05284.h"
#include "../include/Obj06380.h"
typedef unsigned char u8;
extern void func_02049238(void *);
struct Bank;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021BCA30(u8 *p);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204ADA4(unsigned int);
extern void func_0204A8D4(unsigned int);
extern void func_0204AFD8(unsigned int);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020307B0(void *);
void func_021B9B20(u8 *p) {
    int i, j;
    if (p) {
        func_02049238(((struct Obj06380 *)p)->f8C);
        for (i=0; i<4; ++i) {
            void *r = *(void **)(p+8+i*4);
            if (r) func_02030EAC(r);
        }
        func_02030EAC(((struct Obj06380 *)p)->f0);
        func_02030EAC(((struct Obj06380 *)p)->f4);
        func_021BCA30(((struct Obj06380 *)p)->f64);
        func_0204B1CC(((struct Obj06380 *)p)->f20);
        for (j=0; j<2; ++j) {
            u8 *r = p+j*12;
            func_0204ADA4(((struct Obj05284 *)r)->f24);
            func_0204A8D4(((struct Obj05284 *)r)->f28);
            func_0204AFD8(((struct Obj05284 *)r)->f2C);
            func_0204ADA4(((struct Obj05284 *)r)->f3C);
            func_0204A8D4(((struct Obj05284 *)r)->f40);
            func_0204AFD8(((struct Obj05284 *)r)->f44);
        }
        func_0204A5AC();
        func_020450C8();
        func_0203F9B4();
        func_020307B0(p);
    }
}
