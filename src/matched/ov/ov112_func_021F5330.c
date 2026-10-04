/*
 * function: func_021F5330
 * address:  0x021F5330
 * packet:   pkt_ov112_021F5330
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F61D8  0x021F61D8  thumb  ov112
 */
#include "../include/Obj08022.h"
#include "../include/Obj10302.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021F61D8(char *a, char *p);

void func_021F5330(int a, int b) {
    if (((struct Obj08022 *)b)->f10 != 0) {
        func_021F61D8((char *)(*(int *)&((struct Obj10302 *)a)->f4), (char *)(((struct Obj08022 *)b)->f10));
    }
    func_021F61D8((char *)(*(int *)&((struct Obj10302 *)a)->f4), (char *)(((struct Obj08022 *)b)->fC));
    ((struct Obj08022 *)b)->f0 = 0;
}
