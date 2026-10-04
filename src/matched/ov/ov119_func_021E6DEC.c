/*
 * function: func_021E6DEC
 * address: 0x021E6DEC
 * packet: pkt_ov119_021E6DEC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020437AC 0x020437AC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj05338.h"
struct Obj;
extern void func_0204B3B4(struct Obj *p);
struct Obj020437AC;
extern void func_020437AC(struct Obj020437AC *p);
extern void func_0204A8D4(unsigned int);
extern void func_0204ADA4(unsigned int);
extern void func_0204AFD8(unsigned int);
void func_021E6DEC(int p) {
    int i;
    for (i=0;i<8;i++) {
        if (*(int *)(p+i*4+0x10cc)) {
            func_0204B3B4((struct Obj *)(*(int *)(p+i*4+0x10cc)));
            *(int *)(p+i*4+0x10cc)=0;
            func_020437AC(*(void **)(p+i*4+0x10f4));
            *(int *)(p+i*4+0x10f4)=0;
            func_0204A8D4(*(int *)(p+i*4+0x1114));
            *(int *)(p+i*4+0x1114)=0;
        }
    }
    if (((struct Obj05338 *)p)->f10EC) {func_0204ADA4(((struct Obj05338 *)p)->f10EC);((struct Obj05338 *)p)->f10EC=0;}
    if (((struct Obj05338 *)p)->f10EC) {func_0204AFD8(((struct Obj05338 *)p)->f111C);((struct Obj05338 *)p)->f10EC=0;}
}
