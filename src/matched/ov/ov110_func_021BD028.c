/*
 * function: func_021BD028
 * address: 0x021BD028
 * packet: pkt_ov110_021BD028
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 */
#include "../include/Obj13786.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
int func_021BD028(u8 *p)
{
    if(CLACT_GetActorDrawEnable(((struct Obj13786 *)p)->f28) && ((struct Obj13786 *)p)->f2C!=3) return 0;
    return 1;
}
