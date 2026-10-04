/*
 * function: func_021BD0D4
 * address: 0x021BD0D4
 * packet: pkt_ov110_021BD0D4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj13787.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
void func_021BD0D4(u8 *p)
{
    int i;
    for(i=0;i<8;i++) func_0204B3B4(*(void **)(p+i*4+0x70));
    func_0204A8D4(((struct Obj13787 *)p)->f14);
    func_0204AFD8(((struct Obj13787 *)p)->f18);
}
