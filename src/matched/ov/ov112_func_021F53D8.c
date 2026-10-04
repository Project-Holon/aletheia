/*
 * function: func_021F53D8
 * address:  0x021F53D8
 * packet:   pkt_ov112_021F53D8
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021F62FC  0x021F62FC  thumb  ov112
 *   func_021F62DC  0x021F62DC  thumb  ov112
 */
#include "../include/Obj01717.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021F62FC(int, int);
extern void func_021F62DC(char *p);

void func_021F53D8(int a) {
    if (((struct Obj01717 *)a)->f4 == 1) {
        func_021F62FC(((struct Obj01717 *)a)->fC, ((struct Obj01717 *)a)->f10);
        ((struct Obj01717 *)a)->f8 = ((struct Obj01717 *)a)->f10;
        ((struct Obj01717 *)a)->f4 = 0;
        func_021F62DC((char *)(((struct Obj01717 *)a)->fC));
    } else {
        func_021F62FC(((struct Obj01717 *)a)->f10, ((struct Obj01717 *)a)->fC);
        ((struct Obj01717 *)a)->f8 = ((struct Obj01717 *)a)->fC;
        ((struct Obj01717 *)a)->f4 = 1;
        func_021F62DC((char *)(((struct Obj01717 *)a)->f10));
    }
}
